#ifndef GALDERAK_H
#define GALDERAK_H

#define GELAIDMAX 11
#define GALDERAIDMAX 6

#include"GureEstrukturak.h"


EGOERA galderak(int gelaID, JOKALARIA* jokalaria, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);



void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota);
void fondoPantailaGalderekin(char* str, int galderaID, int gelaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], JOKALARIA jokalaria);
EGOERA GalderakErantzun(EXP* exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int eguna);
void azterketa(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int* exp, int eguna, JOKALARIA jokalaria);

#endif // !FUNTZIOAK_H