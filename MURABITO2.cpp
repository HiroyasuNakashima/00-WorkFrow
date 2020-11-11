#include"MURABITO2.h"

void MURABITO2::init(CONTAINER* c) {
	MaeImg1 = c->murabito2MaeImg1;
	MaeImg2 = c->murabito2MaeImg2;
	LeftImg1 = c->murabito2LeftImg1;
	LeftImg2 = c->murabito2LeftImg2;
	RightImg1 = c->murabito2RightImg1;
	RightImg2 = c->murabito2RightImg2;
	UshiroImg1 = c->murabito2UshiroImg1;
	UshiroImg2 = c->murabito2UshiroImg2;
	AnimImg1 = RightImg1;
	AnimImg2 = RightImg2;
	Px = c->murabito2Px;
	Py = c->murabito2Py;
	Rad = c->murabito2Rad;
}
void MURABITO2::update() {
	if (AnimCnt++ / 20 % 2 == 0) {
		Img = AnimImg1;
	}
	else {
		Img = AnimImg2;
	}
}
void MURABITO2::draw() {
	image(Img, Px, Py, Rad);
}
void MURABITO2::maeImg() {
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
}
void MURABITO2::ushiroImg() {
	AnimImg1 = UshiroImg1;
	AnimImg2 = UshiroImg2;
}
void MURABITO2::leftImg() {
	AnimImg1 = LeftImg1;
	AnimImg2 = LeftImg2;
}
void MURABITO2::rightImg() {
	AnimImg1 = RightImg1;
	AnimImg2 = RightImg2;
}
float MURABITO2::px() { return Px; }
float MURABITO2::py() { return Py; }
