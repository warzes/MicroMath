#pragma once

//=============================================================================
// Vector2 Impl
//=============================================================================

template<typename T> MM_INLINE constexpr Vec2<T>::Vec2(T scalar) : x(scalar), y(scalar) {}
template<typename T> MM_INLINE constexpr Vec2<T>::Vec2(T nx, T ny) : x(nx), y(ny) {}

template<typename T> MM_INLINE constexpr Vec2<T>& Vec2<T>::operator=(T scalar) { x = y = scalar; return *this; }

template<typename T> MM_INLINE constexpr T& Vec2<T>::operator[](size_t i) { MM_ASSERT(i < 2); return (&x)[i]; }
template<typename T> MM_INLINE constexpr T const& Vec2<T>::operator[](size_t i) const { MM_ASSERT(i < 2); return (&x)[i]; }

template<typename T> MM_INLINE bool operator==(const Vec2<T>& left, const Vec2<T>& right) noexcept { return left.x == right.x && left.y == right.y; }
template<typename T> MM_INLINE bool operator!=(const Vec2<T>& left, const Vec2<T>& right) noexcept { return left.x != right.x || left.y != right.y; }

template<typename T> MM_INLINE Vec2<T> operator-(const Vec2<T>& in) noexcept { return { -in.x, -in.y }; }

#define Vector2OperatorImpl(op) \
template<typename T> MM_INLINE Vec2<T> operator op(T l, const Vec2<T>& r) noexcept { return { l op r.x, l op r.y }; } \
template<typename T> MM_INLINE Vec2<T> operator op(const Vec2<T>& l, T r) noexcept { return { l.x op r, l.y op r }; } \
template<typename T> MM_INLINE Vec2<T> operator op(const Vec2<T>& l, const Vec2<T>& r) noexcept { return { l.x op r.x, l.y op r.y }; } \
template<typename T> MM_INLINE Vec2<T>& operator##op##=(Vec2<T>& l, T r) noexcept { return l = l op r; } \
template<typename T> MM_INLINE Vec2<T>& operator##op##=(Vec2<T>& l, Vec2<T>& r) noexcept{ return l = l op r; }

Vector2OperatorImpl(-);
Vector2OperatorImpl(+);
Vector2OperatorImpl(*);
Vector2OperatorImpl(/);

#undef Vector2OperatorImpl
