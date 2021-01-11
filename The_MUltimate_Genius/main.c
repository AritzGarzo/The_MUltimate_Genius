#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "GureEstrukturak.h"
#include <stdio.h>
#include <string.h>
//Mapeo

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
void pertsonaiaMugitu(void);
int kontrolak(void);

int main(int argc, char* str[])
{
    int ebentu = 0, irten = 0;
    char esaldia[] = "";
    POSIZIOA pos;    
    void* pixels = NULL;
    int pitch;
    Uint8 bpp;
    Uint32 refreshrate = 0;
    Uint32 moverate = 0;

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
                KargatuMapa(".\\img\\gelaMapeo.bmp", &pixels, &pitch, &bpp);
                fondoPantaila(".\\img\\gela1.bmp");
                pertsonaiaMugitu();
                KolisioakKonprobatu(pixels, pitch, bpp);
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
   // textuaGaitu();
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
    //fondoPantaila(".\\img\\jolastu.bmp");
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

//Nuevo
void pertsonaiaMugitu(void)
{
    int mugi, ebentu, x, y, tama�o = 48, tmp = 0;
    JOKALARIA sprite;
    IRUDIA pos;
    mugi = 3;

    sprite.id_2d = spriteKargatu(".\\img\\PersonajeChicoVF .bmp");
    x = 0; y = 0;
    pos.pos_hasi.x = 50; pos.pos_hasi.y = 50;//Donde va a empezar el jugador?

    while (mugi == 3)
    {

        pantailaGarbitu();
        spriteMugitu(sprite.id_2d, pos.pos_hasi.x, pos.pos_hasi.y);

        ebentu = ebentuaJasoGertatuBada();

        switch (ebentu)
        {
        case TECLA_s:
            //sprite mover abajo//
            pos.pos_hasi.y = pos.pos_hasi.y + 4;
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
            pos.pos_hasi.y = pos.pos_hasi.y - 4;
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

        case TECLA_d:
            //sprite mover derecha//
            pos.pos_hasi.x = pos.pos_hasi.x + 4;
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

        case TECLA_a:
            //sprite mover izquierda//
            pos.pos_hasi.x = pos.pos_hasi.x - 4;
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
        default:
            break;
        }
        irudiakMarraztu();
        spriteakMarraztu(x, y);
        pantailaBerriztu();
    }

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