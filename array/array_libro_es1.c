/*
Genera casualmente N numeri e visualizza il
loro quadrato.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 50
int main()
{
    int a[NUM]; // dichiarazione array
    int i;
    //1 inizial. generatore
    srand(time(NULL));

    for(i = 0; i < NUM; i++) {
        // genero 1 numero casuale
        a[i] = rand() % 100;
    }

    for(i = 0; i < NUM; i++) {
        printf("%d al quadrato %d\n", a[i], a[i]*a[i]);
    }
    return 0;
}
