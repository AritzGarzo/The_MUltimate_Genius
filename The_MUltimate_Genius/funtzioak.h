#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define GELAIDMAX 11
#define GALDERAIDMAX 6

#include"GureEstrukturak.h"

int hasieratu(void);
//
int mu_hasieratu(void);
int menua(void);
void fondoPantaila(char* str);
int jolastu(void);
int kontrolak(void);

//----------NIREAK------
void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota);
void fondoPantailaGalderekin(char* str, int galderaID, int gelaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
int GalderakErantzun(int exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
//----PRUEBA CON FITX---
void galderakEtaAukerakLotu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);

#endif // !FUNTZIOAK_H
