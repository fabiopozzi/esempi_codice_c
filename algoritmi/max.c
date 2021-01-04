#include <limits.h>
#include <stdio.h>

int main()
{
    int n, i, max;
    // max = INT_MIN
    int array[100];
    int pos; // posizione in cui si trova l'elemento massimo
    const char c = 'a';

    do {
        printf("Quanti numeri inserire?: ");
        scanf("%d", &n);
    } while ((n <= 0)&& (n< 100));

    /* leggo i valori */

    for(i = 0; i < n; i++){
        printf("inserisci il valore %d:", i);
        scanf("%d%*c", &array[i]);
    }

    // calcolo il massimo
    pos = 0;
    int min = array[0];

    for (i = 0; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
            pos = i;
        }
    }

    printf("Il valore massimo e': %d\n", max);
    printf("Il valore massimo e' in posizione %d\n", pos);
    printf("Il valore massimo %d\n", array[pos]);
    return 0;

}
