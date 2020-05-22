#include "Brick.h"

void Brick::Init(const RectF & rect_in, Color color_in)
{
	rect = rect_in;
	c = color_in;
}

Brick::Brick(const RectF& rect_in, Color color_in)
	:
	rect(rect_in), 
	c(color_in)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if (!destroyed) {
		gfx.DrawRect(rect, c);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	RectF ballRect = ball.GetRect();
	if (rect.instanceCollision(ball.GetRect())) {
		if (ballRect.top > rect.top && ballRect.bottom < rect.bottom) {
			ball.ReboundX();
			destroyed = true;
			return true;
		}
		else {
			ball.ReboundY();
			destroyed = true;
			return true;
		}
	}
	return false;

}

void Brick::StretchX(float x)
{
	rect.right += x;
}

void Brick::StretchY(float y)
{
	rect.bottom += y;
}

RectF& Brick::GetRect()
{
	return rect;
}
