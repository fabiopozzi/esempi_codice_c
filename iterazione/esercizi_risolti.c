/*
Scrivi un programma che legga una sequenza di numeri terminanti con 0:
Se un numero appartiene all’intervallo (10, 50) il programma deve stampare OK

Se invece il numero è esterno all'intervallo ma inferiore a 10 stampi INF,
mentre se superiore a 50 stamperà SUP.

Il programma termina immediatamente anche quando
viene inserito un numero negativo.
#include<stdio.h>

int main()
{
    int numero;
    do {
        printf("inserisci un numero: ");
        scanf("%d", &numero);
        if (numero >= 10){
            if(numero <= 50) {
                printf("%d OK\n", numero);
            } else {
                // numero >= 10 ma non e' <= 50
                printf("%d SUP\n", numero);
            }
        } else {
            if (numero != 0) {
                printf("%d INF\n", numero);
            }
        }
    }while(numero != 0);

    return 0;
}
*/
/*
Scrivere un programma che visualizzi un rettangolo costituito da
caratteri asterisco, dove i numeri di righe e di colonne del rettangolo
siano decisi dall'utente (ciascuno di questi numeri non deve essere inferiore a 3).
Per esempio, se il numero delle righe è uguale a 5 e il numero di colonne a 6
*/
#include <stdio.h>
int main()
{
    int i, j;
    int r, c;
    do {
        printf("num righe ");
        scanf("%d", &r);
    } while(r < 3);

    do {
        printf("num colonne ");
        scanf("%d", &c);
    } while(c < 3);

    for(j = 0; j < r; j++) {
        // stampa una riga
        for(i = 0; i < c; i++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
