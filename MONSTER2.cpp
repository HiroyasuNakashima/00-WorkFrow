#include"CONTAINER.h"
#include"MONSTER2.h"

MONSTER2::MONSTER2() : CHARACTER(C->monster2NumAnims) {
	//CHARACTER::menber
	Anims[0] = &C->monster2FrontAnim;
	Anims[1] = &C->monster2BackAnim;
	Anims[2] = &C->monster2RightAnim;
	Anims[3] = &C->monster2LeftAnim;
	CharaId = C->monster2CharaId;
}