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
#include<stdlib.h>

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

void GalderaErantzunenPantaillaSortu(int galderaID, GALDERA galdera[]);
void galderakEtaEurenAukerakSortu(GALDERA galdera[]);
void galderakEtaEurenAukerakSortu(GALDERA galdera[]);
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
void fondoPantailaGalderekin(char* str,int galderaID,GALDERA galdera[])
{
    int id;
    pantailaGarbitu();
    id = irudiaKargatu(str);
    irudiaMugitu(id, 0, 0);
    irudiakMarraztu();

    textuaGaitu();
    textuaIdatzi(27, 290, galdera[galderaID].testua);
    textuaIdatzi(55, 512, galdera[galderaID].aukerak.A);
    textuaIdatzi(684, 512, galdera[galderaID].aukerak.B);
    textuaIdatzi(55, 645, galdera[galderaID].aukerak.C);
    textuaIdatzi(684, 645, galdera[galderaID].aukerak.D);

    pantailaBerriztu();
}


int jolastu(void)
{
    int exp = 0, id = 0;
    int irten, ebentu,bukatuta=0;
    static char esaldia[16] = "";
    POSIZIOA pos;
    GALDERA galdera[55];
    irten = 3;
    fondoPantaila(".\\img\\Gela.bmp");

    while (irten == 3)
    {
        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            pos = saguarenPosizioa();
            srand(time(NULL));
            id = 1 + rand() % 3;
            galderakEtaEurenAukerakSortu(galdera);
            //GalderaErantzunenPantaillaSortu(id, galdera);

            if ((pos.x >= 383 && pos.x <= 449) && (pos.y >= 158 && pos.y <= 405)) {//pos autobus
                //----SUPUESTO UNI-----
                fondoPantailaGalderekin(".\\img\\Galderak_Erantzunak\\Preguntas.bmp", id, galdera);

                while (bukatuta == 0) {
                    exp = GalderakErantzun(exp, id, galdera);
                }

            }
        }
        if (ebentu == GERTAERA_IRTEN) {
            return 0;
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

void galderakEtaEurenAukerakSortu(GALDERA galdera[]) {
    int i = 1;
    while (i <= 4) {

        galdera[i].id = i;
        switch (i)
        {
        case 1:
            strcpy(galdera[i].testua, "Zein da FOR baten sintaxia?");
            strcpy(galdera[i].aukerak.A, "(i=0;i<10;i++)"); //ONDO
            strcpy(galdera[i].aukerak.B, "[i=0;i<10;i++]");
            strcpy(galdera[i].aukerak.C, "{i=0,i<10,i++}");
            strcpy(galdera[i].aukerak.D, "{i=0;i<10;i++}");

            break;
        case 2:
            strcpy(galdera[i].testua, "Nola da 65 bitarrean?");
            strcpy(galdera[i].aukerak.A, "01101011");
            strcpy(galdera[i].aukerak.B, "01000001");  //  ONDO
            strcpy(galdera[i].aukerak.C, "11000001");
            strcpy(galdera[i].aukerak.D, "01000010");

            break;
        case 3:
            strcpy(galdera[i].testua, "Zer diferentzia dago do while eta while-en artean?");
            strcpy(galdera[i].aukerak.A, " ez dago desberdintasunik");
            strcpy(galdera[i].aukerak.B, "bat bestea baino azkarragoa da");
            strcpy(galdera[i].aukerak.C, "batek lehenego zerbait egiten du eta gero baldintza konparatu");  //ONDO
            strcpy(galdera[i].aukerak.D, "bat efizienteagoa da");

            break;
        default:
            break;
        }
        i++;
    }
}

//---uste dot sobra-----
//void GalderaErantzunenPantaillaSortu(int galderaID, GALDERA galdera[]) {
//
//    fondoPantailaGalderekin(".\\img\\Galderak_Erantzunak\\Preguntas.bmp",galderaID,galdera);
//
//}

int GalderakErantzun(int exp, int galderaID, GALDERA galdera[]) {

    POSIZIOA pos;
    int ebentu = 0;

        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {

            pos = saguarenPosizioa();

            switch (galderaID)
            {
            case 1:

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1O.bmp"),30,488);
                    irudiakMarraztu();
                    pantailaBerriztu();

                }

                if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1M1.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();

                }
                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1M2.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();

                }

                if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1M3.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();

                }
                break;

            case 2:

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2O.bmp"), 30, 488);
                    irudiakMarraztu();
                    pantailaBerriztu();
                     
                }

                if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2M1.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();
                     
                }
                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2M2.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();

                }

                if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2M3.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();

                }

                break;

            case 3:

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3O.bmp"), 30, 488);
                    irudiakMarraztu();
                    pantailaBerriztu();

                }

                if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3M1.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();
                     
                }
                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3M2.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();
                     
                }

                if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------

                    irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3M3.bmp");
                    irudiakMarraztu();
                    pantailaBerriztu();

                }
                break;

            default:

                break;
            }
        }


    return exp;
}