#include"CONTAINER.h"
#include"MONSTER1.h"

MONSTER1::MONSTER1() : CHARACTER(C->monster1NumAnims) {
	//CHARACTER::menber
	Anims[0] = &C->monster1FrontAnim;
	Anims[1] = &C->monster1BackAnim;
	Anims[2] = &C->monster1RightAnim;
	Anims[3] = &C->monster1LeftAnim;
	CharaId = C->monster1CharaId;
}