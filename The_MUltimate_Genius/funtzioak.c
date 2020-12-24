#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include"GureEstrukturak.h"
#include"funtzioak.h"

//int hasieratu(void)
//{
//    int i;
//    GURE_GAUZAK gureGauzak;
//
//    if (sgHasieratu() == -1)
//    {
//        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
//        return 0;
//    }
//    audioInit();
//    for (i = 0; i < SOINU_KOP; i++)
//    {
//        if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
//        {
//            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
//            return 0;
//        }
//    }
//    if (!loadTheMusic(".\\sound\\beat.wav"))
//    {
//        fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
//        return 0;
//    }
//
//    return 0;
//}
//

void galderaSortu(GALDERA galdera[]);

int mu_hasieratu(void)
{
    int i, ebentu, egoera;
    POSIZIOA pos;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 1280x720 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    pantailaGarbitu();
    fondoPantaila(".\\img\\menu.bmp");

    pantailaBerriztu();

    return 0;
}

int menua(void) {

    int  ebentu, egoera = 0;
    POSIZIOA pos;

    ebentu = ebentuaJasoGertatuBada();
    switch (ebentu)
    {
    case SAGU_BOTOIA_EZKERRA:
        pos = saguarenPosizioa();
        if ((pos.x > 18) && (pos.x < 18 + 175) && (pos.y > 650) && (pos.y < 650 + 50)) egoera = 1;//irten
        else if ((pos.x > 483) && (pos.x < 483 + 343) && (pos.y > 386) && (pos.y < 386 + 68))
        {
            egoera = 2;              //kontrolak
        }
        else if ((pos.x > 483) && (pos.x < 483 + 343) && (pos.y > 293) && (pos.y < 293 + 68))
        {
            egoera = 3;              //jolastu
        }
        break;
    case GERTAERA_IRTEN:
        egoera = 1;
        break;
    default:
        break;
    }
    return egoera;
}

void fondoPantaila(char* str)
{
    int id;
    pantailaGarbitu();
    id = irudiaKargatu(str);
    irudiaMugitu(id, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();
}

int jolastu(void)
{
    int exp = 0, id = 0;
    int irten, ebentu;
    static char esaldia[16] = "";
    POSIZIOA pos;
    GALDERA galdera[55];
    galdera[0].id = 0;
    irten = 3;
    fondoPantaila(".\\img\\Gela.bmp");

    while (irten == 3)
    {
        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            pos = saguarenPosizioa();
            id = srand() % 3;
            if ((pos.x >= 383 && pos.x <= 449) && (pos.y >= 158 && pos.y <= 405)) {//pos autobus
                galderaSortu(galdera);

                exp = galderaEranzun(exp, id,galdera);
            }
        }
        //------HEMEN STAT DAGO------

        //switch (ebentu)
        //{
        //case TECLA_s:
        //    if (irten == 3)
        //    {
        //        strcat(esaldia, "S");//esaldia = S
        //    }
        //    break;
        //case TECLA_t:
        //    strcat(esaldia, "T");//esaldia = U
        //    break;
        //case TECLA_a:
        //    strcat(esaldia, "A");//esaldia = I
        //    break;
        //case GERTAERA_IRTEN:
        //    irten = 1;
        //    break;
        //default:
        //    break;
        //}
        //if (strcmp(esaldia, "STAT") == 0)
        //{
        //    strcpy(esaldia, "");
        //    irten = 0;
        //}
    }

    pantailaBerriztu();
    return irten;
}

int kontrolak(void)
{
    int irten, ebentu;
    POSIZIOA pos;
    irten = 2;
    fondoPantaila(".\\img\\kontrolak.bmp");

    while (irten == 2)
    {
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case SAGU_BOTOIA_EZKERRA:
            pos = saguarenPosizioa();
            if ((pos.x > 33) && (pos.x < 33 + 189) && (pos.y > 633) && (pos.y < 633 + 44)) {  // volver a menu de inicio
                fondoPantaila(".\\img\\menu.bmp");
                irten = 0;
            }
            break;
        case GERTAERA_IRTEN:
            irten = 1;//cerrar SDL/TODO
            break;
        default:
            break;
        }
    }

    return irten;
}

int galderaEranzun(int exp, int galderaID,GALDERA galdera[]) {

    POSIZIOA pos;

    fondoPantaila(".\\img\\Galderak_Erantzunak\\Preguntas.bmp");

    /*textuaGaitu();
    textuaIdatzi(27, 290, "Zein da “For” baten sintaxis egokia?");    -------HAU DENA TESTUA IDAZTEKO------
    pantailaBerriztu();*/

    switch (galderaID)
    {
    case 1:
        textuaGaitu();
        textuaIdatzi(27, 290,galdera[galderaID].testua);
        pantailaBerriztu();

        break;
    case 2:
        textuaGaitu();
        textuaIdatzi(27, 290, galdera[galderaID].testua);
        pantailaBerriztu();

        break;
    case 3:
        textuaGaitu();
        textuaIdatzi(27, 290, galdera[galderaID].testua);
        pantailaBerriztu();

        break;
    default:
        break;
    }

    pos = saguarenPosizioa();

    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
        fondoPantaila(".\\img\\Galderak_Erantzunak\\Pregunta1PROEMA.bmp");
    }

    if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
        fondoPantaila(".\\img\\Galderak_Erantzunak\\Pregunta1PROEMA.bmp");
        exp += 10;
    }
    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
        fondoPantaila(".\\img\\Galderak_Erantzunak\\Pregunta1PROEMA.bmp");
    }

    if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
        fondoPantaila(".\\img\\Galderak_Erantzunak\\Pregunta1PROEMA.bmp");
    }

    return exp;
}

void galderaSortu(GALDERA galdera[]) {
    int i = 1;
    char testua[MAX] = " ";

    while (i <= 4) {

        galdera[i].id = i;
        switch (i)
        {
        case 1:
            strcpy(testua, "Zein da FOR baten sintaxia?");
            strcpy(galdera[i].testua, testua);
            break;
        case 2:
            strcpy(testua, "EZ DAKIT");
            strcpy(galdera[i].testua, testua);
            break;
        case 3:
            strcpy(testua, "BESTE PRUEBA BAT");
            strcpy(galdera[i].testua, testua);
            break;
        default:
            break;
        }
        i++;
    }
}