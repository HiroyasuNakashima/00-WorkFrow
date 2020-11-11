#include"MONSTER3.h"

void MONSTER3::init(CONTAINER* c) {
	MaeImg1 = c->monster3MaeImg1;
	MaeImg2 = c->monster3MaeImg2;
	LeftImg1 = c->monster3LeftImg1;
	LeftImg2 = c->monster3LeftImg2;
	RightImg1 = c->monster3RightImg1;
	RightImg2 = c->monster3RightImg2;
	UshiroImg1 = c->monster3UshiroImg1;
	UshiroImg2 = c->monster3UshiroImg2;
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
	Px = c->monster3Px;
	Py = c->monster3Py;
	Rad = c->monster3Rad;
	ImgLife = c->imgLife;
}
void MONSTER3::update() {
	if (AnimCnt++ / 20 % 2 == 0) {
		Img = AnimImg1;
	}
	else {
		Img = AnimImg2;
	}
	if (ImgLife == 0) {
		Px = -100.0f;
		Py = -100.0f;
	}
}
void MONSTER3::draw() {
	image(Img, Px, Py, Rad);
}
void MONSTER3::maeImg() {
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
}
void MONSTER3::ushiroImg() {
	AnimImg1 = UshiroImg1;
	AnimImg2 = UshiroImg2;
}
void MONSTER3::leftImg() {
	AnimImg1 = LeftImg1;
	AnimImg2 = LeftImg2;
}
void MONSTER3::rightImg() {
	AnimImg1 = RightImg1;
	AnimImg2 = RightImg2;
}

void MONSTER3::setImgLife(int imglife) { ImgLife = imglife; }
float MONSTER3::px() { return Px; }
float MONSTER3::py() { return Py; }