#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
//Aritz Garzo

typedef struct S_GURE_GAUZAK
{
    int idIrudi;
}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

//
int hasieratu(void);
void fondoPantaila(char* str);
int jolastu(void);
int kontrolak(void);
int profila(void);
void idazkeraInteraktiboaAhalbidetu(int ebentu, char str, int x, int y);

int main(int argc, char* str[])
{
    int ebentu = 0, irten = 0;
    char esaldia[] = "";
    POSIZIOA pos;

    //
    hasieratu();
    while (irten != 1)
    {
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case SAGU_BOTOIA_EZKERRA:
            pos = saguarenPosizioa();
            if ((pos.x > 18 && pos.x < 18 + 175) && (pos.y > 650 && pos.y < 650 + 50)) irten = 1;//irten
            else if ((pos.x > 483 && pos.x < 483 + 343) && (pos.y > 386 && pos.y < 386 + 68))//kontrolak
            {
                irten = kontrolak();
                fondoPantaila(".\\img\\menu.bmp");
            }
            else if ((pos.x > 483 && pos.x < 483 + 343) && (pos.y > 293 && pos.y < 293 + 68))//jolastu
            {
                //no tiene ningun juego cargado
                irten = profila();
                fondoPantaila(".\\img\\menu.bmp");
                //
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

//
int hasieratu(void)
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
    int irten, ebentu, ebentu_tmp, luzera;
    static char esaldia[16] = " ";
    luzera = strlen(esaldia);
    //POSIZIOA pos;
    ebentu_tmp = 0;
    irten = 3;
    fondoPantaila(".\\img\\jolastu.bmp");

    textuaGaitu();
    while (irten == 3)
    {
        pantailaGarbitu();
        ebentu = ebentuaJasoGertatuBada();
        //mayus
        /*if (ebentu == TECLA_RIGHT)
        {

        /*switch (ebentu)
            {
            case TECLA_SPACE:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, " ");
                else strcat(esaldia, " ");
                break;
                //
            case TECLA_b:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "b");
                else strcat(esaldia, "b");
                break;
            case TECLA_c:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "c");
                else strcat(esaldia, "c");
                break;
            case TECLA_d:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "d");
                else strcat(esaldia, "d");
                break;
            case TECLA_e:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "e");
                else strcat(esaldia, "e");
                break;
            case TECLA_f:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "f");
                else strcat(esaldia, "f");
                break;
            case TECLA_g:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "g");
                else strcat(esaldia, "g");
                break;
            case TECLA_h:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "h");
                else strcat(esaldia, "h");
                break;
            case TECLA_i:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "i");
                else strcat(esaldia, "i");
                break;
            case TECLA_j:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "j");
                else strcat(esaldia, "j");
                break;
            case TECLA_k:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "k");
                else strcat(esaldia, "k");
                break;
            case TECLA_l:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "l");
                else strcat(esaldia, "l");
                break;
            case TECLA_m:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "m");
                else strcat(esaldia, "m");
                break;
            case TECLA_n:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "n");
                else strcat(esaldia, "n");
                break;
            case TECLA_o:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "o");
                else strcat(esaldia, "o");
                break;
            case TECLA_p:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "p");
                else strcat(esaldia, "p");
                break;
            case TECLA_q:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "q");
                else strcat(esaldia, "q");
                break;
            case TECLA_r:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "r");
                else strcat(esaldia, "r");
                break;
            case TECLA_u:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "u");
                else strcat(esaldia, "u");
                break;
            case TECLA_v:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "v");
                else strcat(esaldia, "v");
                break;
            case TECLA_w:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "w");
                else strcat(esaldia, "w");
                break;
            case TECLA_x:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "x");
                else strcat(esaldia, "x");
                break;
            case TECLA_y:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "y");
                else strcat(esaldia, "y");
                break;
            case TECLA_z:
                if (!strcmp(esaldia, " ")) strcpy(esaldia, "z");
                else strcat(esaldia, "z");
                break;
            case TECLA_LEFT:
                strcpy(esaldia, " ");
                break;
                //
            case TECLA_s:
                if (irten == 3)
                {
                    strcpy(esaldia, "s");//esaldia = S
                }
                break;
            case TECLA_t:
                strcat(esaldia, "t");//esaldia = T
                break;
            case TECLA_a:
                strcat(esaldia, "a");//esaldia = A
                break;
            default:
                break;
            }*/
        //minus
        
        switch (ebentu)
        {
        case TECLA_SPACE:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, " ");
            else strcat(esaldia, " ");
            break;
            //
        case TECLA_b:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "B");
            else strcat(esaldia, "B");
            break;
        case TECLA_c:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "C");
            else strcat(esaldia, "C");
            break;
        case TECLA_d:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "D");
            else strcat(esaldia, "D");
            break;
        case TECLA_e:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "E");
            else strcat(esaldia, "E");
            break;
        case TECLA_f:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "F");
            else strcat(esaldia, "F");
            break;
        case TECLA_g:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "G");
            else strcat(esaldia, "G");
            break;
        case TECLA_h:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "H");
            else strcat(esaldia, "H");
            break;
        case TECLA_i:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "I");
            else strcat(esaldia, "I");
            break;
        case TECLA_j:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "J");
            else strcat(esaldia, "J");
            break;
        case TECLA_k:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "K");
            else strcat(esaldia, "K");
            break;
        case TECLA_l:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "L");
            else strcat(esaldia, "L");
            break;
        case TECLA_m:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "M");
            else strcat(esaldia, "M");
            break;
        case TECLA_n:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "N");
            else strcat(esaldia, "N");
            break;
        case TECLA_o:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "O");
            else strcat(esaldia, "O");
            break;
        case TECLA_p:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "P");
            else strcat(esaldia, "P");
            break;
        case TECLA_q:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "Q");
            else strcat(esaldia, "Q");
            break;
        case TECLA_r:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "R");
            else strcat(esaldia, "R");
            break;
        case TECLA_u:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "U");
            else strcat(esaldia, "U");
            break;
        case TECLA_v:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "V");
            else strcat(esaldia, "V");
            break;
        case TECLA_w:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "W");
            else strcat(esaldia, "W");
            break;
        case TECLA_x:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "X");
            else strcat(esaldia, "X");
            break;
        case TECLA_y:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "Y");
            else strcat(esaldia, "Y");
            break;
        case TECLA_z:
            if (!strcmp(esaldia, " ")) strcpy(esaldia, "Z");
            else strcat(esaldia, "Z");
            break;
        case TECLA_LEFT:
            strcpy(esaldia, " ");
            break;
            //
        case TECLA_s:
            if (irten == 3)
            {
                strcpy(esaldia, "S");//esaldia = S
            }
            break;
        case TECLA_t:
            strcat(esaldia, "T");//esaldia = T
            break;
        case TECLA_a:
            strcat(esaldia, "A");//esaldia = A
            break;
        default:
            break;
        }
        
        textuaIdatzi(0, 0, esaldia);
        pantailaBerriztu();

        if (strcmp(esaldia, "STAT") == 0)
        {
            strcpy(esaldia, " ");
            irten = 0;
            Sleep(2000);
        }
    }
    //system("pause");
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

int profila(void)
{
    int amaitu, ebentu;
    char esaldia[16];
    POSIZIOA pos;
    amaitu = 0;
    ebentu = ebentuaJasoGertatuBada();
    fondoPantaila(".\\img\\profila.bmp");
    do
    {
        pantailaGarbitu();
        pos = saguarenPosizioa();
        //si clicka en izena
        if ((pos.x >= 172 && pos.x <= 172 + 458) && (pos.y >= 166 && pos.y <= 166 + 88))
        {
            idazkeraInteraktiboaAhalbidetu(ebentu, esaldia, 172 + 13, 166 + 14);
        }
        //si clicka en gradua
        /*le aparece una especie de lista*/
        //
        //si clicka en una imagen
        /*se ilumina*/
        //
        //si clicka en jarraitu
        /*pasa a jugar (amaitu = 1)*/
        //
        //si clicka en atzera
        /*se va a tomar por qlo (amaitu = -1)*/
        //
        pantailaBerriztu();
    } while (amaitu == 0);

}

void idazkeraInteraktiboaAhalbidetu(int ebentu, char str, int x, int y)
{
    int amaitu;
    amaitu = 0;
    do
    {
        pantailaGarbitu();
        switch (ebentu)
        {
        case TECLA_SPACE:
            if (!strcmp(str, " ")) strcpy(str, " ");
            else strcat(str, " ");
            break;
        case TECLA_LEFT:
            strcpy(str, " ");
            break;
            //
        case TECLA_b:
            if (!strcmp(str, " ")) strcpy(str, "B");
            else strcat(str, "B");
            break;
        case TECLA_c:
            if (!strcmp(str, " ")) strcpy(str, "C");
            else strcat(str, "C");
            break;
        case TECLA_d:
            if (!strcmp(str, " ")) strcpy(str, "D");
            else strcat(str, "D");
            break;
        case TECLA_e:
            if (!strcmp(str, " ")) strcpy(str, "E");
            else strcat(str, "E");
            break;
        case TECLA_f:
            if (!strcmp(str, " ")) strcpy(str, "F");
            else strcat(str, "F");
            break;
        case TECLA_g:
            if (!strcmp(str, " ")) strcpy(str, "G");
            else strcat(str, "G");
            break;
        case TECLA_h:
            if (!strcmp(str, " ")) strcpy(str, "H");
            else strcat(str, "H");
            break;
        case TECLA_i:
            if (!strcmp(str, " ")) strcpy(str, "I");
            else strcat(str, "I");
            break;
        case TECLA_j:
            if (!strcmp(str, " ")) strcpy(str, "J");
            else strcat(str, "J");
            break;
        case TECLA_k:
            if (!strcmp(str, " ")) strcpy(str, "K");
            else strcat(str, "K");
            break;
        case TECLA_l:
            if (!strcmp(str, " ")) strcpy(str, "L");
            else strcat(str, "L");
            break;
        case TECLA_m:
            if (!strcmp(str, " ")) strcpy(str, "M");
            else strcat(str, "M");
            break;
        case TECLA_n:
            if (!strcmp(str, " ")) strcpy(str, "N");
            else strcat(str, "N");
            break;
        case TECLA_o:
            if (!strcmp(str, " ")) strcpy(str, "O");
            else strcat(str, "O");
            break;
        case TECLA_p:
            if (!strcmp(str, " ")) strcpy(str, "P");
            else strcat(str, "P");
            break;
        case TECLA_q:
            if (!strcmp(str, " ")) strcpy(str, "Q");
            else strcat(str, "Q");
            break;
        case TECLA_r:
            if (!strcmp(str, " ")) strcpy(str, "R");
            else strcat(str, "R");
            break;
        case TECLA_u:
            if (!strcmp(str, " ")) strcpy(str, "U");
            else strcat(str, "U");
            break;
        case TECLA_v:
            if (!strcmp(str, " ")) strcpy(str, "V");
            else strcat(str, "V");
            break;
        case TECLA_w:
            if (!strcmp(str, " ")) strcpy(str, "W");
            else strcat(str, "W");
            break;
        case TECLA_x:
            if (!strcmp(str, " ")) strcpy(str, "X");
            else strcat(str, "X");
            break;
        case TECLA_y:
            if (!strcmp(str, " ")) strcpy(str, "Y");
            else strcat(str, "Y");
            break;
        case TECLA_z:
            if (!strcmp(str, " ")) strcpy(str, "Z");
            else strcat(str, "Z");
            break;
            //
        case TECLA_s:
            if (!strcmp(str, " ")) strcpy(str, "S");
            else strcat(str, "S");
            break;
        case TECLA_t:
            strcat(str, "T");//str = T
            break;
        case TECLA_a:
            strcat(str, "A");//str = A
            break;
        default:
            break;
        }
        textuaGaitu();
        textuaIdatzi(x, y, str);
        pantailaBerriztu();
    } while (amaitu);

}



/*
if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
        fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
        return 0;
*/