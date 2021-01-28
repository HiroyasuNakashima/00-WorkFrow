#include"CONTAINER.h"
#include"MURABITO2.h"

MURABITO2::MURABITO2() : CHARACTER(C->murabito2NumAnims) {
	//CHARACTER::menber
	Anims[0] = &C->murabito2FrontAnim;
	Anims[1] = &C->murabito2BackAnim;
	Anims[2] = &C->murabito2RightAnim;
	Anims[3] = &C->murabito2LeftAnim;
	CharaId = C->murabito2CharaId;
}