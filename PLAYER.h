#pragma once
#include"CONTAINER.h"
#include"MURABITO1.h"
#include"MURABITO2.h"
#include"MONSTER1.h"
#include"MONSTER2.h"
#include"MONSTER3.h"
#include"AITEMWINDOW.h"
#include"MAP.h"

class PLAYER {
public:
	void init(CONTAINER* c);
	void update(MURABITO1* m1, MURABITO2* m2, MONSTER1* e1, MONSTER2* e2, MONSTER3* e3,AITEM_WINDOW* a);
	void draw();
	void setActionFlag(int flag);
	void setTextFlag(int flag);
	void setLife(int life);
	void setClearFlag(int flag);
	void setNgFlag(int flag);
	bool collision();
	int life();
	float px();
	float py();
	int actionFlag();
	int textFlag();
	int clearFlag();
	int ngFlag();
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
	int Life;
	float Wx = 0.0f;
	float Wy = 0.0f;
	float collisionWx = 0.0f;
	float collisionWy = 0.0f;
	float Px;
	float Py;
	float Rad;
	float Speed;
	float Dy;
	float Dx;
	int DirectionCnt;//キャラの1歩の移動時間
	int Day;
	int DayFlag;
	int DayFlag1;
	float TextPx;
	float TextPy;
	float TextPx1;
	float TextPy1;
	int ActionFlag;//他キャラに話すと立つFlag
	int TextFlag;//表示するテキストを決めるFlag
	int PlayerEscape;
	int ClearFlag;
	int NgFlag;
};