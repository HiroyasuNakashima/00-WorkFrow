#include<stdio.h>
#include"graphic.h"
#include"ANIM.h"

ANIM::~ANIM() {
	if (Images) { delete[]Images; Images = 0; }
}

void ANIM::create(int numImages, const char* filenameWithouExt, int animInterval) {
	NumImages = numImages;
	Images = new int[NumImages];
	char filename[256];
	for (int i = 0; i < NumImages; i++) {
		sprintf_s(filename, "assets/chara/%s%d.png", filenameWithouExt, i + 1);
		Images[i] = loadImage(filename);
	}
	AnimInterval = animInterval;
}
void ANIM::draw(float x, float y, int animCnt, float r, float g, float b, float a) {
	int i = 0;
	if (NumImages > 1) {
		i = animCnt / AnimInterval % NumImages;
		animCnt %= AnimInterval * NumImages;
	}
	image(Images[i], x, y);
	COLOR(r, g, b, a);
}
int ANIM::animInterval() { return AnimInterval; }