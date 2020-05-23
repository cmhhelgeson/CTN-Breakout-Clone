#pragma once

#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
public:
	Brick() = default;
	void Init(const RectF& rect_in, Color color_in);
	Brick(const RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
	void StretchX(float x);
	void StretchY(float y);
	RectF& GetRect();
	bool GetDestroyed() {
		return destroyed;
	}
private:
	RectF rect;
	Color c;
	bool destroyed = false;
	float padding = 1.0f;
};