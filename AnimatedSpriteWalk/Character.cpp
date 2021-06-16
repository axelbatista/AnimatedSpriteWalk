#include "Character.h"

void Character::move(int x, int y)
{
	spot.x += x;
	spot.y += y;
}
