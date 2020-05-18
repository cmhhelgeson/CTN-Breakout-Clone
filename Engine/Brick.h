#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"


class Brick {
public:
	Brick(const RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx) const;
	void StretchX(float x);
	void StretchY(float y);
private:
	RectF rect;
	Color c;
	bool destroyed;
};