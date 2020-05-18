#pragma once

#include "Vec2.h"

class RectF {
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool instanceCollision(const RectF& other);
	static RectF RectFromCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float left;
	float right;
	float bottom;
	float top;
};