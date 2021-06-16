#include "Surface.h"
#include <assert.h>
#include <string>

void Surface::PutPixel(int x, int y, Color c) {
	int sum = y * width + x;						//conversion so that we keep one dim array.
	array[sum] = c;
}

void Surface::drawSprite(int m, int n, Rect rect, Graphics& gfx)
{
	if (m <= 0) {
		rect.leftTC.x -= m;
		m = 0;
	}
	if (n <= 0) {							//clipping done here and draw the sprite based on which sprite frame we are given. Passed by value so that the original dimensions aren't messed up.'
		rect.leftTC.y -= n;
		n = 0;
	}
	for (int y = rect.leftTC.y, h = n; y < rect.leftBC.y && h < n + 90 && h < Graphics::ScreenHeight; y++, h++) {
		for (int x = rect.leftTC.x, g = m; x < rect.rightTC.x && g < m + 90 && g < Graphics::ScreenWidth; x++, g++) {
			if (array[y * width + x] != chroma) {
				gfx.PutPixel(g, h, array[y * width + x]);
			}
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
