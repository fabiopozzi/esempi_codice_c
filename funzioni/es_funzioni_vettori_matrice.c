#include <stdio.h>

#define N  10
#define R  2
#define C  10

// PROTOTIPI
void leggi(int v[], int *l);
float media(int v[], int l);
void ordina( int v[], int n);
void scrivi(int v[], int n);

int main()
{
/*
** [0][55][88][]     2
** [42][][][]        1
** [1][2][3][4]      4
** int lunghezze[R]
 */

	//int un_vettore_bellissimo[N] = {0};
	int lunghezze[R];
	int mat[R][C];

	for(int i = 0; i < R; i++){
		leggi(mat[i], &lunghezze[i]);
	}


	for(int i = 0; i < R; i++){
		printf("stampo la riga %d\n", i+1);
		scrivi(mat[i], lunghezze[i]);
	}

	return 0;
}

// passando la lunghezza per indirizzo
void leggi(int v[], int *l)
{
	// chiedere all'utente il numero di valori l (max N)
	// leggere  l valori interi dall'utente e metterli nel vettore v
	do {
		  printf("inserisci numero valori:");
		  scanf("%d", l); // l è un puntatore, quindi quando lo devo passare alla SCANF non devo usare &
	} while((*l > N) || (*l < 0)); // quando voglio il valore devo usare *l

	for (int i = 0; i < *l; i++)
	{
		printf("inserisci il valore %d: ", i+1);
		scanf("%d", &v[i]);
	}
}

// Restuiamo il valore della media
// non modifica il vettore
float media(int v[], int l)
{
	int somma = 0;
	float media;

	for(int i = 0; i < l; i++){
		somma = somma + v[i];
	}
	media = (float)somma / l;

	return media;
}

// modifico il vettore perche' lo ORDINO
// so che il vettore e' sempre modificabile
void ordina( int v[], int n )
{
	int i, j;
	int swap;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++) {

            if (v[j] > v[j+1])
            {
                // SCAMBIO ELEMENTI
                swap   = v[j];
                v[j]   = v[j+1];
                v[j+1] = swap;
            }
		}
	}

}

// non modifica il vettore
void scrivi(int v[], int n)
{
	for(int banana = 0; banana < n; banana++)
	{
		printf("%d\t", v[banana]);
	}
	printf("\n");
}
