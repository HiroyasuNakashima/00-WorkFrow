#include"CHARACTER.h"
class CHARAMAP;

class PLAYER :public CHARACTER {
public:
	PLAYER();
	void update();
private:
	int FrontAnimId = 0;
	int BackAnimId = 0;
	int RightAnimId = 0;
	int LeftAnimId = 0;
	int ChipSize = 0;
	int MoveCnt = 0;
};