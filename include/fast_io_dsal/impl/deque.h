#pragma once

namespace fast_io
{
namespace containers
{
namespace details
{

struct
#if __has_cpp_attribute(__gnu__::__may_alias__)
	[[__gnu__::__may_alias__]]
#endif
	deque_control_block_common
{
	void **controller_ptr;
	void *begin_ptr, *curr_ptr, *end_ptr;
};

template <typename T>
struct deque_control_block
{
	T **controller_ptr;
	T *begin_ptr, *curr_ptr, *end_ptr;
};

inline constexpr ::std::size_t deque_block_size_shift{12};

inline constexpr ::std::size_t deque_block_size_common{static_cast<::std::size_t>(1) << deque_block_size_shift};

template <::std::size_t sz>
inline constexpr ::std::size_t deque_block_size{sz <= (deque_block_size_common / 16u) ? (deque_block_size_common / sz) : 16u};

struct
#if __has_cpp_attribute(__gnu__::__may_alias__)
	[[__gnu__::__may_alias__]]
#endif
	deque_controller_block_common
{
	using replacetype = char unsigned;
	void **controller_start_ptr;
	void **controller_start_reserved_ptr;
	void **controller_after_reserved_ptr;
	void **controller_after_ptr;
};

template <typename T>
struct deque_controller_block
{
	using replacetype = T;
	T **controller_start_ptr;
	T **controller_start_reserved_ptr;
	T **controller_after_reserved_ptr;
	T **controller_after_ptr;
};

template <typename T>
struct deque_controller
{
	using replacetype = T;
	using controlreplacetype = T *;
	::fast_io::containers::details::deque_control_block<T> front_block;
	::fast_io::containers::details::deque_control_block<T> back_block;
	::fast_io::containers::details::deque_controller_block<T> controller_block;
};

struct
#if __has_cpp_attribute(__gnu__::__may_alias__)
	[[__gnu__::__may_alias__]]
#endif
	deque_controller_common
{
	using replacetype = char unsigned;
	using controlreplacetype = void *;
	::fast_io::containers::details::deque_control_block_common front_block;
	::fast_io::containers::details::deque_control_block_common back_block;
	::fast_io::containers::details::deque_controller_block_common controller_block;
};

template <typename T, bool isconst>
struct deque_iterator
{
	using value_type = T;
	using pointer = ::std::conditional_t<isconst, value_type const *, value_type *>;
	using const_pointer = value_type const *;

	using reference = ::std::conditional_t<isconst, value_type const &, value_type &>;
	using const_reference = value_type const &;

	using size_type = ::std::size_t;
	using difference_type = ::std::ptrdiff_t;

	deque_control_block<T> itercontent;

	inline constexpr deque_iterator &operator++() noexcept
	{
		if (++itercontent.curr_ptr == itercontent.end_ptr) [[unlikely]]
		{
			constexpr size_type blocksize{::fast_io::containers::details::deque_block_size<sizeof(value_type)>};
			itercontent.end_ptr = ((itercontent.curr_ptr = itercontent.begin_ptr = (*++itercontent.controller_ptr)) + blocksize);
		}
		return *this;
	}

	inline constexpr deque_iterator &operator--() noexcept
	{
		if (itercontent.curr_ptr == itercontent.begin_ptr) [[unlikely]]
		{
			constexpr size_type blocksize{::fast_io::containers::details::deque_block_size<sizeof(value_type)>};
			itercontent.end_ptr = itercontent.curr_ptr = ((itercontent.begin_ptr = (*--itercontent.controller_ptr)) + blocksize);
		}
		--itercontent.curr_ptr;
		return *this;
	}

	inline constexpr deque_iterator operator++(int) noexcept
	{
		auto temp(*this);
		++*this;
		return temp;
	}

	inline constexpr deque_iterator operator--(int) noexcept
	{
		auto temp(*this);
		--*this;
		return temp;
	}

	inline constexpr reference operator*() const noexcept
	{
		return *this->itercontent.curr_ptr;
	}

	inline constexpr pointer operator->() const noexcept
	{
		return this->itercontent.curr_ptr;
	}

	inline constexpr deque_iterator &operator+=(difference_type pos) noexcept
	{
		constexpr size_type blocksize{::fast_io::containers::details::deque_block_size<sizeof(value_type)>};
		constexpr size_type blocksizem1{blocksize - 1u};
		size_type unsignedpos{static_cast<size_type>(pos)};
		auto curr_ptr{this->itercontent.curr_ptr};
		auto controllerptr{this->itercontent.controller_ptr};
		decltype(curr_ptr) beginptr;
		if (pos < 0)
		{
			size_type diff{static_cast<size_type>(this->itercontent.end_ptr - curr_ptr)};
			constexpr size_type zero{};
			size_type abspos{static_cast<size_type>(zero - unsignedpos)};
			diff += abspos;
			this->itercontent.curr_ptr = (beginptr = *(controllerptr -= diff / blocksize)) + (blocksizem1 - diff % blocksize);
		}
		else
		{
			size_type diff{static_cast<size_type>(curr_ptr - this->itercontent.begin_ptr)};
			diff += unsignedpos;
			this->itercontent.curr_ptr = (beginptr = *(controllerptr += diff / blocksize)) + diff % blocksize;
		}
		this->itercontent.controller_ptr = controllerptr;
		this->itercontent.begin_ptr = beginptr;
		this->itercontent.end_ptr = beginptr + blocksize;
		return *this;
	}

	inline constexpr deque_iterator &operator-=(difference_type pos) noexcept
	{
		constexpr size_type blocksize{::fast_io::containers::details::deque_block_size<sizeof(value_type)>};
		constexpr size_type blocksizem1{blocksize - 1u};
		size_type unsignedpos{static_cast<size_type>(pos)};
		auto curr_ptr{this->itercontent.curr_ptr};
		auto controllerptr{this->itercontent.controller_ptr};
		decltype(curr_ptr) beginptr;
		if (pos < 0)
		{
			size_type diff{static_cast<size_type>(curr_ptr - this->itercontent.begin_ptr)};
			constexpr size_type zero{};
			size_type abspos{static_cast<size_type>(zero - unsignedpos)};
			diff += abspos;
			this->itercontent.curr_ptr = (beginptr = *(controllerptr += diff / blocksize)) + diff % blocksize;
		}
		else
		{
			size_type diff{static_cast<size_type>(this->itercontent.end_ptr - curr_ptr)};
			diff += unsignedpos;
			this->itercontent.curr_ptr = (beginptr = *(controllerptr -= diff / blocksize)) + (blocksizem1 - diff % blocksize);
		}
		this->itercontent.controller_ptr = controllerptr;
		this->itercontent.begin_ptr = beginptr;
		this->itercontent.end_ptr = beginptr + blocksize;
		return *this;
	}

	inline constexpr reference operator[](difference_type pos) const noexcept
	{
		constexpr size_type blocksize{::fast_io::containers::details::deque_block_size<sizeof(value_type)>};
		constexpr size_type blocksizem1{blocksize - 1u};
		size_type unsignedpos{static_cast<size_type>(pos)};
		auto curr_ptr{this->itercontent.curr_ptr};
		auto controllerptr{this->itercontent.controller_ptr};
		if (pos < 0)
		{
			size_type diff{static_cast<size_type>(this->itercontent.end_ptr - curr_ptr) - 1u};
			constexpr size_type zero{};
			size_type abspos{static_cast<size_type>(zero - unsignedpos)};
			diff += abspos;
			return (*(controllerptr - diff / blocksize))[blocksizem1 - diff % blocksize];
		}
		else
		{
			size_type diff{static_cast<size_type>(curr_ptr - this->itercontent.begin_ptr)};
			diff += unsignedpos;
			return controllerptr[diff / blocksize][diff % blocksize];
		}
	}

	inline constexpr operator deque_iterator<T, true>() const noexcept
		requires(!isconst)
	{
		return {this->itercontent};
	}
};

template <typename T, bool isconst>
inline constexpr ::fast_io::containers::details::deque_iterator<T, isconst> operator+(::fast_io::containers::details::deque_iterator<T, isconst> a, ::std::ptrdiff_t pos) noexcept
{
	return (a += pos);
}

template <typename T, bool isconst>
inline constexpr ::fast_io::containers::details::deque_iterator<T, isconst> operator+(::std::ptrdiff_t pos, ::fast_io::containers::details::deque_iterator<T, isconst> a) noexcept
{
	return (a += pos);
}

template <typename T, bool isconst>
inline constexpr ::fast_io::containers::details::deque_iterator<T, isconst> operator-(::fast_io::containers::details::deque_iterator<T, isconst> a, ::std::ptrdiff_t pos) noexcept
{
	return (a -= pos);
}

template <typename T>
inline constexpr ::std::ptrdiff_t deque_iter_difference_common(::fast_io::containers::details::deque_control_block<T> const &a, ::fast_io::containers::details::deque_control_block<T> const &b) noexcept
{
	::std::ptrdiff_t controllerdiff{a.controller_ptr - b.controller_ptr};
	constexpr ::std::ptrdiff_t blocksizedf{static_cast<::std::ptrdiff_t>(::fast_io::containers::details::deque_block_size<sizeof(T)>)};
	return controllerdiff * blocksizedf + (a.curr_ptr - b.begin_ptr) + (b.begin_ptr - b.curr_ptr);
}

template <typename T, bool isconst1, bool isconst2>
inline constexpr ::std::ptrdiff_t operator-(::fast_io::containers::details::deque_iterator<T, isconst1> const &a, ::fast_io::containers::details::deque_iterator<T, isconst2> const &b) noexcept
{
	return ::fast_io::containers::details::deque_iter_difference_common(a.itercontent, b.itercontent);
}

template <typename T, bool isconst1, bool isconst2>
inline constexpr bool operator==(::fast_io::containers::details::deque_iterator<T, isconst1> const &a, ::fast_io::containers::details::deque_iterator<T, isconst2> const &b) noexcept
{
	return a.itercontent.curr_ptr == b.itercontent.curr_ptr;
}

template <typename T, bool isconst1, bool isconst2>
inline constexpr auto operator<=>(::fast_io::containers::details::deque_iterator<T, isconst1> const &a, ::fast_io::containers::details::deque_iterator<T, isconst2> const &b) noexcept
{
	auto block3way{a.itercontent.controller_ptr <=> b.itercontent.controller_ptr};
	if (block3way == 0)
	{
		return a.itercontent.curr_ptr <=> b.itercontent.curr_ptr;
	}
	return block3way;
}


template <typename allocator, typename controllerblocktype>
inline constexpr void deque_destroy_trivial_common_align(controllerblocktype &controller, ::std::size_t aligns, ::std::size_t totalsz) noexcept
{
	for (auto i{controller.controller_start_reserved_ptr}, e{controller.controller_after_reserved_ptr}; i != e; ++i)
	{
		allocator::deallocate_aligned_n(*i, aligns, totalsz);
	}
	::std::size_t const n{static_cast<::std::size_t>(controller.controller_after_ptr - controller.controller_start_ptr + 1) * sizeof(void *)};
	allocator::deallocate_n(controller.controller_start_ptr, n);
}

template <typename allocator, ::std::size_t align, ::std::size_t sz, typename controllerblocktype>
inline constexpr void deque_destroy_trivial_common(controllerblocktype &controller) noexcept
{
	constexpr ::std::size_t totalsz{sz * ::fast_io::containers::details::deque_block_size<sz>};
	if consteval
	{
		::fast_io::containers::details::deque_destroy_trivial_common_align<allocator>(controller, align, totalsz);
	}
	else
	{
		::fast_io::containers::details::deque_destroy_trivial_common_align<allocator>(
			*reinterpret_cast<::fast_io::containers::details::deque_controller_block_common *>(__builtin_addressof(controller)), align, totalsz);
	}
}

template <typename allocator, typename dequecontroltype, typename replacetype>
inline constexpr void deque_init_grow_common_controllerallocate_impl(dequecontroltype &controller, ::std::size_t total_block_size, ::std::size_t mid, replacetype *blockptr) noexcept
{
	using controlreplacetype = typename dequecontroltype::controlreplacetype;
	constexpr ::std::size_t allocatesize{sizeof(controlreplacetype) * 4};
	auto controllerstartptr{static_cast<controlreplacetype *>(allocator::allocate(allocatesize))};
	controller.controller_block.controller_start_ptr = controllerstartptr;
	controller.controller_block.controller_after_reserved_ptr = (controller.controller_block.controller_start_reserved_ptr = controller.back_block.controller_ptr = controller.front_block.controller_ptr = controllerstartptr + 1) + 1;
	controller.controller_block.controller_after_ptr = controllerstartptr + 3u;
	*controller.back_block.controller_ptr = blockptr;
	controller.front_block.begin_ptr = controller.back_block.begin_ptr = blockptr;
	controller.back_block.curr_ptr = controller.front_block.curr_ptr = blockptr + mid;
	controller.front_block.end_ptr = controller.back_block.end_ptr = blockptr + total_block_size;
}

template <typename allocator, typename dequecontroltype>
inline constexpr void deque_init_grow_common_noalign_impl(dequecontroltype &controller, ::std::size_t total_block_size, ::std::size_t mid) noexcept
{
	::fast_io::containers::details::deque_init_grow_common_controllerallocate_impl<allocator>(controller, total_block_size, mid, static_cast<typename dequecontroltype::replacetype *>(allocator::allocate_zero(total_block_size)));
}

template <typename allocator, typename dequecontroltype>
inline constexpr void deque_init_grow_common_align_impl(dequecontroltype &controller, ::std::size_t align, ::std::size_t total_block_size, ::std::size_t mid) noexcept
{
	::fast_io::containers::details::deque_init_grow_common_controllerallocate_impl<allocator>(controller, total_block_size, mid, static_cast<typename dequecontroltype::replacetype *>(allocator::allocate_zero_aligned(align, total_block_size)));
}

template <typename allocator, ::std::size_t align, ::std::size_t block_size, ::std::size_t mid, typename dequecontroltype>
inline constexpr void deque_init_grow_common(dequecontroltype &controller) noexcept
{
	if constexpr (align <= allocator::default_alignment)
	{
		::fast_io::containers::details::deque_init_grow_common_noalign_impl<allocator>(controller, block_size, mid);
	}
	else
	{
		::fast_io::containers::details::deque_init_grow_common_align_impl<allocator>(controller, align, block_size, mid);
	}
}

template <typename allocator, ::std::size_t align, ::std::size_t sz, ::std::size_t block_size, typename dequecontroltype>
inline constexpr void deque_grow_front_common_impl(dequecontroltype &controller) noexcept
{
}
/*
struct
#if __has_cpp_attribute(__gnu__::__may_alias__)
	[[__gnu__::__may_alias__]]
#endif
	deque_controller_block_common
{
	using replacetype = char unsigned;
	void **controller_start_ptr;
	void **controller_start_reserved_ptr;
	void **controller_after_reserved_ptr;
	void **controller_after_ptr;
};
*/

template <typename allocator, typename dequecontroltype>
inline constexpr void deque_grow_to_new_blocks_count_impl(dequecontroltype &controller, ::std::size_t new_blocks_count_least) noexcept
{
	auto old_start_ptr{controller.controller_block.controller_start_ptr};

	auto old_start_reserved_ptr{controller.controller_block.controller_start_reserved_ptr};
	auto old_after_reserved_ptr{controller.controller_block.controller_after_reserved_ptr};

	::std::size_t const old_start_reserved_ptr_pos{static_cast<::std::size_t>(old_start_reserved_ptr - old_start_ptr)};
	::std::size_t const old_after_reserved_ptr_pos{static_cast<::std::size_t>(old_after_reserved_ptr - old_start_ptr)};
	::std::size_t const old_after_ptr_pos{static_cast<::std::size_t>(controller.controller_block.controller_after_ptr - old_start_ptr)};
	::std::size_t const old_front_block_ptr_pos{static_cast<::std::size_t>(controller.front_block.controller_ptr - old_start_ptr)};
	::std::size_t const old_back_block_ptr_pos{static_cast<::std::size_t>(controller.back_block.controller_ptr - old_start_ptr)};

	using block_typed_allocator = ::fast_io::typed_generic_allocator_adapter<allocator, typename dequecontroltype::controlreplacetype>;
	auto [new_start_ptr, new_blocks_count] = block_typed_allocator::allocate_at_least(new_blocks_count_least + 1zu);

	// number of used slots (excluding sentinel)
	::std::size_t const used_blocks_count{old_after_reserved_ptr_pos - old_start_reserved_ptr_pos};

	// put used blocks roughly in the middle, with some headroom on both sides
	::std::size_t const new_blocks_offset{(new_blocks_count - used_blocks_count) >> 1u};

	auto new_start_reserved_ptr{new_start_ptr + new_blocks_offset};
	auto new_after_reserved_ptr{::std::uninitialized_copy(old_start_reserved_ptr, old_after_reserved_ptr, new_start_reserved_ptr)};

	// sentinel
	*new_after_reserved_ptr = nullptr;
	++new_after_reserved_ptr;

	// free old controller array
	block_typed_allocator::deallocate_n(old_start_ptr, old_after_ptr_pos + 1zu);

	// rebuild controller bookkeeping
	controller.controller_block.controller_start_ptr = new_start_ptr;
	controller.controller_block.controller_start_reserved_ptr = new_start_reserved_ptr;
	controller.controller_block.controller_after_reserved_ptr = new_after_reserved_ptr - 1;
	controller.controller_block.controller_after_ptr = new_start_ptr + (new_blocks_count - 1zu);

	// adjust front/back controller_ptr
	controller.front_block.controller_ptr = new_start_ptr + (new_blocks_offset + (old_front_block_ptr_pos - old_start_reserved_ptr_pos));
	controller.back_block.controller_ptr = new_start_ptr + (new_blocks_offset + (old_back_block_ptr_pos - old_start_reserved_ptr_pos));
}

template <typename allocator, typename dequecontroltype>
inline constexpr void deque_rebalance_or_grow_2x_after_blocks_impl(dequecontroltype &controller) noexcept
{
	::std::size_t const used_blocks_count{
		static_cast<::std::size_t>(controller.back_block.controller_ptr - controller.front_block.controller_ptr) + 1zu};

	::std::size_t const total_blocks{
		static_cast<::std::size_t>(controller.controller_block.controller_after_ptr - controller.controller_block.controller_start_ptr)};

	::std::size_t const total_blocks_half{total_blocks >> 1u};

	if (total_blocks_half < used_blocks_count)
	{
		constexpr ::std::size_t maxcount{
			static_cast<::std::size_t>(::std::numeric_limits<::std::size_t>::max() / sizeof(void *))};
		constexpr ::std::size_t mxtoalign{static_cast<::std::size_t>(maxcount - 1u)};
		constexpr ::std::size_t mxtoaligndiv2{mxtoalign >> 1u};

		if (mxtoaligndiv2 < total_blocks)
		{
			::fast_io::fast_terminate();
		}

		::std::size_t const toallocate{total_blocks << 1u};
		deque_grow_to_new_blocks_count_impl<allocator>(controller, toallocate);
	}
	else
	{
		// Rebalance in-place: move reserved range toward the middle
		auto start_ptr{controller.controller_block.controller_start_ptr};
		auto start_reserved_ptr{controller.controller_block.controller_start_reserved_ptr};
		auto after_reserved_ptr{controller.controller_block.controller_after_reserved_ptr};

		::std::size_t const old_start_reserved_pos{static_cast<::std::size_t>(start_reserved_ptr - start_ptr)};
		::std::size_t const old_after_reserved_pos{static_cast<::std::size_t>(after_reserved_ptr - start_ptr)};
		::std::size_t const used{old_after_reserved_pos - old_start_reserved_pos};

		::std::size_t const new_start_reserved_pos{(total_blocks - used) >> 1u};
		auto new_start_reserved_ptr{start_ptr + new_start_reserved_pos};

		if (new_start_reserved_ptr != start_reserved_ptr)
		{
			if (start_reserved_ptr < new_start_reserved_ptr)
			{
				::std::copy_backward(start_reserved_ptr, after_reserved_ptr, new_start_reserved_ptr + used);
			}
			else
			{
				::std::copy(start_reserved_ptr, after_reserved_ptr, new_start_reserved_ptr);
			}
		}

		controller.controller_block.controller_start_reserved_ptr = new_start_reserved_ptr;
		controller.controller_block.controller_after_reserved_ptr = new_start_reserved_ptr + used;
		*(controller.controller_block.controller_after_reserved_ptr) = nullptr;

		// adjust front/back controller_ptr according to the shift
		::std::size_t const delta{new_start_reserved_pos - old_start_reserved_pos};

		controller.front_block.controller_ptr += delta;
		controller.back_block.controller_ptr += delta;
	}
}


template <typename allocator, typename dequecontroltype>
inline constexpr void deque_allocate_on_empty_common_impl(dequecontroltype &controller, ::std::size_t align, ::std::size_t bytes) noexcept
{
	using block_typed_allocator = ::fast_io::typed_generic_allocator_adapter<allocator, typename dequecontroltype::controlreplacetype>;
	auto [allocated_blocks_ptr, allocated_blocks_count] = block_typed_allocator::allocate_at_least(2);
	// we need a null terminator as sentinel like c style string does
	--allocated_blocks_count;
	auto &controller_block{controller.controller_block};
	auto &front_block{controller.front_block};
	auto &back_block{controller.back_block};

	constexpr bool isvoidplaceholder{::std::same_as<typename dequecontroltype::replacetype, void>};
	using begin_ptrtype = ::std::conditional_t<isvoidplaceholder, ::std::byte *, typename dequecontroltype::replacetype *>;

	auto begin_ptr{static_cast<begin_ptrtype>(allocator::allocate_aligned(align, bytes))};

	back_block.controller_ptr = front_block.controller_ptr = controller_block.controller_start_reserved_ptr = controller_block.controller_start_ptr = ::std::construct_at(allocated_blocks_ptr, begin_ptr);

	*(controller_block.controller_after_reserved_ptr = allocated_blocks_ptr + 1) = nullptr; // set nullptr as a sentinel

	controller_block.controller_after_ptr = allocated_blocks_ptr + allocated_blocks_count;
	::std::size_t halfsize{bytes >> 1u};

	back_block.begin_ptr = front_block.begin_ptr = begin_ptr;
	back_block.end_ptr = front_block.end_ptr = (begin_ptr + bytes);
	auto halfposptr{begin_ptr + halfsize};
	front_block.curr_ptr = halfposptr;
	back_block.curr_ptr = halfposptr;
}

template <typename allocator, typename dequecontroltype>
inline constexpr void deque_grow_back_common_impl(
	dequecontroltype &controller,
	::std::size_t align,
	::std::size_t bytes) noexcept
{
	// Case 1: empty deque → allocate initial controller + one block
	if (controller.controller_block.controller_start_ptr == nullptr)
	{
		::fast_io::containers::details::
			deque_allocate_on_empty_common_impl<allocator>(controller, align, bytes);
		return;
	}

	using replacetype = typename dequecontroltype::replacetype;
	constexpr bool isvoidplaceholder = ::std::same_as<replacetype, void>;
	using begin_ptrtype =
		::std::conditional_t<isvoidplaceholder, ::std::byte *, replacetype *>;

	// How many controller slots remain before hitting controller_after_reserved_ptr?
	::std::size_t const diff_to_after_ptr =
		static_cast<::std::size_t>(
			controller.controller_block.controller_after_reserved_ptr -
			controller.back_block.controller_ptr);

	// Need at least 2 slots: one for new block, one for sentinel
	if (diff_to_after_ptr < 2zu)
	{
		// No space at all → must rebalance or grow controller array
		if (!diff_to_after_ptr)
		{
			::fast_io::containers::details::
				deque_rebalance_or_grow_2x_after_blocks_impl<allocator>(controller);
		}

		// Now we have at least 1 slot; allocate a new block and append it
		auto new_block =
			static_cast<begin_ptrtype>(allocator::allocate_aligned(align, bytes));

		// Write block pointer at controller_after_reserved_ptr
		auto pos = controller.controller_block.controller_after_reserved_ptr;
		::std::construct_at(pos, new_block);

		// Advance after_reserved_ptr and write sentinel
		*(controller.controller_block.controller_after_reserved_ptr = pos + 1) = nullptr;
	}

	// Now we definitely have space for a new block pointer
	// Advance controller pointer to the next block slot
	++controller.back_block.controller_ptr;

	// Load the block pointer
	auto begin_ptr =
		static_cast<begin_ptrtype>(*controller.back_block.controller_ptr);

	// Update block range
	controller.back_block.begin_ptr = begin_ptr;
	controller.back_block.curr_ptr = begin_ptr;
	controller.back_block.end_ptr = begin_ptr + bytes;
}


template <typename allocator, ::std::size_t align, ::std::size_t sz, ::std::size_t block_size, typename dequecontroltype>
inline constexpr void deque_grow_front_common(dequecontroltype &controller) noexcept
{
	::fast_io::containers::details::deque_grow_front_common_impl<allocator, align, sz, block_size>(controller);
}

template <typename allocator, ::std::size_t align, ::std::size_t sz, ::std::size_t block_size, typename dequecontroltype>
inline constexpr void deque_grow_back_common(dequecontroltype &controller) noexcept
{
	constexpr ::std::size_t blockbytes{sz * block_size};
	::fast_io::containers::details::deque_grow_back_common_impl<allocator>(controller, align, blockbytes);
}

} // namespace details

template <typename T, typename allocator>
class deque FAST_IO_TRIVIALLY_RELOCATABLE_IF_ELIGIBLE
{
public:
	using value_type = T;
	using pointer = value_type *;
	using reference = value_type &;
	using const_reference = value_type const &;
	using size_type = ::std::size_t;
	using difference_type = ::std::ptrdiff_t;
	using iterator = ::fast_io::containers::details::deque_iterator<T, false>;
	using const_iterator = ::fast_io::containers::details::deque_iterator<T, true>;
	using reverse_iterator = ::std::reverse_iterator<iterator>;
	using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;

	::fast_io::containers::details::deque_controller<T> controller;
	static inline constexpr size_type block_size{::fast_io::containers::details::deque_block_size<sizeof(value_type)>};
	inline constexpr deque() noexcept
		: controller{{}, {}, {}}
	{}

	inline constexpr deque(deque const &) = delete;
	inline constexpr deque &operator=(deque const &) = delete;

	inline constexpr deque(deque &&) noexcept = default;
	inline constexpr deque &operator=(deque &&) noexcept = default;

private:
	inline constexpr void destroy_all_elements() noexcept
	{
		::std::ranges::destroy(controller.front_block.curr_ptr, controller.front_block.end_ptr);
		auto front_controller_ptr{controller.front_block.controller_ptr};
		auto back_controller_ptr{controller.back_block.controller_ptr};
		if (front_controller_ptr != back_controller_ptr)
		{
			for (T **it{front_controller_ptr + 1}, **ed{back_controller_ptr}; it != ed; ++it)
			{
				T *blockptr{*it};
				::std::ranges::destroy(blockptr, blockptr + block_size);
			}
		}
		::std::ranges::destroy(controller.back_block.begin_ptr, controller.back_block.curr_ptr);
	}

	inline constexpr void destroy() noexcept
	{
		if constexpr (!::std::is_trivially_destructible_v<value_type>)
		{
			this->destroy_all_elements();
		}
		::fast_io::containers::details::deque_destroy_trivial_common<allocator, alignof(value_type), sizeof(value_type)>(controller.controller_block);
	}

	[[deprecated]] inline constexpr void init_grow() noexcept
	{
		constexpr size_type mid{block_size >> 1u};
		if (__builtin_is_constant_evaluated())
		{
			::fast_io::containers::details::deque_init_grow_common<allocator, alignof(value_type), block_size, mid>(controller);
		}
		else
		{
			::fast_io::containers::details::deque_init_grow_common<allocator, alignof(value_type), sizeof(value_type) * block_size, sizeof(value_type) * mid>(*reinterpret_cast<::fast_io::containers::details::deque_controller_common *>(__builtin_addressof(controller)));
		}
	}

#if __has_cpp_attribute(__gnu__::__cold__)
	[[__gnu__::__cold__]]
#endif
	inline constexpr void grow_front() noexcept
	{
		if (__builtin_is_constant_evaluated())
		{
			::fast_io::containers::details::deque_grow_front_common<allocator, alignof(value_type), sizeof(value_type), block_size>(controller);
		}
		else
		{
			::fast_io::containers::details::deque_grow_front_common<allocator, alignof(value_type), sizeof(value_type), sizeof(value_type) * block_size>(*reinterpret_cast<::fast_io::containers::details::deque_controller_common *>(__builtin_addressof(controller)));
		}
	}

#if __has_cpp_attribute(__gnu__::__cold__)
	[[__gnu__::__cold__]]
#endif
	inline constexpr void grow_back() noexcept
	{
		if (__builtin_is_constant_evaluated())
		{
			::fast_io::containers::details::deque_grow_back_common<allocator, alignof(value_type), sizeof(value_type), block_size>(controller);
		}
		else
		{
			::fast_io::containers::details::deque_grow_back_common<allocator, alignof(value_type), sizeof(value_type), block_size>(*reinterpret_cast<::fast_io::containers::details::deque_controller_common *>(__builtin_addressof(controller)));
		}
	}

	inline constexpr void front_backspace() noexcept
	{
		controller.front_block.end_ptr = (controller.front_block.curr_ptr = controller.front_block.begin_ptr = *++controller.front_block.controller_ptr) + block_size;
	}

	inline constexpr void back_backspace() noexcept
	{
		controller.back_block.curr_ptr = controller.back_block.end_ptr = (controller.back_block.begin_ptr = *--controller.back_block.controller_ptr) + block_size;
	}

public:
#if 0
	inline constexpr void clear() noexcept
	{
		if (controller.controller_block.start_ptr == controller.controller_block.start_ptr)
		{
			return;
		}
		this->destroy();
		size_type n{(controller.back_block.controller_ptr - controller.front_block.controller_ptr)};
		n >>= 1u;
		auto mid{controller.front_block.controller_ptr + n};
		*mid;
	}
#endif
	template <typename... Args>
		requires ::std::constructible_from<value_type, Args...>
	inline constexpr reference emplace_back(Args &&...args)
	{
		if (controller.back_block.curr_ptr == controller.back_block.end_ptr) [[unlikely]]
		{
			grow_back();
		}
		auto currptr{controller.back_block.curr_ptr};
		::std::construct_at(currptr, ::std::forward<Args>(args)...);
		controller.back_block.curr_ptr = currptr + 1;
		return *currptr;
	}

	inline constexpr void push_back(value_type const &value)
	{
		this->emplace_back(value);
	}

	inline constexpr void push_back(value_type &&value)
	{
		this->emplace_back(::std::move(value));
	}

	inline constexpr void pop_back() noexcept
	{
		if (controller.front_block.curr_ptr == controller.back_block.curr_ptr) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		pop_back_unchecked();
	}

	inline constexpr void pop_back_unchecked() noexcept
	{
		if constexpr (!::std::is_trivially_destructible_v<value_type>)
		{
			::std::destroy_at(controller.back_block.curr_ptr - 1);
		}
		if (--controller.back_block.curr_ptr == controller.back_block.begin_ptr) [[unlikely]]
		{
			this->back_backspace();
		}
	}

	inline constexpr reference back_unchecked() noexcept
	{
		return controller.back_block.curr_ptr[-1];
	}

	inline constexpr const_reference back_unchecked() const noexcept
	{
		return controller.back_block.curr_ptr[-1];
	}

	inline constexpr reference back() noexcept
	{
		if (controller.front_block.curr_ptr == controller.back_block.curr_ptr) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		return controller.back_block.curr_ptr[-1];
	}

	inline constexpr const_reference back() const noexcept
	{
		if (controller.front_block.curr_ptr == controller.back_block.curr_ptr) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		return controller.back_block.curr_ptr[-1];
	}

	template <typename... Args>
		requires ::std::constructible_from<value_type, Args...>
	inline constexpr reference emplace_front(Args &&...args)
	{
		if (controller.front_block.curr_ptr == controller.front_block.begin_ptr) [[unlikely]]
		{
			grow_front();
		}
		::std::construct_at(--controller.front_block.curr_ptr, ::std::forward<Args>(args)...);
		return *controller.front_block.curr_ptr;
	}

	inline constexpr void push_front(value_type const &value)
	{
		this->emplace_front(value);
	}

	inline constexpr void push_front(value_type &&value)
	{
		this->emplace_front(::std::move(value));
	}

	inline constexpr void pop_front() noexcept
	{
		if (controller.front_block.curr_ptr == controller.back_block.curr_ptr) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		pop_front_unchecked();
	}

	inline constexpr void pop_front_unchecked() noexcept
	{
		if constexpr (!::std::is_trivially_destructible_v<value_type>)
		{
			::std::destroy_at(controller.front_block.curr_ptr);
		}

		if (++controller.front_block.curr_ptr == controller.front_block.end_ptr) [[unlikely]]
		{
			this->front_backspace();
		}
	}

	inline constexpr reference front_unchecked() noexcept
	{
		return *controller.front_block.curr_ptr;
	}

	inline constexpr const_reference front_unchecked() const noexcept
	{
		return *controller.front_block.curr_ptr;
	}

	inline constexpr reference front() noexcept
	{
		if (controller.front_block.curr_ptr == controller.back_block.curr_ptr) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		return *controller.front_block.curr_ptr;
	}

	inline constexpr const_reference front() const noexcept
	{
		if (controller.front_block.curr_ptr == controller.back_block.curr_ptr) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		return *controller.front_block.curr_ptr;
	}

	inline constexpr reference operator[](size_type index) noexcept
	{
		if (size() <= index) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		size_type real_index{static_cast<size_type>(controller.front_block.curr_ptr - controller.front_block.begin_ptr) + index};

		return controller.front_block.controller_ptr[real_index / block_size][real_index % block_size];
	}

	inline constexpr const_reference operator[](size_type index) const noexcept
	{
		if (size() <= index) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}

		size_type real_index{static_cast<size_type>(controller.front_block.curr_ptr - controller.front_block.begin_ptr) + index};

		return controller.front_block.controller_ptr[real_index / block_size][real_index % block_size];
	}

	inline constexpr reference index_unchecked(size_type index) noexcept
	{
		size_type real_index{static_cast<size_type>(controller.front_block.curr_ptr - controller.front_block.begin_ptr) + index};

		return controller.front_block.controller_ptr[real_index / block_size][real_index % block_size];
	}

	inline constexpr const_reference index_unchecked(size_type index) const noexcept
	{
		size_type real_index{static_cast<size_type>(controller.front_block.curr_ptr - controller.front_block.begin_ptr) + index};

		return controller.front_block.controller_ptr[real_index / block_size][real_index % block_size];
	}

	static inline constexpr size_type max_size() noexcept
	{
		constexpr size_type mxval{SIZE_MAX / sizeof(value_type)};
		return mxval;
	}

	static inline constexpr size_type max_size_bytes() noexcept
	{
		constexpr size_type mxval{SIZE_MAX / sizeof(value_type) * sizeof(value_type)};
		return mxval;
	}

	inline constexpr size_type size() const noexcept
	{
		return block_size * static_cast<size_type>(controller.back_block.controller_ptr - controller.front_block.controller_ptr) + static_cast<size_type>((controller.back_block.curr_ptr - controller.back_block.begin_ptr) + (controller.front_block.begin_ptr - controller.front_block.curr_ptr));
	}

	inline constexpr size_type size_bytes() const noexcept
	{
		return size() * sizeof(value_type);
	}

	inline constexpr iterator begin() noexcept
	{
		return {this->controller.front_block};
	}

	inline constexpr const_iterator begin() const noexcept
	{
		return {this->controller.front_block};
	}

	inline constexpr const_iterator cbegin() const noexcept
	{
		return {this->controller.front_block};
	}

	inline constexpr reverse_iterator rend() noexcept
	{
		return reverse_iterator({this->controller.front_block});
	}

	inline constexpr const_reverse_iterator rend() const noexcept
	{
		return const_reverse_iterator({this->controller.front_block});
	}

	inline constexpr const_reverse_iterator crend() const noexcept
	{
		return const_reverse_iterator({this->controller.front_block});
	}

private:
	inline constexpr ::fast_io::containers::details::deque_control_block<value_type> end_common() noexcept
	{
		::fast_io::containers::details::deque_control_block<value_type> backblock{this->controller.back_block};
		if (backblock.curr_ptr == backblock.end_ptr) [[unlikely]]
		{
			if (backblock.controller_ptr) [[likely]]
			{
				backblock.end_ptr = ((backblock.curr_ptr = backblock.begin_ptr = (*++backblock.controller_ptr)) + block_size);
			}
		}
		return {backblock};
	}

	inline constexpr ::fast_io::containers::details::deque_control_block<value_type> end_common() const noexcept
	{
		::fast_io::containers::details::deque_control_block<value_type> backblock{this->controller.back_block};
		if (backblock.curr_ptr == backblock.end_ptr) [[unlikely]]
		{
			if (backblock.controller_ptr) [[likely]]
			{
				backblock.end_ptr = ((backblock.curr_ptr = backblock.begin_ptr = (*++backblock.controller_ptr)) + block_size);
			}
		}
		return {backblock};
	}

public:
	inline constexpr iterator end() noexcept
	{
		return {this->end_common()};
	}

	inline constexpr const_iterator end() const noexcept
	{
		return {this->end_common()};
	}

	inline constexpr const_iterator cend() const noexcept
	{
		return {this->end_common()};
	}

	inline constexpr reverse_iterator rbegin() noexcept
	{
		return reverse_iterator({this->end_common()});
	}

	inline constexpr const_reverse_iterator rbegin() const noexcept
	{
		return const_reverse_iterator({this->end_common()});
	}

	inline constexpr const_reverse_iterator crbegin() const noexcept
	{
		return const_reverse_iterator({this->end_common()});
	}

	inline constexpr bool empty() const noexcept
	{
		return controller.front_block.curr_ptr == controller.back_block.curr_ptr;
	}

	inline constexpr bool is_empty() const noexcept
	{
		return controller.front_block.curr_ptr == controller.back_block.curr_ptr;
	}

	inline constexpr void clear_destroy() noexcept
	{
		this->destroy();
		this->controller = {{}, {}, {}};
	}

	inline constexpr ~deque()
	{
		this->destroy();
	}
};

template <typename T, typename allocator1, typename allocator2>
	requires ::std::equality_comparable<T>
inline constexpr bool operator==(deque<T, allocator1> const &lhs, deque<T, allocator2> const &rhs) noexcept
{
	return ::std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
}

#if defined(__cpp_lib_three_way_comparison)

template <typename T, typename allocator1, typename allocator2>
	requires ::std::three_way_comparable<T>
inline constexpr auto operator<=>(deque<T, allocator1> const &lhs, deque<T, allocator2> const &rhs) noexcept
{
	return ::fast_io::freestanding::lexicographical_compare_three_way(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend(), ::std::compare_three_way{});
}

#endif

} // namespace containers

namespace freestanding
{

template <typename T, typename allocator>
struct is_trivially_copyable_or_relocatable<::fast_io::containers::deque<T, allocator>>
{
	inline static constexpr bool value = true;
};

template <typename T, typename allocator>
struct is_zero_default_constructible<::fast_io::containers::deque<T, allocator>>
{
	inline static constexpr bool value = true;
};

} // namespace freestanding

} // namespace fast_io
