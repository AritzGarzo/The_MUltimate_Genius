#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
//Txillu kaixo


#define SOINU_KOP 5
char* soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\128NIGHT_01.wav", ".\\sound\\132TRANCE_02.wav",
                        ".\\sound\\BugleCall.wav",  ".\\sound\\terminator.wav" };

typedef struct S_GURE_GAUZAK
{
    int idSounds[SOINU_KOP];
    int idIrudi;
}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

int hasieratu(void);
//
int mu_hasieratu(void);
void fondoPantaila(char* str);
int jolastu(void);
int kontrolak(void);

int main(int argc, char* str[])
{
    int ebentu = 0, irten = 0;
    char esaldia[] = "";
    POSIZIOA pos;

    /*hasieratu();
    while(!irten)
    {
      ebentu = ebentuaJasoGertatuBada();
      if (ebentu == SAGU_BOTOIA_EZKERRA)
      {
        pos=saguarenPosizioa();
        if ((pos.x > 300) && (pos.x < 300 + 40) && (pos.y>200) && (pos.y < 200 + 38)) irten = 1;
      }
      if (ebentu == TECLA_ESCAPE) irten = 1;
      else if((ebentu >= TECLA_0) &&(ebentu < TECLA_0+SOINU_KOP))
        playSound(gureGauzak.idSounds[ebentu - TECLA_0]);
      else if (ebentu == TECLA_RETURN) toggleMusic();
    }
    audioTerminate();
    sgItxi();*/
    //

    mu_hasieratu();
    do 
    {
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case SAGU_BOTOIA_EZKERRA:
            pos = saguarenPosizioa();
            if ((pos.x > 18) && (pos.x < 18 + 175) && (pos.y > 650) && (pos.y < 650 + 50)) irten = 1;//irten
            else if ((pos.x > 483) && (pos.x < 483 + 343) && (pos.y > 386) && (pos.y < 386 + 68))
            {
                irten = kontrolak();
                fondoPantaila(".\\img\\menu.bmp");
            }
            else if ((pos.x > 483) && (pos.x < 483 + 343) && (pos.y > 293) && (pos.y < 293 + 68))
            {
                irten = jolastu();
                fondoPantaila(".\\img\\menu.bmp");
            }
            break;
        case GERTAERA_IRTEN:
                irten = 1;
                break;
        default:
            break;
        }
    } while (irten != 1);
    audioTerminate();
    sgItxi();
    return 0;
}


int hasieratu(void)
{
    int i;
    char str[128];
    double d = 7.3;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    for (i = 0; i < SOINU_KOP; i++)
    {
        if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
    }
    if (!loadTheMusic(".\\sound\\beat.wav"))
    {
        fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
        return 0;
    }

    return 0;
}
//
int mu_hasieratu(void)
{
    int i;
    char str[128];
    double d = 7.3;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 1280x720 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    pantailaGarbitu();
    fondoPantaila(".\\img\\menu.bmp");
    /*gureGauzak.idIrudi = irudiaKargatu(".\\img\\menu.bmp");
    irudiaMugitu(gureGauzak.idIrudi, 0, 0);
    irudiakMarraztu();*/
    pantailaBerriztu();

    return 0;
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
    int irten, ebentu;
    static char esaldia[16] = "";
    //POSIZIOA pos;
    irten = 3;
    fondoPantaila(".\\img\\jolastu.bmp");
    pantailaGarbitu();

    while (irten == 3)
    {
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case TECLA_s:
            if (irten == 3)
            {
                strcat(esaldia, "S");//esaldia = S
            }
            break;
        case TECLA_t:
            strcat(esaldia, "T");//esaldia = U
            break;
        case TECLA_a:
            strcat(esaldia, "A");//esaldia = I
            break;
        case GERTAERA_IRTEN:
            irten = 1;
            break;
        default:
            break;
        }
        if (strcmp(esaldia, "STAT") == 0)
        {
            strcpy(esaldia,"");
            irten = 0;
        }
    }
    //system("pause");

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
            if ((pos.x > 33) && (pos.x < 33 + 189) && (pos.y > 633) && (pos.y < 633 + 44)) irten = 0;//irten
            break;
        case GERTAERA_IRTEN:
                irten = 1;
            break;
        default:
            break;
        }
    }
    return irten;
}