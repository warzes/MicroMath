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