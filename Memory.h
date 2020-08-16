#ifndef __MEMORY_H__
#define __MEMORY_H__
#pragma once

// from boost libraries
template <uint64_t FnvPrime, uint64_t OffsetBasis>
struct basic_fnv_1 {
		uint64_t operator()( std::string const& text ) const {

		uint64_t hash = OffsetBasis;
		for ( std::string::const_iterator it = text.begin(), end = text.end(); it != end; ++it ) {

			hash *= FnvPrime;
			hash ^= *it;
		}

		return hash;
	}
};

const uint64_t fnv_prime = 1099511628211u;
const uint64_t fnv_offset_basis = 14695981039346656037u;

typedef basic_fnv_1<fnv_prime, fnv_offset_basis> fnv_1;

namespace Memory {

	void TransformPattern( const std::string & pattern, std::string & data, std::string & mask );

	class executable_meta {
	private:

		uintptr_t	m_begin;
		uintptr_t	m_end;
		DWORD		m_size;
	public:
		executable_meta()
			: m_begin( 0 ), m_end( 0 ) {
		}

		void EnsureInit();

		inline uintptr_t begin() { return m_begin; }
		inline uintptr_t end() { return m_end; }
		inline DWORD size() { return m_size; }
	};

	class pattern_match {
	private:
		void * m_pointer;

	public:
		inline pattern_match( void * pointer ) {
			m_pointer = pointer;
		}

		template<typename T>
		T * get( int offset ) {

			if ( m_pointer == nullptr ) 
				return nullptr;

			char * ptr = reinterpret_cast<char*>( m_pointer );
			return reinterpret_cast<T*>( ptr + offset );
		}

		template<typename T>
		T * get() {

			return get<T>( 0 );
		}
	};

	typedef std::vector<pattern_match> matchVec;

	class pattern {
	private:
		std::string			m_bytes;
		std::string			m_mask;
		uint64_t			m_hash;
		size_t				m_size;
		matchVec			m_matches;
		bool				m_matched;

	private:
		void Initialize( const char* pattern, size_t length );
		bool ConsiderMatch( uintptr_t offset );
		void EnsureMatches( int maxCount );

	public:
		template<size_t Len>
		pattern( const char( &pattern )[Len] ) {
			Initialize( pattern, Len );
		}

		inline pattern & count( int expected ) {
			if ( !m_matched ) 
				EnsureMatches( expected );

			return *this;
		}

		inline size_t size() {
			if ( !m_matched ) 
				EnsureMatches( INT_MAX );

			return m_matches.size();
		}

		inline pattern_match & get( int index ) {
			if ( !m_matched ) 
				EnsureMatches( INT_MAX );

			if ( m_matches.size() == 0 ) {
				m_matches.push_back( pattern_match( nullptr ) );
				return m_matches[0];
			}

			return m_matches[index];
		}

	public:
		// define a hint
		static void hint( uint64_t hash, uintptr_t address );
	};

	// for link /DYNAMICBASE executables
	static ptrdiff_t baseAddressDifference;

	// sets the base address difference based on an obtained pointer
	inline void set_base(uintptr_t address)
	{
#ifdef _M_IX86
		uintptr_t addressDiff = (address - 0x400000);
#elif defined(_M_AMD64)
		uintptr_t addressDiff = (address - 0x140000000);
#endif

		// pointer-style cast to ensure unsigned overflow ends up copied directly into a signed value
		baseAddressDifference = *(ptrdiff_t*)&addressDiff;
	}

	// gets the main base of the process
	uintptr_t get_base();
	DWORD get_size();

	// gets the main base of the process with Offset
	uintptr_t get_base_offsetted(DWORD offset);
	
	// gets a multilayer pointer address
	uintptr_t get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets);

	// sets the base to the process main base
	inline void set_base()
	{
		set_base((uintptr_t)GetModuleHandle(NULL));
	}

	// adjusts the address passed to the base as set above
	template<typename T>
	inline void adjust_base(T& address)
	{
		*(uintptr_t*)&address += baseAddressDifference;
	}

	// returns the adjusted address to the stated base
	template<typename T>
	inline uintptr_t get_adjusted(T address)
	{
		return (uintptr_t)address + baseAddressDifference;
	}

	template<typename ValueType, typename AddressType>
	inline void put(AddressType address, ValueType value)
	{
		adjust_base(address);

		memcpy((void*)address, &value, sizeof(value));
	}

	template<typename ValueType, typename AddressType>
	inline void putVP(AddressType address, ValueType value)
	{
		adjust_base(address);

		DWORD oldProtect;
		VirtualProtect((void*)address, sizeof(value), PAGE_EXECUTE_READWRITE, &oldProtect);

		memcpy((void*)address, &value, sizeof(value));

		VirtualProtect((void*)address, sizeof(value), oldProtect, &oldProtect);
	}

	template<typename AddressType>
	inline void nop(AddressType address, size_t length)
	{
		adjust_base(address);

		memset((void*)address, 0x90, length);
	}

	template<typename AddressType>
	inline void return_function(AddressType address, uint16_t stackSize = 0)
	{
		if (stackSize == 0)
			put<uint8_t>(address, 0xC3);
		else
		{
			put<uint8_t>(address, 0xC2);
			put<uint16_t>((uintptr_t)address + 1, stackSize);
		}
	}

	template<typename T>
	inline T* getRVA(uintptr_t rva)
	{
#ifdef _M_IX86
		return (T*)(baseAddressDifference + 0x400000 + rva);
#elif defined(_M_AMD64)
		return (T*)(0x140000000 + rva);
#endif
	}

	template<typename T, typename AT>
	inline void jump(AT address, T func)
	{
		put<uint8_t>(address, 0xE9);
		put<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
	}

	template<typename T, typename AT>
	inline void call(AT address, T func)
	{
		put<uint8_t>(address, 0xE8);
		put<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
	}

	template<typename T>
	inline T get_call(T address)
	{
		intptr_t target = *(uintptr_t*)(get_adjusted(address) + 1);
		target += (get_adjusted(address) + 5);

		return (T)target;
	}

	template<typename TTarget, typename T>
	inline void set_call(TTarget* target, T address)
	{
		*(T*)target = get_call(address);
	}

	namespace vp
	{
		template<typename T, typename AT>
		inline void jump(AT address, T func)
		{
			putVP<uint8_t>(address, 0xE9);
			putVP<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
		}

		template<typename T, typename AT>
		inline void call(AT address, T func)
		{
			putVP<uint8_t>(address, 0xE8);
			putVP<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
		}
	}

	std::vector<DWORD64> get_string_addresses(std::string str);

	template <typename T>
	T get_value(std::vector<DWORD> offsets) {

		uintptr_t Addr = get_multilayer_pointer(Hooking::getWorldPtr(), offsets);
		if (Addr == NULL) 
			return NULL;

		return *((T*)Addr);
	}

	template <typename T>
	void set_value(std::vector<DWORD> offsets, T value) {
		uintptr_t Addr = get_multilayer_pointer(Hooking::getWorldPtr(), offsets);
		if (Addr == NULL) 
			return;

		*reinterpret_cast<T*>(Addr) = value;
	}
}


#endif // __MEMORY_H__

class Module
{
private:
	uintptr_t m_begin;
	uintptr_t m_end;
	DWORD m_size;
public:
	template<typename TReturn, typename TOffset>
	TReturn* getRVA(TOffset rva)
	{
		return (TReturn*)(m_begin + rva);
	}

	Module(void* module = GetModuleHandle(nullptr))
		: m_begin((uintptr_t)module), m_end(0)
	{
		PIMAGE_DOS_HEADER dosHeader = getRVA<IMAGE_DOS_HEADER>(0);
		PIMAGE_NT_HEADERS ntHeader = getRVA<IMAGE_NT_HEADERS>(dosHeader->e_lfanew);

		m_end = m_begin + ntHeader->OptionalHeader.SizeOfCode;
		m_size = ntHeader->OptionalHeader.SizeOfImage;
	}
	inline uintptr_t base() { return m_begin; }
	inline uintptr_t end() { return m_end; }
	inline DWORD size() { return m_size; }
};

namespace mem
{
	namespace traits
	{
		template <typename...>
		using void_t = void;

		template <typename Function, typename = void>
		struct is_invocable
			: std::false_type
		{ };

		template <typename Function>
		struct is_invocable<Function, void_t<typename std::result_of<Function>::type>>
			: std::true_type
		{ };

		template <typename Function>
		struct is_function_pointer
			: std::bool_constant<std::is_pointer<Function>::value && std::is_function<typename std::remove_pointer<typename std::decay<Function>::type>::type>::value>
		{ };
	}

	class handle
	{
	protected:
		void* _handle;

	public:
		handle()
			: _handle(nullptr)
		{ }

		handle(std::nullptr_t null)
			: _handle(null)
		{ }

		handle(void* p)
			: _handle(p)
		{ }

		template <typename T>
		handle(T* p)
			: _handle(const_cast<typename std::remove_cv<T>::type*>(p))
		{ }

		handle(const std::uintptr_t p)
			: _handle(reinterpret_cast<void*>(p))
		{ }

		handle(const handle& copy) = default;

		template <typename T>
		typename std::enable_if<std::is_pointer<T>::value, T>::type as() const
		{
			return reinterpret_cast<T>(this->_handle);
		}

		template <typename T>
		typename std::enable_if<std::is_lvalue_reference<T>::value, T>::type as() const
		{
			return *this->as<typename std::remove_reference<T>::type*>();
		}

		template <typename T>
		typename std::enable_if<std::is_array<T>::value, T&>::type as() const
		{
			return this->as<T&>();
		}

		template <typename T>
		typename std::enable_if<std::is_same<T, std::uintptr_t>::value, T>::type as() const
		{
			return reinterpret_cast<std::uintptr_t>(this->as<void*>());
		}

		template <typename T>
		typename std::enable_if<std::is_same<T, std::intptr_t>::value, T>::type as() const
		{
			return reinterpret_cast<std::intptr_t>(this->as<void*>());
		}

		bool operator==(const handle& rhs) const
		{
			return this->as<void*>() == rhs.as<void*>();
		}

		bool operator!=(const handle& rhs) const
		{
			return this->as<void*>() != rhs.as<void*>();
		}

		bool operator>(const handle& rhs) const
		{
			return this->as<void*>() > rhs.as<void*>();
		}

		bool operator<(const handle& rhs) const
		{
			return this->as<void*>() < rhs.as<void*>();
		}

		bool operator>=(const handle& rhs) const
		{
			return this->as<void*>() >= rhs.as<void*>();
		}

		bool operator<=(const handle& rhs) const
		{
			return this->as<void*>() <= rhs.as<void*>();
		}

		operator void*() const
		{
			return this->as<void*>();
		}

		template <typename T>
		handle save(typename std::enable_if<std::is_pointer<T>::value, T>::type& out) const
		{
			out = this->as<T>();

			return *this;
		}

		template <typename T>
		typename std::enable_if<std::is_integral<T>::value, handle>::type add(const T offset) const
		{
			return this->as<std::uintptr_t>() + offset;
		}

		template <typename T>
		handle rip(const T ipoffset) const
		{
			return this->add(ipoffset).add(this->as<int&>());
		}

		handle translate(const handle from, const handle to) const
		{
			return to.add(this->as<std::intptr_t>() - from.as<std::intptr_t>());
		}

#ifdef _MEMORYAPI_H_
		bool protect(const std::size_t size, const std::uint32_t newProtect, const std::uint32_t* oldProtect)
		{
			return VirtualProtect(this->as<void*>(), size, (DWORD)newProtect, (DWORD*)&oldProtect) == TRUE;
		}

		bool nop(const std::size_t size)
		{
			std::uint32_t oldProtect;

			if (this->protect(size, PAGE_EXECUTE_READWRITE, &oldProtect))
			{
				std::memset(this->as<void*>(), 0x90, size);

				this->protect(size, oldProtect, nullptr);

				return true;
			}

			return false;
		}

		inline bool set(const void * data, const std::size_t size)
		{
			std::uint32_t oldProtect;

			if (this->protect(size, PAGE_EXECUTE_READWRITE, &oldProtect))
			{
				std::memcpy(this->as<void*>(), data, size);

				this->protect(size, oldProtect, nullptr);

				return true;
			}

			return false;
		}

		template <typename T>
		inline void write(const T value)
		{
			static_assert(std::is_trivially_copyable<T>::value, "Type is not trivially copyable");

			this->as<T&>() = value;
		}

		template <typename... T>
		void write_args(const T... args)
		{
			std::uintptr_t off = 0;

			(void)std::initializer_list<int>
			{
				0, (this->add(off).write(args), off += sizeof(args))...
			};
		}

		template <typename T>
		bool write_vp(const T value)
		{
			std::uint32_t oldProtect;

			auto size = sizeof(value);

			if (this->protect(size, PAGE_EXECUTE_READWRITE, &oldProtect))
			{
				this->write(value);

				this->protect(size, oldProtect, nullptr);

				return true;
			}

			return false;
		}

		template <typename... T>
		bool write_args_vp(const T... args)
		{
			std::uint32_t oldProtect;

			auto size = std::valarray<std::size_t>({ sizeof(args)... }).sum();

			if (this->protect(size, PAGE_EXECUTE_READWRITE, &oldProtect))
			{
				this->write_args(args...);

				this->protect(size, oldProtect, nullptr);

				return true;
			}

			return false;
		}
#endif
	};

	template <typename T>
	struct _pattern
	{
	protected:
		using type = T;

		struct nibble
		{
			type expected;
			type mask;

			nibble()
				: mask()
				, expected()
			{ }

			bool matches(const type* value) const
			{
				return !((*value ^ expected) & mask);
			}
		};

		std::vector<nibble> nibbles;

		bool compare(const handle address) const
		{
			for (std::size_t i = 0; i < nibbles.size(); ++i)
			{
				if (!nibbles[i].matches(address.as<const type*>() + i))
				{
					return false;
				}
			}

			return true;
		}

	public:
		_pattern(const char* string)
		{
			static const std::uint8_t hex_char_table[256] =
			{
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
				0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
			};

			while (true)
			{
				nibble      current_nibble;
				std::size_t i = 0;

				while (const char c = *string++)
				{
					const std::uint8_t shift = (i & 1) ? 0 : 4;
					const std::uint8_t value = hex_char_table[static_cast<std::uint8_t>(c)];

					if (value != 0xFF)
					{
						reinterpret_cast<std::uint8_t*>(&current_nibble.mask)[i / 2] |= (0xF << shift);
						reinterpret_cast<std::uint8_t*>(&current_nibble.expected)[i / 2] |= (value << shift);
					}
					else if (c != '?' && shift == 4)
					{
						continue;
					}

					if (++i == (sizeof(type) * 2))
					{
						break;
					}
				}

				if (i > 0)
				{
					nibbles.push_back(current_nibble);
				}

				if (i < (sizeof(type) * 2))
				{
					break;
				}
			}
		}

		handle scan(const handle base, const handle end) const
		{
			end.add(-static_cast<std::intptr_t>(nibbles.size() * sizeof(type)));

			for (handle current = base; current < end; current = current.add(1))
			{
				if (compare(current))
				{
					return current;
				}
			}

			return nullptr;
		}

		std::vector<handle> scan_all(const handle base, const handle end) const
		{
			std::vector<handle> results;

			for (handle current = base; current = this->scan(current, end); current = current.add(1))
			{
				results.push_back(current);
			}

			return results;
		}
	};

#ifdef _INCLUDED_SMM
	bool _pattern<__m128i>::nibble::matches(const __m128i* value) const
	{
		return _mm_testz_si128(_mm_xor_si128(_mm_loadu_si128(value), expected), mask);
	}
#endif

#ifdef _INCLUDED_IMM
	bool _pattern<__m256i>::nibble::matches(const __m256i* value) const
	{
		return _mm256_testz_si256(_mm256_xor_si256(_mm256_loadu_si256(value), expected), mask);
	}
#endif

	using pattern = _pattern<std::uintptr_t>;

	class region
	{
	protected:
		handle      _base;
		std::size_t _size;

	public:
		region(handle base, std::size_t size)
			: _base(base)
			, _size(size)
		{ }

		handle base() const
		{
			return this->_base;
		}

		std::size_t size() const
		{
			return this->_size;
		}

		handle end() const
		{
			return this->add(this->size());
		}

		bool contains(const handle address) const
		{
			return (address >= this->base()) && (address < this->end());
		}

		template <typename T>
		handle add(const T offset) const
		{
			return this->base().add(offset);
		}

		handle distance(const handle pointer) const
		{
			return pointer.as<std::uintptr_t>() - this->base().as<std::uintptr_t>();
		}

		handle memcpy(const handle pointer)
		{
			return std::memcpy(base().as<void*>(), pointer.as<const void*>(), size());
		}

		handle memset(const std::uint8_t value)
		{
			return std::memset(base().as<void*>(), value, size());
		}

		handle scan(const pattern& pattern) const
		{
			return pattern.scan(this->base(), this->end());
		}

		std::vector<handle> scan_all(const pattern& pattern) const
		{
			return pattern.scan_all(this->base(), this->end());
		}

		std::string to_hex_string(bool padded = false)
		{
			static const char* hexTable = "0123456789ABCDEF";

			std::stringstream stream;

			for (std::size_t i = 0; i < size(); ++i)
			{
				if (i && padded)
				{
					stream << ' ';
				}

				stream << hexTable[(base().as<const std::uint8_t*>()[i] >> 4) & 0xF];
				stream << hexTable[(base().as<const std::uint8_t*>()[i] >> 0) & 0xF];
			}

			return stream.str();
		}
	};

#ifdef _WINNT_
	class module : public region
	{
	protected:
		module(handle base)
			: region(base, base.add(base.as<IMAGE_DOS_HEADER&>().e_lfanew).as<IMAGE_NT_HEADERS&>().OptionalHeader.SizeOfImage)
		{ }

	public:
		static module named(const char* name)
		{
			return GetModuleHandleA(name);
		}

		static module named(const wchar_t* name)
		{
			return GetModuleHandleW(name);
		}

		static module named(const std::nullptr_t)
		{
			return module::named(static_cast<char*>(nullptr));
		}

		static module main()
		{
			return module::named(nullptr);
		}
	};
#endif

	template <typename C>
	class safe_class
	{
	protected:
		C * const _handle;

	public:
		safe_class()
			: _handle(nullptr)
		{ }

		safe_class(C* const pClass)
			: _handle(pClass)
		{ }

		C* get() const
		{
			return _handle;
		}

		operator bool() const
		{
			return _handle != nullptr;
		}

		C* operator ->() const
		{
			return _handle;
		}

		C& operator *() const
		{
			return *_handle;
		}

		template <typename T>
		safe_class<T> operator >>(T* C::*pMember) const
		{
			return _handle ? (_handle->*pMember) : nullptr;
		}
	};

	template <typename Invoker>
	struct static_function
	{
	protected:
		static_assert(traits::is_function_pointer<Invoker>::value, "Invoker is not a function pointer");
		static_assert(traits::is_invocable<Invoker(void*)>::value, "Invoker is not invocable with a void*");

		Invoker invoker_;
		std::unique_ptr<void, void(*)(void*)> params_;

		template <typename Invocable>
		static_function(Invocable* p)
			: invoker_([](void* p) { return std::move(*static_cast<Invocable*>(p))(); })
			, params_(p, [](void* p) { delete static_cast<Invocable*>(p); })
		{ }

	public:
		static_function()
			: invoker_(nullptr)
			, params_(nullptr, nullptr)
		{ }

		template <typename Function, typename... Args>
		static_function(Function f, Args... args)
			: static_function(new auto([f, args...]{ return f(args...); }))
		{ }

		Invoker get_invoker() const
		{
			return invoker_;
		}

		void* get_params() const
		{
			return params_.get();
		}
	};

	inline std::uintptr_t get_offset(mem::handle address)
	{
		std::uintptr_t new_address = 0ull;

		auto module = mem::module::main();

		if (module.contains(address))
		{
			new_address = address.as<std::uintptr_t>() - module.base().as<std::uintptr_t>();
		}

		return new_address;
	};

	inline bool compare(const uint8_t* pData, const uint8_t* bMask, const char* sMask)
	{
		for (; *sMask; ++sMask, ++pData, ++bMask)
			if (*sMask == 'x' && *pData != *bMask)
				return false;

		return *sMask == NULL;
	}

	inline std::vector<DWORD64> get_string_addresses(std::string str)
	{
		std::string currentMask;
		static auto module = Module();
		const char* to_scan = str.c_str();
		for (uint8_t i = 0; i < strlen(to_scan); i++)
			currentMask += "x";
		const char* mask = currentMask.c_str();
		std::vector<DWORD64> foundAddrs;
		for (uint32_t i = 0; i < module.size(); ++i) {
			auto address = module.base() + i;
			if (compare((BYTE*)(address), (BYTE*)to_scan, mask)) {
				foundAddrs.push_back((address));
			}
		}

		return foundAddrs;
	}

	inline uintptr_t get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets)
	{
		uintptr_t ptr = *(uintptr_t*)(base_address);
		if (!ptr) {
			return NULL;
		}
		auto level = offsets.size();

		for (auto i = 0; i < level; i++) {
			if (i == level - 1) {
				ptr += offsets[i];
				if (!ptr)
					return NULL;
				return ptr;
			}
			else {
				ptr = *(uint64_t*)(ptr + offsets[i]);
				if (!ptr)
					return NULL;
			}
		}

		return ptr;
	}

	template <typename T>
	T get_value(uintptr_t Addr, std::vector<DWORD> offsets)
	{
		if (Addr == NULL) return NULL;
		uintptr_t ML = get_multilayer_pointer(Addr, offsets);
		if (ML == NULL) return NULL;
		return *((T*)ML);
	}

	template <typename T>
	void set_value(uintptr_t Addr, std::vector<DWORD> offsets, T value) {
		uintptr_t ML = get_multilayer_pointer(Addr, offsets);
		if (ML == NULL) {
			return;
		}

		*reinterpret_cast<T*>(ML) = value;
	}
}

inline mem::handle operator""_Scan(const char* string, std::size_t)
{
	if (auto handle = mem::module::named(nullptr).scan(string))
	{
		return handle;
	}

	Log::Error("Pattern Fail! - %s", string);

	return nullptr;
}

typedef unsigned short ushort;
typedef unsigned int uint;
typedef uintptr_t QWORD;

#ifdef _WIN64
#define PTRMAXVAL ((PVOID)0x000F000000000000)
#else
#define PTRMAXVAL ((PVOID)0xFFF00000)
#endif

class Mem
{
public:

	template <class vType>
	static vType Read(DWORD64 Add)
	{
		__try
		{
			return *(vType*)(Add);
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	static std::string ReadString(DWORD64 Add, size_t strLength)
	{
		char szString[512] = { 0 };
		for (size_t i = 0; i < strLength; i++)
		{
			char tChar;
			tChar = *(char*)(Add + (i * 0x1));
			szString[i] = tChar;
		}
		return szString;
	}

	template <class vType>
	static vType ReadPtr(DWORD64 Add, DWORD64 o1, DWORD64 o2, DWORD64 o3, DWORD64 o4, DWORD64 o5, DWORD64 o6)
	{
		__try
		{
			DWORD64* ptr1 = (DWORD64*)(Add + o1);
			if (IsValid(ptr1))
			{
				DWORD64* ptr2 = (DWORD64*)(*ptr1 + o2);
				if (IsValid(ptr2))
				{
					DWORD64* ptr3 = (DWORD64*)(*ptr2 + o3);
					if (IsValid(ptr3))
					{
						DWORD64* ptr4 = (DWORD64*)(*ptr3 + o4);
						if (IsValid(ptr4))
						{
							DWORD64* ptr5 = (DWORD64*)(*ptr4 + o5);
							if (IsValid(ptr5))
							{
								return *(vType*)(*ptr5 + o6);
							}
						}
					}
				}
			}
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	template <class vType>
	static vType ReadPtr(DWORD64 Add, DWORD64 o1, DWORD64 o2, DWORD64 o3, DWORD64 o4, DWORD64 o5)
	{
		__try
		{
			DWORD64* ptr1 = (DWORD64*)(Add + o1);
			if (IsValid(ptr1))
			{
				DWORD64* ptr2 = (DWORD64*)(*ptr1 + o2);
				if (IsValid(ptr2))
				{
					DWORD64* ptr3 = (DWORD64*)(*ptr2 + o3);
					if (IsValid(ptr3))
					{
						DWORD64* ptr4 = (DWORD64*)(*ptr3 + o4);
						if (IsValid(ptr4))
						{
							return *(vType*)(*ptr4 + o5);
						}
					}
				}
			}
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	template <class vType>
	static vType ReadPtr(DWORD64 Add, DWORD64 o1, DWORD64 o2, DWORD64 o3, DWORD64 o4)
	{
		__try
		{
			DWORD64* ptr1 = (DWORD64*)(Add + o1);
			if (IsValid(ptr1))
			{
				DWORD64* ptr2 = (DWORD64*)(*ptr1 + o2);
				if (IsValid(ptr2))
				{
					DWORD64* ptr3 = (DWORD64*)(*ptr2 + o3);
					if (IsValid(ptr3))
					{
						return *(vType*)(*ptr3 + o4);
					}
				}
			}
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	template <class vType>
	static vType ReadPtr(DWORD64 Add, DWORD64 o1, DWORD64 o2, DWORD64 o3)
	{
		__try
		{
			DWORD64* ptr1 = (DWORD64*)(Add + o1);
			if (IsValid(ptr1))
			{
				DWORD64* ptr2 = (DWORD64*)(*ptr1 + o2);
				if (IsValid(ptr2))
				{
					return *(vType*)(*ptr2 + o3);
				}
			}
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	template <class vType>
	static vType ReadPtr(DWORD64 Add, DWORD64 o1, DWORD64 o2)
	{
		__try
		{
			DWORD64* ptr1 = (DWORD64*)(Add + o1);
			if (IsValid(ptr1))
			{
				return *(vType*)(*ptr1 + o2);
			}
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	template <class vType>
	static vType ReadPtr(DWORD64 Add, DWORD64 o1)
	{
		__try
		{
			DWORD64* ptr1 = (DWORD64*)(Add);
			if (IsValid(ptr1))
			{
				return *(vType*)(*ptr1 + o1);
			}
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return vType();
		}
	}

	template <class vType>
	static BOOLEAN Write(DWORD64 address, vType value)
	{
		__try
		{
			*(vType*)address = value;
		}
		__except (InternalErrorHandler(GetExceptionCode(), GetExceptionInformation()))
		{
			return FALSE;
		}
		return TRUE;
	}

	static int InternalErrorHandler(unsigned int Code, struct _EXCEPTION_POINTERS* EP)
	{
		return (Code == EXCEPTION_ACCESS_VIOLATION) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH;
	}

	static __forceinline BOOLEAN IsValid(PVOID ptr)
	{
		return (ptr >= (PVOID)0x10000) && (ptr < PTRMAXVAL) && ptr != nullptr;
	}

	static DWORD64 GetBase()
	{
		return (DWORD64)GetModuleHandle(NULL);
	}

};