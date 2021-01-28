#include"graphic.h"
#include"CONTAINER.h"
#include"IMG.h"

CONTAINER* IMG::C = 0;

void IMG::draw() {
	image(Img, Px, Py);
	COLOR(R, G, B, A);
}
