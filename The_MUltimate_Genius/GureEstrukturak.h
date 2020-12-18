#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H
#define SOINU_KOP 5

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
	POSIZIOA pos;
	int id;
	MOTA mota;
}JOKO_ELEMENTUA;

char* soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\128NIGHT_01.wav", ".\\sound\\132TRANCE_02.wav",
                        ".\\sound\\BugleCall.wav",  ".\\sound\\terminator.wav" };

typedef struct S_GURE_GAUZAK
{
    int idSounds[SOINU_KOP];
    int idIrudi;
}GURE_GAUZAK;

#endif