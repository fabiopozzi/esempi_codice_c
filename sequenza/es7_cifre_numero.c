/*
 *Dato un numero inserito dall’utente, compreso tra 1000 e 9999, stampalo in modo che ogni cifra sia separata dalle altre da uno spazio.
 */

#include<stdio.h>

int main() {
    int num;
    printf("inserisci un numero:");
    scanf("%d", &num);

    int m = num / 1000;
    num = num - (m * 1000);

    int c = num / 100;
    num = num - (c * 100);

    int d = num / 10;
    num = num - (d * 10);

    printf("%d %d %d %d\n", m, c, d, num);
}
