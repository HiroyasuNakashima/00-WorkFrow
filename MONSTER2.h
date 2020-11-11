#pragma once
#include"CONTAINER.h"

class MONSTER2 {
public:
	void init(CONTAINER* c);
	void update();
	void draw();
	void maeImg();
	void ushiroImg();
	void leftImg();
	void rightImg();
	void setImgLife(int imglife);
	float px();
	float py();
private:
	int Img = 0;
	int AnimImg1 = 0;
	int AnimImg2 = 0;
	int AnimCnt = 0;
	int MaeImg1;
	int MaeImg2;
	int LeftImg1;
	int LeftImg2;
	int RightImg1;
	int RightImg2;
	int UshiroImg1;
	int UshiroImg2;
	float Px;
	float Py;
	float Rad;
	int ImgLife;
};