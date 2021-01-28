#include"CONTAINER.h"
#include"MONSTER3.h"

MONSTER3::MONSTER3() : CHARACTER(C->monster3NumAnims) {
	//CHARACTER::menber
	Anims[0] = &C->monster3FrontAnim;
	Anims[1] = &C->monster3BackAnim;
	Anims[2] = &C->monster3RightAnim;
	Anims[3] = &C->monster3LeftAnim;
	CharaId = C->monster3CharaId;
}