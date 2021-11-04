/*
## Esercizio 6
Scrivere un programma che acquisisca da tastiera un vettore di (max 100) valori di tipo
intero e identifichi la **più lunga** sequenza di *numeri consecutivi uguali*.

Se vengono identificate più sequenze della stessa lunghezza, si consideri solo la prima
identificata. Il programma deve indicare il valore ripetuto e il numero di ripetizioni di
quel valore.

Esempio:

Input: 19 3 15 15 7 9 9 9 9 12 3 3 3

Output: numero: 9, ripetizioni: 4
*/

#include <stdio.h>
#define N 13

int main(void) {
    int val[N] = {19, 3, 15, 15, 7, 9, 9, 9, 8, 3, 3, 3, 3};
    int i, conto = 0;
    int max = 1, num = val[0];

    int tmp = num;
    for(i = 0; i < N; i++){
        if (val[i] == tmp) {
            // sequenza di valori consecutivi
            conto++;
        } else {
            if (conto > max) {
                max = conto;
                num = tmp;
            }
            // cambia il valore
            tmp = val[i];
            conto = 1;
        }
    }

    printf("numero: %d, ripetizioni: %d\n", num, max);
    return 0;
}
