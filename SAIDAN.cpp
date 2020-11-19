#include"SAIDAN.h"

void SAIDAN::init(CONTAINER* c) {
	Img = c->saidanImg;
	Px = c->saidanPx;
	Py = c->saidanPy;
	Rad = c->rad;
}
void SAIDAN::draw() {
	image(Img, Px, Py, Rad);
}

float SAIDAN::px() { return Px; }
float SAIDAN::py() { return Py; }