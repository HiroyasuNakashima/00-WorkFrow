#pragma once
class CONTAINER;
class CHARACTER_MANAGER;

class CHARAMAP {
public:
	CHARAMAP();
	~CHARAMAP();
	void init();
	void draw();
	bool collisionCheck(float px, float py);
	int chipSize();
	static void setContainer(CONTAINER* c) { C = c; }
	static void setCharacterManager(CHARACTER_MANAGER* characterManager) {
		CharacterManager = characterManager;
	}
private:
	int ChipSize = 0;
	char* Data = 0;
	int NumDataColumns = 0;
	int NumDataRows = 0;
	static CONTAINER* C;
	static CHARACTER_MANAGER* CharacterManager;
};