/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include <vector>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f, 300.0f), Vec2(300.0f, 300.0f)),
	walls(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
	brick(RectF(40.0f, 60.0f, 100.0f, 500.0f), Colors::Green)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update(dt);
	bool wallCollide = ball.DoWallCollision(walls);
	if (wallCollide) {
		soundPad.Play();
	}
	bool paddleCollide = brick.DoBallCollision(ball);
	if (paddleCollide) {
		soundBrick.Play();
	}

	/*if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		brick.StretchX(1.0f);
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		brick.StretchX(-1.0f);
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		brick.StretchY(1.0f);
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP)) {
		brick.StretchY(-1.0f);
	}
	*/
}

void Game::ComposeFrame()
{
	std::vector<Vec2> vertVec = { Vec2(100.0f, 100.0f), Vec2(300.0f, 300.0f), { (float)wnd.mouse.GetPosX(), (float)wnd.mouse.GetPosY() } };
	gfx.DrawPolygon(vertVec, Colors::Red);
	gfx.DrawLine({ 100.0f, 100.f }, { (float)wnd.mouse.GetPosX(), (float)wnd.mouse.GetPosY() }, Colors::White);
	/*Vec2 FindDistance Test
		float dist = Vec2(100.0f, 100.0f).FindDistance({ (float)wnd.mouse.GetPosX(), (float)wnd.mouse.GetPosY() });
		gfx.DrawLine({ 100.0f, 400.0f }, { 100.0f + dist, 400.0f }, Colors::Blue); 
	*/
	//gfx.DrawLine({ 100.0f, 100.0f }, { (float)wnd.mouse.GetPos().first, (float)wnd.mouse.GetPos().second }, Colors::White);
	brick.Draw(gfx);
	ball.Draw(gfx);
}
