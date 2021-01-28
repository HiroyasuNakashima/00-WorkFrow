#pragma once
#include"IMG.h"
#include"CONTAINER.h"

class TEXT_WINDOW : public IMG {
public:
	TEXT_WINDOW() {
		Img = C->textWindowImg;
		Px = C->textWindowPx;
		Py = C->textWindowPy;
		R = C->textWindowR;
		G = C->textWindowG;
		B = C->textWindowB;
	}
};