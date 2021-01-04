// MI LEGGETE?
#include <stdio.h>

#define N 3

int main()
{
    // leggere N valori e stampare solo quelli maggiori della MEDIA
    int i;
    int valori[N];
    float media = 0.0;

    for (i = 0; i < N; i++) {
        printf("inserisci il valore %d: ", i + 1);
        scanf("%d", &valori[i]);
        media = media + (float)valori[i];
    }
    // qui avremo tutti i nostri valori nell'array
    media = media / N; // calcolo della media
    for (i = 0; i < N; i++) {
        if (valori[i] > media) {
            printf("valore maggiore della media: %d\n", valori[i]);
        }
    }
    //printf("la media vale %f\n", media);
    return 0;
}