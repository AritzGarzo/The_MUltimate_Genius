#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H
#define SOINU_KOP 5
#define MAX 128
//#define GALDERA1 ".\\img\\Galderak_Erantzunak\\Program\\Preguntas.bmp"

#include "ebentoak.h"


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


//----------------------

typedef enum { MENUA_P, PROFILA_P, JOLASTU_P, IRTEN_P, KONTROLAK_P, KARGATU_P, ETXEA_P, UNI_P }EGOERA;

typedef struct exp
{
    int xp;//galderekin irabazi duen 
    int max;//ikasgaiKop20
}EXP;

typedef struct gradua
{
    int iKop;//ikasgai 
    char izena[128];
    EXP exp;
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
}JOKALARIA;



#endif