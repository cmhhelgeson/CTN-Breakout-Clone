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
	pad(Vec2(400.0f, 500.0f), 50.0f, 15.0f)
{
	const Color colors[4] = { Colors::Red, Colors::Green, Colors::Blue, Colors::Cyan };
	const Vec2 topLeft(0.0f, 0.0f);

	for (int y = 0; y < nBricksDown; y++) {
		const Color c = colors[y];
		for (int x = 0; x < nBrickAcross; x++) {
			bricks[y * nBrickAcross + x] = Brick(
				RectF(topLeft + Vec2(x * brickWidth, y * brickHeight), 
				brickWidth - 1, brickHeight - 1), c);
		}
	}
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
	pad.Update(wnd.kbd, dt);
	pad.DoWallCollision(walls);
	ball.Update(dt);
	//if (brick.DoBallCollision(ball)) {
		//soundBrick.Play();
	//}
	if (pad.DoBallCollision(ball)) {
		soundBrick.Play();
	}
	if (ball.DoWallCollision(walls)) {
		soundPad.Play();
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
	ball.Draw(gfx);
	for (int y = 0; y < nBricksDown; y++) {
		for (int x = 0; x < nBrickAcross; x++) {
			bricks[y * nBrickAcross + x].Draw(gfx);
		}
	}
	pad.Draw(gfx);
}
