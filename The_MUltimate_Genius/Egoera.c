#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Egoera.h"

//------------------------------------Globalak
HITBOX hitbox;
void* pixels = NULL;
int pitch;
Uint8 bpp;
//Uint32 refreshrate = 0;
//Uint32 moverate;

//------------------------------------egoera
EGOERA menua(void)
{
    int id, ebentu;
    POSIZIOA pos;
    EGOERA egoera;
    //
    egoera = MENUA_P;
    //
    pantailaGarbitu();
    id = fondoPantaila(MENUA_F);
    pantailaBerriztu();
    //
    while (egoera == MENUA_P)
    {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        //
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x > 18 && pos.x < 18 + 175) && (pos.y > 650 && pos.y < 650 + 50)))
        {
            egoera = IRTEN_P;//ir
        }
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 483 && pos.x < 483 + 343) && (pos.y >= 386 && pos.y < 386 + 68)))//kontrolak
        {
            egoera = KONTROLAK_P;//kontrolak
        }
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 483 && pos.x < 483 + 343) && (pos.y >= 293 && pos.y < 293 + 68)))//profila
        {
            egoera = PROFILA_P;//profila
        }
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 483 && pos.x < 483 + 343) && (pos.y >= 479 && pos.y < 479 + 68)))//kargatu
        {
            egoera = KARGATU_P;//kargatu
        }
        if (ebentu == GERTAERA_IRTEN)
        {
            egoera = IRTEN_P;
        }
    }
    //
    return egoera;
}

EGOERA jolastu(JOKALARIA* jokalaria)
{
    int error = 0;
    EGOERA egoera;
    //
    egoera = ETXEA_P;
    //

    GALDERA galdera[GELAIDMAX][GALDERAIDMAX];

    error = galderakEtaAukerakLotuFitxategiarenBitartez(galdera);
    if (error == 1)
    {
        galderakEtaEurenAukerakSortu(galdera);
    }
    while (egoera == ETXEA_P || egoera == UNI_P)
    {
        if (egoera == ETXEA_P)
        {
            egoera = etxea(jokalaria);
        }
        if (egoera == UNI_P)
        {
            egoera = uni(jokalaria, galdera);
        }
    }
    //
    return egoera;
}

EGOERA kontrolak()
{
    int fondoa, ebentu;
    POSIZIOA pos;
    EGOERA egoera;
    //
    egoera = KONTROLAK_P;
    fondoa = fondoPantaila(KONTROLAK_F);
    //
    while (egoera == KONTROLAK_P)
    {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x > 33 && pos.x < 33 + 189) && (pos.y > 633 && pos.y < 633 + 44)))
        {
            egoera = MENUA_P;//irten (bat atzera)
        }
        if (ebentu == GERTAERA_IRTEN)
        {
            egoera = IRTEN_P;
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}

EGOERA profila(JOKALARIA* jokalaria)
{
    int ebentu, subBucle, tmpEbentu, aldaketa, fondoa;
    char tmpIzena[8], tmpGradua[128];
    EGOERA egoera;
    POSIZIOA pos;
    //
    egoera = PROFILA_P;
    fondoa = fondoPantaila(PROFILA_F);
    aldaketa = 0;
    strcpy(tmpIzena, " ");
    strcpy(tmpGradua, " ");
    strcpy(jokalaria->izena, " ");
    strcpy(jokalaria->gradua.izena, "Informatika");
    strcpy(jokalaria->irudia.izena, " ");
    textuaGaitu_profila();
    //
    textuaIdatzi(180, 174, jokalaria->izena);
    textuaIdatzi(180, 356, jokalaria->gradua.izena);
    pantailaBerriztu();
    //
    while (egoera == PROFILA_P)
    {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        //si clicka en izena
        if (ebentu == GERTAERA_IRTEN)
        {
            egoera = IRTEN_P;
        }
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 458) && (pos.y >= 166 && pos.y <= 166 + 88)))
        {
            //mantener el grado
            irudiakMarraztu();
            textuaIdatzi(180, 356, jokalaria->gradua.izena);
            pantailaBerriztu();
            //
            subBucle = 0;
            while (strlen(tmpIzena) != 7 && subBucle == 0)
            {
                pos = saguarenPosizioa();
                tmpEbentu = ebentuaJasoGertatuBada();
                switch (tmpEbentu)
                {
                case SAGU_BOTOIA_EZKERRA:
                    if ((pos.x < 172) || (pos.x > 172 + 458) || (pos.y < 166) || (pos.y > 166 + 88))
                    {
                        subBucle = -1;
                    }
                    break;
                    //
                case TECLA_a:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "A");
                    else strcat(tmpIzena, "A");
                    break;
                case TECLA_b:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "B");
                    else strcat(tmpIzena, "B");
                    break;
                case TECLA_c:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "C");
                    else strcat(tmpIzena, "C");
                    break;
                case TECLA_d:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "D");
                    else strcat(tmpIzena, "D");
                    break;
                case TECLA_e:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "E");
                    else strcat(tmpIzena, "E");
                    break;
                case TECLA_f:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "F");
                    else strcat(tmpIzena, "F");
                    break;
                case TECLA_g:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "G");
                    else strcat(tmpIzena, "G");
                    break;
                case TECLA_h:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "H");
                    else strcat(tmpIzena, "H");
                    break;
                case TECLA_i:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "I");
                    else strcat(tmpIzena, "I");
                    break;
                case TECLA_j:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "J");
                    else strcat(tmpIzena, "J");
                    break;
                case TECLA_k:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "K");
                    else strcat(tmpIzena, "K");
                    break;
                case TECLA_l:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "L");
                    else strcat(tmpIzena, "L");
                    break;
                case TECLA_m:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "M");
                    else strcat(tmpIzena, "M");
                    break;
                case TECLA_n:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "N");
                    else strcat(tmpIzena, "N");
                    break;
                case TECLA_o:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "O");
                    else strcat(tmpIzena, "O");
                    break;
                case TECLA_p:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "P");
                    else strcat(tmpIzena, "P");
                    break;
                case TECLA_q:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "Q");
                    else strcat(tmpIzena, "Q");
                    break;
                case TECLA_r:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "R");
                    else strcat(tmpIzena, "R");
                    break;
                case TECLA_s:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "S");
                    else strcat(tmpIzena, "S");
                    break;
                case TECLA_t:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "T");
                    else strcat(tmpIzena, "T");
                    break;
                case TECLA_u:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "U");
                    else strcat(tmpIzena, "U");
                    break;
                case TECLA_v:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "V");
                    else strcat(tmpIzena, "V");
                    break;
                case TECLA_w:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "W");
                    else strcat(tmpIzena, "W");
                    break;
                case TECLA_x:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "X");
                    else strcat(tmpIzena, "X");
                    break;
                case TECLA_y:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "Y");
                    else strcat(tmpIzena, "Y");
                    break;
                case TECLA_z:
                    if (!strcmp(tmpIzena, " ")) strcpy(tmpIzena, "Z");
                    else strcat(tmpIzena, "Z");
                    break;
                default:
                    break;
                }
                textuaIdatzi(180, 174, tmpIzena);
                pantailaBerriztu();
            }
            textuaIdatzi(180, 174, tmpIzena);
            strcpy(jokalaria->izena, tmpIzena);
            pantailaBerriztu();
            strcpy(tmpIzena, " ");
            aldaketa = 1;
        }
        //si clicka en gradua le aparece una especie de lista
        /*if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 458) && (pos.y >= 348 && pos.y <= 348 + 88)))
        {
            crearLista(tmpGradua);
            strcpy((*jokalaria).gradua.izena, tmpGradua);
            fondoa = fondoPantaila(PROFILA_F);
            aldaketa = 1;
        }*/
        //si clicka en una imagen se marca/ilumina
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 932 && pos.x <= 932 + 147) && (pos.y >= 185 && pos.y <= 185 + 133)))//mutila
        {
            strcpy(jokalaria->irudia.izena, CHICO_AVATAR);
            strcpy(jokalaria->irudia2d.izena, CHICO_AVATAR_M);
            jokalaria->irudia.pos_hasi.x = 932; jokalaria->irudia.pos_hasi.y = 185;
            jokalaria->irudia.pos_buka.x = 932 + 147; jokalaria->irudia.pos_buka.y = 185 + 137;
            aldaketa = 1;
        }
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 932 && pos.x <= 932 + 147) && (pos.y >= 350 && pos.y <= 350 + 133)))//neska
        {
            strcpy(jokalaria->irudia.izena, CHICA_AVATAR);
            strcpy(jokalaria->irudia2d.izena, CHICA_AVATAR_M);
            jokalaria->irudia.pos_hasi.x = 932; jokalaria->irudia.pos_hasi.y = 350;
            jokalaria->irudia.pos_buka.x = 932 + 147; jokalaria->irudia.pos_buka.y = 350 + 137;
            aldaketa = 1;
        }
        //jarraitu
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 1077 && pos.x <= 1077 + 175) && (pos.y >= 638 && pos.y <= 638 + 50)))
        {
            if ((strcmp(" ", jokalaria->izena) != 0) && (strcmp(" ", jokalaria->gradua.izena) != 0) && (strcmp(" ", jokalaria->irudia.izena) != 0))
            {
                *jokalaria = pertsonaiaEratu(*jokalaria);
                egoera = JOLASTU_P;
            }
            else
            {
                warning_abisua(HUTSUNERIK_EZ);
                strcpy(jokalaria->izena, " ");
                //strcpy(jokalaria->gradua.izena, " ");
                strcpy(jokalaria->irudia.izena, " ");
                aldaketa = 1;
            }
        }
        //atzera
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 880 && pos.x <= 880 + 175) && (pos.y >= 638 && pos.y <= 638 + 50)))
        {
            egoera = MENUA_P;
        }
        //aplikazio grafiko funtzioanala
        if (aldaketa == 1)
        {
            irudiakMarraztu();
            textuaIdatzi(180, 174, (*jokalaria).izena);//izena beridatzi
            textuaIdatzi(180, 356, (*jokalaria).gradua.izena);//gradua beridatzi
            arkatzKoloreaEzarri(0XF8, 0XF3, 0X2B);
            koadroaMarraztu(jokalaria->irudia.pos_hasi.x - 1, jokalaria->irudia.pos_hasi.y - 1, jokalaria->irudia.pos_buka.x, jokalaria->irudia.pos_buka.y);
            pantailaBerriztu();
            aldaketa = 0;
        }
    }
    //
    textuaDesgaitu();
    irudiaKendu(fondoa);
    //
    return egoera;
}

EGOERA azalpena(void)
{
    int ebentua, fondoa;
    POSIZIOA pos;
    EGOERA egoera = AZALPENA_P;
    fondoa = fondoPantaila(AZALPENA_F);
    while (egoera == AZALPENA_P)
    {
        ebentua = ebentuaJasoGertatuBada();
        if (ebentua == GERTAERA_IRTEN)
        {
            egoera = IRTEN_P;
        }
        pos = saguarenPosizioa();
        if ((ebentua == SAGU_BOTOIA_EZKERRA) && (pos.x >= 1087 && pos.x <= 1262) && (pos.y >= 650 && pos.y <= 700))
        {
            egoera = JOLASTU_P;
        }
    }
    return egoera;
}

EGOERA kargatu(JOKALARIA* jokalaria)
{
    int irakurketa;
    char karpeta[] = "gordeketa.dat";
    EGOERA egoera;
    FILE* fitx;
    //
    egoera = MENUA_P;
    fitx = fopen(karpeta, "rb");
    //
    pantailaGarbitu();
    textuaGaitu_beltza();
    textuaIdatzi_beltza(10, 20, "Partida kargatzen...");
    pantailaBerriztu();
    Sleep(2000);
    if (fitx == NULL)
    {
        printf("Errorea \"%s\" fitxategia irekitzean.\n", karpeta);
        textuaIdatzi_beltza(10, 40, "Ez dago aurreko jokaldirik gordeta.");
        textuaIdatzi_beltza(10, 60, "Partida bat gordetzeko, beste bat gorde behar da aurretik.");
        pantailaBerriztu();
        Sleep(4500);
    }
    else
    {
        textuaIdatzi_beltza(10, 40, "Partida kargatuta.");
        textuaIdatzi_beltza(10, 60, "Jokalaria kargatzen...");
        pantailaBerriztu();
        Sleep(2500);
        irakurketa = fread(jokalaria, sizeof(JOKALARIA), 1, fitx);//karpeta: gordeketa.dat
        if (irakurketa != 1)
        {
            printf("Errorea \"%s\" fitxategian irakurtzerakoan.\n", karpeta);
            textuaIdatzi(10, 80, "Jokalaria ezin izan da kargatu.");
            pantailaBerriztu();
            Sleep(2500);
        }
        else
        {
            textuaIdatzi_beltza(10, 80, "Jokalaria kargatuta.");
            textuaIdatzi_beltza(10, 100, "Informazio guztia ongi kargatu da.");
            pantailaBerriztu();
            Sleep(1500);
            egoera = JOLASTU_P;
        }
        fclose(fitx);
    }
    return egoera;
}

EGOERA etxea(JOKALARIA* jokalaria)
{
    int fondoa, jarraitu = 0, ebentu = 0, klik = 0;
    POSIZIOA pos_jokalaria;
    EGOERA egoera;


    pos_jokalaria.x = 1150;
    pos_jokalaria.y = 180;

    //
    egoera = ETXEA_P;
    KargatuMapa(MAPEO_GELA, &pixels, &pitch, &bpp);
    fondoa = fondoPantaila(ETXEA_F);
    //
    while (egoera == ETXEA_P)//etxea den bitartean
    {
        ebentu = ebentuaJasoGertatuBada();
        //
        klik = pertsonaiaMugitu(ebentu, pos_jokalaria, *jokalaria, egoera);
        //(busa)itzultzerakoan unibertsitatera bidaltzeko
        if (klik == 1)   //(pos.x >= 384 && pos.x <= 384 + 64) && (pos.y >= 159 && pos.y <= 159 + 244))
        {
            karga_gif();
            egoera = UNI_P;
        }
        //(ohea)itzultzerakoan etxera edo menura bidaltzeko
        if (klik == 2)    //(pos.x >= 1193 && pos.x <= 1193 + 46) && (pos.y >= 149 && pos.y <= 149 + 57))
        {
            if ((jokalaria->eguna == 1 || jokalaria->eguna == 2 || jokalaria->eguna == 3) && jokalaria->gradua.exp.xp == 10) {
                jokalaria->gradua.exp.max = 20;
                jokalaria->gradua.exp.nvl++;
            }
            else if ((jokalaria->eguna == 2 || jokalaria->eguna == 3) && jokalaria->gradua.exp.xp == 20) {
                jokalaria->gradua.exp.max = 25;
                jokalaria->gradua.exp.nvl++;
            }
            jokalaria->eguna++;
            //
            egoera = gorde(*jokalaria);
        }
        if (klik == 9)
        {
            egoera = IRTEN_P;
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}

EGOERA uni(JOKALARIA* jokalaria, GALDERA galdera[GELAIDMAX][GALDERAIDMAX])
{
    int fondoa, jarraitu = 1, ebentu = 0, klik = 0;
    EGOERA egoera;
    POSIZIOA pos, pos_jokalaria;
    //
    pos_jokalaria.x = 1150;
    pos_jokalaria.y = 180;

    egoera = UNI_P;
    KargatuMapa(MAPEO_UNI, &pixels, &pitch, &bpp);
    fondoa = fondoPantaila(UNI_F);
    //
    while (egoera == UNI_P)//unibertsitatea den bitartean
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == GERTAERA_IRTEN)
        {
            egoera = IRTEN_P;
        }
        //
        klik = pertsonaiaMugitu(ebentu, pos_jokalaria, *jokalaria, egoera);

        pos = saguarenPosizioa();
        if (klik == 3)
        {
            egoera = galderak(1, jokalaria, galdera);//itzultzerakoan etxera bidaltzeko
        }
        if (klik == 4)
        {
            egoera = galderak(2, jokalaria, galdera);//itzultzerakoan etxera bidaltzeko
        }
        if (klik == 5)
        {
            egoera = galderak(3, jokalaria, galdera);//itzultzerakoan etxera bidaltzeko
        }
        if (klik == 6)
        {
            egoera = galderak(4, jokalaria, galdera);//itzultzerakoan etxera bidaltzeko
        }
        if (klik == 7)
        {
            egoera = galderak(5, jokalaria, galdera);//itzultzerakoan etxera bidaltzeko
        }
        if (klik == 8)
        {
            karga_gif();
            egoera = ETXEA_P;
        }
        if (klik == 9)
        {
            egoera = IRTEN_P;
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}

EGOERA gorde(JOKALARIA jokalaria)
{
    int irakurketa, ebentu;
    char str[4];
    char karpeta[] = "gordeketa.dat";
    EGOERA egoera;
    FILE* fitx;
    //
    strcpy(str, " ");
    ebentu = 0;
    egoera = MENUA_P;
    fitx = fopen(karpeta, "wb");
    //
    pantailaGarbitu();
    textuaGaitu_beltza();
    textuaIdatzi_beltza(10, 20, "Partida gordetzen...");
    pantailaBerriztu();
    Sleep(3500);
    if (fitx == NULL)
    {
        printf("Errorea \"%s\" fitxategia irekitzean.\n", karpeta);
    }
    else
    {
        irakurketa = fwrite(&jokalaria, sizeof(JOKALARIA), 1, fitx);
        if (irakurketa != 1)
        {
            printf("Errorea \"%s\" fitxategian idazterakoan.\n", karpeta);
        }
        else
        {
            textuaIdatzi_beltza(10, 40, "Partida gordeta.");
            pantailaBerriztu();
            textuaIdatzi_beltza(10, 60, "Jolasten jarraitu nahi duzu? (B/E)");
            //
            while (strcmp(str, "B") != 0 && strcmp(str, "E") != 0)
            {
                ebentu = ebentuaJasoGertatuBada();
                switch (ebentu)
                {
                case TECLA_b:
                    if (!strcmp(str, " ")) strcpy(str, "B");
                    else strcat(str, "B");
                    break;
                case TECLA_e:
                    if (!strcmp(str, " ")) strcpy(str, "E");
                    else strcat(str, "E");
                    break;
                case GERTAERA_IRTEN:
                    egoera = IRTEN_P;
                    break;
                default:
                    break;
                }
                textuaIdatzi_beltza(10, 80, str);
                pantailaBerriztu();
            }
            if (strcmp(str, "B") == 0)
            {
                egoera = ETXEA_P;
            }
            if (strcmp(str, "E") == 0)
            {
                egoera = MENUA_P;
            }
        }
        strcpy(str, " ");
        fclose(fitx);
    }
    Sleep(2000);
    textuaDesgaitu();
    pantailaBerriztu();
    //
    return egoera;
}

EGOERA azkenPantaila(EGOERA egoera, JOKALARIA jokalaria, char* str)
{
    int fondo, ebentu;
    EGOERA berria;
    //
    berria = egoera;
    fondo = fondoPantaila(str);
    if (strcmp(str, IRABAZI_F) == 0)
    {
        pantailaGarbitu();
        irudiakMarraztu();
        textuaGaitu_galderak();
        textuaIdatzi(580, 300, jokalaria.izena);
        textuaDesgaitu();
        pantailaBerriztu();
    }
    //
    while (berria == egoera)
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == GERTAERA_IRTEN)
        {
            egoera = IRTEN_P;
        }
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            berria = MENUA_P;
        }
    }
    //
    return berria;
}

EGOERA galderak(int gelaID, JOKALARIA* jokalaria, GALDERA galdera[GELAIDMAX][GALDERAIDMAX])
{
    int galderaID = 1, erantzunda = 0;
    int bukatuta = 0, erantzunOndoKont = 0;
    EGOERA egoera;
    //
    egoera = UNI_P;
    //
    if (jokalaria->eguna == 3) {
        azterketa(galdera, 1, 1, &(jokalaria->gradua.exp.xp), jokalaria->eguna, jokalaria);
        if (jokalaria->gradua.exp.xp >= 23)
        {
            egoera = IRABAZI_P;
        }
        else
        {
            egoera = GALDU_P;
        }
    }
    else
    {
        if (jokalaria->eguna == 2) {
            galderaID = 3;
        }

        fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera, jokalaria->irudia.izena);
        while (erantzunOndoKont < 2 && galdera[gelaID][galderaID].sartuta == 0) {
            erantzunda = GalderakErantzun(&(jokalaria->gradua.exp), gelaID, galderaID, galdera, jokalaria->eguna);//0= ez erantzun, 1=ondo,2=gaizki
            if (erantzunda != 0 && erantzunOndoKont < 2) {
                galdera[gelaID][galderaID].erabilita = 1;
                Sleep(500);
                galderaID++;
                if (erantzunda == 1) {
                    erantzunOndoKont++;
                    galdera[gelaID][galderaID - 1].sartuta = 1;
                }
                else if (erantzunda == 2) {
                    erantzunOndoKont = 5;// gaizki egin duela esateko
                    galdera[gelaID][galderaID - 1].sartuta = 1;
                }
                if (galderaID == 6) {
                    galderaID = 1;
                }
                if (erantzunOndoKont < 2) {
                    fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera, jokalaria->irudia.izena);
                }
            }
        }

        if (erantzunOndoKont > 2) {
            irudiaMugitu(irudiaKargatu(BOTA), 300, 230);
            irudiakMarraztu();
            pantailaBerriztu();
            Sleep(1000);
        }
        if (erantzunOndoKont == 0 || erantzunOndoKont == 2) {
            irudiaMugitu(irudiaKargatu(BUKATU), 300, 230);
            irudiakMarraztu();
            pantailaBerriztu();
            Sleep(1000);
        }
        fondoPantaila(UNI_F);
        pantailaBerriztu();
    }
    //
    return egoera;
}

int pertsonaiaMugitu(int  ebentu, POSIZIOA pos, JOKALARIA jokalaria, EGOERA egoera)
{
    int mugi, x, y, tama�o = 48, tmp = 0;
    JOKALARIA sprite = jokalaria;
    mugi = 10;
    //
    if (strcmp(sprite.irudia.izena, CHICO_AVATAR) == 0)
    {
        sprite.irudia2d.id = spriteKargatu(sprite.irudia2d.izena);
    }
    if (strcmp(sprite.irudia.izena, CHICA_AVATAR) == 0)
    {
        sprite.irudia2d.id = spriteKargatu(sprite.irudia2d.izena);
    }
    x = 0; y = 0;
    pos.x = 1150;
    pos.y = 210;
    //
    while (mugi == 10)
    {
        pantailaGarbitu();
        spriteMugitu(sprite.irudia2d.id, pos.x, pos.y);

        ebentu = ebentuaJasoGertatuBada();
        sprite.pos.x = pos.x;
        sprite.pos.y = pos.y;

        switch (ebentu)
        {
        case TECLA_s:
            KolisioakKonprobatu(pixels, pitch, bpp, sprite);

            if (hitbox.behekoa.ezker == BELTZA)
            {
                pos.y = pos.y;
                x = 4;
                y = 0;
                break;
            }
            else {
                //sprite mover abajo//
                pos.y = pos.y + 4;
                //---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
                y = 0;
                if (tmp == TECLA_s)
                {
                    x = x + 4;
                }
                else
                {
                    x = 4;
                }
                if (x > 8)
                {
                    x = 0;
                }
                tmp = ebentu;
                //------------------------------------------------------------//
                break;
            }
        case TECLA_w:
            KolisioakKonprobatu(pixels, pitch, bpp, sprite);

            if (hitbox.goikoa == BELTZA)
            {
                pos.y = pos.y;
                x = 4;
                y = 13;
                break;
            }
            else {
                //sprite mover arriba//
                pos.y = pos.y - 4;
                //---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
                y = 13;
                if (tmp == TECLA_w)
                {
                    x = x + 4;
                }
                else
                {
                    x = 4;
                }
                if (x > 8)
                {
                    x = 0;
                }
                tmp = ebentu;
                //------------------------------------------------------------//
                break;
            }
        case TECLA_d:
            KolisioakKonprobatu(pixels, pitch, bpp, sprite);
            if ((pos.x >= 430 && pos.x <= 671) && (pos.y >= 50 && pos.y <= 125) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
            {
                warning_abisua(OBRAK);
            }
            if (hitbox.eskuin.erdikoa == BELTZA || hitbox.eskuin.erdikoa == HORIA)
            {
                pos.x = pos.x;
                x = 4;
                y = 8;
                break;
            }
            else {
                //sprite mover derecha//
                pos.x = pos.x + 4;
                //---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
                y = 8;
                if (tmp == TECLA_d)
                {
                    x = x + 4;
                }
                else { x = 4; }

                if (x > 8)
                {
                    x = 0;
                }
                tmp = ebentu;
                //------------------------------------------------------------//

                break;
            }
        case TECLA_i:
        {
            experientzia_pantaila(sprite);
            irudiakMarraztu();
            pantailaBerriztu();
        }
        break;
        case GERTAERA_IRTEN:
            mugi = 9;
            break;

        case TECLA_a:
            KolisioakKonprobatu(pixels, pitch, bpp, sprite);
            if (hitbox.ezker.erdikoa == BELTZA || hitbox.ezker.erdikoa == HORIA)
            {
                pos.x = pos.x;
                x = 4;
                y = 4;
                break;
            }
            else {
                //sprite mover izquierda//
                pos.x = pos.x - 4;
                //---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
                y = 4;
                if (tmp == TECLA_a)
                {
                    x = x + 4;
                }
                else { x = 4; }
                if (x > 8)
                {
                    x = 0;
                }
                tmp = ebentu;
                //------------------------------------------------------------//


                break;
            }
        case SAGU_BOTOIA_EZKERRA:

            if (egoera == ETXEA_P)
            {
                if (hitbox.ezker.erdikoa == HORIA)
                {
                    spriteKendu(sprite.irudia2d.id);
                    mugi = 1;
                }

                //(ohea)itzultzerakoan etxera edo menura bidaltzeko
                if ((hitbox.ezker.erdikoa == GORRIA) || (hitbox.goikoa == GORRIA) || (hitbox.eskuin.erdikoa == GORRIA) || (hitbox.behekoa.ezker == GORRIA))
                {
                    spriteKendu(sprite.irudia2d.id);
                    mugi = 2;
                }
            }
            if (egoera == UNI_P)
            {
                if ((pos.x >= 0 && pos.x <= 187) && (pos.y >= 188 && pos.y <= 248) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
                {
                    spriteKendu(sprite.irudia2d.id);
                    mugi = 3;

                }
                if ((pos.x >= 0 && pos.x <= 64) && (pos.y >= 530 && pos.y <= 595) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
                {
                    spriteKendu(sprite.irudia2d.id);
                    mugi = 4;

                }
                if ((pos.x >= 1215 && pos.x <= 1280) && (pos.y >= 92 && pos.y <= 5 + 157) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
                {

                    spriteKendu(sprite.irudia2d.id);
                    mugi = 5;
                }
                if ((pos.x >= 1215 && pos.x <= 1280) && (pos.y >= 344 && pos.y <= 407) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
                {

                    spriteKendu(sprite.irudia2d.id);
                    mugi = 6;
                }
                if ((pos.x >= 1215 && pos.x <= 1280) && (pos.y >= 594 && pos.y <= 660) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
                {

                    spriteKendu(sprite.irudia2d.id);
                    mugi = 7;
                }
                if ((pos.x >= 715 && pos.x <= 960) && (pos.y >= 64 && pos.y <= 125) && ((hitbox.ezker.erdikoa == HORIA) || (hitbox.eskuin.erdikoa == HORIA)))
                {

                    spriteKendu(sprite.irudia2d.id);
                    mugi = 8;
                }
            }

            break;
        default:
            break;
        }
        //
        irudiakMarraztu();
        spriteakMarraztu(x, y);
        //
        pantailaBerriztu();
    }
    return mugi;
}
