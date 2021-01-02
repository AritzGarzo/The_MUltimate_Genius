#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H
#define SOINU_KOP 5
#define MAX 128
//#define GALDERA1 ".\\img\\Galderak_Erantzunak\\Program\\Preguntas.bmp"

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
    POSIZIOA pos;
    int id;
    MOTA mota;
}JOKO_ELEMENTUA;

typedef struct opzioak {
    char A[MAX];
    char B[MAX];
    char C[MAX];
    char D[MAX];

} OPZIOAK;

typedef struct galdera {

    int gelaID;
    int galderaID;
    char testua[MAX];
    OPZIOAK aukerak;//swicth erabili aukeratzeko
    int erabilita;

}GALDERA;

#endif