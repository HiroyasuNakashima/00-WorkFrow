#include"CONTAINER.h"
#include"MURABITO1.h"

MURABITO1::MURABITO1() : CHARACTER(C->murabito1NumAnims) {
	//CHARACTER::menber
	Anims[0] = &C->murabito1FrontAnim;
	Anims[1] = &C->murabito1BackAnim;
	Anims[2] = &C->murabito1RightAnim;
	Anims[3] = &C->murabito1LeftAnim;
	CharaId = C->murabito1CharaId;
}