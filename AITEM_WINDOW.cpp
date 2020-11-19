#include"AITEM_WINDOW.h"

void AITEM_WINDOW::init(CONTAINER* c) {
	WindowImg = c->aitemWindowImg;
	PlayerImg = c->playerAiconImg;
	WeaponImg = c->weaponAiconImg;
	KaihukuImg = c->kaihukuAiconImg;
	HougyokuImg = c->hougyokuAiconImg;
	WindowPx = c->aitemWindowPx;
	WindowPy = c->aitemWindowPy;
	PlayerPx = c->playerAiconPx;
	PlayerPy = c->playerAiconPy;
	WeaponPx = c->weaponAiconPx;
	WeaponPy = c->weaponAiconPy;
	KaihukuPx = c->kaihukuAiconPx;
	KaihukuPy = c->kaihukuAiconPy;
	HougyokuPx = c->hougyokuAiconPx;
	HougyokuPy = c->hougyokuAiconPy;
	Rad = c->rad;
	WindowLife = c->aitemWindowLife;
	WeaponImgLife = c->weaponImgLife;
	KaihukuImgLife = c->kaihukuImgLife;
	HougyokuImgLife = c->hougyokuImgLife;
}
void AITEM_WINDOW::draw() {
	if(WindowLife == 1){
		image(WindowImg, WindowPx, WindowPy, Rad);
		image(PlayerImg, PlayerPx, PlayerPy, Rad);
		if (WeaponImgLife == 1) {
			image(WeaponImg, WeaponPx, WeaponPy, Rad);
		}
		if (KaihukuImgLife == 1) {
			image(KaihukuImg, KaihukuPx, KaihukuPy, Rad);
		}
		if (HougyokuImgLife == 1) {
			image(HougyokuImg, HougyokuPx, HougyokuPy, Rad);
		}
	}
}

void AITEM_WINDOW::setWindowLife(int life) { WindowLife = life; }
void AITEM_WINDOW::setWeaponImgLife(int life) { WeaponImgLife = life; }
void AITEM_WINDOW::setKaihukuImgLife(int life) { KaihukuImgLife = life; }
void AITEM_WINDOW::setHougyokuImgLife(int life) { HougyokuImgLife = life; }
int AITEM_WINDOW::windowLife() { return WindowLife; }
int AITEM_WINDOW::weaponImgLife() { return WeaponImgLife; }
int AITEM_WINDOW::kaihukuImgLife() { return KaihukuImgLife; }
int AITEM_WINDOW::hougyokuImgLife() { return HougyokuImgLife; }
