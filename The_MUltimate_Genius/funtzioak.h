#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define GELAIDMAX 11
#define GALDERAIDMAX 6

#define GALDERA_PANTALLA ".\\img\\Galderak_Erantzunak\\Preguntas.bmp"

#define GALDERA_NULL ""

#define PROGRAM_GALDERA_1 ".\\galderak\\program\\galdera1.txt"
#define PROGRAM_GALDERA_2 ".\\galderak\\program\\galdera2.txt"
#define PROGRAM_GALDERA_3 ".\\galderak\\program\\galdera3.txt"
#define PROGRAM_GALDERA_4 ".\\galderak\\program\\galdera4.txt"
#define PROGRAM_GALDERA_5 ".\\galderak\\program\\galdera5.txt"

#define MATE_GALDERA_1 ".\\galderak\\mate\\galdera1.txt"
#define MATE_GALDERA_2 ".\\galderak\\mate\\galdera2.txt"
#define MATE_GALDERA_3 ".\\galderak\\mate\\galdera3.txt"
#define MATE_GALDERA_4 ".\\galderak\\mate\\galdera4.txt"
#define MATE_GALDERA_5 ".\\galderak\\mate\\galdera5.txt"

#define FISIKA_GALDERA_1 ".\\galderak\\fisika\\galdera1.txt"
#define FISIKA_GALDERA_2 ".\\galderak\\fisika\\galdera2.txt"
#define FISIKA_GALDERA_3 ".\\galderak\\fisika\\galdera3.txt"
#define FISIKA_GALDERA_4 ".\\galderak\\fisika\\galdera4.txt"
#define FISIKA_GALDERA_5 ".\\galderak\\fisika\\galdera5.txt"

#define OINARRI_GALDERA1 ".\\galderak\\oinarri\\galdera1.txt"
#define OINARRI_GALDERA2 ".\\galderak\\oinarri\\galdera2.txt"
#define OINARRI_GALDERA_3 ".\\galderak\\oinarri\\galdera3.txt"
#define OINARRI_GALDERA_4 ".\\galderak\\oinarri\\galdera4.txt"

#define REDES_GALDERA_1 ".\\galderak\\redes\\galdera1.txt"
#define REDES_GALDERA_2 ".\\galderak\\redes\\galdera2.txt"
#define REDES_GALDERA_3 ".\\galderak\\redes\\galdera3.txt"
#define REDES_GALDERA_4 ".\\galderak\\redes\\galdera4.txt"
#define REDES_GALDERA_5 ".\\galderak\\redes\\galdera5.txt"

#define PROGRAM_II_GALDERA_1 ".\\galderak\\program_II\\galdera1.txt"
#define PROGRAM_II_GALDERA_2 ".\\galderak\\program_II\\galdera2.txt"
#define PROGRAM_II_GALDERA_3 ".\\galderak\\program_II\\galdera3.txt"
#define PROGRAM_II_GALDERA_4 ".\\galderak\\program_II\\galdera4.txt"
#define PROGRAM_II_GALDERA_5 ".\\galderak\\program_II\\galdera5.txt"

#define MATE_II_GALDERA_1 ".\\galderak\\mate_II\\galdera1.txt"
#define MATE_II_GALDERA_2 ".\\galderak\\mate_II\\galdera2.txt"
#define MATE_II_GALDERA_3 ".\\galderak\\mate_II\\galdera3.txt"
#define MATE_II_GALDERA_4 ".\\galderak\\mate_II\\galdera4.txt"
#define MATE_II_GALDERA_5 ".\\galderak\\mate_II\\galdera5.txt"

#define MATE_D_GALDERA_1 ".\\galderak\\mate_D\\galdera1.txt"
#define MATE_D_GALDERA_2 ".\\galderak\\mate_D\\galdera2.txt"
#define MATE_D_GALDERA_3 ".\\galderak\\mate_D\\galdera3.txt"
#define MATE_D_GALDERA_4 ".\\galderak\\mate_D\\galdera4.txt"
#define MATE_D_GALDERA_5 ".\\galderak\\mate_D\\galdera5.txt"

#define ELEKTRONIKA_GALDERA_1 ".\\galderak\\elektronika\\galdera1.txt"
#define ELEKTRONIKA_GALDERA_2 ".\\galderak\\elektronika\\galdera2.txt"
#define ELEKTRONIKA_GALDERA_3 ".\\galderak\\elektronika\\galdera3.txt"
#define ELEKTRONIKA_GALDERA_4 ".\\galderak\\elektronika\\galdera4.txt"
#define ELEKTRONIKA_GALDERA_5 ".\\galderak\\elektronika\\galdera5.txt"

#define EMPRESA_GALDERA_1 ".\\galderak\\empresa\\galdera1.txt"
#define EMPRESA_GALDERA_2 ".\\galderak\\empresa\\galdera2.txt"
#define EMPRESA_GALDERA_3 ".\\galderak\\empresa\\galdera3.txt"
#define EMPRESA_GALDERA_4 ".\\galderak\\empresa\\galdera4.txt"
#define EMPRESA_GALDERA_5 ".\\galderak\\empresa\\galdera5.txt"

#include"GureEstrukturak.h"

int hasieratu(void);
//
int mu_hasieratu(void);
int menua(void);
void fondoPantaila(char* str);
int jolastu(JOKALARIA* jokalaria);
int kontrolak(void);

//----------NIREAK------
void galderakEtaEurenAukerakLotuEskuz(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota);
void fondoPantailaGalderekin(char* str, int galderaID, int gelaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
int GalderakErantzun(int exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
//----PRUEBA CON FITX---
int galderakEtaAukerakLotuFitxategiarenBitartez(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);

#endif // !FUNTZIOAK_H
