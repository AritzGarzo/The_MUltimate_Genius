#ifndef GALDERAK_H
#define GALDERAK_H

#define GELAIDMAX 11
#define GALDERAIDMAX 6

#include"GureEstrukturak.h"


int galderak(int gelaID);



void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota);
void fondoPantailaGalderekin(char* str, int galderaID, int gelaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
int GalderakErantzun(int exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);


#endif // !FUNTZIOAK_H