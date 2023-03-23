#pragma once

//=============================================================================
// Matrix3
//=============================================================================

template<typename T>
class Mat3
{
public:
	typedef Vec3<T> col_type;
	typedef Vec3<T> row_type;
	typedef Mat3<T> type;
	typedef Mat3<T> transpose_type;
	typedef T value_type;
	static inline constexpr size_t length = 3;

	constexpr Mat3() = default;
	constexpr Mat3(const Mat3&) = default;
	explicit constexpr Mat3(T scalar);
	constexpr Mat3(
		T x0, T y0, T z0,
		T x1, T y1, T z1,
		T x2, T y2, T z2);
	constexpr Mat3(
		const Vec3<T>& v0,
		const Vec3<T>& v1,
		const Vec3<T>& v2);
	constexpr Mat3(const Mat4<T>& m);

	constexpr Mat3& operator=(const Mat3&) = default;

	constexpr Vec3<T>& operator[](size_t i);
	constexpr Vec3<T> const& operator[](size_t i) const;

	Vec3<T> value[3];
};

//=============================================================================
// Matrix4
//=============================================================================


//=============================================================================
// Matrix operator
//=============================================================================

// Matrix3
template<typename T> bool operator==(const Mat3<T>& left, const Mat3<T>& right);
template<typename T> bool operator!=(const Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T> operator-(const Mat3<T>& in);
template<typename T> Mat3<T> operator-(T left, const Mat3<T>& right);
template<typename T> Mat3<T> operator-(const Mat3<T>& left, T right);
template<typename T> Mat3<T> operator-(const Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T>& operator-=(Mat3<T>& left, T right);
template<typename T> Mat3<T>& operator-=(Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T> operator+(T left, const Mat3<T>& right);
template<typename T> Mat3<T> operator+(const Mat3<T>& left, T right);
template<typename T> Mat3<T> operator+(const Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T>& operator+=(Mat3<T>& left, T right);
template<typename T> Mat3<T>& operator+=(Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T> operator*(T left, const Mat3<T>& right);
template<typename T> Mat3<T> operator*(const Mat3<T>& left, T right);
template<typename T> Mat3<T> operator*(const Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T>& operator*=(Mat3<T>& left, T right);
template<typename T> Mat3<T>& operator*=(Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T> operator/(T left, const Mat3<T>& right);
template<typename T> Mat3<T> operator/(const Mat3<T>& left, T right);
template<typename T> Mat3<T> operator/(const Mat3<T>& left, const Mat3<T>& right);
template<typename T> Mat3<T>& operator/=(Mat3<T>& left, T right);
template<typename T> Mat3<T>& operator/=(Mat3<T>& left, const Mat3<T>& right);

template<typename T> Vec3<T> operator*(const Mat3<T>& left, const Vec3<T>& right);
template<typename T> Vec3<T> operator*(const Vec3<T>& left, const Mat3<T>& right);
template<typename T> Vec3<T> operator/(const Mat3<T>& left, const Vec3<T>& right);
template<typename T> Vec3<T> operator/(const Vec3<T>& left, const Mat3<T>& right);

//=============================================================================
// Matrix3 Impl
//=============================================================================

template<typename T>
inline constexpr Mat3<T>::Mat3(T scalar) 
	:  value{ Vec3<T>(s, 0, 0), Vec3<T>(0, s, 0), Vec3<T>(0, 0, s) }
{
}

template<typename T>
inline constexpr Mat3<T>::Mat3(
	T x0, T y0, T z0,
	T x1, T y1, T z1,
	T x2, T y2, T z2)
	: value{ Vec3<T>(x0, y0, z0), Vec3<T>(x1, y1, z1), Vec3<T>(x2, y2, z2) }
{
}

template<typename T>
inline constexpr Mat3<T>::Mat3(const Vec3<T>& v0, const Vec3<T>& v1, const Vec3<T>& v2)
	: value{ Vec3<T>(v0), Vec3<T>(v1), Vec3<T>(v2) }
{
}

template<typename T>
inline constexpr Mat3<T>::Mat3(const Mat4<T>& m)
	: value{ Vec3<T>(m[0]), Vec3<T>(m[1]), Vec3<T>(m[2]) }
{
}

template<typename T>
inline constexpr Vec3<T>& Mat3<T>::operator[](size_t i)
{
	MM_ASSERT(i < length);
	return value[i];
}

template<typename T>
inline constexpr Vec3<T> const& Mat3<T>::operator[](size_t i) const
{
	MM_ASSERT(i < length);
	return value[i];
}

template<typename T>
inline bool operator==(const Mat3<T>& m1, const Mat3<T>& m2)
{
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

template<typename T>
inline bool operator!=(const Mat3<T>& m1, const Mat3<T>& m2)
{
	return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]);
}

template<typename T>
inline Mat3<T> operator-(const Mat3<T>& in)
{
	return { -m[0], -m[1], -m[2] };
}

template<typename T>
inline Mat3<T> operator-(T left, const Mat3<T>& right)
{
	return { left - right[0], left - right[1], left - right[2] };
}

template<typename T>
inline Mat3<T> operator-(const Mat3<T>& left, T right)
{
	return { left[0] - right, left[1] - right, left[2] - right };
}

template<typename T>
inline Mat3<T> operator-(const Mat3<T>& left, const Mat3<T>& right)
{
	return { left[0] - right[0], left[1] - right[1], left[2] - right[2] };
}

template<typename T>
inline Mat3<T>& operator-=(Mat3<T>& left, T right)
{
	return left = left - right;
}

template<typename T>
inline Mat3<T>& operator-=(Mat3<T>& left, const Mat3<T>& right)
{
	return left = left - right;
}

template<typename T>
inline Mat3<T> operator+(T left, const Mat3<T>& right)
{
	return { left + right[0], left + right[1], left + right[2] };
}

template<typename T>
inline Mat3<T> operator+(const Mat3<T>& left, T right)
{
	return { left[0] + right, left[1] + right, left[2] + right };
}

template<typename T>
inline Mat3<T> operator+(const Mat3<T>& left, const Mat3<T>& right)
{
	return { left[0] + right[0], left[1] + right[1], left[2] + right[2] };
}


template<typename T>
inline Mat3<T>& operator+=(Mat3<T>& left, T right)
{
	return left = left + right;
}

template<typename T>
inline Mat3<T>& operator+=(Mat3<T>& left, const Mat3<T>& right)
{
	return left = left + right;
}

template<typename T>
inline Mat3<T> operator*(T left, const Mat3<T>& right)
{
	return { left * right[0], left * right[1], left * right[2] };
}

template<typename T>
inline Mat3<T> operator*(const Mat3<T>& left, T right)
{
	return { left[0] * right, left[1] * right, left[2] * right };
}

template<typename T>
inline Mat3<T> operator*(const Mat3<T>& m1, const Mat3<T>& m2)
{
	T const SrcA00 = m1[0][0];
	T const SrcA01 = m1[0][1];
	T const SrcA02 = m1[0][2];
	T const SrcA10 = m1[1][0];
	T const SrcA11 = m1[1][1];
	T const SrcA12 = m1[1][2];
	T const SrcA20 = m1[2][0];
	T const SrcA21 = m1[2][1];
	T const SrcA22 = m1[2][2];

	T const SrcB00 = m2[0][0];
	T const SrcB01 = m2[0][1];
	T const SrcB02 = m2[0][2];
	T const SrcB10 = m2[1][0];
	T const SrcB11 = m2[1][1];
	T const SrcB12 = m2[1][2];
	T const SrcB20 = m2[2][0];
	T const SrcB21 = m2[2][1];
	T const SrcB22 = m2[2][2];

	Mat3<T> Result;
	Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01 + SrcA20 * SrcB02;
	Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01 + SrcA21 * SrcB02;
	Result[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01 + SrcA22 * SrcB02;
	Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11 + SrcA20 * SrcB12;
	Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11 + SrcA21 * SrcB12;
	Result[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11 + SrcA22 * SrcB12;
	Result[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21 + SrcA20 * SrcB22;
	Result[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21 + SrcA21 * SrcB22;
	Result[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21 + SrcA22 * SrcB22;
	return Result;
}

template<typename T>
inline Mat3<T>& operator*=(Mat3<T>& left, T right)
{
	return left = left * right;
}

template<typename T>
inline Mat3<T>& operator*=(Mat3<T>& left, const Mat3<T>& right)
{
	return left = left * right;
}

template<typename T>
inline Mat3<T> operator/(T left, const Mat3<T>& right)
{
	return { left / right[0], left / right[1], left / right[2] };
}

template<typename T>
inline Mat3<T> operator/(const Mat3<T>& left, T right)
{
	return { left[0] / right, left[1] / right, left[2] / right };
}

template<typename T>
inline Mat3<T> operator/(const Mat3<T>& left, const Mat3<T>& right)
{
}

template<typename T>
inline Mat3<T>& operator/=(Mat3<T>& left, T right)
{
	return left = left / right;
}

template<typename T>
inline Mat3<T>& operator/=(Mat3<T>& left, const Mat3<T>& right)
{
	// TODO: вставьте здесь оператор return
}