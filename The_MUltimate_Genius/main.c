#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "GureEstrukturak.h"
#include <stdio.h>
#include <string.h>
//Jorge

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
    while (irten != 1)
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
                fondoPantaila(".\\img\\jolastu.bmp");
                irten = jolastu();
                fondoPantaila(".\\img\\menu.bmp");
            }
            break;

        default:
            break;
        }

    }
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
    textuaGaitu();
    pantailaGarbitu();

    gureGauzak.idIrudi = irudiaKargatu(".\\img\\hexagono.bmp");

    textuaIdatzi(10, 20, "Return: musika ON/OFF");
    textuaIdatzi(10, 40, "[0,4]:  soinu bat");
    textuaIdatzi(10, 60, "ESC:    amaitzeko");
    textuaIdatzi(10, 80, "arratoia hexagonoan: amaitu");
    sprintf(str, "%lf", d);
    textuaIdatzi(10, 100, str);
    irudiaMugitu(gureGauzak.idIrudi, 300, 200);
    irudiakMarraztu();
    arkatzKoloreaEzarri(0xFF, 0xFF, 0xFF);
    zuzenaMarraztu(0, SCREEN_HEIGHT * 2 / 3, SCREEN_WIDTH, SCREEN_HEIGHT * 2 / 3);
    zirkuluaMarraztu(500, 400, 10);
    pantailaBerriztu();
    ;


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
    fondoPantaila(".\\img\\jolastu.bmp");
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
    int irten, ebentu, x, y, tamaño = 48, tmp = 0, x_1, y_1;
    static char esaldia[16] = "";
    JOKALARIA sprite;

    irten = 3;

    sprite.id_2d = spriteKargatu(".\\img\\PersonajeChicoVF.bmp");
    x = 0; y = 0;
    x_1 = 0; y_1 = 0;

    while (irten == 3)
    {

        pantailaGarbitu();
        spriteMugitu(sprite.id_2d, x_1, y_1);

        ebentu = ebentuaJasoGertatuBada();

        switch (ebentu)
        {
        case TECLA_s:
            //sprite mover abajo//
            y_1 = y_1 + 4;
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

        case TECLA_w:
           //sprite mover arriba//
            y_1 = y_1 - 4;
//---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
            y = 12;
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

        case TECLA_d:
           //sprite mover derecha//
            x_1 = x_1 + 4;
//---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
            y = 8;            
            if (tmp == TECLA_d)
            {
                x = x + 4;
            }
            else{ x = 4;}

            if (x > 8)
            {
                x = 0;
            }
            tmp = ebentu;
//------------------------------------------------------------//
            break;    

        case TECLA_a:
           //sprite mover izquierda//
            x_1 = x_1 - 4;
//---------------SPRITEN ANIMAZIOAK IKUSTEKO------------------//
            y = 4;
            if (tmp == TECLA_a)
            {
                x = x + 4;
            }
            else{ x = 4;}
            if (x > 8)
            {
                x = 0;
            }
            tmp = ebentu;
//------------------------------------------------------------//
            break;

        case TECLA_t:
            irten = 0;
            break;
        default:
            break;
        }
        irudiakMarraztu();
        spriteakMarraztu(x, y, tamaño);
        pantailaBerriztu();
    }
  
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
        default:
            break;
        }
    }
    return irten;
}

//Crear funcion de personaje principal//