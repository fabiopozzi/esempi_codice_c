/*
Scrivere un programma che acquisisca da tastiera un vettore di (max 100)
valori di tipo intero e identifichi la più lunga sequenza
di numeri consecutivi uguali.
Se vengono identificate più sequenze della stessa lunghezza,
si consideri solo la prima identificata.
Il programma deve indicare il valore ripetuto e
il numero di ripetizioni di quel valore.
*/
#include <stdio.h>

#define N 100

int main()
{
    int v[N]; // dichiaro un vettore che puo' contenere fino a 100 interi
    int num;
    do {
        printf("quanti valori?");
        scanf("%d", &num);
    } while (num <= 0 || num > N);
    // adesso ho num che rappresenta il mio numero di valori da leggere
    for (int i = 0; i < num; i++) {
        scanf("%d", &v[i]);
    }
    // voglio cercare delle sequenze di valori tutti uguali
    // 1 2 2 3 3 3 4 5 6
    int sequenza = 1;
    int lung_max = 1;
    int val_max = v[0];
    for (int i = 1; i < num; i++) {
        // confronto con il precedente
        if (v[i] == v[i - 1]) {
            sequenza++; // incremento
            // sto CONTANDO la lunghezza della sequenza
            // trovo il massimo
            if (sequenza > lung_max) {
                lung_max = sequenza;
                val_max = v[i];
            }
        } else {
            sequenza = 1;
        }
    }
    printf("lungh massima %d e val massimo %d\n", lung_max, val_max);
}