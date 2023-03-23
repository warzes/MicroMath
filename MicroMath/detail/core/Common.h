#pragma once

//=============================================================================
// Common Functions
//=============================================================================
// Returns x if x >= 0; otherwise, it returns -x.
template<typename T> inline constexpr T Abs(T x);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Abs(const Vec<T>& x);

// Returns 1.0 if x > 0, 0.0 if x == 0, or -1.0 if x < 0.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sign(const Vec<T>& x);

// Returns a value equal to the nearest integer that is less then or equal to x.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Floor(const Vec<T>& x);

// Returns a value equal to the nearest integer to x whose absolute value is not larger than the absolute value of x.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Trunc(const Vec<T>& x);

// Returns a value equal to the nearest integer to x. The fraction 0.5 will round in a direction chosen by the implementation, presumably the direction that is fastest. This includes the possibility that round(x) returns the same value as roundEven(x) for all values of x.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Round(const Vec<T>& x);

// Returns a value equal to the nearest integer to x. A fractional part of 0.5 will round toward the nearest even integer. (Both 3.5 and 4.5 for x will return 4.0.)
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> RoundEven(const Vec<T>& x);

// Returns a value equal to the nearest integer that is greater than or equal to x.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Ceil(const Vec<T>& x);

// Return x - floor(x).
template<typename T> inline constexpr T Fract(T x);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Fract(const Vec<T>& x);

// Modulus. Returns x - y * floor(x / y)
template<typename T> inline constexpr T Mod(T x, T y);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Mod(const Vec<T>& x, const Vec<T>& y);

// Returns the fractional part of x and sets i to the integer part (as a whole number floating point value). Both the return value and the output parameter will have the same sign as x.
template<typename T> inline constexpr T Modf(T x, T y);

// Returns y if y < x; otherwise, it returns x.
template<typename T> inline constexpr T Min(T x, T y);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Min(const Vec<T>& x, const Vec<T>& y);

// Returns y if x < y; otherwise, it returns x.
template<typename T> inline constexpr T Max(T x, T y);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Max(const Vec<T>& x, const Vec<T>& y);

// Returns min(max(x, minVal), maxVal) for each component in x using the floating-point values minVal and maxVal.
template<typename T> inline constexpr T Clamp(T x, T minVal, T maxVal);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Clamp(const Vec<T>& x, T minVal, T maxVal);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Clamp(const Vec<T>& x, const Vec<T>& minVal, const Vec<T>& maxVal);

// If genTypeU is a floating scalar or vector: Returns x * (1.0 - a) + y * a, i.e., the linear blend of x and y using the floating-point value a. The value for a is not restricted to the range [0, 1].
template<typename T> inline constexpr T Mix(T x, T y, T a);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Mix(const Vec<T>& x, const Vec<T>& y, T a);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Mix(const Vec<T>& x, const Vec<T>& y, const Vec<T>& a);

// Returns 0.0 if x < edge, otherwise it returns 1.0.
template<typename T> inline constexpr T Step(T edge, T x);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Step(T edge, const Vec<T>& x);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Step(const Vec<T>& edge, const Vec<T>& x);

// Returns 0.0 if x <= edge0 and 1.0 if x >= edge1 and performs smooth Hermite interpolation between 0 and 1 when edge0 < x < edge1. This is useful in cases where you would want a threshold function with a smooth transition. This is equivalent to:
// genType t;
// t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
// return t * t * (3 - 2 * t);
// Results are undefined if edge0 >= edge1.
template<typename T> inline constexpr T SmoothStep(T edge0, T edge1, T x);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> SmoothStep(T edge0, T edge1, const Vec<T>& x);
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> SmoothStep(const Vec<T>& edge0, const Vec<T>& edge1, const Vec<T>& x);

//=============================================================================
// Common Functions Impl
//=============================================================================
template<typename T>
inline constexpr T Abs(T x)
{
	static_assert(std::numeric_limits<T>::is_iec559 || std::numeric_limits<T>::is_signed, "'Abs' only accept floating-point and integer scalar or vector inputs");
	return x >= T(0) ? x : -x;
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Abs(const Vec<T>& x)
{
	return detail::functor1<Vec, T>::Call(Abs, x);
}