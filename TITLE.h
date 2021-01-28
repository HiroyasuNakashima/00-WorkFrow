#pragma once
#include"IMG.h"
#include"CONTAINER.h"

class TITLE : public IMG {
public:
	TITLE() {
		Img = C->titleBackImg;
		Px = C->titleBackPx;
		Py = C->titleBackPy;
		R = C->titleR;
		G = C->titleG;
		B = C->titleB;
	}
};
