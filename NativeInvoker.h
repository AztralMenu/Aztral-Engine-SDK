#ifndef __NATIVE_INVOKER_H__
#define __NATIVE_INVOKER_H__

#pragma once

namespace rage
{
	static int64_t(*GetEntityAddress)(int) = "83 f9 ff 74 31 4c 8b 0d ? ? ? ? 44 8b c1 49 8b 41 08"_Scan.as<decltype(GetEntityAddress)>();
	static Entity(*AddressToEntity)(int64_t) = "48 89 5c 24 ? 48 89 74 24 ? 57 48 83 ec 20 8b 15 ? ? ? ? 48 8b f9 48 83 c1 10 33 db"_Scan.as<decltype(AddressToEntity)>();
	static uint32_t*(*FileRegister)(uint32_t*, const char*, bool, const char*, bool) = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9"_Scan.as<decltype(FileRegister)>();
}



/*template <uint32_t stackSize>
class NativeStack
{
public:
	static constexpr uint32_t size = stackSize;
protected:

	uint64_t stack[size];

	template <typename T>
	T getAt(uint32_t index)const
	{
		return reinterpret_cast<const T &>(stack[index]);
	}

	template <>
	bool getAt<bool>(uint32_t index)const
	{
		return reinterpret_cast<const int &>(stack[index]) != 0;
	}

	template <typename T>
	void setAt(uint32_t index, const T& value)
	{
		reinterpret_cast<T &>(stack[index]) = value;
	}

	template <>
	void setAt<bool>(uint32_t index, const bool& value)
	{
		reinterpret_cast<int &>(stack[index]) = value != 0;
	}

public:
	const decltype(stack)& getRawPtr()const
	{
		return stack;
	}

	decltype(stack)& getRawPtr()
	{
		return stack;
	}
};


static NativeReturnStack g_Returns;

struct NativeReturnStack : NativeStack<3>
{
	template <typename T> T Get() const
	{
		return getAt<T>(0);
	}

	template <typename T> NativeReturnStack *Set(const T &value)
	{
		setAt(0, value);
		return this;
	}
};*/

class scrNativeCallContext {
protected:

	void *		m_pReturn;
	uint32_t	m_nArgCount;
	void *		m_pArgs;
	uint32_t	m_nDataCount;
	alignas(uintptr_t)uint8_t m_vectorSpace[192];

public:

	template<typename T>
	inline T GetArgument( int idx ) {

		intptr_t * arguments = (intptr_t*)m_pArgs;
		return *(T*)&arguments[idx];
	}

	template<typename T>
	inline void SetResult( int idx, T value ) {

		intptr_t * returnValues = (intptr_t*)m_pReturn;
		*(T*)&returnValues[idx] = value;
	}

	inline int GetArgumentCount() {

		return m_nArgCount;
	}

	template<typename T>
	inline T GetResult( int idx ) {

		intptr_t * returnValues = (intptr_t*)m_pReturn;
		return *(T*)&returnValues[idx];
	}

	static void(*SetVectorResults)(scrNativeCallContext*);
};

class NativeContext : public scrNativeCallContext {
private:

	// Configuration
	enum {
		MaxNativeParams = 16,
		ArgSize = 8,
	};

	// Anything temporary that we need
	uint8_t m_TempStack[MaxNativeParams * ArgSize];

public:

	inline NativeContext() {

		m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack;		//I believe it's okay to point both args and return at the same pointer. The game should handle this.
		m_nArgCount = 0;				//unless their cpus a total piece of shit
		m_nDataCount = 0;
	}

	template <typename T>
	inline void Push( T value ) {

		if ( sizeof( T ) > ArgSize ) {
			throw "Argument has an invalid size"_Secure;
		} else if ( sizeof( T ) < ArgSize ) {
			// Ensure we don't have any stray data
			*reinterpret_cast<uintptr_t*>( m_TempStack + ArgSize * m_nArgCount ) = 0;
		}

		*reinterpret_cast<T*>( m_TempStack + ArgSize * m_nArgCount ) = value;
		m_nArgCount++;
	}

	inline void Reverse() {

		uintptr_t tempValues[MaxNativeParams];
		uintptr_t * args = (uintptr_t*)m_pArgs;

		for ( uint32_t i = 0; i < m_nArgCount; i++ ) { //uint32_t i = 0; i < m_nArgCount; i++ blah

			int target = m_nArgCount - i - 1;
			tempValues[target] = args[i];
		}

		memcpy( m_TempStack, tempValues, sizeof( m_TempStack ) );
	}

	template <typename T>
	inline T GetResult() {

		return *reinterpret_cast<T*>( m_TempStack );
	}
};

struct pass {
	template<typename ...T> pass( T... ) {}
};

class NativeManagerContext : public NativeContext {
public:

	NativeManagerContext()
		: NativeContext() {
	}

	void Reset() {

		m_nArgCount = 0;
		m_nDataCount = 0;
	}

	inline void* GetResultPointer() {

		return m_pReturn;
	}
};

void nativeInit(UINT64 hash);

void nativePush64(UINT64 val);

PUINT64 nativeCall();

#endif // __NATIVE_INVOKER_H__