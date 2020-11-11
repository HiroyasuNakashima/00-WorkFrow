#include"MURABITO1.h"

void MURABITO1::init(CONTAINER* c) {
	MaeImg1 = c->murabito1MaeImg1;
	MaeImg2 = c->murabito1MaeImg2;
	LeftImg1 = c->murabito1LeftImg1;
	LeftImg2 = c->murabito1LeftImg2;
	RightImg1 = c->murabito1RightImg1;
	RightImg2 = c->murabito1RightImg2;
	UshiroImg1 = c->murabito1UshiroImg1;
	UshiroImg2 = c->murabito1UshiroImg2;
	AnimImg1 = LeftImg1;
	AnimImg2 = LeftImg2;
	Px = c->murabito1Px;
	Py = c->murabito1Py;
	Rad = c->murabito1Rad;
}
void MURABITO1::update() {
	if (AnimCnt++ / 20 % 2 == 0) {
		Img = AnimImg1;
	}
	else {
		Img = AnimImg2;
	}
}
void MURABITO1::draw() {
	image(Img, Px, Py, Rad);
}
void MURABITO1::maeImg() {
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
}
void MURABITO1::ushiroImg() {
	AnimImg1 = UshiroImg1;
	AnimImg2 = UshiroImg2;
}
void MURABITO1::leftImg() {
	AnimImg1 = LeftImg1;
	AnimImg2 = LeftImg2;
}
void MURABITO1::rightImg() {
	AnimImg1 = RightImg1;
	AnimImg2 = RightImg2;
}

float MURABITO1::px() { return Px; }
float MURABITO1::py() { return Py; }