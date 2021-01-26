#ifndef JOKALARIA_H
#define JOKALARIA_H

#include "Galdera.h"

//------------------
typedef struct S_POSIZIOA
{
	int x;
	int y;
} POSIZIOA;

typedef struct exp
{
	int nvl;
	int xp;//galderekin irabazi duen 
	int max;//ikasgaiKop*20
}EXP;

typedef struct gradua
{
	int iKop;//ikasgai 
	char izena[128];
	EXP exp;
}GRADUA;

typedef struct irudia
{
	int id;
	char izena[128];
	POSIZIOA pos_hasi;//goi ezkerra
	POSIZIOA pos_buka;//behe eskubia
}IRUDIA;

typedef struct jokalaria
{

	int urtea;//jakiteko zenbateko esperientzia daukan
	char izena[128];
	POSIZIOA pos;//sprite-aren mugimendua
	IRUDIA irudia;//irudia (las preguntas)
	IRUDIA irudia2d;//mugituko den irudia (movimientos/animaciones)
	GRADUA gradua;
	int eguna;
}JOKALARIA;

//------------------

//------jokalaria
JOKALARIA pertsonaiaEratu(JOKALARIA jokalaria);
void experientzia_pantaila(JOKALARIA jokalaria);
int galderakEtaAukerakLotuFitxategiarenBitartez(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void azterketa(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int* exp, int eguna, JOKALARIA* jokalaria);

#endif // !JOKALARIA_H
