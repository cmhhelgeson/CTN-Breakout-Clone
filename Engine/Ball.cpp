#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	velocity(vel_in)
{
}

void Ball::Draw(Graphics & gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

RectF Ball::getRect()
{
	return RectF::RectFromCenter(pos, radius, radius);
}
