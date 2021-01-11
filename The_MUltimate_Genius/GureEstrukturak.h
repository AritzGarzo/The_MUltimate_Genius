#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H

#include "ebentoak.h"



//--------------pantailak--------------
#define MENUA_F ".\\img\\menu.bmp"
#define KONTROLAK_F ".\\img\\kontrolak.bmp"
#define PROFILA_F ".\\img\\profila.bmp"
#define ETXEA_F ".\\img\\etxea.bmp"
#define UNI_F ".\\img\\uni.bmp"
//--------------pertsonaia--------------
#define CHICO_AVATAR ".\\img\\PersonajeChicoHablando.bmp"
#define CHICA_AVATAR ".\\img\\PersonajeChicaHablando.bmp"
#define CHICO_AVATAR_M ".\\img\\PersonajeChicoVF.bmp"
#define CHICA_AVATAR_M ".\\img\\PersonajeChicaVF.bmp"
//--------------extrak--------------
#define ABISUA ".\\img\\abisua.bmp"
//#define BUS_GIF ".\\img\\GIF\\bus_karga.gif"
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

typedef enum { MENUA_P, PROFILA_P, JOLASTU_P, IRTEN_P, KONTROLAK_P, KARGATU_P, ETXEA_P, UNI_P }EGOERA;

typedef struct exp
{
	int xp;//galderekin irabazi duen 
	int max;//ikasgaiKop*20
}EXP;

typedef struct ikasgai
{
	float notaFinala;
	char izena[128];
	char karpeta[128];
	/*
	* GALDERAK ETA
	* separar por carpetas
	* cada carpeta tenga el nombre de la asignatura
	* dentro pregunta y su respuesta
	* aparece pregunta y jugador decide (click)coordenadas
	*/

}IKASGAI;

typedef struct gradua
{
	int iKop;//ikasgai 
	char izena[128];
	IKASGAI* ikasgaiak;
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
	EXP exp;
}JOKALARIA;

#endif