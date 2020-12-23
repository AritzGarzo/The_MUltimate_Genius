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
int jolastu(JOKALARIA* jokalaria);
int kontrolak(void);
int profila(JOKALARIA* jokalaria);
int etxea(JOKALARIA* jokalaria);
int uni(JOKALARIA* jokalaria);
int galderak(int orden);
void crearLista(char str[]);
void koadroaMarraztu(int x1, int y1, int x2, int y2);

int main(int argc, char* str[])
{
    int fondoa, ebentu = 0, irten = 0;
    JOKALARIA jokalaria;
    POSIZIOA pos;
    //
    //
    fondoa = hasieratu();
    while (irten != -1)
    {
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case SAGU_BOTOIA_EZKERRA:
            irudiaKendu(fondoa);
            pos = saguarenPosizioa();
            if ((pos.x > 18 && pos.x < 18 + 175) && (pos.y > 650 && pos.y < 650 + 50)) irten = -1;//irten
            else if ((pos.x > 483 && pos.x < 483 + 343) && (pos.y > 386 && pos.y < 386 + 68))//kontrolak
            {
                irten = kontrolak();
            }
            else if ((pos.x > 483 && pos.x < 483 + 343) && (pos.y > 293 && pos.y < 293 + 68))//jolastu
            {
                fondoa = fondoPantaila(".\\img\\menu.bmp");
                //no tiene ningun juego cargado
                if (irten == 0)
                {
                    irten = profila(&jokalaria);
                }
                //
                if (irten == 1)
                {
                    irten = jolastu(&jokalaria);
                }
            }
            fondoa = fondoPantaila(".\\img\\menu.bmp");
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
    int id;
    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 1280x720 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    pantailaGarbitu();
    id = fondoPantaila(".\\img\\menu.bmp");
    pantailaBerriztu();

    return id;
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

int jolastu(JOKALARIA* jokalaria)
{
    int irten;
    //POSIZIOA pos;
    irten = 0;
    //
    //irten = -1|kanpora
    //irten = 0|etxea
    //irten = 1|unibertsitatea

    while (irten != -1)
    {
        //
        if (irten == 0)
        {
            irten = etxea(jokalaria);
        }
        if (irten == 1)
        {
            irten = uni(jokalaria);
        }
        //
    }
    //
    return irten;
}

int kontrolak(void)
{
    int fondoa, jarraitu, ebentu;
    POSIZIOA pos;
    jarraitu = 1;
    //
    fondoa = fondoPantaila(".\\img\\kontrolak.bmp");
    //
    while (jarraitu == 1)
    {
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case SAGU_BOTOIA_EZKERRA:
            pos = saguarenPosizioa();
            if ((pos.x > 33) && (pos.x < 33 + 189) && (pos.y > 633) && (pos.y < 633 + 44)) jarraitu = 0;//irten
            break;
        default:
            break;
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return jarraitu;
}

int profila(JOKALARIA* jokalaria)
{
    int fondoa, amaitu, ebentu, ebentu_c, aldaketa;
    char gradua[128];
    //char gradua[][128] = { "Informatika", "Empresa", "Magisteritza" };
    static char esaldia[7];
    POSIZIOA pos;
    //
    aldaketa = 0;
    strcpy(esaldia, " ");
    strcpy(gradua, " ");
    strcpy((*jokalaria).izena, esaldia);
    strcpy((*jokalaria).gradua.izena, gradua);
    amaitu = -1;
    fondoa = fondoPantaila(".\\img\\profila.bmp");
    textuaGaitu_profila();
    //
    while (amaitu == -1)
    {
        /*irudiakMarraztu();
        textuaIdatzi(180, 174, esaldia);
        textuaIdatzi(180, 356, gradua);
        pantailaBerriztu();*/
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            //si clicka en izena
            if ((pos.x >= 172 && pos.x <= 172 + 458) && (pos.y >= 166 && pos.y <= 166 + 88))
            {
                //borrar nombre
                irudiakMarraztu();
                textuaIdatzi(180, 174, " ");
                textuaIdatzi(180, 356, (*jokalaria).gradua.izena);
                pantailaBerriztu();
                //
                amaitu = 2;
                while (amaitu == 2)
                {
                    pos = saguarenPosizioa();
                    ebentu_c = ebentuaJasoGertatuBada();
                    if ((ebentu_c == SAGU_BOTOIA_EZKERRA) && ((pos.x < 172) || (pos.x > 172 + 458) || (pos.y < 166) || (pos.y > 166 + 88))) amaitu = -1;
                    switch (ebentu_c)
                    {
                    case TECLA_a:
                        if (!strcmp(esaldia, " ")) strcpy(esaldia, "A");
                        else strcat(esaldia, "A");
                        break;
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
                    case TECLA_s:
                        if (!strcmp(esaldia, " ")) strcpy(esaldia, "S");
                        else strcat(esaldia, "S");
                        break;
                    case TECLA_t:
                        if (!strcmp(esaldia, " ")) strcpy(esaldia, "T");
                        else strcat(esaldia, "T");
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
                    default:
                        break;
                    }
                    textuaIdatzi(180, 174, esaldia);
                    pantailaBerriztu();
                    if (strlen(esaldia) == 7) amaitu = -1;
                }
                strcpy(jokalaria->izena, esaldia);
                irudiakMarraztu();
                textuaIdatzi(180, 174, esaldia);
                pantailaBerriztu();
                strcpy(esaldia, " ");
                aldaketa = 1;
            }
            //si clicka en gradua le aparece una especie de lista
            if ((pos.x >= 172 && pos.x <= 172 + 458) && (pos.y >= 348 && pos.y <= 348 + 88))
            {
                crearLista(gradua);
                strcpy((*jokalaria).gradua.izena, gradua);
                fondoa = fondoPantaila(".\\img\\profila.bmp");
                aldaketa = 1;
            }
            //si clicka en una imagen se marca/ilumina
            if ((pos.x >= 932 && pos.x <= 932 + 147) && (pos.y >= 185 && pos.y <= 185 + 133))//mutila
            {
                jokalaria->id.id = irudiaKargatu(".\\img\\PersonajeChicoHablando.bmp");
                jokalaria->id.pos_hasi.x = 932; jokalaria->id.pos_hasi.y = 185;
                jokalaria->id.pos_buka.x = 932 + 147; jokalaria->id.pos_buka.y = 185 + 133;
                aldaketa = 1;
            }
            if ((pos.x >= 932 && pos.x <= 932 + 147) && (pos.y >= 350 && pos.y <= 350 + 133))//neska
            {
                jokalaria->id.id = irudiaKargatu(".\\img\\PersonajeChicaHablando.bmp");
                jokalaria->id.pos_hasi.x = 932; jokalaria->id.pos_hasi.y = 350;
                jokalaria->id.pos_buka.x = 932 + 147; jokalaria->id.pos_buka.y = 350 + 133;
                aldaketa = 1;
            }
            //jarraitu
            if ((pos.x >= 1077 && pos.x <= 1077 + 175) && (pos.y >= 638 && pos.y <= 638 + 50)) amaitu = 1;
            //atzera
            if ((pos.x >= 880 && pos.x <= 880 + 175) && (pos.y >= 638 && pos.y <= 638 + 50)) amaitu = 0;
        }
        //aplikazio grafiko funtzioanala
        if (aldaketa == 1)
        {
            irudiakMarraztu();
            textuaIdatzi(180, 174, (*jokalaria).izena);
            textuaIdatzi(180, 356, (*jokalaria).gradua.izena);
            arkatzKoloreaEzarri(0XF8, 0XF3, 0X2B);
            koadroaMarraztu(jokalaria->id.pos_hasi.x - 1, jokalaria->id.pos_hasi.y - 1, jokalaria->id.pos_buka.x, jokalaria->id.pos_buka.y);
            pantailaBerriztu();
            aldaketa = 0;
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return amaitu;
}

int etxea(JOKALARIA* jokalaria)
{
    int fondoa, jarraitu = 0, ebentu = 0;
    POSIZIOA pos;
    //
    fondoa = fondoPantaila(".\\img\\etxea.bmp");
    //
    while (jarraitu == 0)//etxea den bitartean
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            if ((pos.x >= 384 && pos.x <= 384 + 64) && (pos.y >= 159 && pos.y <= 159 + 244)) jarraitu = 1;//(busa)itzultzerakoan unibertsitatera bidaltzeko
            if ((pos.x >= 1193 && pos.x <= 1193 + 46) && (pos.y >= 149 && pos.y <= 149 + 57)) jarraitu = -1;//(ohea)itzultzerakoan kanpora bidaltzeko
        }
    }
    //
    irudiaKendu(fondoa);
    return jarraitu;
}

int uni(JOKALARIA* jokalaria)
{
    int fondoa, jarraitu = 1, ebentu = 0;
    POSIZIOA pos;
    //
    fondoa = fondoPantaila(".\\img\\uni.bmp");
    //
    while (jarraitu == 1)//unibertsitatea den bitartean
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            if ((pos.x >= 1 && pos.x <= 1 + 51) && (pos.y >= 103 && pos.y <= 103 + 158))
            {
                jarraitu = galderak(1);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1 && pos.x <= 1 + 51) && (pos.y >= 433 && pos.y <= 433 + 166))
            {
                jarraitu = galderak(2);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1234 && pos.x <= 1234 + 45) && (pos.y >= 5 && pos.y <= 5 + 176))
            {
                jarraitu = galderak(3);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1233 && pos.x <= 1233 + 44) && (pos.y >= 289 && pos.y <= 289 + 160))
            {
                jarraitu = galderak(4);//itzultzerakoan etxera bidaltzeko
            }
            if ((pos.x >= 1233 && pos.x <= 1233 + 46) && (pos.y >= 561 && pos.y <= 561 + 143))
            {
                jarraitu = galderak(5);//itzultzerakoan etxera bidaltzeko
            }
        }
    }
    //
    irudiaKendu(fondoa);
    //
    return jarraitu;
}

int galderak(int orden)
{
    int fondoa, irakaslea, jarraitu = 1, ebentu = 0;
    POSIZIOA pos;
    pos = saguarenPosizioa();
    //
    fondoa = fondoPantaila(".\\img\\Preguntas.bmp");
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

    //
    textuaDesgaitu();
    textuaGaitu_galderak();
    while (jarraitu == 1)//unibertsitatea den bitartean
    {
        pantailaGarbitu();
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
    return jarraitu;
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

/*
if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
        fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
        return 0;
*/