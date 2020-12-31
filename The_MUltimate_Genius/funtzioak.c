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
#include <Windows.h>
#include<time.h>


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
    int exp = 0, id = 0, erantzunda = 0;
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
            id = 1 + rand() % 49;
            id = 1;
            galderakEtaEurenAukerakSortu(galdera);
            if ((pos.x >= 383 && pos.x <= 449) && (pos.y >= 158 && pos.y <= 405)) {//pos autobus
                //----SUPUESTO UNI-----

                fondoPantailaGalderekin(".\\img\\Galderak_Erantzunak\\Preguntas.bmp", id, galdera);

                while (id <= 49) {

                    erantzunda = GalderakErantzun(exp, id, galdera);
                    if (erantzunda != 0) {
                        Sleep(500);
                        id++;
                        fondoPantailaGalderekin(".\\img\\Galderak_Erantzunak\\Preguntas.bmp", id, galdera);

                    }
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

//---HEMEN GALDERAK ETA AUKERAK ESTRUKTURAN SARTZEN DUGU GERO PRINTEATZEKO
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
            strcpy(galdera[i].aukerak.C, "(i=0,i<10,i++)");
            strcpy(galdera[i].aukerak.D, "[i=0;i<10;i++]");

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
            strcpy(galdera[i].aukerak.A, "Ingeniero bat");//ONDO
            strcpy(galdera[i].aukerak.B, "Fisiko bat");
            strcpy(galdera[i].aukerak.C, "Kimiko bat");
            strcpy(galdera[i].aukerak.D, "Elektroniko bat");
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
            strcpy(galdera[i].aukerak.D, "R=(1/R1)+R2)");
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
        case 27:
            strcpy(galdera[i].testua, "Nola deklaratzen da erakusle bat?");
            strcpy(galdera[i].aukerak.A, "?");
            strcpy(galdera[i].aukerak.B, "&");
            strcpy(galdera[i].aukerak.C, "*");  //ONDO
            strcpy(galdera[i].aukerak.D, "^");
            break;
        case 28:
            strcpy(galdera[i].testua, "Zer da programazioan errekurtsibitatea?");
            strcpy(galdera[i].aukerak.A, "Funtzio batek bere buruari deitzea");  //ONDO
            strcpy(galdera[i].aukerak.B, "Funtzio batek beste funtzio bati deitzea");
            strcpy(galdera[i].aukerak.C, "Funtzio bat");
            strcpy(galdera[i].aukerak.D, "Funtzio baten barruan hainbat funtzio edukitzea");
            break;
        case 29:
            strcpy(galdera[i].testua, "Fitxategi bat irekitzeko fopen erabiltzen da, funtzio honek fitxategiaren izena eta modua behar du, zein letra da irakurtzeko?");
            strcpy(galdera[i].aukerak.A, "d");
            strcpy(galdera[i].aukerak.B, "w");
            strcpy(galdera[i].aukerak.C, "a");
            strcpy(galdera[i].aukerak.D, "r");  //ONDO
            break;
        case 30://---MATE II---
            strcpy(galdera[i].testua, "Zer da pibot bat?");
            strcpy(galdera[i].aukerak.A, "Saskibaloiko posizio bat");
            strcpy(galdera[i].aukerak.B, "Ezkerretik hasita 0 ez den lehen zenbakia");  //ONDO
            strcpy(galdera[i].aukerak.C, "Eskuinetik hasieta 0 ez den lehen zenbakia");
            strcpy(galdera[i].aukerak.D, "Eskuinetik hasieta 0 den lehen zenbakia");
            break;
        case 31:
            strcpy(galdera[i].testua, "Noiz erabili behar da Bernoulli?");
            strcpy(galdera[i].aukerak.A, "Ekuazioa lineala denean");
            strcpy(galdera[i].aukerak.B, "Ekuazioa ez lineala denea");
            strcpy(galdera[i].aukerak.C, "Ekuazio diferentziala lineala denean");
            strcpy(galdera[i].aukerak.D, "Ekuazio diferentziala ez lineala denean");  //ONDO
            break;
        case 32:
            strcpy(galdera[i].testua, "Zer esan nahi du matriz bateko zutabe bakoitzean pibot bat edukitzeak?");
            strcpy(galdera[i].aukerak.A, "Matrizea osatzen duen ekuazioek pibot bat dutela");
            strcpy(galdera[i].aukerak.B, "Matrizea osatzen duen ekuazioek sistema indeterminatu bat osatzen dutela");
            strcpy(galdera[i].aukerak.C, "Matrizea osatzen duen ekuazioek sistema bateragarri determinatua dela");   //ONDO
            strcpy(galdera[i].aukerak.D, "Matrizea osatzen duen ekuazioek sistema batera ezin bat dela");
            break;
        case 33:
            strcpy(galdera[i].testua, "Zer da matriz elemental bat?");
            strcpy(galdera[i].aukerak.A, "Matrizeko diagonal nagusian dagoen zenbakiak 1 dira eta beste guztiak 0");  //ONDO
            strcpy(galdera[i].aukerak.B, "Matrizeko diagonal nagusian dagoen zenbakiak 0 dira eta beste denak 1");
            strcpy(galdera[i].aukerak.C, "Ordenaturik dagoen matrize bat");
            strcpy(galdera[i].aukerak.D, "Matrize batean 0-rik ez edukitzea");
            break;
        case 34:
            strcpy(galdera[i].testua, "Zein da ekuazio diferentzial baten orden maila?");
            strcpy(galdera[i].aukerak.A, "Koefiziente handiena ");
            strcpy(galdera[i].aukerak.B, "Deribatu maila handiena");   //ONDO
            strcpy(galdera[i].aukerak.C, "Deribatu maila txikiena");
            strcpy(galdera[i].aukerak.D, "Koefiziente txikiena");
            break;
        case 35://---MATE DISKRETA---
            strcpy(galdera[i].testua, "Zer da grafo Hamilton bat?");
            strcpy(galdera[i].aukerak.A, "Puntu guztietatik pasatzea baina amaiera eta hasiera ezberdinak izanik");
            strcpy(galdera[i].aukerak.B, "Puntu guztietatik behin pasatzea baina amaiera eta hasiera ezberdinak izanik");
            strcpy(galdera[i].aukerak.C, "Hasiera eta amaiera puntu bera izanik ibildide zirkularra egitea puntu guztietatik behin pasatuz");  //ONDO
            strcpy(galdera[i].aukerak.D, "Hasiera eta amaiera puntu bera izanik puntu guztietatik pasatzea");
            break;
        case 36:
            strcpy(galdera[i].testua, "Zer ezberdintasun dago grafo Eulearra eta Hamiltondarraren artean?");
            strcpy(galdera[i].aukerak.A, "Batek ibilbide ziklikoa egiten du eta besteak ez");
            strcpy(galdera[i].aukerak.B, "Batek erpinak hartzen ditu kontua eta besteak ertzak");   //ONDO
            strcpy(galdera[i].aukerak.C, "Batek ibilbide ziklikoak puntuen artean eta besteak ibilbide ziklikoa ertzen artean");
            strcpy(galdera[i].aukerak.D, "Ez dago ezberdintasunik");
            break;
        case 37:
            strcpy(galdera[i].testua, "Zenbat modu daude {1,2,3} zenbakiak ordenatzeko?");
            strcpy(galdera[i].aukerak.A, "4");
            strcpy(galdera[i].aukerak.B, "6"); //ONDO
            strcpy(galdera[i].aukerak.C, "8");
            strcpy(galdera[i].aukerak.D, "10");
            break;
        case 38:
            strcpy(galdera[i].testua, "12 korrikalari dagoen lasterketa baten zenbat modu daude dominak banatzeko orduan? ");
            strcpy(galdera[i].aukerak.A, "1250");
            strcpy(galdera[i].aukerak.B, "1320"); //ONDO
            strcpy(galdera[i].aukerak.C, "1640");
            strcpy(galdera[i].aukerak.D, "1480");
            break;
        case 39:
            strcpy(galdera[i].testua, "15 gozoki izanik zenbat modu daude 20 umeren artean banatzeko gehienez bakoitzak 1 izanik?");
            strcpy(galdera[i].aukerak.A, "10408");
            strcpy(galdera[i].aukerak.B, "15504");//ONDO
            strcpy(galdera[i].aukerak.C, "16450");
            strcpy(galdera[i].aukerak.D, "17430");
            break;
        case 40://--- ELEKTRONIKA GALDERA-----
            strcpy(galdera[i].testua, "Nolakoa da korronte alternoaren uhinak");
            strcpy(galdera[i].aukerak.A, "Sinusoidala");  //ONDO
            strcpy(galdera[i].aukerak.B, "Zirkularra");
            strcpy(galdera[i].aukerak.C, "Ez da ezagutzen");
            strcpy(galdera[i].aukerak.D, "Obalatua");
            break;
        case 41:
            strcpy(galdera[i].testua, "Zer da diodo bat?");
            strcpy(galdera[i].aukerak.A, "Artezgailu bat");  //ONDO
            strcpy(galdera[i].aukerak.B, "Transistore bat");
            strcpy(galdera[i].aukerak.C, "Transformadore bat");
            strcpy(galdera[i].aukerak.D, "Energia iturri bat");
            break;
        case 42:
            strcpy(galdera[i].testua, "Zein da artezgailu baten helburua?");
            strcpy(galdera[i].aukerak.A, "Korronteen frekuentzia handitzea");
            strcpy(galdera[i].aukerak.B, "Korronte zuzena alterno bihurtzea");
            strcpy(galdera[i].aukerak.C, "Korronte alternoa zuzena bihurtzea");//ONDO
            strcpy(galdera[i].aukerak.D, "Korronteen frekuentzia txikitzea");
            break;
        case 43:
            strcpy(galdera[i].testua, "Zenbat transistore mota daude?");
            strcpy(galdera[i].aukerak.A, "2");
            strcpy(galdera[i].aukerak.B, "3");
            strcpy(galdera[i].aukerak.C, "4");//ONDO
            strcpy(galdera[i].aukerak.D, "5");
            break;
        case 44:
            strcpy(galdera[i].testua, "Zer zati ditu elikadura iturri basiko batek?");
            strcpy(galdera[i].aukerak.A, "Transdormadorea-> irteera");
            strcpy(galdera[i].aukerak.B, "Transformadorea->artezgailuak->irteera");
            strcpy(galdera[i].aukerak.C, "Transformadorea->artezgailuak->filtroa->irteera");
            strcpy(galdera[i].aukerak.D, "Transformadorea->artezgailuak->filtroa->reguladorea->irteera");   //ONDO
            break;
        case 45://----EMPRESA----
            strcpy(galdera[i].testua, "Zenbat ingurune nagusi daude enpresa bati eragiten diona?");
            strcpy(galdera[i].aukerak.A, "1");
            strcpy(galdera[i].aukerak.B, "2");//ONDO
            strcpy(galdera[i].aukerak.C, "3");
            strcpy(galdera[i].aukerak.D, "4");
            break;
        case 46:
            strcpy(galdera[i].testua, "Kontabilitate garaian , zenbat atal eduki behar ditu urteko kontuetan?");
            strcpy(galdera[i].aukerak.A, "2");
            strcpy(galdera[i].aukerak.B, "3");
            strcpy(galdera[i].aukerak.C, "4");
            strcpy(galdera[i].aukerak.D, "5");//ONDO
            break;

        case 47:
            strcpy(galdera[i].testua, "Nola kalkulatzen da enpresa baten bermea?");
            strcpy(galdera[i].aukerak.A, "Aktibo erreala/ zorrak");  //ONDO
            strcpy(galdera[i].aukerak.B, "Aktibo/Pasibo");
            strcpy(galdera[i].aukerak.C, "Aktiko erreala*zorrak");
            strcpy(galdera[i].aukerak.D, "Aktibo*Pasibo");
            break;
        case 48:
            strcpy(galdera[i].testua, "-Enpresa baten negozio plana zenbat atal nagusi ditu?");
            strcpy(galdera[i].aukerak.A, "5");
            strcpy(galdera[i].aukerak.B, "7");
            strcpy(galdera[i].aukerak.C, "8"); //ONDO
            strcpy(galdera[i].aukerak.D, "10");
            break;
        case 49:
            strcpy(galdera[i].testua, "Zer esan nahi du enpresa baten ingurune orokorra?");
            strcpy(galdera[i].aukerak.A, "Enpresa guztientzako berdina da eta eragin bera du guztiendako");
            strcpy(galdera[i].aukerak.B, "Enpresa guztientzako berdina da eta denetan izaten du eragina baina ez modu berean");  //ONDO
            strcpy(galdera[i].aukerak.C, "Jarduera-sektore baten barneko enpresetan du bakarrik eragina");
            strcpy(galdera[i].aukerak.D, "Jarduera-sektore guztien barneko enpresetan du bakarrik eragina");
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
    int erantzunda = 0;

    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA) {
        pantailaGarbitu();

        pos = saguarenPosizioa();
        switch (galderaID)
        {
        case 1://---program---

            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);

            }

            else  if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);

            }

            else   if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);

            }

            else {
                erantzunda = 0;
            }

            break;

        case 2:

            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);


            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------

                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2B.bmp"), 656, 489);
                irudiakMarraztu();
                textuaGaitu();
                opzioakAgertu(galdera, galderaID, 2);

            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);

            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);

            }

            else {
                erantzunda = 0;
            }

            break;

        case 3:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);


            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);

            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);


            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------

                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);


            }
            else {
                erantzunda = 0;
            }break;
        case 4:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 5:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 6://---Mate---
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 7:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 8:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 9:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 10:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 11://--Fisika---
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 12:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 13:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 14:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 15:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 16://---oinarri---
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 17:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 18:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 19:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 20://---redes----
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 21:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 22:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 23:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 24:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 25://---program II----
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 26:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 27:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;

        case 28:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 29:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 30://---Mate II----
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 31:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 32:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 33:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 34:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 35://---Mate Diskreta----
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 36:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }

            else {
                erantzunda = 0;
            }break;
        case 37:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 38:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 39:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MDtC.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MDtD.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 40://---elektronika---
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 41:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 42:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 43:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 44:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        case 45:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 46:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 47:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 48:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;
        case 49:
            erantzunda = 1;

            if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5A.bmp"), 30, 490);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 1);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5B.bmp"), 656, 489);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 2);
            }

            else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5C.bmp"), 30, 614);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 3);
            }

            else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5D.bmp"), 656, 616);
                irudiakMarraztu();
                opzioakAgertu(galdera, galderaID, 4);
            }
            else {
                erantzunda = 0;
            }break;

        default:

            break;
        }
        if (erantzunda == 1) {
            pantailaBerriztu();
        }

    }
    return erantzunda;
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