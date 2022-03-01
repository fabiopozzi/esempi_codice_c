#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    clock_t t_inizio = clock();
  
    int i;
    int val[500000];

    for(i=0; i < 500000; i++){
        val[i] = rand();
        // fai altro
    }

    clock_t t_fine = clock();
    double tempo = ((double)t_fine - (double)t_inizio) / CLOCKS_PER_SEC;
    printf("time elapsed: %.2f\n", tempo);
}
