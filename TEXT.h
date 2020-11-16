#include"CONTAINER.h"
#include"PLAYER.h"

class TEXT {
public:
	void init(CONTAINER* c);
	void update(PLAYER* p);
	void draw(PLAYER* p);
private:
	int WindowImg;
	int TextImg1 = 0;
	int TextImg2 = 0;
	float WindowPx;
	float WindowPy;
	float Rad;
	float TextPx1;//1行目
	float TextPy1;
	float TextPx2;//2行目
	float TextPy2;
	float TextPx3;//3行目
	float TextPy3;
	int ImgLife;
};