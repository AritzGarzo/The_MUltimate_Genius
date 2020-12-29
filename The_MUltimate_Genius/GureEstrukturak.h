#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;

typedef struct
{
	int id;//irudia (las preguntas)
	int id_2d;//mugituko den irudia (movimientos/animaciones)
	char izena[128];
	//GRADUA gradua;
	POSIZIOA pos;
}JOKALARIA;

typedef struct
{
	int id;
	POSIZIOA pos_hasi;
	POSIZIOA pos_buka;
}IRUDIA;

#endif