#pragma once
#include"CONTAINER.h"
#include"PLAYER.h"

class MAP {
public:
	void init(CONTAINER* c);
	void draw();
private:
	int backImg;
	float backPx;
	float backPy;
	float backRad;
	int FieldImg = 0;
	int HashiTateImg = 0;
	int HashiYokoImg = 0;
	int ChipSize = 0;
	char* MapData = 0;
	int NumDataColumns = 0;
	int NumDataRows = 0;
};