#pragma once
class CONTAINER;
class CHARACTER;
class TEXT_READ;

class CHARACTER_MANAGER {
public:
	CHARACTER_MANAGER();
	~CHARACTER_MANAGER();
	void init();
	void appear(char charaId, float px, float py, float dx, float dy);
	void update();
	void draw();
	void playerAction(int animId);
	char textCharaId();
	//char setTextCharaId(char textCharaId);
	static void setContainer(CONTAINER* c) { C = c; };
private:
	CHARACTER** Charas = 0;
	TEXT_READ* Conv = 0;
	int Total = 0;
	int PlayerChipSize = 0;
	char TextCharaId = 0;//テキストを表示用CharaId
	static CONTAINER* C;

	int Flag = 0;
};