#include <limits.h>
#include <stdio.h>

#define N 10

int main()
{
    int i, pos, min;
    int array[N] = {1, 50, 44, 3, 24, 7, 15, 42, 11, 67};


    // calcolo il minimo e la sua posizione
    pos = 0;
    min = array[0];

    for (i = 0; i < N; i++) {
        if (array[i] < min) {
            min = array[i];
            pos = i;
        }
    }

    printf("Il valore minimo e': %d\n", min);
    printf("Il valore minimo e' in posizione %d\n", pos);

    return 0;
}
