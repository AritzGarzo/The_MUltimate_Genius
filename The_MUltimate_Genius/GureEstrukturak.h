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
	/*
	* 
	* 
	* GALDERAK ETA 
	* 
	* 
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
	int id;//irudia
	int id_2d;//mugituko den irudia
	char izena[128];
	GRADUA gradua;
	POSIZIOA pos;
}JOKALARIA;

#endif