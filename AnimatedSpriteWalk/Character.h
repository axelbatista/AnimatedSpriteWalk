#pragma once
#include "Location.h"

class Character {
public:
	Location spot;
	Character(int one, int two) : spot{one,two} {}			//really simple information for retaining position and updating.
	void move(int x, int y);
};