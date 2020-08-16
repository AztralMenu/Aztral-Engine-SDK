#ifndef __NATIVE_CALLER_H__
#define __NATIVE_CALLER_H__

#pragma once

template <typename T>
static inline void nativePush(T val)
{
	UINT64 val64 = 0;
	if (sizeof(T) > sizeof(UINT64))
		throw "error, value size > 64 bit"_Secure;

	*reinterpret_cast<T *>(&val64) = val;
	nativePush64(val64);
}

template <typename R, typename... ARGs>
static inline R invoke(UINT64 hash, ARGs ... args)
{
	nativeInit(hash);

	int dummy[] = {
		0,
		((void)nativePush(std::forward<ARGs>(args)),
		0) ... };

	return *reinterpret_cast<R *>(nativeCall());
}

#endif