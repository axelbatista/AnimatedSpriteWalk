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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	character(300,200)
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
	if (wnd.kbd.KeyIsPressed('A')) {
		if (animate.getState() != Animation::state::left) {				//character.move sets the speed of the character.
			animate.setState(Animation::state::left);
		}
		character.move(-2, 0);
		animate.passTime(0,5);
	}
	else if (wnd.kbd.KeyIsPressed('D')) {
		if (animate.getState() != Animation::state::right) {
			animate.setState(Animation::state::right);
		}
		character.move(2, 0);
		animate.passTime(5,10);
	}
	else if (wnd.kbd.KeyIsPressed('W')) {
		if (animate.getState() != Animation::state::back) {
			animate.setState(Animation::state::back);
		}
		character.move(0, -2);
		animate.passTime(10,15);
	}
	else if (wnd.kbd.KeyIsPressed('S')) {
		if (animate.getState() != Animation::state::front) {
			animate.setState(Animation::state::front);
		}
		character.move(0, 2);
		animate.passTime(15,20);
	}
	else {
		animate.setToNoMovement();				//doesn't make sense to have the character suspended in air if there is no movement.
	}
}

void Game::ComposeFrame()
{
	animate.draw(character.spot.x, character.spot.y,gfx);
}
