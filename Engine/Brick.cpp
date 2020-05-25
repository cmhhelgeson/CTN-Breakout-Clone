#include "Brick.h"
#include <assert.h>

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
		gfx.DrawRect((rect.GetExpanded(-padding)), c);
	}
}

bool Brick::CheckBallCollision(const Ball& ball) {
	return !destroyed && rect.instanceCollision(ball.GetRect());
}

bool Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 BallPos = ball.GetPosition();
	if (BallPos.x >= rect.left && BallPos.x <= rect.right) {
		ball.ReboundY();
	} else {
		ball.ReboundX();
	}
	destroyed = true;
	return true;

}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
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
