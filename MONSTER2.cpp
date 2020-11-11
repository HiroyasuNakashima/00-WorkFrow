#include"MONSTER2.h"

void MONSTER2::init(CONTAINER* c) {
	MaeImg1 = c->monster2MaeImg1;
	MaeImg2 = c->monster2MaeImg2;
	LeftImg1 = c->monster2LeftImg1;
	LeftImg2 = c->monster2LeftImg2;
	RightImg1 = c->monster2RightImg1;
	RightImg2 = c->monster2RightImg2;
	UshiroImg1 = c->monster2UshiroImg1;
	UshiroImg2 = c->monster2UshiroImg2;
	AnimImg1 = UshiroImg1;
	AnimImg2 = UshiroImg2;
	Px = c->monster2Px;
	Py = c->monster2Py;
	Rad = c->monster2Rad;
	ImgLife = c->imgLife;
}
void MONSTER2::update() {
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
void MONSTER2::draw() {
	image(Img, Px, Py, Rad);
}
void MONSTER2::maeImg() {
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
}
void MONSTER2::ushiroImg() {
	AnimImg1 = UshiroImg1;
	AnimImg2 = UshiroImg2;
}
void MONSTER2::leftImg() {
	AnimImg1 = LeftImg1;
	AnimImg2 = LeftImg2;
}
void MONSTER2::rightImg() {
	AnimImg1 = RightImg1;
	AnimImg2 = RightImg2;
}

void MONSTER2::setImgLife(int imglife) { ImgLife = imglife; }
float MONSTER2::px() { return Px; }
float MONSTER2::py() { return Py; }