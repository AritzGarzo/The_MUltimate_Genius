#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100

int  irudiaKargatu(char *fileName);
void  irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void irudiaKendu(int id);

int spriteKargatu(char* fileName);
void spriteMugitu(int numImg, int x, int y);
void spriteakMarraztu(int x, int y);
void spriteKendu(int id);
int spritearenPosizioaAurkitu(int id);
#endif
