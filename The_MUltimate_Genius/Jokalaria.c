#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Jokalaria.h"
#include "Egoera.h"

//--------------------------------jokalaria estruktura
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
    if (strcmp(jokalaria.irudia.izena, CHICO_AVATAR) == 0)
    {
        jokalaria.irudia.id = irudiaKargatu(CHICO_AVATAR_G);
    }
    else
    {
        jokalaria.irudia.id = irudiaKargatu(CHICA_AVATAR_G);
    }
    irudiaMugitu(jokalaria.irudia.id, 148, 125);
    //----karratua
    luzera = (jokalaria.gradua.exp.xp * 466) / jokalaria.gradua.exp.max;//zenbateraino luzatu beharko litzatekeen 
    irudiakMarraztu();
    crearCuadro(437, 210, luzera, 74);
    //----textua
        //----nibela
    StrBihurtu_nibela(nibela, jokalaria.gradua.exp.nvl);
    //----experientzia
    StrBihurtu_exp(esperientzia, jokalaria.gradua.exp.xp, jokalaria.gradua.exp.max);
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
    if (exp->xp > exp->max)
    {
        exp->xp = exp->max;
    }
    //
    return erantzunda;
}

void azterketa(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int* exp, int eguna, JOKALARIA* jokalaria) {

    int erantzunda = 0;

    while (galderaID <= 5 && gelaID <= 5) {
        if (galdera[gelaID][galderaID].erabilita == 0) {
            fondoPantailaGalderekin(GALDERA_PANTALLA, gelaID, galderaID, galdera, jokalaria->irudia.izena);
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