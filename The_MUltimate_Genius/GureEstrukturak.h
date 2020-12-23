#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
	POSIZIOA pos;
	int id;
	MOTA mota;
}JOKO_ELEMENTUA;

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
	int iKop;//ikasgai 
	char izena[128];
	IKASGAI* ikasgaiak;
}GRADUA;

typedef struct
{
	int id;
	POSIZIOA pos_hasi;//goi ezkerra
	POSIZIOA pos_buka;//behe eskubia
}IMG;

typedef struct
{
	IMG id;//irudia (las preguntas)
	int id_2d;//mugituko den irudia (movimientos/animaciones)
	char izena[128];
	GRADUA gradua;
	POSIZIOA pos;
}JOKALARIA;

#endif