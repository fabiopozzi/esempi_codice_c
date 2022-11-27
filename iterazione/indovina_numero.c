/*  scrivere un programma che ci permetta di giocare ad 'indovina il numero'
    ovvero dato un numero estratto casualmente tra 1 e 100 avendo a disposizione 10 tentativi
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int numero_casuale;
    int tentativi = 1;
    int numero; // il numero inserito dal giocatore

    srand(time(0));

    numero_casuale = (rand() % 100)+1;
    printf("BENVENUTO NEL GIOCO INDOVINA IL NUMERO\n");
    do {
        printf("inserisci un numero (tentativo num %d)", tentativi);
        scanf("%d", &numero);

        if (numero < numero_casuale) {
            printf("NUMERO TROPPO BASSO!\n");
        } else {
            if (numero > numero_casuale) {
                printf("NUMERO TROPPO GRANDE!\n");
            } else {
                printf("HAI INDOVINATO!! HAI VINTO!\n");
                break;
            }
        }

        tentativi = tentativi + 1;
    } while(tentativi <= 10);


    printf("il numero a caso e' %d\n", numero_casuale);

    return 0;
}