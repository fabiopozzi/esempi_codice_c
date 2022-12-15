/*
Es1:
Costruire un programma che richiede un numero N
e genera N valori interi casuali compresi tra 1 e 100.
Al termina stampa l'elenco di quelli pari.
L'area di memoria deve essere gestita dinamicamente mediante
l'uso di puntatori a integer.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int n;
    int *num_p;
    srand(time(NULL)); // inizializzo il generatore di pseudocasuali

    do {
        printf("Insersci numero N di valori: ");
        scanf("%d", &n);
        // controllare che n sia positivo
    } while(n <= 0);

    // riservo la memoria per gli N numeri
    num_p = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        num_p[i] = (rand() % 100) + 1;
    }

    for(int i = 0; i < n; i++){
        if (num_p[i] %2 == 0) {
            printf("%d\t", num_p[i]);
        }
    }
    free(num_p); // libero la memoria allocata

    return 0;
}