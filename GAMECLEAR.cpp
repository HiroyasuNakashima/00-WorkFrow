#include"GAMECLEAR.h"

void GAMECLEAR::init(CONTAINER* c) {
	Img = c->gameoverImg;
	Px = c->gameclearPx;
	Py = c->gameclearPy;
	Rad = c->rad;
	BacKImg = c->gameclearBackImg;
	BackPx = c->gameclearBackPx;
	BackPy = c->gameclearBackPy;
	Push_EnterImg = c->pushenterImg;
	Push_EnterPx = c->pushenterPx;
	Push_EnterPy = c->pushenterPy;
	Push_EnterCnt = c->pushenterCnt;
}
void GAMECLEAR::update() {

}
void GAMECLEAR::draw() {
	image(Img, Px, Py, Rad);
	image(BacKImg, BackPx, BackPy, Rad);
	if (Push_EnterCnt++ / 60 % 2 == 0) {
		image(Push_EnterImg, Push_EnterPx, Push_EnterPy, Rad);
	}
}