#ifndef GALDERAK_H
#define GALDERAK_H

#define GELAIDMAX 11
#define GALDERAIDMAX 6

#include"GureEstrukturak.h"


int galderak(int gelaID,JOKALARIA* jokalaria, GALDERA galdera[GELAIDMAX][GALDERAIDMAX],int* eguna);



void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota);
void fondoPantailaGalderekin(char* str, int galderaID, int gelaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
int GalderakErantzun(int exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
//--------
void azterketa(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int* exp);

#endif // !FUNTZIOAK_H