#pragma once
#include"CONTAINER.h"

class BUTTLE2 {
public:
	void init(CONTAINER* c);
	void update();
	void draw();
	int playerWin();
	int playerLose();
	int playerEscape();
	enum BUTTLE_TRUN { PLAYER_TRUN, MONSTER_TRUN };
private:
	BUTTLE_TRUN Trun = PLAYER_TRUN;
	int BackImg;
	int MonsterImg;
	int AttckImg;
	float BackPx;
	float BackPy;
	float MonsterPx;
	float MonsterPy;
	float AttckPx;
	float AttckPy;
	float Rad;
	float Radian;
	float ToRad;
	int PlayerLife;
	int PlayerAttckDamege;
	int PlayerAttckDamege2;//武器入手時
	int MonsterLife;
	int MonsterAttckDamege;
	int MonsterImgLife = 1;
	int DamegeCnt;//モンスターの点滅Cnt
	int ImgCnt;
	int CursorLife = 1;//カーソルの点滅用。たたかう中は消える
	int PlayerAttckFlag; //攻撃中Flag
	int MonsterAttckFlag;
	int TextFlag = 0;
	int TextWindowImg;
	int TextMenyuImg;
	int CursorImg;
	int AttckImgLife;
	float TextWindowPx;
	float TextWindowPy;
	float TextMenyuPx;
	float TextMenyuPy;
	float CursorPx;
	float CursorPy;
	float CursorWy = 0.0f;//カーソルの移動する場所を先に取得するためのもの
	float TextPx1;
	float TextPy1;
	float TextPx2;
	float TextPy2;
	float tatakauPx;
	float tatakauPy;
	float kaihukuPx;
	float kaihukuPy;
	float nigeruPx;
	float nigeruPy;
	int ActionFlag = 0;
	int PlayerWin = 0;
	int PlayerLose = 0;
	int PlayerEscape = 0;
};