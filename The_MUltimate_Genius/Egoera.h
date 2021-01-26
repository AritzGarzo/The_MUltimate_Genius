#ifndef EGOERA_H
#define EGOERA_H

//-------------Defineak
	//--------------pantailak--------------
#define MENUA_F ".\\img\\pantailak\\menu.bmp"
#define KONTROLAK_F ".\\img\\pantailak\\kontrolak.bmp"
#define PROFILA_F ".\\img\\pantailak\\profila.bmp"
#define AZALPENA_F ".\\img\\pantailak\\azalpena.bmp"
#define ETXEA_F ".\\img\\pantailak\\etxea.bmp"
#define UNI_F ".\\img\\pantailak\\uni.bmp"
#define EXP_F ".\\img\\pantailak\\exp.bmp"
#define IRABAZI_F ".\\img\\pantailak\\graduado.bmp"
#define GALDU_F ".\\img\\pantailak\\gameOver.bmp"
	//--------------Mapak--------------
#define MAPEO_GELA ".\\img\\pantailak\\mapaketa\\gelaMapeo.bmp"
#define MAPEO_UNI ".\\img\\pantailak\\mapaketa\\uniMapeo.bmp"

//-------------Estrukturak
typedef enum { MENUA_P, PROFILA_P, JOLASTU_P, IRTEN_P, KONTROLAK_P, KARGATU_P, ETXEA_P, UNI_P, AZALPENA_P, EXP_P, IRABAZI_P, GALDU_P }EGOERA;

//-------------Egoera
EGOERA menua(void);
EGOERA jolastu(JOKALARIA* jokalaria);
EGOERA kontrolak(void);
EGOERA profila(JOKALARIA* jokalaria);
EGOERA azalpena(void);
EGOERA kargatu(JOKALARIA* jokalaria);
EGOERA etxea(JOKALARIA* jokalaria);
EGOERA uni(JOKALARIA* jokalaria, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
EGOERA azkenPantaila(EGOERA egoera, JOKALARIA jokalaria, char* str);
EGOERA gorde(JOKALARIA jokalaria);
EGOERA galderak(int gelaID, JOKALARIA* jokalaria, GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
EGOERA GalderakErantzun(EXP* exp, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int eguna);
int pertsonaiaMugitu(int ebentu, POSIZIOA pos, JOKALARIA jokalaria, EGOERA egoera);

#endif // !EGOERA_H
