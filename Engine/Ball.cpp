#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
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
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right) {
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	} 
	if (rect.top < walls.top) {
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom) {
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
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

Vec2 Ball::GetVelocity() const
{
	return velocity;
}

Vec2 Ball::GetPosition() const
{
	return pos;
}
