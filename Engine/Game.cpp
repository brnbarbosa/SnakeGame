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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(std::random_device()()),
	snake({0,0}),
	goal(rng,brd,snake)
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
	if (!gameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			if (direction != "down")
			{
				deltaLoc = { 0,-1 };
				direction = "up";
			}
			
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			if (direction != "up")
			{
				deltaLoc = { 0,1 };
				direction = "down";
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			if (direction != "left")
			{
				deltaLoc = { 1,0 };
				direction = "right";
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (direction != "right")
			{
				deltaLoc = { -1,0 };
				direction = "left";
			}
		}

		++snakeMovementCounter;
		if (snakeMovementCounter == SNAKEMOVEMENTPERIOD)
		{
			snakeMovementCounter = 0;
			const Location next = snake.GetNextHeadLocation(deltaLoc);
			if (!brd.InsideBoard(next) || snake.IsInTile(next))
			{
				gameOver = true;
			}
			else
			{
				const bool isEating = next == goal.GetLocation();
				if (isEating)
				{
					snake.Grow();
				}
				snake.MoveBy(deltaLoc);
				if (isEating)
				{
					goal.Respawn(rng, brd, snake);
				}
			}
		}
	}
	
}

void Game::ComposeFrame()
{
	brd.DrawBorder(gfx);
	snake.Draw(brd);
	goal.Draw(brd);

	if (gameOver) SpriteCodex::DrawGameOver(200, 200, gfx);
}
