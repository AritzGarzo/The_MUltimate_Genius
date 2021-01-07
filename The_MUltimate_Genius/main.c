#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>


#define SOINU_KOP 5
char* soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\128NIGHT_01.wav", ".\\sound\\132TRANCE_02.wav",
                        ".\\sound\\BugleCall.wav",  ".\\sound\\terminator.wav" };

typedef struct S_GURE_GAUZAK
{
    int idSounds[SOINU_KOP];
    int idIrudi;
}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

int mu_hasieratu(void);
void fondoPantaila(char* str);
int jolastu(void);
int kontrolak(void);
void pantallaInicio(void);

// DEVOLVER (CLASIFICA FUNCIONES. NO INFLULLE MUCHO EN EL MAIN): NOMBRE(ENTENDER LA UTILIDAD) : AYUDA EXTERNA(IDENTIDAD DE LAS VARIABLES QUE USA EN LA FUNCION)
int main(int argc, char* str[])
{
    int ebentu = 0, irten = 0;
    char esaldia[] = "";
    POSIZIOA pos;

    mu_hasieratu();
    pantallaInicio();
    audioTerminate();
    sgItxi();

    return 0;
}
//He borrado la funcion Hasieratu
int mu_hasieratu(void)
{
    int i;
    char str[128];
    double d = 7.3;
    //Hace que aparezca la pantalla de inicio
    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 1280x720 video: %s\n", SDL_GetError());
        return 0;
    }
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
        default:
            break;
        }
        if (strcmp(esaldia, "STAT") == 0)
        {
            irten = 0;
        }
    }
    //system("pause");

    pantailaBerriztu();
    return irten;
}

