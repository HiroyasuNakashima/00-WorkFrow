#include"ANIM.h"
#include"MAP.h"
#include"CHARAMAP.h"
#include"CHARACTER.h"
MAP* CHARACTER::Map = 0;
CHARAMAP* CHARACTER::CharaMap = 0;
CONTAINER* CHARACTER::C = 0;

CHARACTER::CHARACTER(int numAnims) {
	Anims = new ANIM*[numAnims];
}
CHARACTER::~CHARACTER() {
	if (Anims) { delete[] Anims; }
}
void CHARACTER::init() {
	Alpha = 0.0f;
	Life = 0;
}
void CHARACTER::appear(float px, float py, float dx, float dy) {
	Px = px;
	Py = py;
	Alpha = 1.0f;
}
void CHARACTER::update() {
	AnimCnt++;
}
void CHARACTER::draw() {
	Anims[AnimId]->draw(Px, Py, AnimCnt, Red, Green, Blue, Alpha);
}
void CHARACTER::InitRGBA() {
	Red = 1.0f;
	Green = 1.0f;
	Blue = 1.0f;
	Alpha = 1.0f;
}
void CHARACTER::setAnimId(int animId) { AnimId = animId; }

int CHARACTER::life() { return Life; }
int CHARACTER::animId() { return AnimId; }
char CHARACTER::charaId() { return CharaId; }
float CHARACTER::alpha() { return Alpha; }
float CHARACTER::px() { return Px; }
float CHARACTER::py() { return Py; }