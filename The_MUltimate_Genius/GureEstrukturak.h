#ifndef GUREESTRUKTURAK_H
#define GUREESTRUKTURAK_H

#include "ebentoak.h"

#define CHICO_AVATAR ".\img\PersonajeChicoHablando.bmp"
#define CHICA_AVATAR ".\img\PersonajeChicaHablando.bmp"
#define CHICO_AVATAR_M ".\img\PersonajeChicoVF.bmp"
#define CHICA_AVATAR_M ".\img\PersonajeChicaVF.bmp"

typedef enum { MENUA, PROFILA, JOLASTU, IRTEN, KONTROLAK, KARGATU, ETXEA, UNI }EGOERA;

typedef struct exp
{
    int xp;//galderekin irabazi duen 
    int max;//ikasgaiKop20
}EXP;

typedef struct ikasgai
{
    float notaFinala;
    char izena[128];
    char karpeta[128];
    /*
        *GALDERAK ETA
        * separar por carpetas
        * cada carpeta tenga el nombre de la asignatura
        * dentro pregunta y su respuesta
        * aparece pregunta y jugador decide(click)coordenadas
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