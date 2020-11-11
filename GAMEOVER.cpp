#include"GAMEOVER.h"

void GAMEOVER::init(CONTAINER* c) {
	Img = c->gameoverImg;
	Px = c->gameoverPx;
	Py = c->gameoverPy;
	Rad = c->gameoverRad;
	Push_EnterImg = c->pushenterImg;
	Push_EnterPx = c->pushenterPx;
	Push_EnterPy = c->pushenterPy;
	Push_EnterRad = c->pushenterRad;
	Push_EnterCnt = c->pushenterCnt;
}
void GAMEOVER::draw() {
	image(Img, Px, Py, Rad);
	if (Push_EnterCnt++ / 60 % 2 == 0) {
		image(Push_EnterImg, Push_EnterPx, Push_EnterPy, Push_EnterRad);
	}
}