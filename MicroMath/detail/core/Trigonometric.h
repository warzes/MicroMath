#pragma once

//=============================================================================
// Trigonometry Functions
//=============================================================================

// Converts degrees to radians and returns the result.
inline constexpr float DegreesToRadians(float degrees);
template<template<typename T> class Vec, typename T> inline constexpr Vec<T> DegreesToRadians(const Vec<T>& v);
// Converts radians to degrees and returns the result.
inline constexpr float RadiansToDegrees(float radians);
template<template<typename T> class Vec, typename T> inline constexpr Vec<T> RadiansToDegrees(const Vec<T>& v);

// The standard trigonometric sine function. The values returned by this function will range from [-1, 1].
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sin(const Vec<T>& v);
// The standard trigonometric cosine function. The values returned by this function will range from [-1, 1].
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Cos(const Vec<T>& v);
// The standard trigonometric tangent function.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Tan(const Vec<T>& v);

// Arc sine. Returns an angle whose sine is x. The range of values returned by this function is [-PI/2, PI/2]. Results are undefined if |x| > 1.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> ASin(const Vec<T>& v);
// Arc cosine. Returns an angle whose cosine is x. The range of values returned by this function is [0, PI]. Results are undefined if |x| > 1.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> ACos(const Vec<T>& v);
// Arc tangent. Returns an angle whose tangent is y/x. The signs of x and y are used to determine what quadrant the angle is in. The range of values returned by this function is [-PI, PI]. Results are undefined if x and y are both 0.
inline const float ATan(float y, float x);
template<template<typename T> class Vec, typename T>
inline const Vec<T> ATan(const Vec<T>& y, const Vec<T>& x);
// Arc tangent. Returns an angle whose tangent is y_over_x. The range of values returned by this function is [-PI/2, PI/2].
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> ATan(const Vec<T>& y_over_x);
// Returns the hyperbolic sine function, (exp(x) - exp(-x)) / 2
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sinh(const Vec<T>& angle);
// Returns the hyperbolic cosine function, (exp(x) + exp(-x)) / 2
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Cosh(const Vec<T>& angle);
// Returns the hyperbolic tangent function, sinh(angle) / cosh(angle)
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Tanh(const Vec<T>& angle);
// Arc hyperbolic sine; returns the inverse of sinh.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Asinh(const Vec<T>& x);
// Arc hyperbolic cosine; returns the non-negative inverse of cosh. Results are undefined if x < 1.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Acosh(const Vec<T>& x);
// Arc hyperbolic tangent; returns the inverse of tanh. Results are undefined if abs(x) >= 1.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Atanh(const Vec<T>& x);

//=============================================================================
// Trigonometry Functions Impl
//=============================================================================

inline constexpr float DegreesToRadians(float degrees)
{
	return degrees * 0.01745329251994329576923690768489f;
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> DegreesToRadians(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(DegreesToRadians, v);
}

inline constexpr float RadiansToDegrees(float radians)
{
	return radians * 57.295779513082320876798154814105f;
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> RadiansToDegrees(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(RadiansToDegrees, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sin(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::sin, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Cos(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::cos, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Tan(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::tan, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> ASin(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::asin, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> ACos(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::acos, v);
}

inline const float ATan(float y, float x)
{
	return std::atan2(y, x);
}

template<template<typename T> class Vec, typename T>
inline const Vec<T> ATan(const Vec<T>& y, const Vec<T>& x)
{
	return detail::functor2<Vec, T>::Call(ATan, y, x);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> ATan(const Vec<T>& y_over_x)
{
	return detail::functor1<Vec, T>::Call(std::atan, y_over_x);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sinh(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::sinh, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Cosh(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::cosh, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Tanh(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::tanh, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Asinh(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::asinh, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Acosh(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::acosh, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Atanh(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::atanh, v);
}