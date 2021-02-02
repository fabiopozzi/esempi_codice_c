#include <stdio.h>

#define N 10

int main()
{
    int i, j, swap;
    int array[N] = {1, 50, 44, 3, 24, 7, 15, 42, 11, 67};
    int scambi = 1;

    for (i = 0 ; (i < N - 1) && scambi; i++)
    {
        scambi = 0;
        for (j = 0 ; j < N - i - 1; j++)
        {
            // se voglio ordinamento decrescente userò '<'
            if (array[j] > array[j+1])
            {
                scambi = 1;
                // SCAMBIO ELEMENTI
                swap       = array[j];
                array[j]   = array[j+1];
                array[j+1] = swap;
            }
        }
    }

    printf("Array ordinato con ordine crescente:\n");

    for (i = 0; i < N; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
