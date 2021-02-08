#include <stdio.h>

#define N1 10
#define N2 10
#define N 20

int main()
{
	int vet1[N1] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int vet2[N2] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int risultato[N];
    int i = 0, j = 0, k = 0;

	// attraversa entrambi gli array usando un while
    while (i<N1 && j <N2)
    {
		/* controlla se l'elemento corrente del primo array e' piu piccolo dell'elemento corrente
		 * del secondo array. Se si memorizza l'elemento del primo array e incrementa gli indici.
		 * Altrimenti fai la stessa cosa ma usando il secondo array */
        if (vet1[i] < vet2[j]) {
            risultato[k] = vet1[i];
			k++;
			i++;
        } else {
            risultato[k] = vet2[j];
			k++;
			j++;
		}
    }

    // Store remaining elements of first array
    // Copia gli elementi rimanenti del primo array
    while (i < N1) {
        risultato[k] = vet1[i];
		k++;
		i++;
	}

    // Copia gli elementi rimanenti del secondo array
    while (j < N2) {
        risultato[k] = vet2[j];
		k++;
		j++;
	}

	return 0;
}
