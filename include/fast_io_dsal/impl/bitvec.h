#pragma once

namespace fast_io
{

namespace details
{

struct bitvec_rep
{
	char unsigned *begin_ptr{};
	::std::size_t curr_pos{}, end_pos{};
};

} // namespace details

namespace containers
{

template <typename allocator>
class bitvec
{
public:
	using allocator_type = allocator;
	using underlying_type = char unsigned;
	using size_type = ::std::size_t;
	using difference_type = ::std::ptrdiff_t;
	using underlying_pointer = underlying_type *;
	using underlying_const_pointer = underlying_type const *;
	static inline constexpr size_type underlying_digits{
		::std::numeric_limits<underlying_type>::digits};
	::fast_io::details::bitvec_rep imp{};
	constexpr bitvec() noexcept = default;
	static inline constexpr ::std::size_t max_size() noexcept
	{
		constexpr ::std::size_t szmx{::std::numeric_limits<::std::size_t>::max()};
		return szmx;
	}
	static inline constexpr ::std::size_t max_size_bytes() noexcept
	{
		constexpr ::std::size_t szbytesmx{::std::numeric_limits<::std::size_t>::max() /
										  ::std::numeric_limits<underlying_type>::digits};
		return szbytesmx;
	}

private:
	using typed_allocator = ::fast_io::typed_generic_allocator_adapter<allocator, underlying_type>;
	inline constexpr void grow_to_new_capacity(size_type n) noexcept
	{
		::std::size_t current_capacity{this->imp.end_pos};
		if constexpr (underlying_digits == 8)
		{
			current_capacity >>= 3u;
		}
		else
		{
			current_capacity /= underlying_digits;
		}

		auto [new_begin_ptr, new_capacity] = typed_allocator::reallocate_n_at_least(this->imp.begin_ptr, current_capacity, n);
		constexpr ::std::size_t mxbytes{max_size_bytes()};
		if (mxbytes < new_capacity)
		{
			new_capacity = mxbytes;
		}
		this->imp.begin_ptr = new_begin_ptr;
		if constexpr (underlying_digits == 8)
		{
			new_capacity <<= 3u;
		}
		else
		{
			new_capacity *= underlying_digits;
		}
		this->imp.end_pos = new_capacity;
	}
	inline constexpr void grow_twice() noexcept
	{
		::std::size_t current_capacity{this->imp.end_pos};
		if constexpr (underlying_digits == 8)
		{
			current_capacity >>= 3u;
		}
		else
		{
			current_capacity /= underlying_digits;
		}
		constexpr ::std::size_t mxbyteshalf{max_size() >> 1};
		if (mxbyteshalf < current_capacity)
		{
			::fast_io::fast_terminate();
		}
		::std::size_t toallocate{current_capacity << 1u};
		if (current_capacity == 0)
		{
			toallocate = 1;
		}
		this->grow_to_new_capacity(toallocate);
	}
	inline static constexpr ::fast_io::details::bitvec_rep allocate_new(size_type n, bool zeroing) noexcept
	{
		size_type to_allocate_bytes{n};
		if constexpr (underlying_digits == 8)
		{
			to_allocate_bytes = (n >> 3u) + ((n & 3u) != 0);
		}
		else
		{
			size_type const ndivdigits{n / underlying_digits};
			size_type const nmoddigits{n % underlying_digits};
			to_allocate_bytes = ndivdigits + (nmoddigits != 0);
		}
		constexpr ::std::size_t mxbytes{max_size_bytes()};
		if (mxbytes < to_allocate_bytes)
		{
			::fast_io::fast_terminate();
		}
		auto [new_begin_ptr, new_capacity] = (zeroing ? typed_allocator::allocate_zero_at_least(n) : typed_allocator::allocate_at_least(n));
		if (mxbytes < new_capacity)
		{
			new_capacity = mxbytes;
		}
		if constexpr (underlying_digits == 8)
		{
			new_capacity <<= 3u;
		}
		else
		{
			new_capacity *= underlying_digits;
		}

		return {new_begin_ptr, n, new_capacity};
	}
	inline static constexpr ::fast_io::details::bitvec_rep clone_imp(::fast_io::details::bitvec_rep const &other) noexcept
	{
		auto newrep{allocate_new(other.curr_pos, false)};
		size_type n{other.curr_pos};
		size_type to_copy_bytes;
		if constexpr (underlying_digits == 8)
		{
			to_copy_bytes = (n >> 3u) + ((n & 3u) != 0);
		}
		else
		{
			size_type const ndivdigits{n / underlying_digits};
			size_type const nmoddigits{n % underlying_digits};
			to_copy_bytes = ndivdigits + (nmoddigits != 0);
		}
		::fast_io::freestanding::non_overlapped_copy_n(other.begin_ptr, to_copy_bytes, newrep.begin_ptr);
		return newrep;
	}
	inline constexpr void destroy_bitvec() noexcept
	{
		auto begin_ptr{imp.begin_ptr};
		if (begin_ptr == nullptr)
		{
			return;
		}
		typed_allocator::deallocate_n(imp.begin_ptr, imp.end_pos);
	}

public:
	inline constexpr bitvec(size_type n) noexcept : imp{allocate_new(n, true)}
	{
	}
	inline constexpr bitvec(size_type n, ::fast_io::for_overwrite_t) noexcept : imp{allocate_new(n, false)}
	{
	}

	inline constexpr void push_back(bool v) noexcept
	{
		if (this->imp.curr_pos == this->imp.end_pos) [[unlikely]]
		{
			this->grow_twice();
		}
		this->push_back_unchecked(v);
	}

	inline constexpr void push_back_unchecked(bool v) noexcept
	{
		if constexpr (underlying_digits == 8)
		{
			size_type bitpos{imp.curr_pos};
			size_type byte_index{bitpos >> 3}; // bitpos / 8
			size_type bit_index{bitpos & 7};   // bitpos % 8

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			// Branchless set/clear
			byteval = (byteval & static_cast<underlying_type>(~mask)) |
					  (static_cast<underlying_type>(v) * mask);

			++imp.curr_pos;
		}
		else
		{
			size_type bitpos{imp.curr_pos};
			size_type byte_index{bitpos / underlying_digits};
			size_type bit_index{bitpos % underlying_digits};

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask =
				static_cast<underlying_type>(1u << bit_index);

			byteval = (byteval & static_cast<underlying_type>(~mask)) |
					  (static_cast<underlying_type>(v) * mask);

			++imp.curr_pos;
		}
	}

	inline constexpr bool test_unchecked(size_type pos) const noexcept
	{
		if constexpr (underlying_digits == 8)
		{
			// Compute which byte contains the bit
			size_type byte_index{pos >> 3}; // pos / 8
			// Compute which bit inside that byte
			size_type bit_index{pos & 7}; // pos % 8

			underlying_type byteval{imp.begin_ptr[byte_index]};

			// Extract the bit
			return (byteval >> bit_index) & 1u;
		}
		else
		{
			// Compute which byte contains the bit
			size_type byte_index{pos / underlying_digits};
			// Compute which bit inside that byte
			size_type bit_index{pos % underlying_digits};

			underlying_type byteval{imp.begin_ptr[byte_index]};

			// Extract the bit
			return (byteval >> bit_index) & 1u;
		}
	}
	inline constexpr bool test(size_type pos) const noexcept
	{
		if (this->imp.curr_pos <= pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		return this->test_unchecked(pos);
	}
	inline constexpr void set_unchecked(size_type pos, bool value = true) noexcept
	{
		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{pos >> 3}; // pos / 8
			size_type bit_index{pos & 7};   // pos % 8

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			// Branchless set/clear
			byteval = (byteval & static_cast<underlying_type>(~mask)) |
					  (static_cast<underlying_type>(value) * mask);
		}
		else
		{
			size_type byte_index{pos / underlying_digits};
			size_type bit_index{pos % underlying_digits};

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask =
				static_cast<underlying_type>(1u << bit_index);

			byteval = (byteval & static_cast<underlying_type>(~mask)) |
					  (static_cast<underlying_type>(value) * mask);
		}
	}
	inline constexpr void set(size_type pos, bool value = true) noexcept
	{
		if (this->imp.curr_pos <= pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->set_unchecked(pos, value);
	}

	inline constexpr void reset_unchecked(size_type pos) noexcept
	{
		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{pos >> 3}; // pos / 8
			size_type bit_index{pos & 7};   // pos % 8

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			// Clear the bit (branchless)
			byteval &= static_cast<underlying_type>(~mask);
		}
		else
		{
			size_type byte_index{pos / underlying_digits};
			size_type bit_index{pos % underlying_digits};

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask =
				static_cast<underlying_type>(1u << bit_index);

			byteval &= static_cast<underlying_type>(~mask);
		}
	}
	inline constexpr void reset(size_type pos) noexcept
	{
		if (this->imp.curr_pos <= pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->reset_unchecked(pos);
	}

	inline constexpr bool pop_back_unchecked() noexcept
	{
		// Position of last bit (curr_pos > 0 assumed)
		size_type bitpos{imp.curr_pos - 1};

		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{bitpos >> 3}; // bitpos / 8
			size_type bit_index{bitpos & 7};   // bitpos % 8

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			// Read the bit before clearing it
			bool old = (byteval >> bit_index) & 1u;

			// Clear the bit
			byteval &= static_cast<underlying_type>(~mask);

			--imp.curr_pos;
			return old;
		}
		else
		{
			size_type byte_index{bitpos / underlying_digits};
			size_type bit_index{bitpos % underlying_digits};

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask =
				static_cast<underlying_type>(1u << bit_index);

			bool old = (byteval >> bit_index) & 1u;

			byteval &= static_cast<underlying_type>(~mask);

			--imp.curr_pos;
			return old;
		}
	}

	inline constexpr bool pop_back() noexcept
	{
		if (!(this->imp.curr_pos)) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		return this->pop_back_unchecked();
	}

	inline constexpr bool test_front_unchecked() const noexcept
	{
		// front bit is always at pos 0
		return (*this->imp.begin_ptr) & 1u;
	}

	inline constexpr bool test_front() const noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		return this->test_front_unchecked();
	}

	inline constexpr void set_front_unchecked(bool value = true) noexcept
	{
		underlying_type &byteval = *imp.begin_ptr;
		constexpr underlying_type mask = static_cast<underlying_type>(1u);
		constexpr underlying_type invmask = ~mask;

		byteval = (byteval & invmask) | (static_cast<underlying_type>(value));
	}
	inline constexpr void set_front(bool value = true) noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->set_front_unchecked(value);
	}

	inline constexpr void reset_front_unchecked() noexcept
	{
		constexpr underlying_type mask = static_cast<underlying_type>(1u);
		constexpr underlying_type invmask = ~mask;
		(*imp.begin_ptr) &= invmask;
	}

	inline constexpr void reset_front() noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->reset_front_unchecked();
	}

	inline constexpr bool test_back_unchecked() const noexcept
	{
		// last bit is at pos curr_pos - 1
		size_type bitpos{this->imp.curr_pos - 1};

		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{bitpos >> 3}; // bitpos / 8
			size_type bit_index{bitpos & 7};   // bitpos % 8

			underlying_type byteval{this->imp.begin_ptr[byte_index]};
			return (byteval >> bit_index) & 1u;
		}
		else
		{
			size_type byte_index{bitpos / underlying_digits};
			size_type bit_index{bitpos % underlying_digits};

			underlying_type byteval{this->imp.begin_ptr[byte_index]};
			return (byteval >> bit_index) & 1u;
		}
	}

	inline constexpr bool test_back() const noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		return this->test_back_unchecked();
	}

	inline constexpr void set_back_unchecked(bool value = true) noexcept
	{
		size_type bitpos{this->imp.curr_pos - 1};

		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{bitpos >> 3};
			size_type bit_index{bitpos & 7};

			underlying_type &byteval = this->imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			byteval = (byteval & static_cast<underlying_type>(~mask)) |
					  (static_cast<underlying_type>(value) * mask);
		}
		else
		{
			size_type byte_index{bitpos / underlying_digits};
			size_type bit_index{bitpos % underlying_digits};

			underlying_type &byteval = this->imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			byteval = (byteval & static_cast<underlying_type>(~mask)) |
					  (static_cast<underlying_type>(value) * mask);
		}
	}

	inline constexpr void set_back(bool value = true) noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->set_back_unchecked(value);
	}

	inline constexpr void reset_back_unchecked() noexcept
	{
		size_type bitpos{this->imp.curr_pos - 1};

		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{bitpos >> 3};
			size_type bit_index{bitpos & 7};

			underlying_type &byteval = this->imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			byteval &= static_cast<underlying_type>(~mask);
		}
		else
		{
			size_type byte_index{bitpos / underlying_digits};
			size_type bit_index{bitpos % underlying_digits};

			underlying_type &byteval = this->imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			byteval &= static_cast<underlying_type>(~mask);
		}
	}

	inline constexpr void reset_back() noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->reset_back_unchecked();
	}

	inline constexpr void flip_unchecked(size_type pos) noexcept
	{
		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{pos >> 3}; // pos / 8
			size_type bit_index{pos & 7};   // pos % 8

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			// Toggle the bit (branchless)
			byteval ^= mask;
		}
		else
		{
			size_type byte_index{pos / underlying_digits};
			size_type bit_index{pos % underlying_digits};

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask =
				static_cast<underlying_type>(1u << bit_index);

			byteval ^= mask;
		}
	}

	inline constexpr void flip(size_type pos) noexcept
	{
		if (this->imp.curr_pos <= pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->flip_unchecked(pos);
	}

	inline constexpr void flip_front_unchecked() noexcept
	{
		// front bit is always bit 0 of byte 0
		constexpr underlying_type mask = static_cast<underlying_type>(1u);
		(*imp.begin_ptr) ^= mask;
	}
	inline constexpr void flip_front() noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->flip_front_unchecked();
	}

	inline constexpr void flip_back_unchecked() noexcept
	{
		size_type bitpos{imp.curr_pos - 1};

		if constexpr (underlying_digits == 8)
		{
			size_type byte_index{bitpos >> 3}; // bitpos / 8
			size_type bit_index{bitpos & 7};   // bitpos % 8

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask = static_cast<underlying_type>(1u << bit_index);

			byteval ^= mask;
		}
		else
		{
			size_type byte_index{bitpos / underlying_digits};
			size_type bit_index{bitpos % underlying_digits};

			underlying_type &byteval = imp.begin_ptr[byte_index];
			underlying_type mask =
				static_cast<underlying_type>(1u << bit_index);

			byteval ^= mask;
		}
	}

	inline constexpr void flip_back() noexcept
	{
		if (!this->imp.curr_pos) [[unlikely]]
		{
			::fast_io::fast_terminate();
		}
		this->flip_back_unchecked();
	}

	constexpr bitvec(bitvec &&other) noexcept : imp{other.imp}
	{
		other.imp = {};
	}
	constexpr bitvec &operator=(bitvec &&other) noexcept
	{
		if (__builtin_addressof(other) == this) [[unlikely]]
		{
			return *this;
		}
		this->destroy_bitvec();
		this->imp = other.imp;
		other.imp = {};
		return *this;
	}
	constexpr bitvec(bitvec const &other) noexcept : imp{clone_imp(other.imp)}
	{}
	constexpr bitvec &operator=(bitvec const &other) noexcept
	{
		if (__builtin_addressof(other) == this) [[unlikely]]
		{
			return *this;
		}
		auto newimp{clone_imp(other.imp)};
		this->destroy_bitvec();
		this->imp = newimp;
		return *this;
	}
	constexpr ~bitvec()
	{
		this->destroy_bitvec();
	}

	constexpr underlying_pointer underlying_data() noexcept
	{
		return this->imp.begin_ptr;
	}
	constexpr underlying_const_pointer underlying_data() const noexcept
	{
		return this->imp.begin_ptr;
	}
	constexpr size_type size() noexcept
	{
		return this->imp.curr_pos;
	}
	constexpr size_type size_bytes() const noexcept
	{
		size_type pos{this->imp.curr_pos};
		if constexpr (underlying_digits == 8)
		{
			// Compute which byte contains the bit
			size_type byte_index{pos >> 3u}; // pos / 8
			// Compute which bit inside that byte
			size_type bit_index{pos & 7u}; // pos % 8
			return byte_index + (bit_index != 0u);
		}
		else
		{
			// Compute which byte contains the bit
			size_type byte_index{pos / underlying_digits};
			// Compute which bit inside that byte
			size_type bit_index{pos % underlying_digits};
			return byte_index + (bit_index != 0u);
		}
	}
	constexpr size_type capacity() noexcept
	{
		return this->imp.end_pos;
	}
	constexpr size_type capacity_bytes() const noexcept
	{
		size_type pos{this->imp.end_pos};
		if constexpr (underlying_digits == 8)
		{
			// Compute which byte contains the bit
			size_type byte_index{pos >> 3u}; // pos / 8
			// Compute which bit inside that byte
			size_type bit_index{pos & 7u}; // pos % 8
			return byte_index + (bit_index != 0u);
		}
		else
		{
			// Compute which byte contains the bit
			size_type byte_index{pos / underlying_digits};
			// Compute which bit inside that byte
			size_type bit_index{pos % underlying_digits};
			return byte_index + (bit_index != 0u);
		}
	}
	constexpr void clear() noexcept
	{
		this->imp.curr_pos = 0;
	}
	constexpr void clear_destroy() noexcept
	{
		this->destroy_bitvec();
		this->imp = {};
	}

private:
	inline static constexpr size_type bits_to_blocks(size_type bits) noexcept
	{
		if constexpr (underlying_digits == 8)
		{
			return (bits + 7) >> 3; // ceil(bits / 8)
		}
		else
		{
			return (bits + (underlying_digits - 1)) / underlying_digits;
		}
	}

public:
	constexpr void reserve(size_type n) noexcept
	{
		if (this->imp.end_pos < n)
		{
			this->grow_to_new_capacity(bits_to_blocks(n));
		}
	}
};

} // namespace containers

} // namespace fast_io
