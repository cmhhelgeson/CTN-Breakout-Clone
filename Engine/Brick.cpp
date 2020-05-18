#include "Brick.h"

Brick::Brick(const RectF& rect_in, Color color_in)
	:
	rect(rect_in), 
	c(color_in)
{
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, c);
}

void Brick::StretchX(float x)
{
	rect.right += x;
}

void Brick::StretchY(float y)
{
	rect.bottom += y;
}
