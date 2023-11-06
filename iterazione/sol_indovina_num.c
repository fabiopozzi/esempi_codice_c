/*  scrivere un programma che ci permetta di giocare ad 'indovina il numero'
    dato un numero tra 1 e 100 estratto casualmente abbiamo 10 tentativi per
    indovinarlo
*/
#include<stdio.h>

int main()
{
    int tentativi = 0;
    int numero;
    int valore;

    srand(42);
    numero = (rand() % 100) + 1;

    do {
        printf("indovina il numero, tentativo numero %d: ", tentativi+1);
        scanf("%d", valore);

        if (valore > numero) {
            printf("troppo grande!");
        }
        if (valore < numero) {
            printf("troppo piccolo!");
        } else {
            printf("HAI INDOVINATO!");
            break;
        }
        tentativi++;
    } while(tentativi <= 10);
    printf("hai perso!");

}