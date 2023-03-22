#pragma once

//=============================================================================
// Quaternion
//=============================================================================

template<typename T>
class Quat
{
public:
	static inline constexpr size_t length = 4;

	constexpr Quat() = default;
	constexpr Quat(const Quat&) = default;
	constexpr explicit Quat(T scalar);
	constexpr Quat(T s, const Vec3<T>& v);
	constexpr Quat(T nw, T nx, T ny, T nz);
	// Create a quaternion from two normalized axis
	// http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
	Quat(const Vec3<T>& u, const Vec3<T>& v);
	// Build a quaternion from euler angles (pitch, yaw, roll), in radians.
	constexpr explicit Quat(const Vec3<T>& eulerAngles);

	explicit Quat(const Mat3<T>& q);
	explicit Quat(const Mat4<T>& q);

	constexpr Quat& operator=(const Quat&) = default;

	explicit operator Mat3<T>() const;
	explicit operator Mat4<T>() const;

	constexpr T& operator[](size_t i);
	constexpr T const& operator[](size_t i) const;

	T w, x, y, z;
};

// TODO: доделать

//=============================================================================
// Quaternion operator
//=============================================================================
template<typename T> bool operator==(const Quat<T>& left, const Quat<T>& right);
template<typename T> bool operator!=(const Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T> operator-(const Quat<T>& in);
template<typename T> Quat<T> operator-(T left, const Quat<T>& right);
template<typename T> Quat<T> operator-(const Quat<T>& left, T right);
template<typename T> Quat<T> operator-(const Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T>& operator-=(Quat<T>& left, T right);
template<typename T> Quat<T>& operator-=(Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T> operator+(T left, const Quat<T>& right);
template<typename T> Quat<T> operator+(const Quat<T>& left, T right);
template<typename T> Quat<T> operator+(const Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T>& operator+=(Quat<T>& left, T right);
template<typename T> Quat<T>& operator+=(Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T> operator*(T left, const Quat<T>& right);
template<typename T> Quat<T> operator*(const Quat<T>& left, T right);
template<typename T> Quat<T> operator*(const Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T>& operator*=(Quat<T>& left, T right);
template<typename T> Quat<T>& operator*=(Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T> operator/(T left, const Quat<T>& right);
template<typename T> Quat<T> operator/(const Quat<T>& left, T right);
template<typename T> Quat<T> operator/(const Quat<T>& left, const Quat<T>& right);
template<typename T> Quat<T>& operator/=(Quat<T>& left, T right);
template<typename T> Quat<T>& operator/=(Quat<T>& left, const Quat<T>& right);

//=============================================================================
// Quaternion Impl
//=============================================================================

template<typename T> MM_INLINE constexpr Quat<T>::Quat(T scalar) : w(scalar), x(scalar), y(scalar), z(scalar) {}
template<typename T> MM_INLINE constexpr Quat<T>::Quat(T nw, T nx, T ny, T nz) : w(nw), x(nx), y(ny), z(nz) {}

template<typename T> MM_INLINE constexpr T& Quat<T>::operator[](size_t i) { MM_ASSERT(i < Quat<T>::length); return (&x)[i]; }
template<typename T> MM_INLINE constexpr T const& Quat<T>::operator[](size_t i) const { MM_ASSERT(i < Quat<T>::length); return (&x)[i]; }

template<typename T> MM_INLINE bool operator==(const Quat<T>& left, const Quat<T>& right) { return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w; }
template<typename T> MM_INLINE bool operator!=(const Quat<T>& left, const Quat<T>& right) { return left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w; }

template<typename T> MM_INLINE Quat<T> operator-(const Quat<T>& in) { return { -in.x, -in.y, -in.z, -in.w }; }

#define Vector4OperatorImpl(op) \
template<typename T> MM_INLINE Quat<T> operator op(T l, const Quat<T>& r) { return { l op r.x, l op r.y, l op r.z, l op r.w }; } \
template<typename T> MM_INLINE Quat<T> operator op(const Quat<T>& l, T r) { return { l.x op r, l.y op r, l.z op r, l.w op r }; } \
template<typename T> MM_INLINE Quat<T> operator op(const Quat<T>& l, const Quat<T>& r) { return { l.x op r.x, l.y op r.y, l.z op r.z, l.w op r.w }; } \
template<typename T> MM_INLINE Quat<T>& operator##op##=(Quat<T>& l, T r) { return l = l op r; } \
template<typename T> MM_INLINE Quat<T>& operator##op##=(Quat<T>& l, Quat<T>& r){ return l = l op r; }

Vector4OperatorImpl(-);
Vector4OperatorImpl(+);
Vector4OperatorImpl(*);
Vector4OperatorImpl(/ );

#undef Vector4OperatorImpl