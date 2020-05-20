#pragma once

#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
class Paddle {
public:
	Paddle(const Vec2& in_pos, float in_hWidth, float in_hHeight);
	void Draw(Graphics& gfx);
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
private:
	Color c = Colors::White;
	Vec2 pos;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;


};