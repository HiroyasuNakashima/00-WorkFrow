#pragma once
class CONTAINER;
class CHARACTER;

class CHARACTER_MANAGER {
public:
	CHARACTER_MANAGER();
	~CHARACTER_MANAGER();
	void init();
	void appear(char charaId, float px, float py, float dx, float dy);
	void update();
	void draw();
	void playerAction(int animId);
	static void setContainer(CONTAINER* c) { C = c; };
private:
	CHARACTER** Charas = 0;
	int Total = 0;
	int PlayerChipSize = 0;
	static CONTAINER* C;
};