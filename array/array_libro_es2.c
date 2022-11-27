/*
Scrivi un programma che legge un numero positivo
in ingresso inferiore a 10.000 e
calcola i suoi divisori memorizzandoli in un vettore.
Quindi li visualizza sullo schermo al termine dell’elaborazione.
*/
#include <stdio.h>

int main()
{
    int numero, i;
    int divisori[1000];
    int j = 0;

    do{
        printf("vai col numero (meno di 10000 mi raccomando)");
        scanf("%d", &numero);
    } while(numero >= 10000);

    // divisore di un numero
    //se numero % i == 0 --> i e' un divisore
    for(i = 1; i <= numero; i++) {
        if(numero % i == 0) {
            divisori[j] = i;
            j++;
        }
    }

    for(i = 0; i < j; i++) {
        printf("%d e' divisore\n", divisori[i]);
    }

}
