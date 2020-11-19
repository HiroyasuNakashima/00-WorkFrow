#include"CONTAINER.h"
#include"PLAYER.h"
#include"AITEM_WINDOW.h"

class TEXT {
public:
	void init(CONTAINER* c);
	void update(PLAYER* p, AITEM_WINDOW* a);
	void draw(PLAYER* p);
private:
	int Img;
	int TextImg1 = 1;
	int TextImg2 = 0;
	float WindowPx;
	float WindowPy;
	float TextPx1;
	float TextPy1;
	float TextPx2;
	float TextPy2;
	float Rad;
	int ImgLife;
};