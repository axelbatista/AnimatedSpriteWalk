#include "Animation.h"


void Animation::draw(int x, int y, Graphics& gfx)
{
	sprite.drawSprite(x, y, array[currentFrame],gfx);			//this is the frame to be drawn with the position of the character at the time. 
}

void Animation::passTime(int x, int limit)
{
	if (toPlay >= threshold) {									//have a certain amount of time pass before we move onto the next frame in a certain animation (either left, right, etc).
		advance(x,limit);
		toPlay = 0;
	}
	toPlay++;
}

void Animation::advance(int x, int limit)
{
	if (++currentFrame >= limit) {					//left animations for walking for example are the first five frames.
		currentFrame = x;							//we cycle between those frames if we are still stuck moving left.
	}												//increment it upwards until you hit the limit and then start the cycle again.
}

void Animation::setState(state type)
{
	if (type == Animation::state::left) {
		movement = type;
		currentFrame = 0;
	}
	else if (type == Animation::state::right) {					//set the movement here and the start of an animation movement cycle.
		movement = type;										//left starts from 0 and ends at 4 inclusive, right from 5 to 9 inclusive, and so on.
		currentFrame = 5;
	}
	else if (type == Animation::state::back) {
		movement = type;
		currentFrame = 10;
	}
	else if (type == Animation::state::front) {
		movement = type;
		currentFrame = 15;										
	}
}

Animation::state Animation::getState() const
{
	return movement;
}

void Animation::setToNoMovement()
{
	switch (movement) {
		case Animation::state::left:
		currentFrame = 0;
		break;
		case Animation::state::right:
		currentFrame = 5;
		break;
		case Animation::state::back:
		currentFrame = 10;
		break;
		case Animation::state::front:
		currentFrame = 15;
		break;
	 }
}
