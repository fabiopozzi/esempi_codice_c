/*
Scrivere un programma che letti due numeri: A (il numero A deve essere dispari) ed L,
stampi una lettera h di altezza A e larghezza L
    Esempio
    a=7  l=5
    *   *
    *   *
    *   *
    *****
    *   *
    *   *
    *   *
    
    1- abbiamo prima letto i valori e controllato che fossero validi
    2- abbiamo diviso il problema in parti
    3- risolto la riga "normale"  *    *
    4- abbiamo aggiunto la riga piena di asterischi
*/
#include <stdio.h>

int main()
{
    int a, l;
    int i, j;
    do {
        printf("inserisci A: ");
        scanf("%d", &a);
    } while (a % 2 == 0);

    do {
        printf("inserisci L: ");
        scanf("%d", &l);
    } while (l <= 0);

    for (i = 0; i < a; i++) {
        // STAMPA UNA RIGA
        if (i == (a / 2)) { // questa e' la riga diversa
            for (j = 0; j < l; j++) {
                printf("*");
            }
        } else {
            // TUTTO IL RESTO
            printf("*");
            for (j = 0; j < l - 2; j++) {
                printf(" ");
            }
            printf("*");
        }
        // devo sempre andare a capo a fine riga
        printf("\n");
    }
}