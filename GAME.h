class CONTAINER;
class TEXT;
class GAMEOVER;
class TITLE;
class MAP;
class PLAYER;
class MURABITO1;
class MURABITO2;
class MONSTER1;
class MONSTER2;
class MONSTER3;
class BUTTLE1;
class BUTTLE2;
class BUTTLE3;

class GAME {
public:
	GAME();
	~GAME();
	void proc();
	enum GAME_STATE {
		GAME_TITLE, GAME_PLAY, GAME_BUTTLE1, GAME_BUTTLE2, GAME_BUTTLE3,
		GAME_GAMEOVER, GAME_CLEAR
	};
private:
	GAME_STATE GameState = GAME_TITLE;
	CONTAINER* C = 0;
	TEXT* T = 0;
	GAMEOVER* Gameover = 0;
	TITLE* Title = 0;
	MAP* Map = 0;
	PLAYER* Player = 0;
	MURABITO1* Murabito1 = 0;
	MURABITO2* Murabito2 = 0;
	MONSTER1* Monster1 = 0;
	MONSTER2* Monster2 = 0;
	MONSTER3* Monster3 = 0;
	BUTTLE1* Buttle1 = 0;
	BUTTLE2* Buttle2 = 0;
	BUTTLE3* Buttle3 = 0;
};
