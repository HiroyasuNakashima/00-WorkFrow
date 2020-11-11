#include"MAP.h"

void MAP::init(CONTAINER* c) {
	backImg = c->backImg;
	backPx = c->backPx;
	backPy = c->backPy;
	backRad = c->backRad;
	FieldImg = c->fieldImg;
	HashiTateImg = c->hashiTateImg;
	HashiYokoImg = c->hashiYokoImg;
	ChipSize = 32;
	const char* mapdata =
		"........................."
		"........................."
		"........................."
		"........................."
		".............1..........."
		".............1..........."
		".............2..........."
		"........111.111.........."
		"........1113111.........."
		"............111.........."
		".............2..........."
		"............11..........."
		"............11..........."
		"........................."
		"........................."
		"........................."
		"........................."
		"........................."
		".........................";
	MapData = (char*)mapdata;
	NumDataColumns = 25;
	NumDataRows = 19;
}
void MAP::draw() {
	//îwåi
	image(backImg, backPx, backPy, backRad);
	//FIELD
	for (int col = 0; col < NumDataColumns; col++) {
		for (int row = 0; row < NumDataRows; row++) {
			int i = col + row * NumDataColumns;
			if (MapData[i] == '1') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				image(FieldImg, px, py);
			}
			if (MapData[i] == '2') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				image(HashiTateImg, px, py);
			}
			if (MapData[i] == '3') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				image(HashiYokoImg, px, py);
			}
		}
	}
}