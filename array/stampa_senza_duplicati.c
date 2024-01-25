#include<stdio.h>
#define N 6

int main()
{
    int array[N] = {1, 2, 20, 1, 2, 20};
    int i, j;
    int stampa;

    for(i = 0; i < N; i++) { // attraversa ARRAY
        stampa = 1;
        // devo controllare tutti i valori precedenti a quello corrente
        for(j = 0; j < i; j++) { // devo cercare i valori precedenti
            if (array[i] == array[j]) { // ho una coppia di valori
                stampa = 0;
                break;
            }
        }
        if (stampa == 1) {
            printf("%d ", array[i]);
        }
    }
    return 0;
}
