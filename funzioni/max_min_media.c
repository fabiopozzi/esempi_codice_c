/*
  Scrivere una funzione max_min_media che dato un array di valori interi
  sia in grado di calcolare e restituire il massimo, il minimo e la media
  dei valori dell'array
*/
#include<stdio.h>
#define N 5

void max_min_media(int *max, int *min,
                   float *media, int v[])
{
    int i;
    float somma = 0.0;
    *max = v[0];
    *min = v[0];
    for( i = 0; i < N; i++ ){
        somma = somma + v[i];
        if (v[i] > *max) {
            *max = v[i];
        }
        if (v[i] < *min) {
            *min = v[i];
        }
    }

    *media = somma / N;
        
}
    

int main ()
{
    int v[N] = {104, 69, 420, 520, 208};
    int massimo, minimo;
    float media;

    max_min_media(&massimo, &minimo, &media, v);
    printf("massimo: %d, minimo %d, media %f\n", massimo,
           minimo, media);
}

    
    

