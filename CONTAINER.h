#pragma once
#include"libOne.h"
#include"graphic.h"
#include"IMG.h"
#include"MAP.h"
#include"CHARAMAP.h"
#include"ANIM.h"
#include"CHARACTER.h"
#include"CHARACTER_MANAGER.h"
#include"CONVERSATION.h"

class CONTAINER {
public:
	//プレイヤーHP～モンスター攻撃力---------------------------
	const int playerLife = 200;


	//SYSTEM---------------------------------------------------
	const int windowWidth = 800;
	const int windowHeidth = 640;
	//TITLE
	int titleBackImg = 0;
	const float titleBackPx = 0.0f;
	const float titleBackPy = 0.0f;
	const float titleR = 0.0f;
	const float titleG = 0.0f;
	const float titleB = 0.0f;
	//MAP
	int mapAllImg = 0;
	int mapFieldImg = 0;
	int mapVerticalBridge = 0;//縦向き
	int mapSideWaysBridge = 0;//横向き
	const int mapChipsize = 32;
	const char* mapDataFile1 = "assets/mapdata/map1.txt";
	//CHARAMAP
	const int charaMapChipsize = 32;
	const char* charaMapDataFile1 = "assets/mapdata/chara1.txt";
	//CHARACTER_MANAGER
	const int numPlayers = 1;
	const int numMurabito1 = 1;
	const int numMurabito2 = 1;
	const int numMonster1 = 1;
	const int numMonster2 = 1;
	const int numMonster3 = 1;
	const int numAltar = 1;
	//PLAYER
	ANIM playerFrontAnim;
	ANIM playerBackAnim;
	ANIM playerRightAnim;
	ANIM playerLeftAnim;
	const int playerNumAnims = 4;
	const int playerFrontAnimId = 0;
	const int playerBackAnimId = 1;
	const int playerRightAnimId = 2;
	const int playerLeftAnimId = 3;
	const int playerChipSize = 32;
	const int playerMoveCnt = 32;
	const float playerSpeed = 1.0f;
	const char playerCharaId = 'a';
	//MURABITO1
	ANIM murabito1FrontAnim;
	ANIM murabito1BackAnim;
	ANIM murabito1RightAnim;
	ANIM murabito1LeftAnim;
	const int murabito1NumAnims = 4;
	const int murabito1FrontAnimId = 0;
	const int murabito1BackAnimId = 1;
	const int murabito1RightAnimId = 2;
	const int murabito1LeftAnimId = 3;
	const char murabito1CharaId = 'b';
	//MURABITO2
	ANIM murabito2FrontAnim;
	ANIM murabito2BackAnim;
	ANIM murabito2RightAnim;
	ANIM murabito2LeftAnim;
	const int murabito2NumAnims = 4;
	const int murabito2FrontAnimId = 0;
	const int murabito2BackAnimId = 1;
	const int murabito2RightAnimId = 2;
	const int murabito2LeftAnimId = 3;
	const char murabito2CharaId = 'c';
	//MONSTER1
	ANIM monster1FrontAnim;
	ANIM monster1BackAnim;
	ANIM monster1RightAnim;
	ANIM monster1LeftAnim;
	const int monster1NumAnims = 4;
	const int monster1FrontAnimId = 0;
	const int monster1BackAnimId = 1;
	const int monster1RightAnimId = 2;
	const int monster1LeftAnimId = 3;
	const char monster1CharaId = 'd';
	//MONSTER2
	ANIM monster2FrontAnim;
	ANIM monster2BackAnim;
	ANIM monster2RightAnim;
	ANIM monster2LeftAnim;
	const int monster2NumAnims = 4;
	const int monster2FrontAnimId = 0;
	const int monster2BackAnimId = 1;
	const int monster2RightAnimId = 2;
	const int monster2LeftAnimId = 3;
	const char monster2CharaId = 'e';
	//MONSTER3
	ANIM monster3FrontAnim;
	ANIM monster3BackAnim;
	ANIM monster3RightAnim;
	ANIM monster3LeftAnim;
	const int monster3NumAnims = 4;
	const int monster3FrontAnimId = 0;
	const int monster3BackAnimId = 1;
	const int monster3RightAnimId = 2;
	const int monster3LeftAnimId = 3;
	const char monster3CharaId = 'f';
	//祭壇
	ANIM altarAnim;
	const int altarNumAnims = 1;
	const int altarAnimId = 0;
	const char altarCharaId = 'g';
	//テキスト
	//外枠 通常
	int textWindowImg = 0;
	const float textWindowPx = 100.0f;
	const float textWindowPy = 400.0f;
	const float textWindowR = 0.0f;
	const float textWindowG = 0.0f;
	const float textWindowB = 0.0f;
	//バトル中
	//文字表示位置　通常
	const float textPx = 150.0f;
	const float textPy = 450.0f;
	//コンストラクタ
	CONTAINER() {
		//システム初期化-----------------------------------------------
		window(windowWidth, windowHeidth, 1);
		//画像読み込み-------------------------------------------------
		titleBackImg = loadImage("assets/TITLE_BACK.png");
		mapAllImg = loadImage("assets/mapchip/mapall.png");
		mapFieldImg = cutImage(mapAllImg, 0, 0, 32, 32);
		mapVerticalBridge = cutImage(mapAllImg, 44, 93, 32, 32);
		mapSideWaysBridge = cutImage(mapAllImg, 0, 93, 32, 32);
		textWindowImg = loadImage("assets/TEXTWINDOW.png");
		//アニメーション画像読み込み
		playerFrontAnim.create(4, "playerF", 20);
		playerRightAnim.create(4, "playerR", 20);
		playerBackAnim.create(4, "playerB", 20);
		playerLeftAnim.create(4, "playerL", 20);
		murabito1FrontAnim.create(4, "murabito1F", 20);
		murabito1RightAnim.create(4, "murabito1R", 20);
		murabito1BackAnim.create(4, "murabito1B", 20);
		murabito1LeftAnim.create(4, "murabito1L", 20);
		murabito2FrontAnim.create(4, "murabito2F", 20);
		murabito2RightAnim.create(4, "murabito2R", 20);
		murabito2BackAnim.create(4, "murabito2B", 20);
		murabito2LeftAnim.create(4, "murabito2L", 20);
		monster1FrontAnim.create(4, "monster1F", 20);
		monster1RightAnim.create(4, "monster1R", 20);
		monster1BackAnim.create(4, "monster1B", 20);
		monster1LeftAnim.create(4, "monster1L", 20);
		monster2FrontAnim.create(4, "monster2F", 20);
		monster2RightAnim.create(4, "monster2R", 20);
		monster2BackAnim.create(4, "monster2B", 20);
		monster2LeftAnim.create(4, "monster2L", 20);
		monster3FrontAnim.create(4, "monster3F", 20);
		monster3RightAnim.create(4, "monster3R", 20);
		monster3BackAnim.create(4, "monster3B", 20);
		monster3LeftAnim.create(4, "monster3L", 20);
		altarAnim.create(1, "altar", 0);
		//コンテナ情報を必要なクラスへポインタを渡す-------------------
		IMG::setContainer(this);
		MAP::setContainer(this);
		CHARAMAP::setContainer(this);
		CHARACTER::setContainer(this);
		CHARACTER_MANAGER::setContainer(this);
		CONVERSATION::setContainer(this);
	}
};