#pragma once

template<typename T>
class Vec2_
{
public:
	Vec2_() = default;
	Vec2_(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	Vec2_ Vec2_::operator+(const Vec2_& rhs) const
	{
		return Vec2_(x + rhs.x, y + rhs.y);
	}

	Vec2_& Vec2_::operator+=(const Vec2_& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2_ Vec2_::operator*(T rhs) const
	{
		return Vec2_(x * rhs, y * rhs);
	}

	Vec2_& Vec2_::operator*=(T rhs)
	{
		return *this = *this * rhs;
	}

	Vec2_ Vec2_::operator-(const Vec2_& rhs) const
	{
		return Vec2_(x - rhs.x, y - rhs.y);
	}

	Vec2_& Vec2_::operator-=(const Vec2_& rhs)
	{
		return *this = *this - rhs;
	}

	T Vec2_::GetLength() const
	{
		return (T)std::sqrt(GetLengthSq());
	}

	T Vec2_::GetLengthSq() const
	{
		return x * x + y * y;
	}

	Vec2_& Vec2_::Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2_ Vec2_::GetNormalized() const
	{
		const float len = GetLength();
		if (len != (T)0)
		{
			return *this * ((T)1 / len);
		}
		return *this;
	}

	T Vec2_::FindDistance(const Vec2_& rhs) const
	{
		T a = x - rhs.x;
		T b = y - rhs.y;
		return sqrt((a * a) + (b * b));
	}
public:
	T x;
	T y;
};


typedef Vec2_<float> Vec2;
typedef Vec2_<int> Vei2;
typedef Vec2_<double> Ved2;