#include"CONTAINER.h"
#include"PLAYER.h"

class TEXT {
public:
	void init(CONTAINER* c);
	void update(PLAYER* p);
	void draw(PLAYER* p);
private:
	int Img;
	int TextImg1 = 0;
	int TextImg2 = 0;
	float Px;
	float Py;
	float Rad;
	int ImgLife;
};