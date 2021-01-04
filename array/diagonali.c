#include <stdio.h>

/*
x - - - X
- x - x -
- - x - -
- x - x -
x - - - x
*/
int main()
{
    int r, c;
    int n;
    int x1 = 0;
    int x2;

    do {
        printf("valore");
        scanf("%d", &n);
    } while (n % 2 == 0);
    x2 = n - 1;
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            if ((c == x1) || (c == x2)) {
                printf("X ");
            } else {
                printf("- ");
            }
        } // qui ho finito di stampare una riga, quindi
        // sposto la x nella colonna successiva
        x1++;
        x2--;
        // vado a capo
        printf("\n");
    }
}