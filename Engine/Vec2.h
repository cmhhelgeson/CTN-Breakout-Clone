#pragma once

template<typename T>
class Vec2
{
public:
	Vec2() = default;
	Vec2::Vec2(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	Vec2 Vec2::operator+(const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}

	Vec2& Vec2::operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2 Vec2::operator*(T rhs) const
	{
		return Vec2(x * rhs, y * rhs);
	}

	Vec2& Vec2::operator*=(T rhs)
	{
		return *this = *this * rhs;
	}

	Vec2 Vec2::operator-(const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	Vec2& Vec2::operator-=(const Vec2& rhs)
	{
		return *this = *this - rhs;
	}

	T Vec2::GetLength() const
	{
		return (T)std::sqrt(GetLengthSq());
	}

	T Vec2::GetLengthSq() const
	{
		return (T)(x * x + y * y);
	}

	Vec2& Vec2::Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2 Vec2::GetNormalized() const
	{
		const float len = GetLength();
		if (len != (T)0)
		{
			return *this * ((T)1 / len);
		}
		return *this;
	}

	T Vec2::FindDistance(const Vec2& rhs) const
	{
		T a = x - rhs.x;
		T b = y - rhs.y;
		return sqrt((a * a) + (b * b));
	}
	Vec2() = default;
	Vec2( float x_in,float y_in );
	Vec2 operator+( const Vec2& rhs ) const;
	Vec2& operator+=( const Vec2& rhs );
	Vec2 operator*( float rhs ) const;
	Vec2& operator*=( float rhs );
	Vec2 operator-( const Vec2& rhs ) const;
	Vec2& operator-=( const Vec2& rhs );
	float GetLength() const;
	float GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalized() const;
	float FindDistance(const Vec2& rhs) const;
public:
	T x;
	T y;
};

typedef Vec2<int> Veci;