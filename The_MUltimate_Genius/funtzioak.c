#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include "funtzioak.h"
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "Jokalaria.h"

//------------------------------------Globalak
extern void* pixels;

//------------------------------------estrukturarik gabe
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

void StrBihurtu_nibela(char str[], int nvl)
{
    char tmp[128];
    //
    IntStrBihurtu(nvl, tmp);
    strcpy(str, tmp);
}

void StrBihurtu_exp(char str[], int xp_orain, int max)
{
    char tmp[128];
    //
    IntStrBihurtu(xp_orain, tmp);
    strcpy(str, tmp);
    //
    strcat(str, "/");
    strcat(str, "\0");
    //
    IntStrBihurtu(max, tmp);
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

