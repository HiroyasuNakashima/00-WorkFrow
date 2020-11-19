#include"CONTAINER.h"

class GAMECLEAR {
public:
	void init(CONTAINER* c);
	void update();
	void draw();
private:
	int Img;
	float Px;
	float Py;
	float Rad;
	int BacKImg;
	float BackPx;
	float BackPy;
	int Push_EnterImg;
	float Push_EnterPx;
	float Push_EnterPy;
	float Push_EnterRad;
	int Push_EnterCnt;
	int OkFlag;
	int NgFlag;
};