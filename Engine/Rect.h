#pragma once
#include "Location.h"

class Rect {
public:
	Location leftTC;
	Location rightTC;
	Location leftBC;
	Rect() = default;
	Rect(Location one, Location two, Location three) : leftTC(one), rightTC{ two }, leftBC{three}{}
};