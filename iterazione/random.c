#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int seme = time(NULL); // barbatrucco per ottenere un numero diverso di
    //inizializzazione ogni volta che lancio il programma

    srand(seme);

    int val;
    for(int i = 0; i < 100; i++){
        val = (rand()%100)+1;
        printf("%d ", val);
    }
    return 0;
}