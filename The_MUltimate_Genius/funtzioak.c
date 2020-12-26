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
void opzioakAgertu(GALDERA galdera[], int galderaID, int mota);


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

void fondoPantailaGalderekin(char* str, int galderaID, GALDERA galdera[])
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
    int irten, ebentu, bukatuta = 0;
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
            id = 1 + rand() % 14;
            id = 22;
            galderakEtaEurenAukerakSortu(galdera);
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
    while (i < 50) {


        galdera[i].id = i;


        switch (i)
        {
        case 1://---PROGRAMEKO GALDERAK---
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
            strcpy(galdera[i].aukerak.A, "ez dago desberdintasunik");
            strcpy(galdera[i].aukerak.B, "bat bestea baino azkarragoa da");
            strcpy(galdera[i].aukerak.C, "batek lehenego zerbait egiten du eta gero baldintza konparatu");  //ONDO
            strcpy(galdera[i].aukerak.D, "bat efizienteagoa da");
            break;
        case 4:
            strcpy(galdera[i].testua, "If eta else if sententzia asko erabiltzen denean, zer beste sentetzia dago hori azkarrago egiteko?");
            strcpy(galdera[i].aukerak.A, "switch");  //ONDO
            strcpy(galdera[i].aukerak.B, "change");
            strcpy(galdera[i].aukerak.C, "goto");
            strcpy(galdera[i].aukerak.D, "break");
            break;
        case 5:
            strcpy(galdera[i].testua, "ASCII taula karaktere kode bat da, zer orden da egokia?");
            strcpy(galdera[i].aukerak.A, "Zenbakiak->xehez>Larriz");
            strcpy(galdera[i].aukerak.B, "xehez>Larriz->zenbakiak");
            strcpy(galdera[i].aukerak.C, "Larriz->xehez>zenbakiak");
            strcpy(galdera[i].aukerak.D, "Zenbakiak->Larriz-> xehez");  //ONDO
            break;
        case 6://----MATEKO GALDERAK------
            strcpy(galdera[i].testua, "Zein da (Sinx/Cosx) dx ren integrala?");
            strcpy(galdera[i].aukerak.A, "-Ln(cosx)");  //ONDO
            strcpy(galdera[i].aukerak.B, "tanx");
            strcpy(galdera[i].aukerak.C, "Ln(sinx)");
            strcpy(galdera[i].aukerak.D, "arctan x");
            break;
        case 7:
            strcpy(galdera[i].testua, "Zein da Cos2x ren baliokidea");
            strcpy(galdera[i].aukerak.A, "(cosx)^2-(sinx)^2");  //ONDO
            strcpy(galdera[i].aukerak.B, "cosx-sinx");
            strcpy(galdera[i].aukerak.C, "2sinxcosx");
            strcpy(galdera[i].aukerak.D, "sinxcosx");
            break;
        case 8:
            strcpy(galdera[i].testua, "Noiz esaten da limite bat jarraia dela? ");
            strcpy(galdera[i].aukerak.A, "Ez dakit");
            strcpy(galdera[i].aukerak.B, "Alboko limiteak desberdinak direnean");
            strcpy(galdera[i].aukerak.C, "Alboko limiteak berdinak direnean"); //ONDO
            strcpy(galdera[i].aukerak.D, "Limite bat ez dagoenean");
            break;

        case 9:
            strcpy(galdera[i].testua, "Zenbat da Sin5(pi)/6?");
            strcpy(galdera[i].aukerak.A, "erro(2)/2");  
            strcpy(galdera[i].aukerak.B, "1/2");//ONDO
            strcpy(galdera[i].aukerak.C, "erro(3)/3");
            strcpy(galdera[i].aukerak.D, "-erro(2)/2");
            break;
        case 10:
            strcpy(galdera[i].testua, "idatzi (2i-4)/(3+2i) polarrean.");
            strcpy(galdera[i].aukerak.A, "(-8+14i)/13");  //ONDO
            strcpy(galdera[i].aukerak.B, "(-6-5i)/14,");
            strcpy(galdera[i].aukerak.C, "(5+16i)/10");
            strcpy(galdera[i].aukerak.D, "(7-9i)/12");
            break;

        case 11://----FISIKAKO GALDERA-----
            strcpy(galdera[i].testua, "Zer/zeinen legea da hau? (V=R*I\R=V/I\I=V/R)");
            strcpy(galdera[i].aukerak.A, "Ohm-en legea");  //ONDO
            strcpy(galdera[i].aukerak.B, "Thevenin-ren legea");
            strcpy(galdera[i].aukerak.C, "Coulomb-en legea");
            strcpy(galdera[i].aukerak.D, "Joul-en legea");
            break;
        case 12:
            strcpy(galdera[i].testua, "Zein zen Thevenin?");
            strcpy(galdera[i].aukerak.A, "Ingeniero bat");
            strcpy(galdera[i].aukerak.B, "Fisiko bat");
            strcpy(galdera[i].aukerak.C, "Kimiko bat");
            strcpy(galdera[i].aukerak.D, "Elektroniko bat");//ONDO
            break;
        case 13:
            strcpy(galdera[i].testua, " Zein da Kirchhoff-en legea?");
            strcpy(galdera[i].aukerak.A, "Korapiloaren legea,");  //ONDO
            strcpy(galdera[i].aukerak.B, "Energia kontserbazioaren legea");
            strcpy(galdera[i].aukerak.C, "Akzio-erreakzio");
            strcpy(galdera[i].aukerak.D, "Kanpo magnetikoaren legea");
            break;
        case 14:
            strcpy(galdera[i].testua, "Nola kalkulatzen da erresistentzi totala paraleloan badaude?");
            strcpy(galdera[i].aukerak.A, "R=R1+R2");
            strcpy(galdera[i].aukerak.B, "(1/R)=(1/R1)+(1/R2)");  //ONDO
            strcpy(galdera[i].aukerak.C, "R=(1/R1)+(1/R2)");
            strcpy(galdera[i].aukerak.D, "R=R1+(1/R2)");
            break;
        case 15:
            strcpy(galdera[i].testua, "Zein da potentzialaren formula egokia?");
            strcpy(galdera[i].aukerak.A, "V/(I^2)"); 
            strcpy(galdera[i].aukerak.B, "(I^2)/R");
            strcpy(galdera[i].aukerak.C, "(V^2)*R");
            strcpy(galdera[i].aukerak.D, "I*(R^2)"); //ONDO
            break;
        case 16: //---OINARRIKO GALDERA---
            strcpy(galdera[i].testua, "Zertarako balio du Git?");
            strcpy(galdera[i].aukerak.A, "Bertsioen kontrol bat egiteko");  //ONDO
            strcpy(galdera[i].aukerak.B, "Programa bat gehiago nahasteko");
            strcpy(galdera[i].aukerak.C, "Textu bat lainoan gordetzeko");
            strcpy(galdera[i].aukerak.D, "Web bat egiteko");        
            break;
        case 17:
            strcpy(galdera[i].testua, "PDF batek irudia badu zer eduki behar du berarekin?");
            strcpy(galdera[i].aukerak.A, "Deskripzio bat bakarrik");
            strcpy(galdera[i].aukerak.B, "Irudien taula bakarrik");
            strcpy(galdera[i].aukerak.C, "Deskripzio bat eta irudien taula");  //ONDO
            strcpy(galdera[i].aukerak.D, "Ezer");
            break;
        case 18:
            strcpy(galdera[i].testua, "Zer etiketa erabili behar da izenburua jartzeko?");
            strcpy(galdera[i].aukerak.A, "<head> ... </head>");  
            strcpy(galdera[i].aukerak.B, "<title> ... </title>");  //ONDO
            strcpy(galdera[i].aukerak.C, "<img> ... </img>");
            strcpy(galdera[i].aukerak.D, "<p> ... </p>");
            break;

        case 19:
            strcpy(galdera[i].testua, "Zer etiketa erabili behar da kodigoa jartzeko?");
            strcpy(galdera[i].aukerak.A, "<strong> ... </strong>");  
            strcpy(galdera[i].aukerak.B, "<div> ... </div>");
            strcpy(galdera[i].aukerak.C, "<script> ... </script>");  //ONDO
            strcpy(galdera[i].aukerak.D, "<head> ... <\head>");
            break;
        case 20://---REDES---
            strcpy(galdera[i].testua, "Zein da Google-ren DNS IPv4-a?");
            strcpy(galdera[i].aukerak.A, "1.1.1.1");  
            strcpy(galdera[i].aukerak.B, "5.5.5.5");
            strcpy(galdera[i].aukerak.C, "0.0.0.0");
            strcpy(galdera[i].aukerak.D, "8.8.8.8");  //ONDO
            break;
        case 21:
            strcpy(galdera[i].testua, "Zer izen du transporte kapan lan egiten duen PDU-ari?");
            strcpy(galdera[i].aukerak.A, "bits");  
            strcpy(galdera[i].aukerak.B, "trama");
            strcpy(galdera[i].aukerak.C, "segmento");  //ONDO
            strcpy(galdera[i].aukerak.D, "pakete");
            break;
        case 22:
            strcpy(galdera[i].testua, "Ari - gabeko host batek IP helbide bat eskatu behar du, zer protokolo erabili behar du eskaera hori  egiteko?");
            strcpy(galdera[i].aukerak.A, "HTTP");
            strcpy(galdera[i].aukerak.B, "SNMP");
            strcpy(galdera[i].aukerak.C, "DHCP");  //ONDO    
            strcpy(galdera[i].aukerak.D, "ICMP");
            break;
        case 23:
            strcpy(galdera[i].testua, "Zein da IPv6 helbide honen (2001:0000:0000:abcd:0000:0000:0000:0001) idazkera motzena?");
            strcpy(galdera[i].aukerak.A, "2001:0000:0000:abcd::1");  
            strcpy(galdera[i].aukerak.B, "2001:0:0:abcd::1");    //ONDO
            strcpy(galdera[i].aukerak.C, "2001::abcd::1");
            strcpy(galdera[i].aukerak.D, "2001::abdc:0:1");
            break;
        case 24:
            strcpy(galdera[i].testua, "255.255.255.248 maskaran zenbat host dira helbideragarriak?");
            strcpy(galdera[i].aukerak.A, "2");  
            strcpy(galdera[i].aukerak.B, "6");  //ONDO
            strcpy(galdera[i].aukerak.C, "8");
            strcpy(galdera[i].aukerak.D, "14");
            break;
        case 25://---PORGRAM II---
            strcpy(galdera[i].testua, "Zein da arraya[i]-ren baliokidea?");
            strcpy(galdera[i].aukerak.A, "*(arraya+i)");  //ONDO
            strcpy(galdera[i].aukerak.B, "arraya.i");
            strcpy(galdera[i].aukerak.C, "(arraya+i)");
            strcpy(galdera[i].aukerak.D, "*arraya+i");
            break;
        case 26:
            strcpy(galdera[i].testua, "Zer da erakusle bat?");
            strcpy(galdera[i].aukerak.A, "Ezer");  
            strcpy(galdera[i].aukerak.B, "Memoriako zati bat");
            strcpy(galdera[i].aukerak.C, "Memoriako elementuak");
            strcpy(galdera[i].aukerak.D, "Memoriako helbide bat zehazten duen elementu bat");//ONDO
            break;
        /*
                case 5:
            strcpy(galdera[i].testua, "");
            strcpy(galdera[i].aukerak.A, "");  //ONDO
            strcpy(galdera[i].aukerak.B, "");
            strcpy(galdera[i].aukerak.C, "");
            strcpy(galdera[i].aukerak.D, "");
            break;

        */
        default:
            break;
        }
        i++;
    }


}

int GalderakErantzun(int exp, int galderaID, GALDERA galdera[]) {

    POSIZIOA pos;
    int ebentu = 0;

    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA) {
        pantailaGarbitu();

        pos = saguarenPosizioa();
        switch (galderaID)
        {
        case 1:

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1O.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1M1.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);

            }
            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1M2.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);

            }

            if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1M3.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);

            }
            break;

        case 2:

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2M1.bmp");
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);


            }

            if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------

                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2O.bmp"), 30, 488);
                irudiakMarraztu();
                textuaGaitu();
                opzioakAgertu(galdera, galderaID, 2);

            }
            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2M2.bmp");
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);

            }

            if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2M3.bmp");
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);

            }

            break;

        case 3:

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3M1.bmp");
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);


            }

            if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3M2.bmp");
                irudiakMarraztu();

                opzioakAgertu(galdera, galderaID, 2);


            }
            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3O.bmp"), 30, 488);
                irudiakMarraztu();

                opzioakAgertu(galdera, galderaID, 3);


            }

            if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------

                irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3M3.bmp");
                irudiakMarraztu();

                opzioakAgertu(galdera, galderaID, 4);


            }
            break;

        default:

            break;
        }
        pantailaBerriztu();

    }
    return exp;
}

void opzioakAgertu(GALDERA galdera[], int galderaID, int mota) {

    switch (mota)
    {
    case 1:
        textuaGaitu();
        textuaIdatzi(27, 290, galdera[galderaID].testua);
        textuaIdatzi(684, 512, galdera[galderaID].aukerak.B);
        textuaIdatzi(55, 645, galdera[galderaID].aukerak.C);
        textuaIdatzi(684, 645, galdera[galderaID].aukerak.D);
        break;
    case 2:
        textuaGaitu();
        textuaIdatzi(27, 290, galdera[galderaID].testua);
        textuaIdatzi(55, 512, galdera[galderaID].aukerak.A);
        textuaIdatzi(55, 645, galdera[galderaID].aukerak.C);
        textuaIdatzi(684, 645, galdera[galderaID].aukerak.D);
        break;
    case 3:
        textuaGaitu();
        textuaIdatzi(27, 290, galdera[galderaID].testua);
        textuaIdatzi(55, 512, galdera[galderaID].aukerak.A);
        textuaIdatzi(684, 512, galdera[galderaID].aukerak.B);
        textuaIdatzi(684, 645, galdera[galderaID].aukerak.D);

        break;
    case 4:
        textuaGaitu();
        textuaIdatzi(27, 290, galdera[galderaID].testua);
        textuaIdatzi(55, 512, galdera[galderaID].aukerak.A);
        textuaIdatzi(684, 512, galdera[galderaID].aukerak.B);
        textuaIdatzi(55, 645, galdera[galderaID].aukerak.C);
        break;
    default:
        break;
    }


}