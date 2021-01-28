#pragma once
class CONTAINER;
class IMG;
class MAP;
class CHARAMAP;
class CHARACTER_MANAGER;

class GAME {
public:
	GAME();
	~GAME();
	void proc();
private:
	enum GAME_STATE {
		GAME_STATE_TITLE, GAME_STATE_PLAY, GAME_STATE_BUTTLE,
		GAME_STATE_CLEAR, GAME_STATE_GAMEOVER
	};
	GAME_STATE GameState = GAME_STATE_TITLE;
	CONTAINER* C = 0;
	IMG* Title = 0;
	MAP* Map = 0;
	CHARAMAP* CharaMap = 0;
	CHARACTER_MANAGER* Charas = 0;
};