#include"MONSTER1.h"

void MONSTER1::init(CONTAINER* c) {
	MaeImg1 = c->monster1MaeImg1;
	MaeImg2 = c->monster1MaeImg2;
	LeftImg1 = c->monster1LeftImg1;
	LeftImg2 = c->monster1LeftImg2;
	RightImg1 = c->monster1RightImg1;
	RightImg2 = c->monster1RightImg2;
	UshiroImg1 = c->monster1UshiroImg1;
	UshiroImg2 = c->monster1UshiroImg2;
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
	Px = c->monster1Px;
	Py = c->monster1Py;
	Rad = c->monster1Rad;
	ImgLife = c->imgLife;
}
void MONSTER1::update() {
	if (AnimCnt++ / 20 % 2 == 0) {
		Img = AnimImg1;
	}
	else {
		Img = AnimImg2;
	}
	if (ImgLife == 0) { //ì|Ç≥ÇÍÇΩÇÁâÊñ äOÇ÷èoÇ∑
		Px = -100.0f;
		Py = -100.0f;
	}
}
void MONSTER1::draw() {
	if (ImgLife == 1) {
		image(Img, Px, Py, Rad);
	}
}
void MONSTER1::maeImg() {
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
}
void MONSTER1::ushiroImg() {
	AnimImg1 = UshiroImg1;
	AnimImg2 = UshiroImg2;
}
void MONSTER1::leftImg() {
	AnimImg1 = LeftImg1;
	AnimImg2 = LeftImg2;
}
void MONSTER1::rightImg() {
	AnimImg1 = RightImg1;
	AnimImg2 = RightImg2;
}

void MONSTER1::setImgLife(int imglife) { ImgLife = imglife; }
float MONSTER1::px() { return Px; }
float MONSTER1::py() { return Py; }
