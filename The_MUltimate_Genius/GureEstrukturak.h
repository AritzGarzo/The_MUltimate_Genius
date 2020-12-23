#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H
#define SOINU_KOP 5

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
	POSIZIOA pos;
	int id;
	MOTA mota;
}JOKO_ELEMENTUA;

typedef enum{A=1,B,C,D} OPZIOAK; 
typedef enum {/*EMAITZAREN ORDENA*/  } EMAITZAK;

typedef struct galdera {

	int id;
	char testua[128];
	OPZIOAK erantzuna;//swicth erabili aukeratzeko

}GALDERA;

#endif