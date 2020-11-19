#pragma once
#include"libOne.h"

class CONTAINER {
	class DATA* Data = 0;
	int NumData = 0;
public:
	CONTAINER() {
		//システム初期化
		window(800, 600, 1);
		//TITLE
		titleImg = loadImage("assets/SHIRO.png");
		//BACKGROUND
		backImg = loadImage("assets/BACKGROUND.png");
		//MAP
		iroiroAllImg = loadImage("assets/IROIRO.png");
		fieldImg = cutImage(iroiroAllImg, 0, 0, 32, 32);
		//祭壇
		saidanImg = cutImage(iroiroAllImg, 44, 400, 32, 32);
		//橋
		hashiTateImg = cutImage(iroiroAllImg, 44, 93, 32, 32);
		hashiYokoImg = cutImage(iroiroAllImg, 0, 96, 32, 32);
		//PUSH_ENTER_KEY
		pushenterTitleImg = loadImage("assets/PUSH_TITLE.png");
		pushenterImg = loadImage("assets/PUSH_ENTER.png");
		//GAMEOVER
		gameoverImg = loadImage("assets/GAMEOVER.png");
		//GAMECLEAR
		gameclearBackImg = loadImage("assets/GAMECLEAR_BACK.png");
		//TEXT
		textWindowImg = loadImage("assets/TEXTWINDOW.png");
		//AITEM_AICON
		aitemWindowImg = loadImage("assets/AITEM_WINDOW.png");
		playerAiconImg = loadImage("assets/PLAYER_AICON.png");
		weaponAiconImg = loadImage("assets/WEAPON_AICON.png");
		kaihukuAiconImg = loadImage("assets/KAIHUKU_AICON.png");
		hougyokuAiconImg = loadImage("assets/HOUGYOKU_AICON.png");
		//PLAYER
		playerAllImg = loadImage("assets/YUUSHA.png");
		playerMaeImg1 = cutImage(playerAllImg, 0, 0, 32, 32);
		playerMaeImg2 = cutImage(playerAllImg, 64, 0, 32, 32);
		playerLeftImg1 = cutImage(playerAllImg, 0, 33, 32, 32);
		playerLeftImg2 = cutImage(playerAllImg, 64, 33, 32, 32);
		playerRightImg1 = cutImage(playerAllImg, 0, 65, 32, 32);
		playerRightImg2 = cutImage(playerAllImg, 64, 65, 32, 32);
		playerUshiroImg1 = cutImage(playerAllImg, 0, 97, 32, 32);
		playerUshiroImg2 = cutImage(playerAllImg, 64, 97, 32, 32);
		//MURABITO1
		murabito1AllImg = loadImage("assets/MURABITO1.png");
		murabito1MaeImg1 = cutImage(murabito1AllImg, 0, 0, 32, 32);
		murabito1MaeImg2 = cutImage(murabito1AllImg, 64, 0, 32, 32);
		murabito1LeftImg1 = cutImage(murabito1AllImg, 0, 33, 32, 32);
		murabito1LeftImg2 = cutImage(murabito1AllImg, 64, 33, 32, 32);
		murabito1RightImg1 = cutImage(murabito1AllImg, 0, 65, 32, 32);
		murabito1RightImg2 = cutImage(murabito1AllImg, 64, 65, 32, 32);
		murabito1UshiroImg1 = cutImage(murabito1AllImg, 0, 97, 32, 32);
		murabito1UshiroImg2 = cutImage(murabito1AllImg, 64, 97, 32, 32);
		//MURABITO2
		murabito2AllImg = loadImage("assets/MURABITO2.png");
		murabito2MaeImg1 = cutImage(murabito2AllImg, 0, 0, 32, 32);
		murabito2MaeImg2 = cutImage(murabito2AllImg, 64, 0, 32, 32);
		murabito2LeftImg1 = cutImage(murabito2AllImg, 0, 32, 32, 32);
		murabito2LeftImg2 = cutImage(murabito2AllImg, 64, 32, 32, 32);
		murabito2RightImg1 = cutImage(murabito2AllImg, 0, 64, 32, 32);
		murabito2RightImg2 = cutImage(murabito2AllImg, 64, 64, 32, 32);
		murabito2UshiroImg1 = cutImage(murabito2AllImg, 0, 97, 32, 32);
		murabito2UshiroImg2 = cutImage(murabito2AllImg, 64, 97, 32, 32);
		//MONSTER1
		monster1AllImg = loadImage("assets/MONSTER1.png");
		monster1MaeImg1 = cutImage(monster1AllImg, 0, 0, 32, 32);
		monster1MaeImg2 = cutImage(monster1AllImg, 64, 0, 32, 32);
		monster1LeftImg1 = cutImage(monster1AllImg, 0, 33, 32, 32);
		monster1LeftImg2 = cutImage(monster1AllImg, 64, 33, 32, 32);
		monster1RightImg1 = cutImage(monster1AllImg, 0, 65, 32, 32);
		monster1RightImg2 = cutImage(monster1AllImg, 64, 65, 32, 32);
		monster1UshiroImg1 = cutImage(monster1AllImg, 0, 97, 32, 32);
		monster1UshiroImg2 = cutImage(monster1AllImg, 64, 97, 32, 32);
		//MONSTER2
		monster2AllImg = loadImage("assets/MONSTER2.png");
		monster2MaeImg1 = cutImage(monster2AllImg, 0, 0, 32, 32);
		monster2MaeImg2 = cutImage(monster2AllImg, 64, 0, 32, 32);
		monster2LeftImg1 = cutImage(monster2AllImg, 0, 33, 32, 32);
		monster2LeftImg2 = cutImage(monster2AllImg, 64, 33, 32, 32);
		monster2RightImg1 = cutImage(monster2AllImg, 0, 65, 32, 32);
		monster2RightImg2 = cutImage(monster2AllImg, 64, 65, 32, 32);
		monster2UshiroImg1 = cutImage(monster2AllImg, 0, 97, 32, 32);
		monster2UshiroImg2 = cutImage(monster2AllImg, 64, 97, 32, 32);
		//MONSTER3
		monster3AllImg = loadImage("assets/MONSTER3.png");
		monster3MaeImg1 = cutImage(monster3AllImg, 0, 0, 32, 32);
		monster3MaeImg2 = cutImage(monster3AllImg, 64, 0, 32, 32);
		monster3LeftImg1 = cutImage(monster3AllImg, 0, 33, 32, 32);
		monster3LeftImg2 = cutImage(monster3AllImg, 64, 33, 32, 32);
		monster3RightImg1 = cutImage(monster3AllImg, 0, 65, 32, 32);
		monster3RightImg2 = cutImage(monster3AllImg, 64, 65, 32, 32);
		monster3UshiroImg1 = cutImage(monster3AllImg, 0, 97, 32, 32);
		monster3UshiroImg2 = cutImage(monster3AllImg, 64, 97, 32, 32);
		//BUTTLE
		buttleBackImg = loadImage("assets/BUTTLE_BACK.png");
		buttleMonster1Img = loadImage("assets/BUTTLE_MON1.png");
		buttleMonster2Img = loadImage("assets/BUTTLE_MON2.png");
		buttleMonster3Img = loadImage("assets/BUTTLE_MON3.png");
		//BUTTLE_TEXT
		buttleTextWindowImg = loadImage("assets/BUTTLE_WINDOW.png");
		buttleTextMenyuImg = loadImage("assets/BUTTLE_MENYU.png");
		buttleCursorImg = loadImage("assets/BUTTLE_CURSOR.png");
		//エフェクト
		playerAttckAllImg = loadImage("assets/EFECT1.png"); //剣撃 
		playerAttckImg = cutImage(playerAttckAllImg, 720, 0, 240, 240);
		//HP_BAR
		hpbarImg = loadImage("assets/HP_BAR.png");
	}
	//プレイヤー、モンスターのHPやダメージ量----------------------------------
	//PLAYER
	const int playerLife = 200;
	const int playerAttckDamege = 22;
	const int playerAttckDamege2 = 45;//武器入手時
	//MONSTER1
	const int monster1Life = 150;
	const int monster1AttckDamege = 38;
	//MONSTER2
	const int monster2Life = 180;
	const int monster2AttckDamege = 56;
	//MONSTER3
	const int monster3Life = 250;
	const int monster3AttckDamege = 48;

	//CONTAINER---------------------------------------------------
	//BACKGROUND
	int backImg = 0;
	const float backPx = 0.0f;
	const float backPy = 0.0f;
	const float backRad = 0.0f;
	//TITLE
	int titleImg = 0;
	const float titlePx = 0.0f;
	const float titlePy = 50.0f;
	const float titleRad = 0.0f;
	const float titleTextPx1 = 100.0f;//ゲームルール説明
	const float titleTextPy1 = 300.0f;
	const float titleTextPx2 = 100.0f;//内容
	const float titleTextPy2 = 325.0f;
	const float titleTextPx3 = 100.0f;//操作説明
	const float titleTextPy3 = 350.0f;
	const float titleTextPx4 = 100.0f;//上下左右キー
	const float titleTextPy4 = 375.0f;
	const float titleTextPx5 = 100.0f;//Zキー
	const float titleTextPy5 = 400.0f;
	const float titleTextPx6 = 100.0f;//Xキー
	const float titleTextPy6 = 425.0f;
	//PUSH_ENTER_KEY
	int pushenterImg = 0;
	int pushenterTitleImg = 0;
	const float pushenterPx = 100.0f;
	const float pushenterPy = 330.0f;
	const float pushenterTitlePx = 100.0f;
	const float pushenterTitlePy = 425.0f;
	const float pushenterRad = 0.0f;
	const int pushenterCnt = 0;
	//GAMECLEAR
	int gameclearImg = 0;
	int gameclearBackImg = 0;
	const float gameclearPx = 0.0f;
	const float gameclearPy = 100.0f;
	const float gameclearBackPx = 0.0f;
	const float gameclearBackPy = 0.0f;
	//GAMEOVER
	int gameoverImg = 0;
	const float gameoverPx = 0.0f;
	const float gameoverPy = 100.0f;
	const float gameoverRad = 0.0f;
	//TEXT
	int textWindowImg = 0;
	const float textWindowPx = 100.0f;
	const float textWindowPy = 400.0f;
	const float textPx1 = 150.0f;
	const float textPy1 = 450.0f;
	const float textPx2 = 150.0f;
	const float textPy2 = 475.0f;
	const int textImgLife = 0;
	//MAP
	int iroiroAllImg = 0;
	int fieldImg = 0;
	const float rad = 0.0f;
	//祭壇
	int saidanImg = 0;
	const float saidanPx = 416.0f;
	const float saidanPy = 384.0f;
	//橋
	int hashiTateImg = 0;
	int hashiYokoImg = 0;
	//AITEM_AICON
	int aitemWindowImg = 0;
	int playerAiconImg = 0;
	int weaponAiconImg = 0;
	int kaihukuAiconImg = 0;
	int hougyokuAiconImg = 0;
	const float aitemWindowPx = 100.0f;
	const float aitemWindowPy = 450.0f;
	const float playerAiconPx = 130.0f;
	const float playerAiconPy = 462.5f;
	const float weaponAiconPx = 255.0f;
	const float weaponAiconPy = 462.5f;
	const float kaihukuAiconPx = 380.0f;
	const float kaihukuAiconPy = 462.5f;
	const float hougyokuAiconPx = 505.0f;
	const float hougyokuAiconPy = 462.5f;
	const int aitemWindowLife = 1;
	const int weaponImgLife = 0;
	const int kaihukuImgLife = 0;
	const int hougyokuImgLife = 0;
	//ANIM
	const int imgLife = 1;
	//PLAYER
	int playerAllImg = 0;
	int playerMaeImg1 = 0;
	int playerMaeImg2 = 0;
	int playerLeftImg1 = 0;
	int playerLeftImg2 = 0;
	int playerRightImg1 = 0;
	int playerRightImg2 = 0;
	int playerUshiroImg1 = 0;
	int playerUshiroImg2 = 0;
	const float playerPx = 384.0f;
	const float playerPy = 288.0f;
	const float playerRad = 0.0f;
	const float playerSpeed = 1.0f;
	const float playerDx = 0.0f;
	const float playerDy = 0.0f;
	const int playerDirectionCnt = 0;
	const float playertextPx = 600.0f;//残り日数(文字)
	const float playertextPy = 75.0f;
	const float playertextPx1 = 700.0f;//残り日数(数字)
	const float playertextPy1 = 75.0f;
	const int playertextDay = 10;//残り日数
	const int playerDayFlag = 0;
	const int playerDayFlag1 = 0;
	const int playerActionFlag = 0;
	const int playerTextFlag = 0;
	const int okFlag = 0;
	const int ngFlag = 0;
	//MURABITO1
	int murabito1AllImg = 0;
	int murabito1MaeImg1 = 0;
	int murabito1MaeImg2 = 0;
	int murabito1LeftImg1 = 0;
	int murabito1LeftImg2 = 0;
	int murabito1RightImg1 = 0;
	int murabito1RightImg2 = 0;
	int murabito1UshiroImg1 = 0;
	int murabito1UshiroImg2 = 0;
	const float murabito1Px = 448.0f;
	const float murabito1Py = 256.0f;
	const float murabito1Rad = 0.0f;
	//MURABITO2
	int murabito2AllImg = 0;
	int murabito2MaeImg1 = 0;
	int murabito2MaeImg2 = 0;
	int murabito2LeftImg1 = 0;
	int murabito2LeftImg2 = 0;
	int murabito2RightImg1 = 0;
	int murabito2RightImg2 = 0;
	int murabito2UshiroImg1 = 0;
	int murabito2UshiroImg2 = 0;
	const float murabito2Px = 320.0f;
	const float murabito2Py = 256.0f;
	const float murabito2Rad = 0.0f;
	//MONSTER1
	int monster1AllImg = 0;
	int monster1MaeImg1 = 0;
	int monster1MaeImg2 = 0;
	int monster1LeftImg1 = 0;
	int monster1LeftImg2 = 0;
	int monster1RightImg1 = 0;
	int monster1RightImg2 = 0;
	int monster1UshiroImg1 = 0;
	int monster1UshiroImg2 = 0;
	const float monster1Px = 384.0f;
	const float monster1Py = 224.0f;
	const float monster1Rad = 0.0f;
	//MONSTER2
	int monster2AllImg = 0;
	int monster2MaeImg1 = 0;
	int monster2MaeImg2 = 0;
	int monster2LeftImg1 = 0;
	int monster2LeftImg2 = 0;
	int monster2RightImg1 = 0;
	int monster2RightImg2 = 0;
	int monster2UshiroImg1 = 0;
	int monster2UshiroImg2 = 0;
	const float monster2Px = 416.0f;
	const float monster2Py = 352.0f;
	const float monster2Rad = 0.0f;
	//MONSTER3
	int monster3AllImg = 0;
	int monster3MaeImg1 = 0;
	int monster3MaeImg2 = 0;
	int monster3LeftImg1 = 0;
	int monster3LeftImg2 = 0;
	int monster3RightImg1 = 0;
	int monster3RightImg2 = 0;
	int monster3UshiroImg1 = 0;
	int monster3UshiroImg2 = 0;
	const float monster3Px = 416.0f;
	const float monster3Py = 160.0f;
	const float monster3Rad = 0.0f;
	//エフェクト
	int playerAttckAllImg = 0;
	int playerAttckImg = 0;
	//HP_BAR
	int hpbarImg = 0;
	const float hpbarPx = 630.0f;
	const float hpbarPy = 550.0f;
	//BUTTLE
	int buttleBackImg = 0;
	int buttleMonster1Img = 0;
	int buttleMonster2Img = 0;
	int buttleMonster3Img = 0;
	int buttleTextWindowImg = 0;
	int buttleTextMenyuImg = 0;
	int buttleCursorImg = 0;
	int buttleHpbarImg = 0;
	const float buttleBackPx = 0.0f;
	const float buttleBackPy = 0.0f;
	const float buttleMonsterPx = 280.0f;
	const float buttleMonsterPy = 75.0f;
	const float buttleTextWindowPx = 200.0f;
	const float buttleTextWindowPy = 350.0f;
	const float buttleTextMenyuPx = 0.0f;
	const float buttleTextMenyuPy = 350.0f;
	const float buttleCursorPx = 30.0f;
	const float buttleCursorPy = 403.0f;
	const float buttlePlayerAttckPx = 305.0f;
	const float buttlePlayerAttckPy = 75.0f;
	const float buttleRadian = 3.141592 / 180.0f;
	const float buttleRad = 0.0f;
	const int buttleAttckImgLife = 0;
	const int buttleMonsterImgLife = 1;
	const int buttleImgCnt = 0;
	const int buttleDamegeCnt = 0;
	const int buttleMonsterAttckFlag = 0;
	const int buttleTextFlag = 0;
	const float buttleTextPx1 = 250.0f;
	const float buttleTextPy1 = 425.0f;
	const float buttleTextPx2 = 200.0f;
	const float buttleTextPy2 = 450.0f;
	const float buttleHpTextPx1 = 635.0f;
	const float buttleHpTextPy1 = 540.0f;
	const float buttleHpTextPx2 = 665.0f;
	const float buttleHpTextPy2 = 540.0f;
	const float buttletatakauPx = 75.0f;
	const float buttletatakauPy = 425.0f;
	const float buttlekaihukuPx = 75.0f;
	const float buttlekaihukuPy = 475.0f;
	const float buttlenigeruPx = 75.0f;
	const float buttlenigeruPy = 525.0f;
	const float buttlePlayerAiconPx = 608.0f;
	const float buttlePlayerAiconPy = 390.0f;
	const int buttlePlayerActionFlag = 0;
	const int buttlePlayerWin = 0;
	const int buttlePlayerLose = 0;
	const int buttlePlayerEscape = 0;




	//~CONTAINER();
	////ファイルからデータを読み込む
	//int loadData(const char* filename);
	////データをfloat値として取得
	//float fData(const char* name);
	////データをint値として取得
	//int iData(const char* name);
};