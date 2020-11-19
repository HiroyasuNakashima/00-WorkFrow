#pragma once
#include"CONTAINER.h"

class SAIDAN {
public:
	void init(CONTAINER* c);
	void draw();
	float px();
	float py();
private:
	int Img;
	float Px;
	float Py;
	float Rad;
};