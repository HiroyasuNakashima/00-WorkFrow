#pragma once
#include"CONTAINER.h"

class AITEM_WINDOW {
public:
	void init(CONTAINER* c);
	void draw();
	void setWeaponImgLife(int life);
	void setHealImgLife(int life);
	void setHougyokuImgLife(int life);
	int weaponImgLife();
	int kaihukuImgLife();
private:
	int WindowImg;
	int PlayerImg;
	int WeaponImg;
	int KaihukuImg;
	int HougyokuImg;
	float WindowPx;
	float WindowPy;
	float PlayerPx;
	float PlayerPy;
	float WeaponPx;
	float WeaponPy;
	float KaihukuPx;
	float KaihukuPy;
	float HougyokuPx;
	float HougyokuPy;
	float Rad = 0.0f;
	int WeaponImgLife;
	int KaihukuImgLife;
	int HougyokuImgLife;
};