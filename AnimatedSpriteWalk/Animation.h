#pragma once
#include "Surface.h"
#include "Rect.h"
#include "Graphics.h"

class Animation {
public:
	enum state {
		left,
		right,
		back,
		front
	};
private:
	Rect array[20];											//there are 20 sprite frames within the bitmap, so we have 20 spaces here.
	int toPlay = 0;
	int threshold = 15;			
	Surface& sprite;
	const int length = 5;
	int currentFrame = 0;
	state movement;
public:
	Animation(Surface& surface) : sprite(surface) {
		for (int j = 0, y = 0; j < sprite.getHeight(); j += 90, y++) {
			for (int i = 0, x = 0; i < sprite.getWidth(); i += 90, x++) {				//rect simply just contains the dimensions for every single rectangle so as to properly give out the dimensions for any individual frame.
				array[y * length + x] = Rect{ {i,j}, {i + 90, j}, {i,j+90} };
			}
		}
	}
	void draw(int x, int y, Graphics& gfx);
	void passTime(int x, int limit);
	void advance(int x, int limit);
	void setState(state type);
	state getState() const;
	void setToNoMovement();
};