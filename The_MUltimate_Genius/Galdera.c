#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <string.h>
#include "funtzioak.h"
#include "Galdera.h"



//--------------------------------galdera estruktura
void fondoPantailaGalderekin(char* str, int gelaID, int galderaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], char* ikaslea)
{
	int id, id_irakaslea, id_ikaslea;
	char irakaslea[128];
	//
	pantailaGarbitu();
	id = irudiaKargatu(str);
	irudiaMugitu(id, 0, 0);
	//
	switch (gelaID)
	{
	case 1:
		strcpy(irakaslea, PROGRAM_PROFE);
		break;
	case 2:
		strcpy(irakaslea, MATE_PROFE);
		break;
	case 3:
		strcpy(irakaslea, FISIKA_PROFE);
		break;
	case 4:
		strcpy(irakaslea, OINARRI_PROFE);
		break;
	case 5:
		strcpy(irakaslea, REDES_PROFE);
		break;
		//2.seihilekoa
	/*case 6:
		strcpy(irakaslea, PROGRAM_II_PROFE);
		break;
	case 7:
		strcpy(irakaslea, MATE_II_PROFE);
		break;
	case 8:
		strcpy(irakaslea, MATE_D_PROFE);
		break;
	case 9:
		strcpy(irakaslea, ELEKTRONIKA_PROFE);
		break;
	case 10:
		strcpy(irakaslea, EMPRESA_PROFE);
		break;*/
	default:
		strcpy(irakaslea, MATE_PROFE);
		break;
	}
	//----------aurpegiak kargatu
	id_irakaslea = irudiaKargatu(irakaslea);
	irudiaMugitu(id_irakaslea, 907, 72);
	if (strcmp(ikaslea, CHICO_AVATAR) == 0)
	{
		id_ikaslea = irudiaKargatu(CHICO_AVATAR_G);
	}
	else
	{
		id_ikaslea = irudiaKargatu(CHICA_AVATAR_G);
	}
	irudiaMugitu(id_ikaslea, 189, 81);
	irudiakMarraztu();
	//
	textuaGaitu_galderak();
	textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
	textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
	textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
	textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
	textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);
	//
	pantailaBerriztu();
}

//---HEMEN GALDERAK ETA AUKERAK ESTRUKTURAN SARTZEN DUGU GERO PRINTEATZEKO
int galderakEtaAukerakLotuFitxategiarenBitartez(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]) {

	char galderak[60][128] = {
		GALDERA_NULL,PROGRAM_GALDERA_1,PROGRAM_GALDERA_2,PROGRAM_GALDERA_3,PROGRAM_GALDERA_4,PROGRAM_GALDERA_5,
		GALDERA_NULL,MATE_GALDERA_1,MATE_GALDERA_2,MATE_GALDERA_3,MATE_GALDERA_4,MATE_GALDERA_5,
		GALDERA_NULL,FISIKA_GALDERA_1,FISIKA_GALDERA_2,FISIKA_GALDERA_3,FISIKA_GALDERA_4,FISIKA_GALDERA_5,
		GALDERA_NULL,OINARRI_GALDERA1,OINARRI_GALDERA2,OINARRI_GALDERA_3,OINARRI_GALDERA_4,OINARRI_GALDERA_5,
		GALDERA_NULL,REDES_GALDERA_1,REDES_GALDERA_2,REDES_GALDERA_3,REDES_GALDERA_4,REDES_GALDERA_5,
		GALDERA_NULL,PROGRAM_II_GALDERA_1,PROGRAM_II_GALDERA_2,PROGRAM_II_GALDERA_3,PROGRAM_II_GALDERA_4,PROGRAM_II_GALDERA_1,
		GALDERA_NULL,MATE_II_GALDERA_1,MATE_II_GALDERA_2,MATE_II_GALDERA_3,MATE_II_GALDERA_4,MATE_II_GALDERA_5,
		GALDERA_NULL,MATE_D_GALDERA_1,MATE_D_GALDERA_2,MATE_D_GALDERA_3,MATE_D_GALDERA_4,MATE_D_GALDERA_5,
		GALDERA_NULL,ELEKTRONIKA_GALDERA_1,ELEKTRONIKA_GALDERA_2,ELEKTRONIKA_GALDERA_3,ELEKTRONIKA_GALDERA_4,ELEKTRONIKA_GALDERA_5,
		GALDERA_NULL,EMPRESA_GALDERA_1,EMPRESA_GALDERA_2,EMPRESA_GALDERA_3,EMPRESA_GALDERA_1,EMPRESA_GALDERA_5
	};

	FILE* fitx;
	int fitxategiKont = 1, gelaIDKont = 1, galderaIDKont = 1, error = 0;


	while (fitxategiKont < 60) {

		fitx = fopen(galderak[fitxategiKont], "r");

		if (fitxategiKont == 6 || fitxategiKont == 12 || fitxategiKont == 18 || fitxategiKont == 23 || fitxategiKont == 24 || fitxategiKont == 30 || fitxategiKont == 36 || fitxategiKont == 42 || fitxategiKont == 48 || fitxategiKont == 54);

		else if (fitx == NULL) {
			printf("Errorea galderen fitxategia irakurtzerako orduan\n");
			return error = 1;
		}

		else {
			galdera[gelaIDKont][galderaIDKont].gelaID = gelaIDKont;
			galdera[gelaIDKont][galderaIDKont].galderaID = galderaIDKont;
			galdera[gelaIDKont][galderaIDKont].sartuta = 0;
			galdera[gelaIDKont][galderaIDKont].erabilita = 0;
			fgets(galdera[gelaIDKont][galderaIDKont].testua, 128, fitx);
			fgets(galdera[gelaIDKont][galderaIDKont].aukerak.A, 128, fitx);
			fgets(galdera[gelaIDKont][galderaIDKont].aukerak.B, 128, fitx);
			fgets(galdera[gelaIDKont][galderaIDKont].aukerak.C, 128, fitx);
			fgets(galdera[gelaIDKont][galderaIDKont].aukerak.D, 128, fitx);

			galdera[gelaIDKont][galderaIDKont].testua[strlen(galdera[gelaIDKont][galderaIDKont].testua) - 1] = '\0';
			galdera[gelaIDKont][galderaIDKont].aukerak.A[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.A) - 1] = '\0';
			galdera[gelaIDKont][galderaIDKont].aukerak.B[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.B) - 1] = '\0';
			galdera[gelaIDKont][galderaIDKont].aukerak.C[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.C) - 1] = '\0';
			galdera[gelaIDKont][galderaIDKont].aukerak.D[strlen(galdera[gelaIDKont][galderaIDKont].aukerak.D) - 1] = '\0';
			fclose(fitx);

		}
		if (galderaIDKont > 5) {
			gelaIDKont++;
			galderaIDKont = 1;
		}
		else {
			galderaIDKont++;
		}

		fitxategiKont++;

	}
	return error;
}

void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]) {
	int gelaID = 1, galderaID = 1;
	while (gelaID <= 10) {

		switch (gelaID)
		{
		case 1://---program---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da FOR baten sintaxia?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "(i=0;i<10;i++)"); //ondo
					strcpy(galdera[gelaID][galderaID].aukerak.B, "[i=0;i<10;i++]");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(i=0,i<10,i++)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "[i=0;i<10;i++]");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola da 65 bitarrean?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "01101011");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "01000001");  //  ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "11000001");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "01000010");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer diferentzia dago do while eta while-en artean?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "ez dago desberdintasunik");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "bat bestea baino azkarragoa da");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "batek lehenego zerbait egiten du eta gero baldintza konparatu");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "bat efizienteagoa da");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "If eta else if sententzia asko erabiltzen denean, zer beste sentetzia dago hori azkarrago egiteko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "switch");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "change");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "goto");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "break");
					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "ASCII taula karaktere kode bat da, zer orden da egokia?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Zenbakiak->xehez>Larriz");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "xehez>Larriz->zenbakiak");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Larriz->xehez>zenbakiak");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Zenbakiak->Larriz-> xehez");  //ONDO
					break;
				default:
					break;
				}
				galderaID++;
			}
			break;

		case 2://---mate---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1://----MATEKO GALDERAK------
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da (Sinx/Cosx) dx ren integrala?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "-Ln(cosx)");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "tanx");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ln(sinx)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "arctan x");
					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da Cos2x ren baliokidea");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "(cosx)^2-(sinx)^2");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "cosx-sinx");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "2sinxcosx");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "sinxcosx");
					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Noiz esaten da limite bat jarraia dela? ");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ez dakit");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Alboko limiteak desberdinak direnean");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Alboko limiteak berdinak direnean"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Limite bat ez dagoenean");
					break;

				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat da Sin5(pi)/6?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "erro(2)/2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "1/2");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "erro(3)/3");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "-erro(2)/2");
					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "idatzi (2i-4)/(3+2i) polarrean.");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "(-8+14i)/13");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "(-6-5i)/14,");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(5+16i)/10");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "(7-9i)/12");
					break;


				default:
					break;
				}
				galderaID++;
			}
			break;

		case 3://---fisika---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1://----FISIKAKO GALDERA-----
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer/zeinen legea da hau? (V=R*I R=V/I I=V/R)");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ohm-en legea");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Thevenin-ren legea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Coulomb-en legea");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Joul-en legea");
					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein zen Thevenin?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ingeniari bat");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Fisikari bat");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Kimikari bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Elektroniko bat");
					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, " Zein da Kirchhoff-en legea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Korapiloaren legea");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Energia kontserbazioaren legea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Akzio-erreakzio");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Kanpo magnetikoaren legea");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola kalkulatzen da erresistentzia baliokidea paraleloan badaude?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "R=R1+R2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "(1/R)=(1/R1)+(1/R2)");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "R=(1/R1)+(1/R2)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "R=(1/R1)+R2)");
					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da potentziaren formula egokia?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "V/(I^2)");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "(I^2)/R");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(V^2)*R");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "(I^2)*R"); //ONDO
					break;

				default:
					break;
				}
				galderaID++;
			}
			break;

		case 4://---oinarri---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zertarako balio du Git-ek?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Bertsioen kontrol bat egiteko");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Programa bat gehiago nahasteko");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Textu bat lainoan gordetzeko");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Web bat egiteko");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "PDF batek irudia badu, zer eduki behar du berarekin?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Deskripzio bat bakarrik");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Irudien taula bakarrik");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Deskripzio bat eta irudien taula");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Ezer");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "HTML-n zer etiketa erabili behar da izenburua jartzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "<head> ... </head>");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "<title> ... </title>");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "<img> ... </img>");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "<p> ... </p>");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "HTML-n zer etiketa erabili behar da kodigoa jartzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "<strong> ... </strong>");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "<div> ... </div>");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "<script> ... </script>");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "<head> ... </head>");

					break;

				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer lengoaia mota da JavaScript?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Konpilatutako lengoaia");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Interpretatutako lengoaia"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Bat ere ez");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Irakurritako lengoaia bat");

					break;

				default:
					break;
				}
				galderaID++;
			}
			break;
		case 5://---redes---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da Google-ren DNS IPv4-a?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "1.1.1.1");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "5.5.5.5");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "0.0.0.0");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "8.8.8.8");  //ONDO

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer izen du transporte kapan lan egiten duen PDU-ari?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "bits");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "trama");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "segmento");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "pakete");


					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Ari - gabeko host batek IP helbide bat eskatu behar du, zer protokolo erabili behar du eskaera hori  egiteko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "HTTP");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "SNMP");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "DHCP");  //ONDO    
					strcpy(galdera[gelaID][galderaID].aukerak.D, "ICMP");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da IPv6 helbide honen (2001:0000:0000:abcd:0000:0000:0000:0001) idazkera motzena?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2001:0000:0000:abcd::1");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "2001:0:0:abcd::1");    //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "2001::abcd::1");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "2001::abdc:0:1");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "255.255.255.248 maskaran zenbat host dira helbideragarriak?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "6");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "8");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "14");

					break;
				default:
					break;
				}
				galderaID++;
			}
			break;

		case 6://---program II---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da arraya[gelaID][galderaID]-ren baliokidea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "*(arraya+i)");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "arraya.i");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "(arraya+i)");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "*arraya+i");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da erakusle bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ezer");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Memoriako zati bat");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Memoriako elementuak");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Memoriako helbide bat zehazten duen elementu bat");//ONDO


					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola deklaratzen da erakusle bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "?");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "&");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "*");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "^");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da programazioan errekurtsibitatea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Funtzio batek bere buruari deitzea");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Funtzio batek beste funtzio bati deitzea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Funtzio bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Funtzio baten barruan hainbat funtzio edukitzea");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Fitxategi bat irekitzeko fopen erabiltzen da, funtzio honek fitxategiaren izena eta modua behar du, zein letra da irakurtzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "d");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "w");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "a");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "r");  //ONDO

					break;
				default:
					break;
				}
				galderaID++;
			}
			break;

		case 7://---mate II---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da pibot bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Saskibaloiko posizio bat");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Ezkerretik hasita 0 ez den lehen zenbakia");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Eskuinetik hasieta 0 ez den lehen zenbakia");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Eskuinetik hasieta 0 den lehen zenbakia");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Noiz erabili behar da Bernoulli?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Ekuazioa lineala denean");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Ekuazioa ez lineala denea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ekuazio diferentziala lineala denean");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Ekuazio diferentziala ez lineala denean");  //ONDO

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer esan nahi du matriz bateko zutabe bakoitzean pibot bat edukitzeak?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Matrizea osatzen duen ekuazioek pibot bat dutela");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Matrizea osatzen duen ekuazioek sistema indeterminatu bat osatzen dutela");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Matrizea osatzen duen ekuazioek sistema bateragarri determinatua dela");   //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Matrizea osatzen duen ekuazioek sistema batera ezin bat dela");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da matriz elemental bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Matrizeko diagonal nagusian dagoen zenbakiak 1 dira eta beste guztiak 0");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Matrizeko diagonal nagusian dagoen zenbakiak 0 dira eta beste denak 1");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ordenaturik dagoen matrize bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Matrize batean 0-rik ez edukitzea");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da ekuazio diferentzial baten orden maila?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Koefiziente handiena ");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Deribatu maila handiena");   //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Deribatu maila txikiena");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Koefiziente txikiena");

					break;

				default:
					break;
				}
				galderaID++;
			}
			break;

		case 8://---mate D---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da grafo Hamilton bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Puntu guztietatik pasatzea baina amaiera eta hasiera ezberdinak izanik");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Puntu guztietatik behin pasatzea baina amaiera eta hasiera ezberdinak izanik");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Hasiera eta amaiera puntu bera izanik ibildide zirkularra egitea puntu guztietatik behin pasatuz");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Hasiera eta amaiera puntu bera izanik puntu guztietatik pasatzea");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer ezberdintasun dago grafo Eulearra eta Hamiltondarraren artean?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Batek ibilbide ziklikoa egiten du eta besteak ez");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Batek erpinak hartzen ditu kontua eta besteak ertzak");   //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Batek ibilbide ziklikoak puntuen artean eta besteak ibilbide ziklikoa ertzen artean");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Ez dago ezberdintasunik");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat modu daude {1,2,3} zenbakiak ordenatzeko?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "4");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "6"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "8");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "10");

					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "12 korrikalari dagoen lasterketa baten zenbat modu daude dominak banatzeko orduan? ");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "1250");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "1320"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "1640");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "1480");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "15 gozoki izanik zenbat modu daude 20 umeren artean banatzeko gehienez bakoitzak 1 izanik?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "10408");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "15504");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "16450");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "17430");

					break;

				default:
					break;
				}
				galderaID++;
			}
			break;
		case 9://---elektrtonika---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nolakoa da korronte alternoaren uhinak");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Sinusoidala");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Zirkularra");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Ez da ezagutzen");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Obalatua");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer da diodo bat?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Artezgailu bat");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Transistore bat");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Transformadore bat");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Energia iturri bat");

					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zein da artezgailu baten helburua?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Korronteen frekuentzia handitzea");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Korronte zuzena alterno bihurtzea");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Korronte alternoa zuzena bihurtzea");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Korronteen frekuentzia txikitzea");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat transistore mota daude?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "3");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "4");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "5");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer zati ditu elikadura iturri basiko batek?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Transdormadorea-> irteera");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Transformadorea->artezgailuak->irteera");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Transformadorea->artezgailuak->filtroa->irteera");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Transformadorea->artezgailuak->filtroa->reguladorea->irteera");   //ONDO

					break;

				default:
					break;
				}
				galderaID++;
			}
			break;
		case 10://---elektrtonika---
			galderaID = 1;
			while (galderaID <= 5) {
				switch (galderaID)
				{
				case 1:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zenbat ingurune nagusi daude enpresa bati eragiten diona?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "1");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "2");//ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "3");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "4");

					break;
				case 2:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Kontabilitate garaian , zenbat atal eduki behar ditu urteko kontuetan?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "2");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "3");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "4");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "5");//ONDO
					break;
				case 3:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Nola kalkulatzen da enpresa baten bermea?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Aktibo erreala/ zorrak");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Aktibo/Pasibo");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Aktiko erreala*zorrak");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Aktibo*Pasibo");
					break;
				case 4:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "-Enpresa baten negozio plana zenbat atal nagusi ditu?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "5");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "7");
					strcpy(galdera[gelaID][galderaID].aukerak.C, "8"); //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.D, "10");

					break;
				case 5:
					galdera[gelaID][galderaID].gelaID = gelaID;
					galdera[gelaID][galderaID].galderaID = galderaID;
					galdera[gelaID][galderaID].sartuta = 0;
					galdera[gelaID][galderaID].erabilita = 0;
					strcpy(galdera[gelaID][galderaID].testua, "Zer esan nahi du enpresa baten ingurune orokorra?");
					strcpy(galdera[gelaID][galderaID].aukerak.A, "Enpresa guztientzako berdina da eta eragin bera du guztiendako");
					strcpy(galdera[gelaID][galderaID].aukerak.B, "Enpresa guztientzako berdina da eta denetan izaten du eragina baina ez modu berean");  //ONDO
					strcpy(galdera[gelaID][galderaID].aukerak.C, "Jarduera-sektore baten barneko enpresetan du bakarrik eragina");
					strcpy(galdera[gelaID][galderaID].aukerak.D, "Jarduera-sektore guztien barneko enpresetan du bakarrik eragina");

					break;

				default:
					break;
				}
				galderaID++;
			}
			break;

		default:
			break;
		}

		gelaID++;
	}
}

void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota) {

	switch (mota)
	{
	case 1:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
		textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
		textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);
		break;
	case 2:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
		textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
		textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);
		break;
	case 3:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
		textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
		textuaGaldera(684, 645, 590, galdera[gelaID][galderaID].aukerak.D);

		break;
	case 4:
		textuaGaitu_galderak();
		textuaGaldera(27, 290, 1280, galdera[gelaID][galderaID].testua);
		textuaGaldera(55, 512, 590, galdera[gelaID][galderaID].aukerak.A);
		textuaGaldera(684, 512, 590, galdera[gelaID][galderaID].aukerak.B);
		textuaGaldera(55, 645, 590, galdera[gelaID][galderaID].aukerak.C);
		break;
	default:
		break;
	}
}