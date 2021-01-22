#ifndef GALDERA_H
#define GALDERA_H

#define MAX 128
#define GELAIDMAX 11
#define GALDERAIDMAX 6
//------


typedef struct opzioak {
	char A[MAX];
	char B[MAX];
	char C[MAX];
	char D[MAX];

} OPZIOAK;

typedef struct galdera {

	int gelaID;
	int galderaID;
	char testua[MAX];
	OPZIOAK aukerak;//swicth erabili aukeratzeko
	int erabilita;
	int sartuta;

}GALDERA;



//------galderak
void galderakEtaEurenAukerakSortu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX]);
void opzioakAgertu(GALDERA galdera[GELAIDMAX][GALDERAIDMAX], int gelaID, int galderaID, int mota);
void fondoPantailaGalderekin(char* str, int galderaID, int gelaID, GALDERA galdera[GELAIDMAX][GALDERAIDMAX], char* ikaslea);

#endif // !GALDERA_H
