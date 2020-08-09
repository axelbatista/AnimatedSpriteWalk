#include "Surface.h"

void Surface::PutPixel(int x, int y, Color c) {
	array[y * width + x] = c;
}

void Surface::drawSprite(const Rect& rect, Graphics& gfx)
{
	for (int j = 100, y = rect.leftTC.y; j < 190 && y < rect.leftBC.y; j++, y++) {
		for (int i = 100, x = rect.leftTC.x; i < 190 && x < rect.rightTC.x; i++, x++) {
			if (array[y*width + x] != chroma)
				gfx.PutPixel(i, j, array[y*width+x]);
		}
	}
}

int Surface::getHeight()
{
	return height;
}

int Surface::getWidth()
{
	return width;
}
