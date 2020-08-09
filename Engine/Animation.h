#pragma once
#include "Surface.h"
#include "Rect.h"
#include "Graphics.h"

class Animation {
	enum movement {
		left,
		right,
		back,
		front
	};
	Rect array[20];
	int toPlay = 0;
	int threshold = 5000;
	Surface& sprite;
	const int length = 5;
public:
	Animation(Surface& surface) : sprite(surface) {
		for (int j = 0; j < sprite.getHeight(); j += 90) {
			for (int i = 0; i < sprite.getWidth(); i += 90) {
				int y = j / 90;
				int x = i / 90;
				array[y * length + x] = Rect{ {i,j}, {i + 90, j}, {i,j+90} };
			}
		}
	}
	void draw(Graphics& gfx);
};