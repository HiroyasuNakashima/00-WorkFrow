#include"CONTAINER.h"
#include"PLAYER.h"

PLAYER::PLAYER() : CHARACTER(C->playerNumAnims) {
	//CHARACTER::menber
	Anims[0] = &C->playerFrontAnim;
	Anims[1] = &C->playerBackAnim;
	Anims[2] = &C->playerRightAnim;
	Anims[3] = &C->playerLeftAnim;
	CharaId  =  C->playerCharaId;
	Speed    =  C->playerSpeed;
	//PLAYER::menber
	FrontAnimId = C->playerFrontAnimId;
	BackAnimId  = C->playerBackAnimId;
	RightAnimId = C->playerRightAnimId;
	LeftAnimId  = C->playerLeftAnimId;
	ChipSize    = C->playerChipSize;
}
void PLAYER::update() {
	AnimCnt++;
	//移動------------------------------------------------------
	float nextPx = Px;
	float nextPy = Py;
	float currentPx = Px;
	float currentPy = Py;
	if (Dx == 0.0f && Dy == 0.0f) {//キー入力なし
		if (isTrigger(KEY_RIGHT)) {
			nextPx += (float)ChipSize;
			Dx = Speed;
			AnimId = RightAnimId;
			MoveCnt = C->playerMoveCnt;
		}
		if (isTrigger(KEY_LEFT)) {
			nextPx -= (float)ChipSize;
			Dx = -Speed;
			AnimId = LeftAnimId;
			MoveCnt = C->playerMoveCnt;
		}
		if (isTrigger(KEY_UP)) {
			nextPy -= (float)ChipSize;
			Dy = -Speed;
			AnimId = BackAnimId;
			MoveCnt = C->playerMoveCnt;
		}
		if (isTrigger(KEY_DOWN)) {
			nextPy += (float)ChipSize;
			Dy = Speed;
			AnimId = FrontAnimId;
			MoveCnt = C->playerMoveCnt;
		}
	}
	if(Dx == 1.0f && Dy == 1.0f || Dx == -1.0f && Dy == -1.0f ||//同時押しだったら
	   Dx == -1.0f && Dy == 1.0f || Dx == 1.0f && Dy == -1.0f ){
		Dx = 0.0f;
		Dy = 0.0f;
	}
	if (MoveCnt-- <= 0) {//移動時間で停止
		Dx = 0.0f;
		Dy = 0.0f;
	}
	else {
		Px += Dx;
		Py += Dy;
	}
	//当たり判定--------------------------------------------------------------
	//キャラ同士の当たり判定
	if (CharaMap->collisionCheck(nextPx, nextPy) == true) {
		Dx = 0.0f;
		Dy = 0.0f;
		Px = currentPx;
		Py = currentPy;
	}
	//フィールド外との当たり判定
	if (Map->collisionCheck(nextPx, nextPy) == false) {
		Dx = 0.0f;
		Dy = 0.0f;
		Px = currentPx;
		Py = currentPy;
	}
	//会話----------------------------------------------------------------------
}