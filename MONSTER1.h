#include"CHARACTER.h"

class MONSTER1 :public CHARACTER {
public:
	MONSTER1();
private:
	int FrontAnimId = 0;
	int BackAnimId = 0;
	int RightAnimId = 0;
	int LeftAnimId = 0;
};