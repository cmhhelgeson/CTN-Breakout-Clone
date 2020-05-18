#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	velocity(vel_in)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += velocity * dt;
}

bool Ball::DoWallCollision(const RectF & walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left) {
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right) {
		ReboundX();
		collided = true;
	} 
	if (rect.top < walls.top) {
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom) {
		ReboundY();
		collided = true;
	}
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

RectF Ball::GetRect() const
{
	return RectF::RectFromCenter(pos, radius, radius);
}
