#pragma once
class ANIM;
class MAP;
class CHARAMAP;
class CONTAINER;

class CHARACTER {
public:
	CHARACTER(int numAnims);
	virtual ~CHARACTER();
	virtual void init();
	virtual void appear(float px, float py, float dx, float dy);
	virtual void update();
	virtual void draw();
	void setAnimId(int animId);
	int life();
	int animId();
	char charaId();
	float alpha();
	float px();
	float py();
	static void setMap(MAP* map) { Map = map; }
	static void setCharaMap(CHARAMAP* charaMap) { CharaMap = charaMap; }
	static void setContainer(CONTAINER* c) { C = c; }
protected:
	void InitRGBA();
	ANIM** Anims = 0;
	int Total = 0;
	int AnimId = 0;
	int AnimCnt = 0;
	char CharaId = 0;
	float Px = 0;
	float Py = 0;
	float Red = 1;
	float Green = 1;
	float Blue = 1;
	float Alpha = 0;
	float AlphaDecayVal = 0;
	int Life = 0;
	int InitialLife = 0;
	float Dx = 0;
	float Dy = 0;
	float Speed = 0;
	static MAP* Map;
	static CHARAMAP* CharaMap;
	static CONTAINER* C;
};