#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include"GureEstrukturak.h"
#include<stdlib.h>
#include <Windows.h>
#include<time.h>
#include"Galderak.h"



void fondoPantailaGalderekin(char* str, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX])
{
    int id;
    pantailaGarbitu();
    id = irudiaKargatu(str);
    irudiaMugitu(id, 0, 0);
    irudiakMarraztu();

    textuaGaitu_galderak();
    textuaIdatzi(27, 290, galdera[gelaID][galderaID].testua);
    textuaIdatzi(55, 512, galdera[gelaID][galderaID].aukerak.A);
    textuaIdatzi(684, 512, galdera[gelaID][galderaID].aukerak.B);
    textuaIdatzi(55, 645, galdera[gelaID][galderaID].aukerak.C);
    textuaIdatzi(684, 645, galdera[gelaID][galderaID].aukerak.D);

    pantailaBerriztu();
}

int galderak(int gelaID)
{
    int exp = 0, galderaID = 0, erantzunda = 0, denakErantzunda = 0;
    int irten, ebentu, bukatuta = 0;
    static char esaldia[16] = "";
    POSIZIOA pos;
    GALDERA galdera[GELAIDMAX][GALDERAIDMAX];
    irten = 3;
    srand(time(NULL));
    galderakEtaEurenAukerakSortu(galdera);
    //fondoPantaila(".\\img\\Gela.bmp");
    switch (gelaID)
    {case 1:  
        galderaID = 1 + rand() % 5;
        fondoPantailaGalderekin(".\\img\\Galderak_Erantzunak\\Preguntas.bmp", gelaID, galderaID, galdera);
        while (galderaID <= 5) {
            erantzunda = GalderakErantzun(exp, gelaID, galderaID, galdera);
            if (erantzunda != 0) {
                Sleep(500);
                galderaID++;
                if (galderaID == 6) {
                    denakErantzunda = 1;
                    galderaID = 1;
                }
                else {
                    fondoPantailaGalderekin(".\\img\\Galderak_Erantzunak\\Preguntas.bmp", gelaID, galderaID, galdera);
                }
            }

        }
        //denakErantzunda = 0;
        break;
    case 2:
        galderaID = 1 + rand() % 5;
        fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
        while (galderaID <= 5 && !denakErantzunda) {
            erantzunda = GalderakErantzun(exp, gelaID, galderaID, galdera);
            if (erantzunda != 0) {
                Sleep(500);
                galderaID++;
                if (galderaID == 6) {
                    denakErantzunda = 1;
                    galderaID = 1;
                }
                else {
                    fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
                }
            }

        }
        //denakErantzunda = 0;
        break;
    case 3:
        galderaID = 1 + rand() % 5;
        fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
        while (galderaID <= 5 && !denakErantzunda) {
            erantzunda = GalderakErantzun(exp, gelaID, galderaID, galdera);
            if (erantzunda != 0) {
                Sleep(500);
                galderaID++;
                if (galderaID == 6) {
                    denakErantzunda = 1;
                    galderaID = 1;
                }
                else {
                    fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
                }
            }

        }
        //denakErantzunda = 0;
        break;
    case 4:
        galderaID = 1 + rand() % 4;
        fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
        while (galderaID <= 5 && !denakErantzunda) {
            erantzunda = GalderakErantzun(exp, gelaID, galderaID, galdera);
            if (erantzunda != 0) {
                Sleep(500);
                galderaID++;
                if (galderaID == 6) {
                    denakErantzunda = 1;
                    galderaID = 1;
                }
                else {
                    fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
                }
            }

        }
        //denakErantzunda = 0;
        break;
    case 5:
        galderaID = 1 + rand() % 5;
        fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
        while (galderaID <= 5 && !denakErantzunda) {
            erantzunda = GalderakErantzun(exp, gelaID, galderaID, galdera);
            if (erantzunda != 0) {
                Sleep(500);
                galderaID++;
                if (galderaID == 6) {
                    denakErantzunda = 1;
                    galderaID = 1;
                }
                else {
                    fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera);
                }
            }

        }
        //denakErantzunda = 0;
        break;
    default:
        break;
    }

                
                    
                
     


    pantailaBerriztu();
    return irten;
}



//---HEMEN GALDERAK ETA AUKERAK ESTRUKTURAN SARTZEN DUGU GERO PRINTEATZEKO
void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]) {
    int gelaID = 1, galderaID = 1;
    while (gelaID <= 10) {

        switch (gelaID)
        {
        case 1://---program---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da FOR baten sintaxia?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "(i=0;i<10;i++)"); //ondo
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "[i=0;i<10;i++]");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "(i=0,i<10,i++)");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "[i=0;i<10;i++]");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Nola da 65 bitarrean?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "01101011");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "01000001");  //  ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "11000001");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "01000010");

                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer diferentzia dago do while eta while-en artean?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "ez dago desberdintasunik");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "bat bestea baino azkarragoa da");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "batek lehenego zerbait egiten du eta gero baldintza konparatu");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "bat efizienteagoa da");
                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "If eta else if sententzia asko erabiltzen denean, zer beste sentetzia dago hori azkarrago egiteko?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "switch");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "change");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "goto");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "break");
                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "ASCII taula karaktere kode bat da, zer orden da egokia?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Zenbakiak->xehez>Larriz");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "xehez>Larriz->zenbakiak");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Larriz->xehez>zenbakiak");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Zenbakiak->Larriz-> xehez");  //ONDO
                    break;
                default:
                    break;
                }
                galderaID++;
            }
            break;

        case 2://---mate---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1://----MATEKO GALDERAK------
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da (Sinx/Cosx) dx ren integrala?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "-Ln(cosx)");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "tanx");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Ln(sinx)");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "arctan x");
                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da Cos2x ren baliokidea");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "(cosx)^2-(sinx)^2");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "cosx-sinx");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "2sinxcosx");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "sinxcosx");
                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Noiz esaten da limite bat jarraia dela? ");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Ez dakit");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Alboko limiteak desberdinak direnean");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Alboko limiteak berdinak direnean"); //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Limite bat ez dagoenean");
                    break;

                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zenbat da Sin5(pi)/6?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "erro(2)/2");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "1/2");//ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "erro(3)/3");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "-erro(2)/2");
                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "idatzi (2i-4)/(3+2i) polarrean.");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "(-8+14i)/13");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "(-6-5i)/14,");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "(5+16i)/10");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "(7-9i)/12");
                    break;


                default:
                    break;
                }
                galderaID++;
            }
            break;

        case 3://---fisika---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1://----FISIKAKO GALDERA-----
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer/zeinen legea da hau? (V=R*I\R=V/I\I=V/R)");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Ohm-en legea");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Thevenin-ren legea");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Coulomb-en legea");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Joul-en legea");
                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein zen Thevenin?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Ingeniero bat");//ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Fisiko bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Kimiko bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Elektroniko bat");
                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, " Zein da Kirchhoff-en legea?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Korapiloaren legea,");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Energia kontserbazioaren legea");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Akzio-erreakzio");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Kanpo magnetikoaren legea");
                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Nola kalkulatzen da erresistentzi totala paraleloan badaude?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "R=R1+R2");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "(1/R)=(1/R1)+(1/R2)");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "R=(1/R1)+(1/R2)");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "R=(1/R1)+R2)");
                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da potentzialaren formula egokia?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "V/(I^2)");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "(I^2)/R");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "(V^2)*R");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "I*(R^2)"); //ONDO
                    break;

                default:
                    break;
                }
                galderaID++;
            }
            break;

        case 4://---oinarri---
            galderaID = 1;
            while (galderaID <= 4) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zertarako balio du Git?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Bertsioen kontrol bat egiteko");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Programa bat gehiago nahasteko");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Textu bat lainoan gordetzeko");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Web bat egiteko");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "PDF batek irudia badu zer eduki behar du berarekin?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Deskripzio bat bakarrik");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Irudien taula bakarrik");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Deskripzio bat eta irudien taula");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Ezer");

                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer etiketa erabili behar da izenburua jartzeko?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "<head> ... </head>");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "<title> ... </title>");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "<img> ... </img>");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "<p> ... </p>");

                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer etiketa erabili behar da kodigoa jartzeko?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "<strong> ... </strong>");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "<div> ... </div>");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "<script> ... </script>");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "<head> ... <\head>");

                    break;
                default:
                    break;
                }
                galderaID++;
            }
            break;
        case 5://---redes---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da Google-ren DNS IPv4-a?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "1.1.1.1");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "5.5.5.5");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "0.0.0.0");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "8.8.8.8");  //ONDO

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer izen du transporte kapan lan egiten duen PDU-ari?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "bits");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "trama");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "segmento");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "pakete");


                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Ari - gabeko host batek IP helbide bat eskatu behar du, zer protokolo erabili behar du eskaera hori  egiteko?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "HTTP");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "SNMP");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "DHCP");  //ONDO    
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "ICMP");

                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da IPv6 helbide honen (2001:0000:0000:abcd:0000:0000:0000:0001) idazkera motzena?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "2001:0000:0000:abcd::1");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "2001:0:0:abcd::1");    //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "2001::abcd::1");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "2001::abdc:0:1");

                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "255.255.255.248 maskaran zenbat host dira helbideragarriak?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "6");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "8");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "14");

                    break;
                default:
                    break;
                }
                galderaID++;
            }
            break;

        case 6://---program II---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da arraya[gelaID][galderaID]-ren baliokidea?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "*(arraya+i)");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "arraya.i");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "(arraya+i)");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "*arraya+i");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer da erakusle bat?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Ezer");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Memoriako zati bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Memoriako elementuak");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Memoriako helbide bat zehazten duen elementu bat");//ONDO


                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Nola deklaratzen da erakusle bat?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "?");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "&");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "*");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "^");

                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer da programazioan errekurtsibitatea?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Funtzio batek bere buruari deitzea");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Funtzio batek beste funtzio bati deitzea");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Funtzio bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Funtzio baten barruan hainbat funtzio edukitzea");

                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Fitxategi bat irekitzeko fopen erabiltzen da, funtzio honek fitxategiaren izena eta modua behar du, zein letra da irakurtzeko?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "d");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "w");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "a");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "r");  //ONDO

                    break;
                default:
                    break;
                }
                galderaID++;
            }
            break;

        case 7://---mate II---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer da pibot bat?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Saskibaloiko posizio bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Ezkerretik hasita 0 ez den lehen zenbakia");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Eskuinetik hasieta 0 ez den lehen zenbakia");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Eskuinetik hasieta 0 den lehen zenbakia");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Noiz erabili behar da Bernoulli?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Ekuazioa lineala denean");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Ekuazioa ez lineala denea");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Ekuazio diferentziala lineala denean");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Ekuazio diferentziala ez lineala denean");  //ONDO

                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer esan nahi du matriz bateko zutabe bakoitzean pibot bat edukitzeak?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Matrizea osatzen duen ekuazioek pibot bat dutela");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Matrizea osatzen duen ekuazioek sistema indeterminatu bat osatzen dutela");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Matrizea osatzen duen ekuazioek sistema bateragarri determinatua dela");   //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Matrizea osatzen duen ekuazioek sistema batera ezin bat dela");

                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer da matriz elemental bat?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Matrizeko diagonal nagusian dagoen zenbakiak 1 dira eta beste guztiak 0");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Matrizeko diagonal nagusian dagoen zenbakiak 0 dira eta beste denak 1");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Ordenaturik dagoen matrize bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Matrize batean 0-rik ez edukitzea");

                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da ekuazio diferentzial baten orden maila?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Koefiziente handiena ");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Deribatu maila handiena");   //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Deribatu maila txikiena");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Koefiziente txikiena");

                    break;

                default:
                    break;
                }
                galderaID++;
            }
            break;

        case 8://---mate D---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer da grafo Hamilton bat?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Puntu guztietatik pasatzea baina amaiera eta hasiera ezberdinak izanik");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Puntu guztietatik behin pasatzea baina amaiera eta hasiera ezberdinak izanik");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Hasiera eta amaiera puntu bera izanik ibildide zirkularra egitea puntu guztietatik behin pasatuz");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Hasiera eta amaiera puntu bera izanik puntu guztietatik pasatzea");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer ezberdintasun dago grafo Eulearra eta Hamiltondarraren artean?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Batek ibilbide ziklikoa egiten du eta besteak ez");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Batek erpinak hartzen ditu kontua eta besteak ertzak");   //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Batek ibilbide ziklikoak puntuen artean eta besteak ibilbide ziklikoa ertzen artean");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Ez dago ezberdintasunik");

                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zenbat modu daude {1,2,3} zenbakiak ordenatzeko?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "4");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "6"); //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "8");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "10");

                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "12 korrikalari dagoen lasterketa baten zenbat modu daude dominak banatzeko orduan? ");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "1250");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "1320"); //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "1640");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "1480");

                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "15 gozoki izanik zenbat modu daude 20 umeren artean banatzeko gehienez bakoitzak 1 izanik?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "10408");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "15504");//ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "16450");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "17430");

                    break;

                default:
                    break;
                }
                galderaID++;
            }
            break;
        case 9://---elektrtonika---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Nolakoa da korronte alternoaren uhinak");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Sinusoidala");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Zirkularra");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Ez da ezagutzen");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Obalatua");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer da diodo bat?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Artezgailu bat");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Transistore bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Transformadore bat");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Energia iturri bat");

                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zein da artezgailu baten helburua?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Korronteen frekuentzia handitzea");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Korronte zuzena alterno bihurtzea");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Korronte alternoa zuzena bihurtzea");//ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Korronteen frekuentzia txikitzea");
                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zenbat transistore mota daude?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "3");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "4");//ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "5");

                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer zati ditu elikadura iturri basiko batek?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Transdormadorea-> irteera");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Transformadorea->artezgailuak->irteera");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Transformadorea->artezgailuak->filtroa->irteera");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Transformadorea->artezgailuak->filtroa->reguladorea->irteera");   //ONDO

                    break;

                default:
                    break;
                }
                galderaID++;
            }
            break;
        case 10://---elektrtonika---
            galderaID = 1;
            while (galderaID <= 5) {
                switch (galderaID)
                {
                case 1:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zenbat ingurune nagusi daude enpresa bati eragiten diona?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "1");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "2");//ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "3");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "4");

                    break;
                case 2:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Kontabilitate garaian , zenbat atal eduki behar ditu urteko kontuetan?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "3");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "4");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "5");//ONDO
                    break;
                case 3:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Nola kalkulatzen da enpresa baten bermea?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Aktibo erreala/ zorrak");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Aktibo/Pasibo");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Aktiko erreala*zorrak");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Aktibo*Pasibo");
                    break;
                case 4:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "-Enpresa baten negozio plana zenbat atal nagusi ditu?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "5");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "7");
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "8"); //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "10");

                    break;
                case 5:
                    galdera[gelaID][galderaID].gelaID = gelaID;
                    galdera[gelaID][galderaID].galderaID = galderaID;
                    strcpy(galdera[gelaID][galderaID].testua, "Zer esan nahi du enpresa baten ingurune orokorra?");
                    strcpy(galdera[gelaID][galderaID].aukerak.A, "Enpresa guztientzako berdina da eta eragin bera du guztiendako");
                    strcpy(galdera[gelaID][galderaID].aukerak.B, "Enpresa guztientzako berdina da eta denetan izaten du eragina baina ez modu berean");  //ONDO
                    strcpy(galdera[gelaID][galderaID].aukerak.C, "Jarduera-sektore baten barneko enpresetan du bakarrik eragina");
                    strcpy(galdera[gelaID][galderaID].aukerak.D, "Jarduera-sektore guztien barneko enpresetan du bakarrik eragina");

                    break;

                default:
                    break;
                }
                galderaID++;
            }
            break;

        default:
            break;
        }

        gelaID++;
    }
    //oinarria
    /*
            case 5:
        strcpy(galdera[i].testua, "");
        strcpy(galdera[i].aukerak.A, "");  //ONDO
        strcpy(galdera[i].aukerak.B, "");
        strcpy(galdera[i].aukerak.C, "");
        strcpy(galdera[i].aukerak.D, "");
        break;

    */
}

int GalderakErantzun(int exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]) {

    POSIZIOA pos;
    int ebentu = 0;
    int erantzunda = 0;

    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA) {
        pantailaGarbitu();

        pos = saguarenPosizioa();
        switch (gelaID)//zer gelara sartu den ikusiko dugu.
        {
        case 1://---program---
            switch (galderaID)
            {
            case 1:

                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);

                }

                else  if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else   if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
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
                    opzioakAgertu(galdera, gelaID, galderaID, 1);

                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);

                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);

                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);

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
                    opzioakAgertu(galdera, gelaID, galderaID, 1);

                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);

                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);


                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);

                }

                else {
                    erantzunda = 0;
                }

                break;
            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program\\P5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            default:
                break;
            }
            break;
        case 2://---mate---
            switch (galderaID)
            {

            case 1:

                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;
            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate\\M5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;
            default:
                break;
            }
            break;
        case 3://---fisika---
            switch (galderaID)
            {
            case 1://--Fisika---
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;
            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;
            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;
            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Fisika\\F5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            default:
                break;
            }
            break;
        case 4://---oinarri---
            switch (galderaID)
            {
            case 1://---oinarri---
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;
            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\oinarri\\O4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }

                break;

            default:
                break;
            }
            break;
        case 5://---redes---
            switch (galderaID)
            {
            case 1:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\redes\\R5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            default:
                break;
            }
            break;
        case 6://---program II----
            switch (galderaID)
            {
            case 1:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Program_II\\PII5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            default:
                break;
            }
            break;
        case 7://---Mate II---
            switch (galderaID)
            {

            case 1:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Mate_II\\M_II5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;


            default:
                break;
            }
            break;
        case 8://---Mate D---
            switch (galderaID)
            {

            case 1:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MD5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MDtC.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\MateD\\MDtD.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            default:
                break;
            }
            break;
        case 9://---elektronika---
            switch (galderaID)
            {
            case 1://---elektronika---
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;

            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Elektronika\\E5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;


            default:
                break;
            }
            break;
        case 10://---empresa---
            switch (galderaID)
            {
            case 1:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM1D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            case 2:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM2D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            case 3:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM3D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            case 4:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM4D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            case 5:
                erantzunda = 1;

                if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5A.bmp"), 30, 490);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 1);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5B.bmp"), 656, 489);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 2);
                }

                else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5C.bmp"), 30, 614);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 3);
                }

                else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                    irudiaMugitu(irudiaKargatu(".\\img\\Galderak_Erantzunak\\Empresa\\EM5D.bmp"), 656, 616);
                    irudiakMarraztu();
                    opzioakAgertu(galdera, gelaID, galderaID, 4);
                }

                else {
                    erantzunda = 0;
                }
                break;
            default:

                break;
            }
        default:
            break;
        }

    }

    if (erantzunda == 1) {
        pantailaBerriztu();
    }

    return erantzunda;
}

void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota) {

    switch (mota)
    {
    case 1:
        textuaGaitu_galderak();
        textuaIdatzi(27, 290, galdera[gelaID][galderaID].testua);
        textuaIdatzi(684, 512, galdera[gelaID][galderaID].aukerak.B);
        textuaIdatzi(55, 645, galdera[gelaID][galderaID].aukerak.C);
        textuaIdatzi(684, 645, galdera[gelaID][galderaID].aukerak.D);
        break;
    case 2:
        textuaGaitu_galderak();
        textuaIdatzi(27, 290, galdera[gelaID][galderaID].testua);
        textuaIdatzi(55, 512, galdera[gelaID][galderaID].aukerak.A);
        textuaIdatzi(55, 645, galdera[gelaID][galderaID].aukerak.C);
        textuaIdatzi(684, 645, galdera[gelaID][galderaID].aukerak.D);
        break;
    case 3:
        textuaGaitu_galderak();
        textuaIdatzi(27, 290, galdera[gelaID][galderaID].testua);
        textuaIdatzi(55, 512, galdera[gelaID][galderaID].aukerak.A);
        textuaIdatzi(684, 512, galdera[gelaID][galderaID].aukerak.B);
        textuaIdatzi(684, 645, galdera[gelaID][galderaID].aukerak.D);

        break;
    case 4:
        textuaGaitu_galderak();
        textuaIdatzi(27, 290, galdera[gelaID][galderaID].testua);
        textuaIdatzi(55, 512, galdera[gelaID][galderaID].aukerak.A);
        textuaIdatzi(684, 512, galdera[gelaID][galderaID].aukerak.B);
        textuaIdatzi(55, 645, galdera[gelaID][galderaID].aukerak.C);
        break;
    default:
        break;
    }
}