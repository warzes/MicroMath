#pragma once

//=============================================================================
// Vector2
//=============================================================================

template<typename T> 
class Vec2
{
public:
	typedef T valueType;
	typedef Vec2<T> type;
	static inline constexpr size_t length = 2;

	constexpr Vec2() = default;
	constexpr Vec2(const Vec2&) = default;
	constexpr explicit Vec2(T scalar);
	constexpr Vec2(T nx, T ny);

	constexpr Vec2& operator=(const Vec2&) = default;
	constexpr Vec2& operator=(T scalar);

	constexpr T& operator[](size_t i);
	constexpr T const& operator[](size_t i) const;

	T x, y;
};

//=============================================================================
// Vector3
//=============================================================================

template<typename T>
class Vec3
{
public:
	typedef T valueType;
	typedef Vec3<T> type;
	static inline constexpr size_t length = 3;

	constexpr Vec3() = default;
	constexpr Vec3(const Vec3&) = default;
	constexpr explicit Vec3(T scalar);
	constexpr Vec3(T nx, T ny, T nz);

	constexpr Vec3& operator=(const Vec3&) = default;
	constexpr Vec3& operator=(T scalar);

	constexpr T& operator[](size_t i);
	constexpr T const& operator[](size_t i) const;

	T x, y, z;
};

//=============================================================================
// Vector4
//=============================================================================

template<typename T>
class Vec4
{
public:
	typedef T valueType;
	typedef Vec4<T> type;
	static inline constexpr size_t length = 4;

	constexpr Vec4() = default;
	constexpr Vec4(const Vec4&) = default;
	constexpr explicit Vec4(T scalar);
	constexpr Vec4(T nx, T ny, T nz, T nw);

	constexpr Vec4& operator=(const Vec4&) = default;
	constexpr Vec4& operator=(T scalar);

	constexpr T& operator[](size_t i);
	constexpr T const& operator[](size_t i) const;

	T x, y, z, w;
};

//=============================================================================
// Vector operator
//=============================================================================


// Vector2
template<typename T> bool operator==(const Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> bool operator!=(const Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator-(const Vec2<T>& in) noexcept;
template<typename T> Vec2<T> operator-(T left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator-(const Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T> operator-(const Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T>& operator-=(Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T>& operator-=(Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator+(T left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator+(const Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T> operator+(const Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T>& operator+=(Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T>& operator+=(Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator*(T left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator*(const Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T> operator*(const Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T>& operator*=(Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T>& operator*=(Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator/(T left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T> operator/(const Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T> operator/(const Vec2<T>& left, const Vec2<T>& right) noexcept;
template<typename T> Vec2<T>& operator/=(Vec2<T>& left, T right) noexcept;
template<typename T> Vec2<T>& operator/=(Vec2<T>& left, const Vec2<T>& right) noexcept;

// Vector3
template<typename T> bool operator==(const Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> bool operator!=(const Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator-(const Vec3<T>& in) noexcept;
template<typename T> Vec3<T> operator-(T left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator-(const Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T> operator-(const Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T>& operator-=(Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T>& operator-=(Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator+(T left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator+(const Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T> operator+(const Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T>& operator+=(Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T>& operator+=(Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator*(T left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator*(const Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T> operator*(const Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T>& operator*=(Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T>& operator*=(Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator/(T left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T> operator/(const Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T> operator/(const Vec3<T>& left, const Vec3<T>& right) noexcept;
template<typename T> Vec3<T>& operator/=(Vec3<T>& left, T right) noexcept;
template<typename T> Vec3<T>& operator/=(Vec3<T>& left, const Vec3<T>& right) noexcept;

// Vector4
template<typename T> bool operator==(const Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> bool operator!=(const Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator-(const Vec4<T>& in) noexcept;
template<typename T> Vec4<T> operator-(T left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator-(const Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T> operator-(const Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T>& operator-=(Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T>& operator-=(Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator+(T left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator+(const Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T> operator+(const Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T>& operator+=(Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T>& operator+=(Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator*(T left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator*(const Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T> operator*(const Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T>& operator*=(Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T>& operator*=(Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator/(T left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T> operator/(const Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T> operator/(const Vec4<T>& left, const Vec4<T>& right) noexcept;
template<typename T> Vec4<T>& operator/=(Vec4<T>& left, T right) noexcept;
template<typename T> Vec4<T>& operator/=(Vec4<T>& left, const Vec4<T>& right) noexcept;

//=============================================================================
// Vector2 Impl
//=============================================================================

template<typename T> MM_INLINE constexpr Vec2<T>::Vec2(T scalar) : x(scalar), y(scalar) {}
template<typename T> MM_INLINE constexpr Vec2<T>::Vec2(T nx, T ny) : x(nx), y(ny) {}

template<typename T> MM_INLINE constexpr Vec2<T>& Vec2<T>::operator=(T scalar) { x = y = scalar; return *this; }

template<typename T> MM_INLINE constexpr T& Vec2<T>::operator[](size_t i) { MM_ASSERT(i < Vec2<T>::length); return (&x)[i]; }
template<typename T> MM_INLINE constexpr T const& Vec2<T>::operator[](size_t i) const { MM_ASSERT(i < Vec2<T>::length); return (&x)[i]; }

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
Vector2OperatorImpl(/ );

#undef Vector2OperatorImpl

//=============================================================================
// Vector3 Impl
//=============================================================================

template<typename T> MM_INLINE constexpr Vec3<T>::Vec3(T scalar) : x(scalar), y(scalar), z(scalar) {}
template<typename T> MM_INLINE constexpr Vec3<T>::Vec3(T nx, T ny, T nz) : x(nx), y(ny), z(nz) {}

template<typename T> MM_INLINE constexpr Vec3<T>& Vec3<T>::operator=(T scalar) { x = y = z = scalar; return *this; }

template<typename T> MM_INLINE constexpr T& Vec3<T>::operator[](size_t i) { MM_ASSERT(i < Vec3<T>::length); return (&x)[i]; }
template<typename T> MM_INLINE constexpr T const& Vec3<T>::operator[](size_t i) const { MM_ASSERT(i < Vec3<T>::length); return (&x)[i]; }

template<typename T> MM_INLINE bool operator==(const Vec3<T>& left, const Vec3<T>& right) noexcept { return left.x == right.x && left.y == right.y && left.z == right.z; }
template<typename T> MM_INLINE bool operator!=(const Vec3<T>& left, const Vec3<T>& right) noexcept { return left.x != right.x || left.y != right.y || left.z != right.z; }

template<typename T> MM_INLINE Vec3<T> operator-(const Vec3<T>& in) noexcept { return { -in.x, -in.y, -in.z }; }

#define Vector3OperatorImpl(op) \
template<typename T> MM_INLINE Vec3<T> operator op(T l, const Vec3<T>& r) noexcept { return { l op r.x, l op r.y, l op r.z }; } \
template<typename T> MM_INLINE Vec3<T> operator op(const Vec3<T>& l, T r) noexcept { return { l.x op r, l.y op r, l.z op r }; } \
template<typename T> MM_INLINE Vec3<T> operator op(const Vec3<T>& l, const Vec3<T>& r) noexcept { return { l.x op r.x, l.y op r.y, l.z op r.z }; } \
template<typename T> MM_INLINE Vec3<T>& operator##op##=(Vec3<T>& l, T r) noexcept { return l = l op r; } \
template<typename T> MM_INLINE Vec3<T>& operator##op##=(Vec3<T>& l, Vec3<T>& r) noexcept{ return l = l op r; }

Vector3OperatorImpl(-);
Vector3OperatorImpl(+);
Vector3OperatorImpl(*);
Vector3OperatorImpl(/ );

#undef Vector3OperatorImpl

//=============================================================================
// Vector4 Impl
//=============================================================================

template<typename T> MM_INLINE constexpr Vec4<T>::Vec4(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
template<typename T> MM_INLINE constexpr Vec4<T>::Vec4(T nx, T ny, T nz, T nw) : x(nx), y(ny), z(nz), w(nw) {}

template<typename T> MM_INLINE constexpr Vec4<T>& Vec4<T>::operator=(T scalar) { x = y = z = w = scalar; return *this; }

template<typename T> MM_INLINE constexpr T& Vec4<T>::operator[](size_t i) { MM_ASSERT(i < Vec4<T>::length); return (&x)[i]; }
template<typename T> MM_INLINE constexpr T const& Vec4<T>::operator[](size_t i) const { MM_ASSERT(i < Vec4<T>::length); return (&x)[i]; }

template<typename T> MM_INLINE bool operator==(const Vec4<T>& left, const Vec4<T>& right) noexcept { return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w; }
template<typename T> MM_INLINE bool operator!=(const Vec4<T>& left, const Vec4<T>& right) noexcept { return left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w; }

template<typename T> MM_INLINE Vec4<T> operator-(const Vec4<T>& in) noexcept { return { -in.x, -in.y, -in.z, -in.w }; }

#define Vector4OperatorImpl(op) \
template<typename T> MM_INLINE Vec4<T> operator op(T l, const Vec4<T>& r) noexcept { return { l op r.x, l op r.y, l op r.z, l op r.w }; } \
template<typename T> MM_INLINE Vec4<T> operator op(const Vec4<T>& l, T r) noexcept { return { l.x op r, l.y op r, l.z op r, l.w op r }; } \
template<typename T> MM_INLINE Vec4<T> operator op(const Vec4<T>& l, const Vec4<T>& r) noexcept { return { l.x op r.x, l.y op r.y, l.z op r.z, l.w op r.w }; } \
template<typename T> MM_INLINE Vec4<T>& operator##op##=(Vec4<T>& l, T r) noexcept { return l = l op r; } \
template<typename T> MM_INLINE Vec4<T>& operator##op##=(Vec4<T>& l, Vec4<T>& r) noexcept{ return l = l op r; }

Vector4OperatorImpl(-);
Vector4OperatorImpl(+);
Vector4OperatorImpl(*);
Vector4OperatorImpl(/ );

#undef Vector4OperatorImpl