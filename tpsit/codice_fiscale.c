#include <stdio.h>
#include <string.h>

char sequenza[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int tab_dispari[] = {1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 2, 4, 18, 20, 11, 3, 6, 8, 12, 14, 16, 10, 22, 25, 24, 23};
int tab_pari[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

char tab_controllo[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char **argv)
{
	int i;
	int indice;
	char cod[17];
	char ricerca[2] = {0};
	char *c;
	int somma = 0;

	/* printf("inserisci codice fiscale:"); */
	/* scanf("%16s", cod); */
	if(argc < 2) {
		printf("manca codice fiscale");
		return -1;
	}
	strcpy(cod,argv[1]);

	int l = strlen(cod) - 1; // voglio saltare il carattere di controllo
	for(i = 0; i < l; i++) {
		ricerca[0] = cod[i]; // compongo la stringa da cercare
		// possibilita' 1: uso strcspn
		/* indice = strcspn(sequenza, ricerca); */

		// possibilita' 2: ottengo puntatore all'elemento nella sequenza
		c = strchr(sequenza, cod[i]);
		// ottengo indice come differenza tra l'indirizzo del carattere trovato
		// e indirizzo della prima lettera
		indice = c - sequenza;

		// sommo 1 perche' il calcolo parte con la posizione numero 1 (non da indice 0 come in C)
		if ((i + 1) % 2 == 0){
				  /* printf("tab pari %d\n", tab_pari[indice]); */
				  somma += tab_pari[indice];
		} else {
				  /* printf("tab dispari %d\n", tab_dispari[indice]); */
				  somma += tab_dispari[indice];
		}
	}
	indice = somma % 26;
	/* printf("carattere controllo: %c\n", tab_controllo[indice]); */

	// alla posizione 15 c'e' l'ultimo carattere (quello di controllo)
	// controllo che il calcolo coincida
	if (tab_controllo[indice] == cod[15]) {
		printf("codice fiscale corretto\n");
	} else {
		printf("codice fiscale errato\n");
	}

	return 0;
}
