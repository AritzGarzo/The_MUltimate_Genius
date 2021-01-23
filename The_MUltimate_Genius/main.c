#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include "funtzioak.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Egoera.h"
//Master

int main(int argc, char* str[])
{
	int hasi;
	JOKALARIA jokalaria;
	EGOERA egoera;
	//sdl-a hasieratzeko
	hasi = hasieratu();
	//
	if (hasi == 0)
	{
		do
		{
			egoera = menua();
			if (egoera == PROFILA_P)
			{
				egoera = profila(&jokalaria);
				if (egoera == JOLASTU_P)
				{
					egoera = azalpena();
				}
			}
			if (egoera == KARGATU_P)
			{
				egoera = kargatu(&jokalaria);//JOLASTU
			}
			//
			switch (egoera)
			{
			case JOLASTU_P:
				egoera = jolastu(&jokalaria);
				break;
			case KONTROLAK_P:
				egoera = kontrolak();//
				break;
			default://irten
				break;
			}
			//
			if (egoera == IRABAZI_P)
			{
				egoera = azkenPantaila(egoera, jokalaria, IRABAZI_F);
			}
			else if (egoera == GALDU_P)
			{
				egoera = azkenPantaila(egoera, jokalaria, GALDU_F);
			}
			//
		} while (egoera == MENUA_P);
	}
	//
	//audioTerminate();
	sgItxi();

	return 0;
}
