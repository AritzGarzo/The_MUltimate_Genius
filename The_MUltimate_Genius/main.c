#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "GureEstrukturak.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
//Aritz Garzo

//
int hasieratu(void);
int fondoPantaila(char* str);
EGOERA menua(void);
EGOERA jolastu(JOKALARIA* jokalaria);
EGOERA kontrolak(void);
EGOERA profila(JOKALARIA* jokalaria);
EGOERA etxea(JOKALARIA* jokalaria);
EGOERA uni(JOKALARIA* jokalaria);
EGOERA galderak(int orden);
void insertarNombre(char str[]);
void crearLista(char str[]);
void koadroaMarraztu(int x1, int y1, int x2, int y2);
EGOERA gorde(JOKALARIA jokalaria);
EGOERA kargatu(JOKALARIA* jokalaria);
JOKALARIA pertsonaiaEratu(JOKALARIA jokalaria);
//_________
EGOERA menua();
EGOERA kontrolak();

int main(int argc, char* str[])
{
    int hasi;
    JOKALARIA jokalaria;
    EGOERA egoera;
    //sdl-a hasieratzeko
    hasi = hasieratu();
    //
    if (hasi == 0)
    {
        do
        {
            egoera = menua();
            if (egoera == PROFILA_P)
            {
                egoera = profila(&jokalaria);
                //egoera = JOLASTU_P;//JOLASTU
            }
            if (egoera == KARGATU_P)
            {
                //kargatu()
                egoera = JOLASTU_P;//JOLASTU
            }
            //
            switch (egoera)
            {
            case JOLASTU_P:
                egoera = jolastu(&jokalaria);
                break;
            case KONTROLAK_P:
                egoera = kontrolak();//
                break;
            default://irten
                break;
            }
        } while (egoera == MENUA_P);
    }
    //
    audioTerminate();
    sgItxi();

    return 0;
}

//_________
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
    //
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
EGOERA jolastu(JOKALARIA* jokalaria)
{
    //int jarraitu;
    EGOERA egoera;
    //
    egoera = ETXEA_P;
    //jarraitu = 1;
    //
    while (egoera == ETXEA_P || egoera == UNI_P)
    {
        if (egoera == ETXEA_P)
        {
            egoera = etxea(jokalaria);
        }
        if (egoera == UNI_P)
        {
            egoera = uni(jokalaria);
        }
    }
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
    strcpy(jokalaria->gradua.izena, " ");
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
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 172 && pos.x <= 172 + 458) && (pos.y >= 348 && pos.y <= 348 + 88)))
        {
            crearLista(tmpGradua);
            strcpy((*jokalaria).gradua.izena, tmpGradua);
            fondoa = fondoPantaila(PROFILA_F);
            aldaketa = 1;
        }
        //si clicka en una imagen se marca/ilumina
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 932 && pos.x <= 932 + 147) && (pos.y >= 185 && pos.y <= 185 + 133)))//mutila
        {
            strcpy(jokalaria->irudia.izena, CHICO_AVATAR);
            jokalaria->irudia.pos_hasi.x = 932; jokalaria->irudia.pos_hasi.y = 185;
            jokalaria->irudia.pos_buka.x = 932 + 147; jokalaria->irudia.pos_buka.y = 185 + 133;
            aldaketa = 1;
        }
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 932 && pos.x <= 932 + 147) && (pos.y >= 350 && pos.y <= 350 + 133)))//neska
        {
            strcpy(jokalaria->irudia.izena, CHICA_AVATAR);
            jokalaria->irudia.pos_hasi.x = 932; jokalaria->irudia.pos_hasi.y = 350;
            jokalaria->irudia.pos_buka.x = 932 + 147; jokalaria->irudia.pos_buka.y = 350 + 133;
            aldaketa = 1;
        }
        //jarraitu
        if ((ebentu == SAGU_BOTOIA_EZKERRA) && ((pos.x >= 1077 && pos.x <= 1077 + 175) && (pos.y >= 638 && pos.y <= 638 + 50)))
        {
            egoera = JOLASTU_P;
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
    if (fitx == NULL)
    {
        printf("Errorea \"%s\" fitxategia irekitzean.\n", karpeta);
    }
    else
    {
        irakurketa = fread(&jokalaria, sizeof(JOKALARIA), 1, fitx);//karpeta: gordeketa.dat
        if (irakurketa != 1)
        {
            printf("Errorea \"%s\" fitxategian irakurtzerakoan.\n", karpeta);
            egoera = JOLASTU_P;
        }
    }
    fclose(fitx);
    return egoera;
}
        //
EGOERA etxea(JOKALARIA* jokalaria)
{
    int fondoa, jarraitu = 0, ebentu = 0;
    POSIZIOA pos;
    EGOERA egoera;
    //
    egoera = ETXEA_P;
    fondoa = fondoPantaila(ETXEA_F);
    //
    while (egoera == ETXEA_P)//etxea den bitartean
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            //(busa)itzultzerakoan unibertsitatera bidaltzeko
            if ((pos.x >= 384 && pos.x <= 384 + 64) && (pos.y >= 159 && pos.y <= 159 + 244))
            {
                egoera = UNI_P;
            }
            //(ohea)itzultzerakoan etxera edo menura bidaltzeko
            if ((pos.x >= 1193 && pos.x <= 1193 + 46) && (pos.y >= 149 && pos.y <= 149 + 57))
            {
                egoera = gorde(*jokalaria);
            }
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}
EGOERA uni(JOKALARIA* jokalaria)
{
    int fondoa, jarraitu = 1, ebentu = 0;
    EGOERA egoera;
    POSIZIOA pos;
    //
    egoera = UNI_P;
    fondoa = fondoPantaila(".\\img\\uni.bmp");
    //
    while (egoera == UNI_P)//unibertsitatea den bitartean
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            if ((pos.x >= 1 && pos.x <= 1 + 51) && (pos.y >= 103 && pos.y <= 103 + 158))
            {
                egoera = galderak(1);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1 && pos.x <= 1 + 51) && (pos.y >= 433 && pos.y <= 433 + 166))
            {
                egoera = galderak(2);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1234 && pos.x <= 1234 + 45) && (pos.y >= 5 && pos.y <= 5 + 176))
            {
                egoera = galderak(3);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1233 && pos.x <= 1233 + 44) && (pos.y >= 289 && pos.y <= 289 + 160))
            {
                egoera = galderak(4);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1233 && pos.x <= 1233 + 46) && (pos.y >= 561 && pos.y <= 561 + 143))
            {
                egoera = galderak(5);//itzultzerakoan etxera bidaltzeko
            }
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
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
void koadroaMarraztu(int x1, int y1, int x2, int y2)
{
    //goia
    zuzenaMarraztu(x1 - 1, y1 - 1, x2 - 1, y1 -1);
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
            //
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
            textuaIdatzi_beltza(10, 60, "Jolasten jarraitu nahi duzu? (Bai/Ez)");
            //
            while (strcmp(str, "BAI") != 0 && strcmp(str, "EZ") != 0)
            {
                ebentu = ebentuaJasoGertatuBada();
                switch (ebentu)
                {
                case TECLA_a:
                    if (!strcmp(str, " ")) strcpy(str, "A");
                    else strcat(str, "A");
                    break;
                case TECLA_b:
                    if (!strcmp(str, " ")) strcpy(str, "B");
                    else strcat(str, "B");
                    break;
                case TECLA_e:
                    if (!strcmp(str, " ")) strcpy(str, "E");
                    else strcat(str, "E");
                    break;
                case TECLA_i:
                    if (!strcmp(str, " ")) strcpy(str, "I");
                    else strcat(str, "I");
                    break;
                case TECLA_z:
                    if (!strcmp(str, " ")) strcpy(str, "Z");
                    else strcat(str, "Z");
                    break;
                default:
                    break;
                }
                textuaIdatzi_beltza(10, 80, str);
                pantailaBerriztu();
            }
            if(strcmp(str, "BAI") == 0)
            {
                egoera = ETXEA_P;
            }
            if (strcmp(str, "EZ") == 0)
            {
                egoera = MENUA_P;
            }
        }
        strcpy(str, " ");
    }
    Sleep(2000);
    fclose(fitx);
    textuaDesgaitu();
    pantailaBerriztu();
    //
    return egoera;
}
EGOERA galderak(int orden)
{
    int fondoa, irakaslea, jarraitu = 1, ebentu = 0;
    EGOERA egoera;
    POSIZIOA pos;
    //
    egoera = ETXEA_P;
    fondoa = fondoPantaila(".\\img\\Galderak_Erantzunak\\Preguntas.bmp");
    pos = saguarenPosizioa();
    //
    switch (orden)
    {
    case 1://mate
        irakaslea = irudiaKargatu(".\\img\\ProfeMates.bmp");
        break;
    case 2://program
        irakaslea = irudiaKargatu(".\\img\\ProfeProgram.bmp");
        break;
    case 3://oinarri
        irakaslea = irudiaKargatu(".\\img\\ProfeOinarri.bmp");
        break;
    case 4://redes
        irakaslea = irudiaKargatu(".\\img\\ProfeRedes.bmp");
        break;
    case 5://empresa
        irakaslea = irudiaKargatu(".\\img\\ProfeEmpresa.bmp");
        break;
    default:
        break;
    }
    irudiaMugitu(irakaslea, 907, 72);
    irudiakMarraztu();
    //
    textuaGaitu_galderak();
    while (jarraitu == 1)//unibertsitatea den bitartean
    {
        textuaIdatzi(11, 267, "Hola gente! Buenas! Que pasa guacho! Ey! Apa! Aupa! Kaixo!");
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            if ((pos.x >= 657 && pos.x <= 657 + 600) && (pos.y >= 490 && pos.y <= 490 + 82)) jarraitu = 0;//itzultzerakoan etxera bidaltzeko
        }
        pantailaBerriztu();
    }
    //
    irudiaKendu(fondoa);
    //
    return egoera;
}
JOKALARIA pertsonaiaEratu(JOKALARIA jokalaria)
{
    JOKALARIA berria;
    IKASGAI iBerria;
    //
    berria = jokalaria;
    //
        //urtea----------------------------------
    berria.urtea = 1;
        //gradua----------------------------------
    berria.gradua.iKop = 10;
            //ikasgaia----------------------------
    iBerria.notaFinala = 0;
    berria.gradua.ikasgaiak = &iBerria;
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
    else if(strcmp(berria.irudia.izena, CHICA_AVATAR) == 0)
    {
        strcpy(berria.irudia2d.izena, CHICA_AVATAR_M);
    }
            //pos---------------------------------
    
        //exp-------------------------------------
    berria.exp.xp = 0;
    berria.exp.max = berria.gradua.iKop * 20;    
    //
    return berria;
}
