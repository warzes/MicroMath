#pragma once

//=============================================================================
// STD Header
//=============================================================================
#if MM_ENABLE_NOSTDHEADER
#error "no impl"

typedef signed char                      int8;
typedef signed short                     int16;
typedef signed int                       int32;

typedef unsigned char                    uint8;
typedef unsigned short                   uint16;
typedef unsigned int                     uint32;

#	if( defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) ) // C99
typedef uint64_t                         uint64;
typedef int64_t                          int64;
#	elif defined(_MSC_VER)
typedef unsigned __int64                 uint64;
typedef signed __int64                   int64;
#	elif defined(__GNUC__)
__extension__ typedef unsigned long long uint64;
__extension__ typedef signed long long   int64;
#	elif defined(__clang__)
typedef unsigned long long               uint64;
typedef signed long long                 int64;
#	else
typedef unsigned long long               uint64;
typedef signed long long                 int64;
#	endif

#else

#	include <cstdint>
#	include <cmath>
#	include <climits>
#	include <cfloat>
#	if MM_ENABLE_ASSERT
#		include <cassert>
#	endif

typedef std::int8_t                      int8;
typedef std::int16_t                     int16;
typedef std::int32_t                     int32;
typedef std::int64_t                     int64;

typedef std::uint8_t                     uint8;
typedef std::uint16_t                    uint16;
typedef std::uint32_t                    uint32;
typedef std::uint64_t                    uint64;

#endif // MM_ENABLE_NOSTDHEADER

//=============================================================================
// Base Macros
//=============================================================================

#define MM_ARCH_32 32
#define MM_ARCH_64 64

#if defined(_M_ARM64) || defined(__LP64__) || defined(_M_X64) || defined(__ppc64__) || defined(__x86_64__)
#	define MM_ARCH MM_ARCH_64
#elif defined(__i386__) || defined(__ppc__) || defined(__ILP32__) || defined(_M_ARM)
#	define MM_ARCH MM_ARCH_32
#else
#	define MM_ARCH MM_ARCH_32
#endif

#if MM_ENABLE_FORCE_INLINE
#	if defined(_MSC_VER)
#		define MM_INLINE __forceinline
#		define MM_NEVER_INLINE __declspec(noinline)
#	elif defined(__GNUC__) || defined(__clang__)
#		define MM_INLINE inline __attribute__((__always_inline__))
#		define MM_NEVER_INLINE __attribute__((__noinline__))
#	else
#		define MM_INLINE inline
#		define MM_NEVER_INLINE
#	endif
#else
#	define MM_INLINE inline
#	define MM_NEVER_INLINE
#endif // MM_ENABLE_FORCE_INLINE

#if MM_ENABLE_ASSERT
#	define MM_ASSERT(x) assert(x)
#else
#	define MM_ASSERT(x)
#endif // MM_ENABLE_ASSERT

//=============================================================================
// Base Utility Func
//=============================================================================

// Implementation from "08/02/2015 Better array 'countof' implementation with C++ 11 (updated)" - https://www.g-truc.net/post-0708.html
template<typename T, size_t N>
constexpr size_t Countof(T const (&)[N])
{
	return N;
}

//=============================================================================
// FWD
//=============================================================================
template<typename T> class Vec2;
template<typename T> class Vec3;
template<typename T> class Vec4;
#if MM_ENABLE_QUATERNION
template<typename T> class Quat;
#endif
template<typename T> class Mat3;
template<typename T> class Mat4;

//template<size_t N, typename T> class Vec;
//
//typedef Vec<1, int> iVector1;
//typedef Vec<2, int> iVector2;
//typedef Vec<3, int> iVector3;
//typedef Vec<4, int> iVector4;
//
//typedef Vec<1, float> Vector1;
//typedef Vec<2, float> Vector2;
//typedef Vec<3, float> Vector3;
//typedef Vec<4, float> Vector4;
//
//typedef Vec<1, double> dVector1;
//typedef Vec<2, double> dVector2;
//typedef Vec<3, double> dVector3;
//typedef Vec<4, double> dVector4;
//
//template<typename T> class Quat;
//typedef Quat<float> Quaternion;
//typedef Quat<double> dQuaternion;
//
//template<size_t C, size_t R, typename T> class Mat;

//template<typename T> class Vector_1;
//template<typename T> class Vector_2;
//template<typename T> class Vector_3;
//template<typename T> class Vector_4;

//template<class T>
//class Vector_1
//{
//	T d;
//};

//template<class T> requires std::is_same_v<T, float> || std::is_same_v<T, double>
//class Vector_1
//{
//
//};
//template<class T> requires std::is_floating_point_v<T>
//class Vector_1
//{
//
//};


//=============================================================================
// private impl
//=============================================================================

// возможно удалить
namespace detail
{
	template<template<typename T> class Vec, typename T> struct functor1;
	template<template<typename T> class Vec, typename T> struct functor2;

	template<typename T> struct functor1<Vec2, T>
	{
		inline constexpr static Vec2<T> Call(T(*Func)(T arg), const Vec2<T>& v) { return { Func(v.x), Func(v.y) }; }
	};
	template<typename T> struct functor1<Vec3, T>
	{
		inline constexpr static Vec3<T> Call(T(*Func)(T arg), const Vec3<T>& v) { return { Func(v.x), Func(v.y), Func(v.z) }; }
	};
	template<typename T> struct functor1<Vec4, T>
	{
		inline constexpr static Vec4<T> Call(T(*Func)(T arg), const Vec4<T>& v) { return { Func(v.x), Func(v.y), Func(v.z), Func(v.w) }; }
	};

	template<typename T> struct functor2<Vec2, T>
	{
		inline constexpr static Vec2<T> Call(T(*Func)(T arg1, T arg2), const Vec2<T>& a, const Vec2<T>& b) { return { Func(a.x, b.x), Func(a.y, b.y) }; }
	};
	template<typename T> struct functor2<Vec3, T>
	{
		inline constexpr static Vec3<T> Call(T(*Func)(T arg1, T arg2), const Vec3<T>& a, const Vec3<T>& b) { return { Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z) }; }
	};
	template<typename T> struct functor2<Vec4, T>
	{
		inline constexpr static Vec4<T> Call(T(*Func)(T arg1, T arg2), const Vec4<T>& a, const Vec4<T>& b) { return { Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w) }; }
	};
}