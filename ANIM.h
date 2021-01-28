#pragma once

class ANIM {
public:
	~ANIM();
	void create(int numImages, const char* filenameWithoutExt, int animInterval);
	void draw(float x, float y, int animCnt, float r, float g, float b, float a);
	int animInterval();
private:
	int NumImages = 0;
	int* Images = 0;
	int AnimInterval = 1;
};