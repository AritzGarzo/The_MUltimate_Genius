#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include "funtzioak.h"
#include<stdlib.h>
#include <Windows.h>
#include<time.h>

extern HITBOX hitbox;
JOKALARIA sprite;
void* pixels = NULL;
int pitch;
Uint8 bpp;
Uint32 refreshrate = 0;
Uint32 moverate = 0;
//------------------------------------
int hasieratu(void)
{
    int sdl;
    //
    sdl = sgHasieratu();
    //
    if (sdl == -1)
    {
        fprintf(stderr, "Unable to set 1280x720 video: %s\n", SDL_GetError());
    }
    //
    return sdl;
}

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
    }
    //
    return egoera;
}
//--------------------------------
EGOERA jolastu(JOKALARIA* jokalaria)
{
    EGOERA egoera;
    //
    egoera = ETXEA_P;
    //
    int error = 0;

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
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}
//--------------------------------
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
        pos = saguarenPosizioa();
        if (ebentua == SAGU_BOTOIA_EZKERRA && (pos.x >= 1087 && pos.x <= 1262) && (pos.y >= 650 && pos.y <= 700))
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
        Sleep(2500);
        pantailaBerriztu();
        irakurketa = fread(&jokalaria, sizeof(JOKALARIA), 1, fitx);//karpeta: gordeketa.dat
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

//----------------------------
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
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}

JOKALARIA pertsonaiaEratu(JOKALARIA jokalaria)
{
    JOKALARIA berria;
    //
    berria = jokalaria;
    //
        //urtea----------------------------------
    berria.urtea = 1;
    //gradua----------------------------------
    berria.gradua.iKop = 10;
    //exp----------------------------
    berria.gradua.exp.nvl = 0;
    berria.gradua.exp.xp = 0;
    berria.gradua.exp.max = 10;
    //irudia----------------------------------
        //id----------------------------------
//berria.irudia.id = irudiaKargatu(berria.irudia.izena); //behar denean kargatuko da
        //pos---------------------------------
    berria.irudia.pos_hasi.x = 0;
    berria.irudia.pos_hasi.y = 0;
    //irudia2d--------------------------------
        //izena-------------------------------
    if (strcmp(berria.irudia.izena, CHICO_AVATAR) == 0)
    {
        strcpy(berria.irudia2d.izena, CHICO_AVATAR_M);
    }
    else if (strcmp(berria.irudia.izena, CHICA_AVATAR) == 0)
    {
        strcpy(berria.irudia2d.izena, CHICA_AVATAR_M);
    }
    //eguna---------------------------------
    berria.eguna = 1;

    //
    return berria;
}

void koadroaMarraztu(int x1, int y1, int x2, int y2)
{
    //goia
    zuzenaMarraztu(x1 - 1, y1 - 1, x2 - 1, y1 - 1);
    zuzenaMarraztu(x1, y1, x2, y1);
    //ezkerra
    zuzenaMarraztu(x1 - 1, y1 - 1, x1 - 1, y2 + 1);
    zuzenaMarraztu(x1, y1, x1, y2);
    //eskuina
    zuzenaMarraztu(x2, y1, x2, y2);
    zuzenaMarraztu(x2 + 1, y1 - 1, x2 + 1, y2 + 1);
    //behea
    zuzenaMarraztu(x1, y2, x2, y2);
    zuzenaMarraztu(x1 - 1, y2 + 1, x2 + 1, y2 + 1);
}

void crearLista(char str[])
{
    int id, amaitu, ebentu;
    POSIZIOA pos;
    //
    strcpy(str, " ");
    amaitu = 0;
    id = irudiaKargatu(".\\img\\zerrenda.bmp");
    irudiaMugitu(id, 171, 29);
    irudiakMarraztu();
    //
    textuaGaitu_profila();
    irudiakMarraztu();
    textuaIdatzi(172, 29, "Informatika");
    textuaIdatzi(172, 102, "Elektronika");
    pantailaBerriztu();
    //
    while (amaitu == 0)
    {
        pos = saguarenPosizioa();
        ebentu = ebentuaJasoGertatuBada();
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 29 && pos.y <= 29 + 74))) amaitu = 1;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 102 && pos.y <= 102 + 74))) amaitu = 2;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 175 && pos.y <= 175 + 74))) amaitu = 3;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 248 && pos.y <= 248 + 74))) amaitu = 4;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 321 && pos.y <= 321 + 74))) amaitu = 5;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 394 && pos.y <= 394 + 74))) amaitu = 6;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 467 && pos.y <= 467 + 74))) amaitu = 7;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 540 && pos.y <= 540 + 74))) amaitu = 8;
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 459) && (pos.y >= 613 && pos.y <= 613 + 74))) amaitu = 9;
    }
    //
    switch (amaitu)
    {
    case 1:
        strcpy(str, "Informatika");
        break;
    case 2:
        strcpy(str, "Elektronika");
        break;
    default:
        strcpy(str, "ey");
        break;
    }
    //
}
//------------------------
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
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            berria = MENUA_P;
        }
    }
    //
    return berria;
}
//--------------------
int fondoPantaila(char* str)
{
    int id;
    pantailaGarbitu();
    id = irudiaKargatu(str);
    irudiaMugitu(id, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();
    return id;
}

int pertsonaiaMugitu(int  ebentu, POSIZIOA pos, JOKALARIA jokalaria, EGOERA egoera)
{
    int mugi, x, y, tamaño = 48, tmp = 0;
    JOKALARIA sprite = jokalaria;
    mugi = 10;

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

        irudiakMarraztu();
        spriteakMarraztu(x, y);

        pantailaBerriztu();


    }
    return mugi;



}

void warning_abisua(char* str)
{
    int id, i;
    for (i = 0; i < 3; i++)
    {
        pantailaGarbitu();
        id = irudiaKargatu(str);
        irudiaMugitu(id, 320, 270);
        irudiakMarraztu();
        pantailaBerriztu();
        Sleep(650);
        irudiaKendu(id);
        pantailaGarbitu();
        irudiakMarraztu();
        pantailaBerriztu();
        Sleep(100);
    }
}

void karga_gif()
{
    int id, i, j;
    char busa_gif[][128] = { BUS_1, BUS_2, BUS_3, BUS_4, BUS_5, BUS_6, BUS_7, BUS_8, BUS_9, BUS_10, BUS_11, BUS_12, BUS_13, BUS_14, BUS_15, BUS_16, BUS_17, BUS_18, BUS_19, BUS_20, BUS_21, BUS_22 };
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 22; i++)
        {
            pantailaGarbitu();
            id = irudiaKargatu(busa_gif[i]);
            irudiaMugitu(id, 0, 0);
            irudiakMarraztu();
            pantailaBerriztu();
            Sleep(50);
            irudiaKendu(id);
        }
    }
}

int galderakEtaAukerakLotuFitxategiarenBitartez(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]) {

    char galderak[60][128] = {
        GALDERA_NULL,PROGRAM_GALDERA_1,PROGRAM_GALDERA_2,PROGRAM_GALDERA_3,PROGRAM_GALDERA_4,PROGRAM_GALDERA_5,
        GALDERA_NULL,MATE_GALDERA_1,MATE_GALDERA_2,MATE_GALDERA_3,MATE_GALDERA_4,MATE_GALDERA_5,
        GALDERA_NULL,FISIKA_GALDERA_1,FISIKA_GALDERA_2,FISIKA_GALDERA_3,FISIKA_GALDERA_4,FISIKA_GALDERA_5,
        GALDERA_NULL,OINARRI_GALDERA1,OINARRI_GALDERA2,OINARRI_GALDERA_3,OINARRI_GALDERA_4,OINARRI_GALDERA_5,
        GALDERA_NULL,REDES_GALDERA_1,REDES_GALDERA_2,REDES_GALDERA_3,REDES_GALDERA_4,REDES_GALDERA_5,
        GALDERA_NULL,PROGRAM_II_GALDERA_1,PROGRAM_II_GALDERA_2,PROGRAM_II_GALDERA_3,PROGRAM_II_GALDERA_4,PROGRAM_II_GALDERA_1,
        GALDERA_NULL,MATE_II_GALDERA_1,MATE_II_GALDERA_2,MATE_II_GALDERA_3,MATE_II_GALDERA_4,MATE_II_GALDERA_5,
        GALDERA_NULL,MATE_D_GALDERA_1,MATE_D_GALDERA_2,MATE_D_GALDERA_3,MATE_D_GALDERA_4,MATE_D_GALDERA_5,
        GALDERA_NULL,ELEKTRONIKA_GALDERA_1,ELEKTRONIKA_GALDERA_2,ELEKTRONIKA_GALDERA_3,ELEKTRONIKA_GALDERA_4,ELEKTRONIKA_GALDERA_5,
        GALDERA_NULL,EMPRESA_GALDERA_1,EMPRESA_GALDERA_2,EMPRESA_GALDERA_3,EMPRESA_GALDERA_1,EMPRESA_GALDERA_5
    };

    FILE* fitx;
    int fitxategiKont = 1, gelaIDKont = 1, galderaIDKont = 1, error = 0;


    while (fitxategiKont < 60) {

        fitx = fopen(galderak[fitxategiKont], "r");

        if (fitxategiKont == 6 || fitxategiKont == 12 || fitxategiKont == 18 || fitxategiKont == 23 || fitxategiKont == 24 || fitxategiKont == 30 || fitxategiKont == 36 || fitxategiKont == 42 || fitxategiKont == 48 || fitxategiKont == 54);

        else if (fitx == NULL) {
            printf("Errorea galderen fitxategia irakurtzerako orduan\n");
            return error = 1;
        }

        else {
            galdera[gelaIDKont][galderaIDKont].gelaID = gelaIDKont;
            galdera[gelaIDKont][galderaIDKont].galderaID = galderaIDKont;
            galdera[gelaIDKont][galderaIDKont].sartuta = 0;
            galdera[gelaIDKont][galderaIDKont].erabilita = 0;
            fgets(galdera[gelaIDKont][galderaIDKont].testua, 128, fitx);
            fgets(galdera[gelaIDKont][galderaIDKont].aukerak.A, 128, fitx);
            fgets(galdera[gelaIDKont][galderaIDKont].aukerak.B, 128, fitx);
            fgets(galdera[gelaIDKont][galderaIDKont].aukerak.C, 128, fitx);
            fgets(galdera[gelaIDKont][galderaIDKont].aukerak.D, 128, fitx);

            galdera[gelaIDKont][galderaIDKont].testua[strlen(galdera[gelaIDKont][galderaIDKont].testua) - 1] = '\0';
            galdera[gelaIDKont][galderaIDKont].aukerak.A[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.A) - 1] = '\0';
            galdera[gelaIDKont][galderaIDKont].aukerak.B[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.B) - 1] = '\0';
            galdera[gelaIDKont][galderaIDKont].aukerak.C[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.C) - 1] = '\0';
            galdera[gelaIDKont][galderaIDKont].aukerak.D[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.D) - 1] = '\0';
            fclose(fitx);

        }
        if (galderaIDKont > 5) {
            gelaIDKont++;
            galderaIDKont = 1;
        }
        else {
            galderaIDKont++;
        }

        fitxategiKont++;

    }
    return error;
}

void experientzia_pantaila(JOKALARIA jokalaria)
{
    int ebentu, fondo, luzera;
    char nibela[128], esperientzia[128];
    EGOERA egoera;
    POSIZIOA pos;
    //
    egoera = EXP_P;
    fondo = fondoPantaila(EXP_F);
    //pertsonaiaren irudia kargatu
        //----irudiak
    jokalaria.irudia.id = irudiaKargatu(jokalaria.irudia.izena);
    irudiaMugitu(jokalaria.irudia.id, 168, 142);
    //----karratua
    luzera = (jokalaria.gradua.exp.xp * 466) / jokalaria.gradua.exp.max;//zenbateraino luzatu beharko litzatekeen 
    irudiakMarraztu();
    crearCuadro(437, 210, luzera, 74);
    //----textua
        //----nibela
    StrBihurtu_nibela(nibela, jokalaria.gradua.exp.nvl);
    //----experientzia
    StrBihurtu_exp(esperientzia, jokalaria.gradua.exp);
    //---exp
    textuaGaitu_exp();
    textuaIdatzi_exp(617, 295, nibela);//nv
    textuaIdatzi_exp(562, 355, esperientzia);//exp
    textuaDesgaitu();
    //----
    pantailaBerriztu();
    //
    while (egoera == EXP_P)
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            if ((pos.x >= 18 && pos.x <= 18 + 175) && (pos.y >= 650 && pos.y <= 650 + 50))
            {
                egoera = UNI_P;
                irudiaKendu(fondo);
                irudiaKendu(jokalaria.irudia.id);
            }
        }
    }
}
//--------------------
void StrBihurtu_nibela(char str[], int nvl)
{
    char tmp[128];
    //
    IntStrBihurtu(nvl, tmp);
    strcpy(str, tmp);
}

void StrBihurtu_exp(char str[], EXP jokalaria)
{
    char tmp[128];
    //
    IntStrBihurtu(jokalaria.xp, tmp);
    strcpy(str, tmp);
    //
    strcat(str, "/");
    strcat(str, "\0");
    //
    IntStrBihurtu(jokalaria.max, tmp);
    strcat(str, tmp);
    //
//str[strlen(str)] = '\0';
}

void IntStrBihurtu(int n, char str[])
{
    int kont, i, kopia;
    char tmp, c = '0';
    kopia = n;
    kont = 0;
    if (kopia == 0)
    {
        str[kont] = c;
        kont++;
    }
    else
    {
        while (kopia > 0)
        {
            str[kont] = c + (kopia % 10);
            kopia /= 10;
            kont++;
        }
    }
    str[kont] = '\0';
    //itzulbiratu
    for (i = 0; i < kont / 2; i++)
    {
        tmp = str[i];
        str[i] = str[kont - (i + 1)];
        str[kont - (i + 1)] = tmp;
    }
}

void crearCuadro(int x, int y, int luzera, int altuera)
{
    int i;
    //
    arkatzKoloreaEzarri(142, 238, 255);
    //
    for (i = 0; i < altuera; i++)
    {
        zuzenaMarraztu(x, y + i, x + luzera, y + i);
    }
}
//--------------------
void fondoPantailaGalderekin(char* str, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], JOKALARIA jokalaria)
{
	int id, id_irakaslea;
    char irakaslea[128];
    //
	pantailaGarbitu();
	id = irudiaKargatu(str);
	irudiaMugitu(id, 0, 0);
    //
    switch (gelaID)
    {
    case 1:
        strcpy(irakaslea, PROGRAM_PROFE);
        break;
    case 2:
        strcpy(irakaslea, MATE_PROFE);
        break;
    case 3:
        strcpy(irakaslea, FISIKA_PROFE);
        break;
    case 4:
        strcpy(irakaslea, OINARRI_PROFE);
        break;
    case 5:
        strcpy(irakaslea, REDES_PROFE);
        break;
        //2.seihilekoa
    /*case 6:
        strcpy(irakaslea, PROGRAM_II_PROFE);
        break;
    case 7:
        strcpy(irakaslea, MATE_II_PROFE);
        break;
    case 8:
        strcpy(irakaslea, MATE_D_PROFE);
        break;
    case 9:
        strcpy(irakaslea, ELEKTRONIKA_PROFE);
        break;
    case 10:
        strcpy(irakaslea, EMPRESA_PROFE);
        break;*/
    default:
        strcpy(irakaslea, MATE_PROFE);
        break;
    }
    //----------aurpegiak kargatu
    id_irakaslea = irudiaKargatu(irakaslea);
    irudiaMugitu(id_irakaslea, 907, 72);
    if (strcmp(jokalaria.irudia.izena, CHICO_AVATAR) == 0)
    {
        jokalaria.irudia.id = irudiaKargatu(CHICO_AVATAR_G);
    }
    else
    {
        jokalaria.irudia.id = irudiaKargatu(CHICA_AVATAR_G);
    }
    irudiaMugitu(jokalaria.irudia.id, 189, 81);
    irudiakMarraztu();
    //
	irudiakMarraztu();

	textuaGaitu_galderak();
	textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
	textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
	textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
	textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
	textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);

	pantailaBerriztu();
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

        fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera, *jokalaria);
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
                    fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera, *jokalaria);
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da FOR baten sintaxia?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "(i=0;i<10;i++)"); //ondo
					strcpy(galdera[gelaID][galderaID].aukerak.B, "[i=0;i<10;i++]");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(i=0,i<10,i++)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "[i=0;i<10;i++]");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola da 65 bitarrean?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "01101011");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "01000001");  //  ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "11000001");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "01000010");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer diferentzia dago do while eta while-en artean?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "ez dago desberdintasunik");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "bat bestea baino azkarragoa da");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "batek lehenego zerbait egiten du eta gero baldintza konparatu");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "bat efizienteagoa da");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "If eta else if sententzia asko erabiltzen denean, zer beste sentetzia dago hori azkarrago egiteko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "switch");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "change");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "goto");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "break");
					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da (Sinx/Cosx) dx ren integrala?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "-Ln(cosx)");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "tanx");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ln(sinx)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "arctan x");
					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da Cos2x ren baliokidea");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "(cosx)^2-(sinx)^2");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "cosx-sinx");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "2sinxcosx");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "sinxcosx");
					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Noiz esaten da limite bat jarraia dela? ");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ez dakit");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Alboko limiteak desberdinak direnean");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Alboko limiteak berdinak direnean"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Limite bat ez dagoenean");
					break;

				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat da Sin5(pi)/6?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "erro(2)/2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "1/2");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "erro(3)/3");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "-erro(2)/2");
					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer/zeinen legea da hau? (V=R*I R=V/I I=V/R)");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ohm-en legea");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Thevenin-ren legea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Coulomb-en legea");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Joul-en legea");
					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein zen Thevenin?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ingeniari bat");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Fisikari bat");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Kimikari bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Elektroniko bat");
					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, " Zein da Kirchhoff-en legea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Korapiloaren legea");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Energia kontserbazioaren legea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Akzio-erreakzio");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Kanpo magnetikoaren legea");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola kalkulatzen da erresistentzia baliokidea paraleloan badaude?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "R=R1+R2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "(1/R)=(1/R1)+(1/R2)");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "R=(1/R1)+(1/R2)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "R=(1/R1)+R2)");
					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da potentziaren formula egokia?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "V/(I^2)");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "(I^2)/R");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(V^2)*R");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "(I^2)*R"); //ONDO
					break;

				default:
					break;
				}
				galderaID++;
			}
			break;

		case 4://---oinarri---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zertarako balio du Git-ek?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Bertsioen kontrol bat egiteko");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Programa bat gehiago nahasteko");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Textu bat lainoan gordetzeko");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Web bat egiteko");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "PDF batek irudia badu, zer eduki behar du berarekin?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Deskripzio bat bakarrik");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Irudien taula bakarrik");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Deskripzio bat eta irudien taula");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Ezer");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "HTML-n zer etiketa erabili behar da izenburua jartzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "<head> ... </head>");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "<title> ... </title>");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "<img> ... </img>");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "<p> ... </p>");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "HTML-n zer etiketa erabili behar da kodigoa jartzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "<strong> ... </strong>");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "<div> ... </div>");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "<script> ... </script>");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "<head> ... </head>");

					break;

				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer lengoaia mota da JavaScript?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Konpilatutako lengoaia");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Interpretatutako lengoaia"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Bat ere ez");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Irakurritako lengoaia bat");

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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da Google-ren DNS IPv4-a?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "1.1.1.1");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "5.5.5.5");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "0.0.0.0");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "8.8.8.8");  //ONDO

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer izen du transporte kapan lan egiten duen PDU-ari?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "bits");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "trama");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "segmento");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "pakete");


					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Ari - gabeko host batek IP helbide bat eskatu behar du, zer protokolo erabili behar du eskaera hori  egiteko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "HTTP");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "SNMP");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "DHCP");  //ONDO    
					strcpy(galdera[gelaID][galderaID].aukerak.D, "ICMP");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da IPv6 helbide honen (2001:0000:0000:abcd:0000:0000:0000:0001) idazkera motzena?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2001:0000:0000:abcd::1");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "2001:0:0:abcd::1");    //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "2001::abcd::1");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "2001::abdc:0:1");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da arraya[gelaID][galderaID]-ren baliokidea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "*(arraya+i)");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "arraya.i");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(arraya+i)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "*arraya+i");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da erakusle bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ezer");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Memoriako zati bat");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Memoriako elementuak");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Memoriako helbide bat zehazten duen elementu bat");//ONDO


					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola deklaratzen da erakusle bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "?");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "&");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "*");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "^");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da programazioan errekurtsibitatea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Funtzio batek bere buruari deitzea");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Funtzio batek beste funtzio bati deitzea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Funtzio bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Funtzio baten barruan hainbat funtzio edukitzea");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da pibot bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Saskibaloiko posizio bat");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Ezkerretik hasita 0 ez den lehen zenbakia");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Eskuinetik hasieta 0 ez den lehen zenbakia");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Eskuinetik hasieta 0 den lehen zenbakia");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Noiz erabili behar da Bernoulli?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ekuazioa lineala denean");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Ekuazioa ez lineala denea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ekuazio diferentziala lineala denean");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Ekuazio diferentziala ez lineala denean");  //ONDO

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer esan nahi du matriz bateko zutabe bakoitzean pibot bat edukitzeak?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Matrizea osatzen duen ekuazioek pibot bat dutela");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Matrizea osatzen duen ekuazioek sistema indeterminatu bat osatzen dutela");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Matrizea osatzen duen ekuazioek sistema bateragarri determinatua dela");   //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Matrizea osatzen duen ekuazioek sistema batera ezin bat dela");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da matriz elemental bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Matrizeko diagonal nagusian dagoen zenbakiak 1 dira eta beste guztiak 0");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Matrizeko diagonal nagusian dagoen zenbakiak 0 dira eta beste denak 1");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ordenaturik dagoen matrize bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Matrize batean 0-rik ez edukitzea");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da grafo Hamilton bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Puntu guztietatik pasatzea baina amaiera eta hasiera ezberdinak izanik");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Puntu guztietatik behin pasatzea baina amaiera eta hasiera ezberdinak izanik");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Hasiera eta amaiera puntu bera izanik ibildide zirkularra egitea puntu guztietatik behin pasatuz");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Hasiera eta amaiera puntu bera izanik puntu guztietatik pasatzea");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer ezberdintasun dago grafo Eulearra eta Hamiltondarraren artean?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Batek ibilbide ziklikoa egiten du eta besteak ez");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Batek erpinak hartzen ditu kontua eta besteak ertzak");   //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Batek ibilbide ziklikoak puntuen artean eta besteak ibilbide ziklikoa ertzen artean");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Ez dago ezberdintasunik");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat modu daude {1,2,3} zenbakiak ordenatzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "4");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "6"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "8");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "10");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "12 korrikalari dagoen lasterketa baten zenbat modu daude dominak banatzeko orduan? ");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "1250");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "1320"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "1640");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "1480");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nolakoa da korronte alternoaren uhinak");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Sinusoidala");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Zirkularra");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ez da ezagutzen");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Obalatua");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da diodo bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Artezgailu bat");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Transistore bat");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Transformadore bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Energia iturri bat");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da artezgailu baten helburua?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Korronteen frekuentzia handitzea");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Korronte zuzena alterno bihurtzea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Korronte alternoa zuzena bihurtzea");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Korronteen frekuentzia txikitzea");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat transistore mota daude?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "3");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "4");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "5");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat ingurune nagusi daude enpresa bati eragiten diona?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "1");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "2");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "3");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "4");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Kontabilitate garaian , zenbat atal eduki behar ditu urteko kontuetan?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "3");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "4");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "5");//ONDO
					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola kalkulatzen da enpresa baten bermea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Aktibo erreala/ zorrak");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Aktibo/Pasibo");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Aktiko erreala*zorrak");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Aktibo*Pasibo");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "-Enpresa baten negozio plana zenbat atal nagusi ditu?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "5");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "7");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "8"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "10");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
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
}

int GalderakErantzun(EXP* exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int eguna) {

    POSIZIOA pos;
    int ebentu = 0, erantzunda = 0, irudiaId;
    while (erantzunda == 0)
    {
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);//aukera sobranteak printeatzeko
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);

                    }

                    else  if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else   if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 2:

                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;


                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);

                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);

                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);

                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;

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

                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;

                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(FISIKA_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;

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
                case 1:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;


                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(OINARRI_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
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
                switch (galderaID) {
                case 1:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }
                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }
                    break;

                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }
                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(REDES_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(PROGRAM_II_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_II_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);

                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);

                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(MATE_DISKRETA_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;

                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(ELEKTRONIKA_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;
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
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_1_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_1_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_1_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_1_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 2:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_2_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_2_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_2_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_2_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                        exp->xp++; erantzunda = 1;
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 3:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_3_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_3_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_3_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_3_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 4:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_4_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_4_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_4_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_4_D);
                        irudiaMugitu(irudiaId, 656, 616);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 4);
                    }

                    else {
                        erantzunda = 0;
                    }

                    break;
                case 5:
                    erantzunda = 2;

                    if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS A------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_5_A);
                        irudiaMugitu(irudiaId, 30, 490);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 1);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 493 && pos.y <= 569)) { //-------------POS B------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_5_B);
                        irudiaMugitu(irudiaId, 656, 489);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 2);
                        exp->xp++; erantzunda = 1;
                    }

                    else if ((pos.x >= 34 && pos.x <= 628) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS C------------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_5_C);
                        irudiaMugitu(irudiaId, 30, 614);
                        irudiakMarraztu();
                        opzioakAgertu(galdera, gelaID, galderaID, 3);
                    }

                    else if ((pos.x >= 659 && pos.x <= 1255) && (pos.y >= 616 && pos.y <= 694)) { //-------------POS D-----------------
                        irudiaId = irudiaKargatu(EMPRESA_GALDERA_5_D);
                        irudiaMugitu(irudiaId, 656, 616);
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
    }

    if (erantzunda == 1 || erantzunda == 2) {
        irudiaKendu(irudiaId);
        pantailaBerriztu();
    }
    //capar la exp demás
    if(exp->xp > exp->max)
    {
        exp->xp = exp->max;
    }
    //
    return erantzunda;
}

void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota) {

	switch (mota)
	{
	case 1:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
		textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
		textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);
		break;
	case 2:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
		textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
		textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);
		break;
	case 3:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
		textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
		textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);

		break;
	case 4:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
		textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
		textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
		break;
	default:
		break;
	}
}

void azterketa(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int* exp, int eguna, JOKALARIA* jokalaria) {

    int erantzunda = 0;

    while (galderaID <= 5 && gelaID <= 5) {
        if (galdera[gelaID][galderaID].erabilita == 0) {
            fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera, *jokalaria);
            erantzunda = GalderakErantzun(&(jokalaria->gradua.exp), gelaID, galderaID, galdera, eguna);
            if (erantzunda != 0) {
                galdera[gelaID][galderaID].erabilita = 1;
                Sleep(500);
                gelaID++;
            }

        }
        else if (galderaID == 6) {
            gelaID++;
            galderaID = 1;
        }
        else galderaID++;
    }
}