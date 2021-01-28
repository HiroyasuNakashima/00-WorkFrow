#include"CHARACTER.h"

class MONSTER3 :public CHARACTER {
public:
	MONSTER3();
private:
	int FrontAnimId = 0;
	int BackAnimId = 0;
	int RightAnimId = 0;
	int LeftAnimId = 0;
};