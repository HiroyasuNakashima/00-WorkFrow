#pragma once
#include"CONTAINER.h"

class AITEM_WINDOW {
public:
	void init(CONTAINER* c);
	void draw();
	void setWindowLife(int life);
	void setWeaponImgLife(int life);
	void setKaihukuImgLife(int life);
	void setHougyokuImgLife(int life);
	int windowLife();
	int weaponImgLife();
	int kaihukuImgLife();
	int hougyokuImgLife();
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
	float Rad;
	int WindowLife;
	int WeaponImgLife;
	int KaihukuImgLife;
	int HougyokuImgLife;
};