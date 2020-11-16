#include"input.h"
#include"PLAYER.h"

void PLAYER::init(CONTAINER* c) {
	MaeImg1 = c->playerMaeImg1;
	MaeImg2 = c->playerMaeImg2;
	LeftImg1 = c->playerLeftImg1;
	LeftImg2 = c->playerLeftImg2;
	RightImg1 = c->playerRightImg1;
	RightImg2 = c->playerRightImg2;
	UshiroImg1 = c->playerUshiroImg1;
	UshiroImg2 = c->playerUshiroImg2;
	AnimImg1 = MaeImg1;
	AnimImg2 = MaeImg2;
	Wx = c->playerPx;
	Wy = c->playerPy;
	Px = c->playerPx;
	Py = c->playerPy;
	Rad = c->playerRad;
	Speed = c->playerSpeed;
	Dx = c->playerDx;
	Dy = c->playerDy;
	DirectionCnt = c->playerDirectionCnt;
	Day = c->playertextDay;
	DayFlag = c->playerDayFlag;
	DayFlag1 = c->playerDayFlag1;
	TextPx = c->playertextPx;
	TextPy = c->playertextPy;
	TextPx1 = c->playertextPx1;
	TextPy1 = c->playertextPy1;
	Life = c->playerLife;
	ActionFlag = c->playerActionFlag;
	TextFlag = c->playerTextFlag;
	
}
void PLAYER::update(MURABITO1* m1, MURABITO2* m2, MONSTER1* e1, MONSTER2* e2, MONSTER3* e3) {
	//移動
	//現在の場所をWx,Wyに記憶させておく
	if (TextFlag == 0) { //話しかけ中でないなら行動出来る
		Wx = Px;
		Wy = Py;
		collisionWx = Px;
		collisionWy = Py;
		DayFlag1 = 0;
		if (Dx == 0.0f && Dy == 0.0f) {//キー入力が無いとき
			if (isTrigger(KEY_UP)) {
				Dy -= Speed;
				DirectionCnt = 32;
				AnimImg1 = UshiroImg1;
				AnimImg2 = UshiroImg2;
				collisionWy -= 30.0f;
			}
			if (isTrigger(KEY_DOWN)) {
				Dy += Speed;
				DirectionCnt = 32;
				AnimImg1 = MaeImg1;
				AnimImg2 = MaeImg2;
				collisionWy += 30.0f;
			}
			if (isTrigger(KEY_LEFT)) {
				Dx -= Speed;
				DirectionCnt = 32;
				AnimImg1 = LeftImg1;
				AnimImg2 = LeftImg2;
				collisionWx -= 30.0f;
			}
			if (isTrigger(KEY_RIGHT)) {
				Dx += Speed;
				DirectionCnt = 32;
				AnimImg1 = RightImg1;
				AnimImg2 = RightImg2;
				collisionWx += 30.0f;
			}
		}
		else {
			DayFlag = 1;
		}
		if (DirectionCnt-- > 0) {//移動時間
			Px += Dx;
			Py += Dy;
		}
		else {
			Dx = 0.0f;
			Dy = 0.0f;
		}
		//当たり判定
		//MURABITO1との距離
		float px_m1x = m1->px() - Px;
		float py_m1y = m1->py() - Py;
		float p_m1len = sqrt(px_m1x * px_m1x + py_m1y * py_m1y);
		//MURABITO2との距離
		float px_m2x = m2->px() - Px;
		float py_m2y = m2->py() - Py;
		float p_m2len = sqrt(px_m2x * px_m2x + py_m2y * py_m2y);
		//MONSTER1との距離
		float px_e1x = e1->px() - Px;
		float py_e1y = e1->py() - Py;
		float p_e1len = sqrt(px_e1x * px_e1x + py_e1y * py_e1y);
		//MONSTER2との距離
		float px_e2x = e2->px() - Px;
		float py_e2y = e2->py() - Py;
		float p_e2len = sqrt(px_e2x * px_e2x + py_e2y * py_e2y);
		//MONSTER3との距離
		float px_e3x = e3->px() - Px;
		float py_e3y = e3->py() - Py;
		float p_e3len = sqrt(px_e3x * px_e3x + py_e3y * py_e3y);
		
		if (collision() == false) {//フィールドの当たり判定
			Px = Wx;
			Py = Wy;
			DirectionCnt = 0;//0にすることでPLAYERが他キャラに向かって行った後、すぐ動ける
			DayFlag1 = 1;//このフラグが立つ間Dayは減らない
		}

		if (p_m1len < 32.0f || p_m2len < 32.0f || p_e1len < 32.0f || p_e2len < 32.0f || p_e3len < 32.0f) {
			Px = Wx;//元の位置に戻す
			Py = Wy;
			DirectionCnt = 0;//0にすることでPLAYERが他キャラに向かって行った後、すぐ動ける
			DayFlag1 = 1;//このフラグが立つ間Dayは減らない
		}
		//アクションキー・イベントトリガー(向き合わせる）
		if (isTrigger(KEY_Z)) {
			//MURABITO1
			if (p_m1len < 33.0f) {//距離の範囲内なら
				if (Py == m1->py() - 32.0f && AnimImg1 == MaeImg1) { //PLAYERの位置とIMG画像で向きと場所を判断
					m1->ushiroImg();
					TextFlag = 1;
				}
				if (Py == m1->py() + 32.0f && AnimImg1 == UshiroImg1) {
					m1->maeImg();
					TextFlag = 1;
				}
				if (Px == m1->px() - 32.0f && AnimImg1 == RightImg1) {
					m1->leftImg();
					TextFlag = 1;
				}
				if (Px == m1->px() + 32.0f && AnimImg1 == LeftImg1) {
					m1->rightImg();
					TextFlag = 1;
				}
			}
			//MURABITO2
			if (p_m2len < 33.0f) {//距離の範囲内なら
				if (Py == m2->py() - 32.0f && AnimImg1 == MaeImg1) { //PLAYERの位置とIMG画像で向きと場所を判断
					m2->ushiroImg();
					TextFlag = 2;
				}
				if (Py == m2->py() + 32.0f && AnimImg1 == UshiroImg1) {
					m2->maeImg();
					TextFlag = 2;
				}
				if (Px == m2->px() - 32.0f && AnimImg1 == RightImg1) {
					m2->leftImg();
					TextFlag = 2;
				}
				if (Px == m2->px() + 32.0f && AnimImg1 == LeftImg1) {
					m2->rightImg();
					TextFlag = 2;
				}
			}
			//MONSTER1
			if (p_e1len < 33.0f) {//距離の範囲内なら
				if (Py == e1->py() - 32.0f && AnimImg1 == MaeImg1) { //PLAYERの位置とIMG画像で向きと場所を判断
					e1->ushiroImg();
					TextFlag = 3;
				}
				if (Py == e1->py() + 32.0f && AnimImg1 == UshiroImg1) {
					e1->maeImg();
					TextFlag = 3;
				}
				if (Px == e1->px() - 32.0f && AnimImg1 == RightImg1) {
					e1->leftImg();
					TextFlag = 3;
				}
				if (Px == e1->px() + 32.0f && AnimImg1 == LeftImg1) {
					e1->rightImg();
					TextFlag = 3;
				}
			}
			//MONSTER2
			if (p_e2len < 33.0f) {//距離の範囲内なら
				if (Py == e2->py() - 32.0f && AnimImg1 == MaeImg1) { //PLAYERの位置とIMG画像で向きと場所を判断
					e2->ushiroImg();
					TextFlag = 4;
				}
				if (Py == e2->py() + 32.0f && AnimImg1 == UshiroImg1) {
					e2->maeImg();
					TextFlag = 4;
				}
				if (Px == e2->px() - 32.0f && AnimImg1 == RightImg1) {
					e2->leftImg();
					TextFlag = 4;
				}
				if (Px == e2->px() + 32.0f && AnimImg1 == LeftImg1) {
					e2->rightImg();
					TextFlag = 4;
				}
			}
			//MONSTER3
			if (p_e3len < 33.0f) {//距離の範囲内なら
				if (Py == e3->py() - 32.0f && AnimImg1 == MaeImg1) { //PLAYERの位置とIMG画像で向きと場所を判断
					e3->ushiroImg();
					TextFlag = 5;
				}
				if (Py == e3->py() + 32.0f && AnimImg1 == UshiroImg1) {
					e3->maeImg();
					TextFlag = 5;
				}
				if (Px == e3->px() - 32.0f && AnimImg1 == RightImg1) {
					e3->leftImg();
					TextFlag = 5;
				}
				if (Px == e3->px() + 32.0f && AnimImg1 == LeftImg1) {
					e3->rightImg();
					TextFlag = 5;
				}
			}
		}
	}
	//残り日数
	if (DayFlag1 != 1) {
		if (DayFlag == 1 && DirectionCnt == 0) {
			Day -= 1;
			DayFlag = 0;
		}
	}
	//アニメーション
	if (AnimCnt++ / 20 % 2 == 0) {
		Img = AnimImg1;
	}
	else {
		Img = AnimImg2;
	}
}
void PLAYER::draw() {
	image(Img, Px, Py, Rad);
	fill(255, 255, 255);
	rect(597, 50, 125, 26);
	fill(0);
	text("残り日数", TextPx, TextPy);
	text(Day, TextPx1, TextPy1);
	fill(255);
}
bool PLAYER::collision() {//フィールドとの当たり判定
	if (448.0f >= collisionWx && collisionWx >= 384.0f && 288.0f >= collisionWy && collisionWy >= 224.0f) {
		return true;
	}
	if (416.0f >= collisionWx && collisionWx >= 416.0f && 384.0f >= collisionWy && collisionWy >= 128.0f) {
		return true;
	}
	if (416.0f >= collisionWx && collisionWx >= 384.0f && 384.0f >= collisionWy && collisionWy >= 352.0f) {
		return true;
	}
	if (448.0f >= collisionWx && collisionWx >= 256.0f && 256.0f >= collisionWy && collisionWy >= 256.0f) {
		return true;
	}
	if (320.0f >= collisionWx && collisionWx >= 256.0f && 256.0f >= collisionWy && collisionWy >= 224.0f) {
		return true;
	}
	return false;
}

void PLAYER::setActionFlag(int flag) { ActionFlag = flag; }
void PLAYER::setTextFlag(int flag) { TextFlag = flag; }
int PLAYER::life() { return Life; }
float PLAYER::px() { return Px; }
float PLAYER::py() { return Py; }
int PLAYER::actionFlag() { return ActionFlag; }
int PLAYER::textFlag() { return TextFlag; }