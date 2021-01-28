#include"CHARACTER.h"

class MONSTER2 :public CHARACTER {
public:
	MONSTER2();
private:
	int FrontAnimId = 0;
	int BackAnimId = 0;
	int RightAnimId = 0;
	int LeftAnimId = 0;
};