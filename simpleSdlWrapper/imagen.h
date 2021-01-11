#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100
typedef struct Img
{
	int id;
	SDL_Surface* imagen;
	SDL_Texture* texture;
	SDL_Rect dest;
}IMG;

int  irudiaKargatu(char *fileName);
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void irudiakMarraztu(void);
void irudiaKendu(int id);
//Nuevo
//SPRITES

void KargatuMapa(char mapa[], void** pixels, int* pitch, Uint8* bpp);
int spriteKargatu(char* fileName);
void spriteMugitu(int numImg, int x, int y);
void spriteakMarraztu(int x, int y);
void spriteKendu(int id);
int spritearenPosizioaAurkitu(int id);
Uint32 getpixel(void* pixels, int pitch, Uint8 bpp, int x, int y);

#endif
