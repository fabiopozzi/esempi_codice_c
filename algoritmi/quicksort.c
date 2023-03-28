#include <stdio.h>
#define N 12

void scambia(int v[], int p1, int p2)
{
    int tmp;
    tmp = v[p1];
    v[p1] = v[p2];
    v[p2] = tmp;
} 

void mostraVettore(int v[])
{
    for (int i = 0; i < N; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("--------");
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t", v[i]);
    }
    printf("\n\n");
}

int partiziona(int vett[], int sx, int dx)
{
    int pivot, ipivot; // valore di pivot e sua posizione

    ipivot = sx;
    pivot = vett[ipivot];
    printf("pos pivot %d, pivot vale %d\n", ipivot, pivot);
    mostraVettore(vett);

    while (sx < dx) {
        while((vett[sx] <= pivot) && (sx < dx)) {
            sx++;
        }
        while (vett[dx] > pivot) {
            dx--;
        }

        if (sx < dx) {
            printf("scambio valore > pivot preso a sx con valore < pivot preso a dx\n");
            printf("scambia v[%d] = %d con v[%d] = %d\n", sx, vett[sx], dx, vett[dx]);
            scambia(vett, sx, dx);
        }
    }
    printf("termino loop perche sx = %d, dx = %d\n", sx, dx);
           
    mostraVettore(vett);
    printf("posiziono il pivot in posizione %d scambiandolo con v[%d] = %d\n", ipivot, dx, vett[dx]);
    scambia(vett, ipivot, dx);
    mostraVettore(vett);

    return dx;
}

void quicksort(int vett[], int e_sx, int e_dx)
{
    int q;

    if (e_sx < e_dx) {
        q = partiziona(vett, e_sx, e_dx);
        printf("\n partiziona ha restituito %d\n", q);
        printf("chiamo quicksort(vett, %d, %d)\n", e_sx, q-1);
        quicksort(vett, e_sx, q - 1);
        printf("chiamo quicksort(vett, %d, %d)\n", q+1, e_dx);
        quicksort(vett, q + 1, e_dx);
    } else {
        printf("intervallo non valido\n");
    }
}

int main()
{
    int v[N] = {27, 7, 49, 44, 45, 30, 31, 6, 39, 19, 33, 26};

    quicksort(v, 0, 11);

}
