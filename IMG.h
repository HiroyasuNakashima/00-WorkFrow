#pragma once
class CONTAINER;

class IMG {
public:
	void draw();
	static void setContainer(CONTAINER* c) { C = c; }
protected:
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float R = 1;
	float G = 1;
	float B = 1;
	float A = 1;
	static CONTAINER* C;
};