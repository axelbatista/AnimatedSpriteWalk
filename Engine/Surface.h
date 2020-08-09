#pragma once
#include <string>
#include <fstream>
#include "ChiliWin.h"
#include "Colors.h"
#include "Graphics.h"
#include "Rect.h"


class Surface {
	Color chroma = Colors::Magenta;
	Color* array;
	int width;
	int height;
	std::string fileName;
public:
	Surface(const std::string& fileName_) : fileName{ fileName_ } {
		std::ifstream file(fileName, std::ios::binary);
		BITMAPFILEHEADER bf;
		file.read(reinterpret_cast<char*>(&bf), sizeof(bf));
		BITMAPINFOHEADER bInfo;
		file.read(reinterpret_cast<char*>(&bInfo), sizeof(bInfo));
		width = bInfo.biWidth;
		height = bInfo.biHeight;
		const int padding = (4 - (width * 3) % 4) % 4;
		array = new Color[width * height];
		file.seekg(bf.bfOffBits);
		for (int j = height - 1; j >= 0; j--) {
			for (int i = 0; i < width; i++) {
				PutPixel(i, j, Color(file.get(), file.get(), file.get()));
			}
			file.seekg(padding, std::ios::cur);
		}
	}
	void PutPixel(int x, int y, Color c);
	void drawSprite(const Rect& rect, Graphics& gfx);
	int getHeight();
	int getWidth();
};