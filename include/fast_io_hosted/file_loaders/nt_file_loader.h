#pragma once

namespace fast_io 
{

namespace win32::nt::details 
{

struct nt_file_loader_return_value_t {
	char* address_begin{};
	char* address_end{};
};

template <bool zw>
inline void* nt_create_section_common_impl(void* hfilemappingobj) {
	::fast_io::win32::nt::object_attributes objAttr{
		.Length = sizeof(object_attributes),
		.Attributes = 0x40L /*OBJ_CASE_INSENSITIVE*/
	};
	void* h_section{};
	auto status{::fast_io::win32::nt::nt_create_section<zw>(__builtin_addressof(h_section), 0x000F0000 | 0x0001 | 0x0004, __builtin_addressof(objAttr), nullptr, 0x08, 0x08000000, hfilemappingobj)};
	if (status)
		throw_nt_error(status);
	return h_section;
}

template <bool zw>
inline nt_file_loader_return_value_t nt_create_map_view_common_impl(void* handle) {
	void* h_section{nt_create_section_common_impl<zw>(handle)};
	void* p_map_address{};
	::std::size_t view_size{};
	void* current_process_handle{reinterpret_cast<void*>(-1)};

	auto status{::fast_io::win32::nt::nt_map_view_of_section<zw>(h_section, current_process_handle, __builtin_addressof(p_map_address), 0, 0, nullptr, __builtin_addressof(view_size), ::fast_io::win32::nt::section_inherit::ViewShare, 0, 0x08)};
	if (status)
		throw_nt_error(status);

	status = ::fast_io::win32::nt::nt_close<zw>(h_section);
	if (status)
		throw_nt_error(status);

	return {reinterpret_cast<char*>(p_map_address), reinterpret_cast<char*>(p_map_address) + view_size};
}

template <bool zw>
inline auto nt_load_file_impl(nt_fs_dirent fsdirent, ::fast_io::open_mode om, ::fast_io::perms pm) {
	::fast_io::basic_nt_family_file<zw ? ::fast_io::nt_family::zw : ::fast_io::nt_family::nt, char> nf(fsdirent, om, pm);
	return nt_create_map_view_common_impl<zw>(nf.handle);
}

template <bool zw, ::fast_io::constructible_to_os_c_str T>
inline auto nt_load_file_impl(T const& str, ::fast_io::open_mode om, ::fast_io::perms pm) {
	::fast_io::basic_nt_family_file<zw ? ::fast_io::nt_family::zw : ::fast_io::nt_family::nt, char> nf(str, om, pm);
	return nt_create_map_view_common_impl<zw>(nf.handle);
}

template <bool zw, ::fast_io::constructible_to_os_c_str T>
inline auto nt_load_file_impl(::fast_io::nt_at_entry ent, T const& str, ::fast_io::open_mode om, ::fast_io::perms pm) {
	::fast_io::basic_nt_family_file<zw ? ::fast_io::nt_family::zw : ::fast_io::nt_family::nt, char> nf(ent, str, om, pm);
	return nt_create_map_view_common_impl<zw>(nf.handle);
}

template <bool zw, ::fast_io::constructible_to_os_c_str T>
inline auto nt_load_file_impl(::fast_io::io_kernel_t, T const& t, ::fast_io::open_mode om, ::fast_io::perms pm = static_cast<::fast_io::perms>(436)) {
	::fast_io::basic_nt_family_file<zw ? ::fast_io::nt_family::zw : ::fast_io::nt_family::nt, char> nf(::fast_io::io_kernel, t, om, pm);
	return nt_create_map_view_common_impl<zw>(nf.handle);
}

template <bool zw, ::fast_io::constructible_to_os_c_str T>
inline auto nt_load_file_impl(::fast_io::io_kernel_t, ::fast_io::nt_at_entry ent, T const& t, ::fast_io::open_mode om, ::fast_io::perms pm = static_cast<::fast_io::perms>(436)) {
	::fast_io::basic_nt_family_file<zw ? ::fast_io::nt_family::zw : ::fast_io::nt_family::nt, char> nf(::fast_io::io_kernel, ent, t, om, pm);
	return nt_create_map_view_common_impl<zw>(nf.handle);
}

template <bool zw>
inline void nt_unload_address(void* address) noexcept {
	void* current_process_handle{reinterpret_cast<void*>(-1)};
	auto status{::fast_io::win32::nt::nt_unmap_view_of_section<zw>(current_process_handle, address)};
	if (status)
		throw_nt_error(status);
}

}  // namespace win32::nt::details
template <bool zw>
class basic_nt_file_loader {
public:
	using value_type = char;
	using pointer = char*;
	using const_pointer = char const*;
	using const_iterator = const_pointer;
	using iterator = pointer;
	using reference = char&;
	using const_reference = char const&;
	using size_type = ::std::size_t;
	using difference_type = ::std::ptrdiff_t;
	using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;
	using reverse_iterator = ::std::reverse_iterator<iterator>;

	pointer address_begin{};
	pointer address_end{};

	inline constexpr basic_nt_file_loader() noexcept = default;
	inline explicit basic_nt_file_loader(::fast_io::nt_at_entry ent) {
		auto ret{::fast_io::win32::nt::details::nt_create_map_view_common_impl<zw>(ent.handle)};
		address_begin = ret.address_begin;
		address_end = ret.address_end;
	}
	inline explicit basic_nt_file_loader(::fast_io::nt_fs_dirent fsdirent, ::fast_io::open_mode om = ::fast_io::open_mode::in, ::fast_io::perms pm = static_cast<::fast_io::perms>(436)) {
		auto ret{::fast_io::win32::nt::details::nt_load_file_impl<zw>(fsdirent, om, pm)};
		address_begin = ret.address_begin;
		address_end = ret.address_end;
	}
	template <::fast_io::constructible_to_os_c_str T>
	inline explicit basic_nt_file_loader(T const& filename, ::fast_io::open_mode om = ::fast_io::open_mode::in, ::fast_io::perms pm = static_cast<::fast_io::perms>(436)) {
		auto ret{::fast_io::win32::nt::details::nt_load_file_impl<zw>(filename, om, pm)};
		address_begin = ret.address_begin;
		address_end = ret.address_end;
	}
	template <::fast_io::constructible_to_os_c_str T>
	inline explicit basic_nt_file_loader(::fast_io::nt_at_entry ent, T const& filename, ::fast_io::open_mode om = ::fast_io::open_mode::in, ::fast_io::perms pm = static_cast<::fast_io::perms>(436)) {
		auto ret{::fast_io::win32::nt::details::nt_load_file_impl<zw>(ent, filename, om, pm)};
		address_begin = ret.address_begin;
		address_end = ret.address_end;
	}
	basic_nt_file_loader(basic_nt_file_loader const&) = delete;
	basic_nt_file_loader& operator=(basic_nt_file_loader const&) = delete;
	constexpr basic_nt_file_loader(basic_nt_file_loader&& __restrict other) noexcept : address_begin(other.address_begin), address_end(other.address_end) {
		other.address_end = other.address_begin = nullptr;
	}
	basic_nt_file_loader& operator=(basic_nt_file_loader&& __restrict other) noexcept {
		::fast_io::win32::nt::details::nt_unload_address<zw>(address_begin);
		address_begin = other.address_begin;
		address_end = other.address_end;
		other.address_end = other.address_begin = nullptr;
		return *this;
	}
	constexpr pointer data() const noexcept {
		return address_begin;
	}
	constexpr bool empty() const noexcept {
		return address_begin == address_end;
	}
	constexpr ::std::size_t size() const noexcept {
		return static_cast<::std::size_t>(address_end - address_begin);
	}
	constexpr ::std::size_t max_size() const noexcept {
		return SIZE_MAX;
	}
	constexpr const_iterator cbegin() const noexcept {
		return address_begin;
	}
	constexpr const_iterator begin() const noexcept {
		return address_begin;
	}
	constexpr iterator begin() noexcept {
		return address_begin;
	}
	constexpr const_iterator cend() const noexcept {
		return address_end;
	}
	constexpr const_iterator end() const noexcept {
		return address_end;
	}
	constexpr iterator end() noexcept {
		return address_end;
	}
	constexpr const_reverse_iterator crbegin() const noexcept {
		return const_reverse_iterator{address_end};
	}
	constexpr reverse_iterator rbegin() noexcept {
		return reverse_iterator{address_end};
	}
	constexpr const_reverse_iterator rbegin() const noexcept {
		return const_reverse_iterator{address_end};
	}
	constexpr const_reverse_iterator crend() const noexcept {
		return const_reverse_iterator{address_begin};
	}
	constexpr reverse_iterator rend() noexcept {
		return reverse_iterator{address_begin};
	}
	constexpr const_reverse_iterator rend() const noexcept {
		return const_reverse_iterator{address_begin};
	}
	constexpr const_reference front() const noexcept {
		return *address_begin;
	}
	constexpr reference front() noexcept {
		return *address_begin;
	}
	constexpr const_reference back() const noexcept {
		return address_end[-1];
	}
	constexpr reference back() noexcept {
		return address_end[-1];
	}

#if __has_cpp_attribute(nodiscard)
	[[nodiscard]]
#endif
	constexpr pointer
	release() noexcept {
		pointer temp{this->address_begin};
		this->address_end = this->address_begin = nullptr;
		return temp;
	}
	inline constexpr reference operator[](size_type size) noexcept {
		return address_begin[size];
	}
	inline constexpr const_reference operator[](size_type size) const noexcept {
		return address_begin[size];
	}
	inline void close() {
		::fast_io::win32::nt::details::nt_unload_address<zw>(address_begin);
		address_end = address_begin = nullptr;
	}
	~basic_nt_file_loader() {
		::fast_io::win32::nt::details::nt_unload_address<zw>(address_begin);
	}
};

template <bool zw>
inline constexpr basic_io_scatter_t<char> print_alias_define(io_alias_t, basic_nt_file_loader<zw> const& load) noexcept {
	return {load.data(), load.size()};
}

using nt_file_loader = basic_nt_file_loader<false>;
using zw_file_loader = basic_nt_file_loader<true>;

}
