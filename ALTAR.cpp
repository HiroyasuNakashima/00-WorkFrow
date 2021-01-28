#include"CONTAINER.h"
#include"ALTAR.h"

ALTAR::ALTAR() : CHARACTER(C->altarNumAnims){
	//CHARACTER::menber
	Anims[0] = &C->altarAnim;
	CharaId = C->altarCharaId;
}