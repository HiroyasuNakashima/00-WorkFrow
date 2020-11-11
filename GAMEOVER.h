#pragma once
#include"CONTAINER.h"

class GAMEOVER {
public:
	void init(CONTAINER* c);
	void draw();
private:
	int Img;
	float Px;
	float Py;
	float Rad;
	int Push_EnterImg;
	float Push_EnterPx;
	float Push_EnterPy;
	float Push_EnterRad;
	int Push_EnterCnt;
};