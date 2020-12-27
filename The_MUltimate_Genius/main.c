#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include"funtzioak.h"

//Txillu kaixo

int main(int argc, char* str[])
{
    int ebentu = 0, irten = 0, egoera = 0;
    char esaldia[] = "";

    mu_hasieratu();

    do
    {
        egoera = menua();
        if (egoera == 1) {
            irten = 1;
        }
        else if (egoera == 2) {
            irten=kontrolak();
            //fondoPantaila(".\\img\\menu.bmp");

        }
        else if (egoera == 3) {
            irten = jolastu();
            //fondoPantaila(".\\img\\menu.bmp");

        }

    } while (irten != 1);
    audioTerminate();
    sgItxi();
    return 0;
}

