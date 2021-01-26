#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#include "ebentoak.h"
#include "Jokalaria.h"

//--------------pertsonaia--------------
#define CHICO_AVATAR ".\\img\\pertsonaia\\PersonajeChicoHablando.bmp"
#define CHICA_AVATAR ".\\img\\pertsonaia\\PersonajeChicaHablando.bmp"
#define CHICO_AVATAR_M ".\\img\\pertsonaia\\PersonajeChicoVF_.bmp"
#define CHICA_AVATAR_M ".\\img\\pertsonaia\\PersonajeChicaVF_.bmp"
#define CHICO_AVATAR_G ".\\img\\pertsonaia\\PersonajeChicoGalderak.bmp"
#define CHICA_AVATAR_G ".\\img\\pertsonaia\\PersonajeChicaGalderak.bmp"

//--------------abisuak--------------
#define HUTSUNERIK_EZ ".\\img\\abisuak\\hutsunerikEz.bmp"
#define OBRAK ".\\img\\abisuak\\obrak.bmp"
#define BUKATU ".\\img\\abisuak\\klaseaBukatu.bmp"
#define BOTA ".\\img\\abisuak\\GelatikBota.bmp"

//----------busa----------
#define BUS_1 ".\\img\\GIF\\bus_1.bmp"
#define BUS_2 ".\\img\\GIF\\bus_2.bmp"
#define BUS_3 ".\\img\\GIF\\bus_3.bmp"
#define BUS_4 ".\\img\\GIF\\bus_4.bmp"
#define BUS_5 ".\\img\\GIF\\bus_5.bmp"
#define BUS_6 ".\\img\\GIF\\bus_6.bmp"
#define BUS_7 ".\\img\\GIF\\bus_7.bmp"
#define BUS_8 ".\\img\\GIF\\bus_8.bmp"
#define BUS_9 ".\\img\\GIF\\bus_9.bmp"
#define BUS_10 ".\\img\\GIF\\bus_10.bmp"
#define BUS_11 ".\\img\\GIF\\bus_11.bmp"
#define BUS_12 ".\\img\\GIF\\bus_12.bmp"
#define BUS_13 ".\\img\\GIF\\bus_13.bmp"
#define BUS_14 ".\\img\\GIF\\bus_14.bmp"
#define BUS_15 ".\\img\\GIF\\bus_15.bmp"
#define BUS_16 ".\\img\\GIF\\bus_16.bmp"
#define BUS_17 ".\\img\\GIF\\bus_17.bmp"
#define BUS_18 ".\\img\\GIF\\bus_18.bmp"
#define BUS_19 ".\\img\\GIF\\bus_19.bmp"
#define BUS_20 ".\\img\\GIF\\bus_20.bmp"
#define BUS_21 ".\\img\\GIF\\bus_21.bmp"
#define BUS_22 ".\\img\\GIF\\bus_22.bmp"

typedef enum { GORRIA = 249, BELTZA = 0, TXURIA = 255, BERDEA = 250, HORIA = 127, MOREA = 253, URDINA = 252 }KOLOREAK;



typedef struct S_BEHEKOPIXEL
{
	KOLOREAK ezker;
	KOLOREAK eskuin;
}BEHEKOPIXEL;

typedef struct S_ALBOKOPIXEL
{
	KOLOREAK goikoa;
	KOLOREAK erdikoa;
	KOLOREAK behekoa;
}ALBOKOPIXEL;

typedef struct S_HITBOX
{
	ALBOKOPIXEL ezker;
	ALBOKOPIXEL eskuin;
	BEHEKOPIXEL behekoa;
	KOLOREAK goikoa;

}HITBOX;


//---------------------------------------------------------------------------
int hasieratu(void);
void koadroaMarraztu(int x1, int y1, int x2, int y2);
void crearLista(char str[]);
int fondoPantaila(char* str);
void warning_abisua(char* str);
void karga_gif();
void IntStrBihurtu(int n, char str[]);
void StrBihurtu_nibela(char str[], int nvl);
void StrBihurtu_exp(char str[], int xp_orain, int max);
void crearCuadro(int x, int y, int luzera, int altuera);

#endif
