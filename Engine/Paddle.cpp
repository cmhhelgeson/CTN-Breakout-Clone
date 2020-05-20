#include "Paddle.h"

Paddle::Paddle(const Vec2 & in_pos, float in_hWidth, float in_hHeight) 
	:
	pos(in_pos),
	halfWidth(in_hWidth),
	halfHeight(in_hHeight)
{
}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetRect(), c);
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	if (GetRect().instanceCollision(ball.GetRect())) {
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF & walls)
{
	const RectF rect = GetRect();
	if (rect.left < walls.left) {
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right) {
		pos.x -= rect.right - walls.right;
	}

}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::RectFromCenter(pos, halfWidth, halfHeight);
}
