#pragma once

//=============================================================================
// Exponential Functions
//=============================================================================

// Returns 'base' raised to the power 'exponent'.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Pow(const Vec<T>& base, const Vec<T>& exponent);

// Returns the natural exponentiation of v, i.e., e^v.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Exp(const Vec<T>& v);

// Returns the natural logarithm of v, i.e., returns the value y which satisfies the equation x = e^y. Results are undefined if v <= 0.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Log(const Vec<T>& v);

// Returns 2 raised to the v power.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Exp2(const Vec<T>& v);

// Returns the base 2 log of x, i.e., returns the value y, which satisfies the equation x = 2 ^ y.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Log2(const Vec<T>& v);

// Returns the positive square root of v.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sqrt(const Vec<T>& v);

// Returns the reciprocal of the positive square root of v.
template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> InverseSqrt(const Vec<T>& v);

//=============================================================================
// Exponential Functions Impl
//=============================================================================

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Pow(const Vec<T>& base, const Vec<T>& exponent)
{
	return detail::functor2<Vec, T>::Call(std::pow, base, exponent);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Exp(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::exp, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Log(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::log, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Exp2(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::exp2, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Log2(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::log2, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> Sqrt(const Vec<T>& v)
{
	return detail::functor1<Vec, T>::Call(std::sqrt, v);
}

template<template<typename T> class Vec, typename T>
inline constexpr Vec<T> InverseSqrt(const Vec<T>& v)
{
	return static_cast<T>(1) / Sqrt(v);
}
