#include"AITEMWINDOW.h"

void AITEM_WINDOW::init(CONTAINER* c) {
	WindowImg = c->aitemWindowImg;
	WindowPx = c->aitemWindowPx;
	WindowPy = c->aitemWindowPy;
	PlayerImg = c->playerAiconImg;
	PlayerPx = c->playerAiconPx;
	PlayerPy = c->playerAiconPy;
	WeaponImg = c->weaponAiconImg;
	WeaponPx = c->weaponAiconPx;
	WeaponPy = c->weaponAiconPy;
	WeaponImgLife = c->weaponImgLife;
	KaihukuImg = c->kaihukuAiconImg;
	KaihukuPx = c->kaihukuAiconPx;
	KaihukuPy = c->kaihukuAiconPy;
	KaihukuImgLife = c->kaihukuImgLife;
	HougyokuImg = c->hougyokuAiconImg;
	HougyokuPx = c->hougyokuAiconPx;
	HougyokuPy = c->hougyokuAiconPy;
	HougyokuImgLife = c->hougyokuImgLife;
}
void AITEM_WINDOW::draw() {
	//ウィンドウ枠
	image(WindowImg, WindowPx, WindowPy, Rad);
	//プレイヤーアイコン
	image(PlayerImg, PlayerPx, PlayerPy, Rad);
	//武器
	if (WeaponImgLife == 1) {
		image(WeaponImg, WeaponPx, WeaponPy, Rad);
	}
	//かいふくアイテム
	if (KaihukuImgLife == 1) {
		image(KaihukuImg, KaihukuPx, KaihukuPy, Rad);
	}
	//宝玉
	if (HougyokuImgLife == 1) {
		image(HougyokuImg, HougyokuPx, HougyokuPy, Rad);
	}
}

void AITEM_WINDOW::setWeaponImgLife(int life) { WeaponImgLife = life; }
void AITEM_WINDOW::setHealImgLife(int life) { KaihukuImgLife = life; }
void AITEM_WINDOW::setHougyokuImgLife(int life) { HougyokuImgLife = life; }
int AITEM_WINDOW::weaponImgLife() { return WeaponImgLife; }
int AITEM_WINDOW::kaihukuImgLife() { return KaihukuImgLife; }
