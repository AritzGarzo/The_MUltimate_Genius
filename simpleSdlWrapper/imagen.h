#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100

int  irudiaKargatu(char* fileName);
void  irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void irudiaKendu(int id);

int spriteKargatu(char* fileName);
void spriteMugitu(int numImg, int x, int y);
void spriteakMarraztu(int x, int y);
void spriteKendu(int id);
int spritearenPosizioaAurkitu(int id);
void KargatuMapa(char mapa[], void** pixels, int* pitch, Uint8* bpp);
Uint32 getpixel(void* pixels, int pitch, Uint8 bpp, int x, int y);
#endif