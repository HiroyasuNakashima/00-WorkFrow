#pragma once
#include"CONTAINER.h"
#include"AITEMWINDOW.h"
#include"PLAYER.h"

class BUTTLE2 {
public:
	void init(CONTAINER* c, PLAYER* p, AITEM_WINDOW* a);
	void update(AITEM_WINDOW* a);
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
	int PlayerAiconImg;
	float BackPx;
	float BackPy;
	float MonsterPx;
	float MonsterPy;
	float AttckPx;
	float AttckPy;
	float PlayerAiconPx;
	float PlayerAiconPy;
	float Rad;
	float Radian;
	float ToRad;
	int PlayerLife;
	int PlayerAttckDamege;
	int PlayerAttckDamege2;//武器入手時
	int PlayerHeal;
	int MonsterLife;
	int MonsterAttckDamege;
	int MonsterImgLife = 1;
	int DamegeCnt;//モンスターの点滅Cnt
	int PlayerAttckFlag; //攻撃中Flag
	int MonsterAttckFlag;
	int TextFlag;
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
	int ActionFlag;
	int PlayerWin;
	int PlayerLose;
	int PlayerEscape;
	int HpbarImg[HP];
	float HpbarPx[HP];
	float HpbarPy[HP];
	float HpbarTextPx1;
	float HpbarTextPy1;
	float HpbarTextPx2;
	float HpbarTextPy2;
};