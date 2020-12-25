#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100

int  irudiaKargatu(char *fileName);
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void spriteakMarraztu(void);
void irudiaKendu(int id);

//SPRITES

int spriteKargatu(char* fileName);
void spriteMugitu(int numImg, int x, int y);
void spriteakMarraztu(void);
void spriteKendu(int id);
int spritearenPosizioaAurkitu(int id);

#endif
