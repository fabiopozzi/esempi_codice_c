#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000

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
    /* printf("pos pivot %d, pivot vale %d\n", ipivot, pivot); */
    /* mostraVettore(vett); */

    while (sx < dx) {
        while((vett[sx] <= pivot) && (sx < dx)) {
            sx++;
        }
        while (vett[dx] > pivot) {
            dx--;
        }

        if (sx < dx) {
            /* printf("scambio valore > pivot preso a sx con valore < pivot preso a dx\n"); */
            /* printf("scambia v[%d] = %d con v[%d] = %d\n", sx, vett[sx], dx, vett[dx]); */
            scambia(vett, sx, dx);
        }
    }
    /* printf("termino loop perche sx = %d, dx = %d\n", sx, dx); */
           
    /* mostraVettore(vett); */
    /* printf("posiziono il pivot in posizione %d scambiandolo con v[%d] = %d\n", ipivot, dx, vett[dx]); */
    scambia(vett, ipivot, dx);
    /* mostraVettore(vett); */

    return dx;
}

void quicksort(int vett[], int e_sx, int e_dx)
{
    int q;

    if (e_sx < e_dx) {
        q = partiziona(vett, e_sx, e_dx);
        /* printf("\n partiziona ha restituito %d\n", q); */
        /* printf("chiamo quicksort(vett, %d, %d)\n", e_sx, q-1); */
        quicksort(vett, e_sx, q - 1);
        /* printf("chiamo quicksort(vett, %d, %d)\n", q+1, e_dx); */
        quicksort(vett, q + 1, e_dx);
    /* } else { */
    /*     printf("intervallo non valido\n"); */
    }
}

void riempi_vettore(int v[])
{
    srand(time(NULL)); 

    for (int i= 0; i < N; i++) {
        v[i] = rand() % 101;
    }
}

void selection_sort(int array[])
{
    int i, j;
    int tmp;
    int posizione_minimo, valore_minimo;

    for (i = 0; i < N - 1; i++) { // ripeti n-1 volte
      // il primo elemento non ordinato è in posizione i
        // inizializza minimo
        posizione_minimo = i; // posizione
        valore_minimo = array[i]; // valore

        // trova minimo nel resto dell'array
        for (j = i + 1; j < N; j++) {

            // trova posizione minimo
            if (array[j] < valore_minimo) {
              posizione_minimo = j;
              valore_minimo = array[j];
            }
        } // finito di trovare il minimo


        // scambia minimo (in posizione min) con elemento in posizione i
        tmp = array[posizione_minimo];
        array[posizione_minimo] = array[i];
        array[i] = tmp;
    }
}

int main()
{
    clock_t start_t, end_t;
    float total_t;
    int array[N];


    riempi_vettore(array);

    start_t = clock();
    selection_sort(array);
    end_t = clock();
    total_t = ((float)end_t - start_t) / CLOCKS_PER_SEC;
    total_t = ((float)(end_t - start_t)) / CLOCKS_PER_SEC;
    printf("Tempo totale di elaborazione selection sort:\t%f\n", total_t );

    riempi_vettore(array);
    start_t = clock();
    quicksort(array, 0, N - 1);
    end_t = clock();
    total_t = (((float)end_t - start_t)) / CLOCKS_PER_SEC;
    printf("Tempo totale di elaborazione quicksort:\t\t%f\n", total_t );
    /* stampa array ordinato */
    /* for (i = 0; i < N; i++) { */
    /*   printf("%d\t", array[i]); */
    /* } */
    /* printf("\n"); */


    return 0;
}
