#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;

#define CHICA_AVATAR ".\\img\\chica....bmp";
#define CHICO_AVATAR ".\\img\\chico....bmp";

typedef struct
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

typedef struct
{
	int xp;//galderekin irabazi duen 
	int max;//ikasgaiKop*20
}EXP;

typedef struct
{
	int iKop;//ikasgai 
	char izena[128];
	IKASGAI* ikasgaiak;
}GRADUA;

typedef struct
{
	int id;
	char izena[128];
	POSIZIOA pos_hasi;//goi ezkerra
	POSIZIOA pos_buka;//behe eskubia
}IRUDIA;

typedef struct
{
	int urtea;//jakiteko zenbateko esperientzia daukan
	IRUDIA irudia;//irudia (las preguntas)
	IRUDIA irudia2d;//mugituko den irudia (movimientos/animaciones)
	char izena[128];
	GRADUA gradua;
	POSIZIOA pos;
}JOKALARIA;

#endif