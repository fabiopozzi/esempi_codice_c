#include<stdio.h>
#define N 5

int converti(int ms);
void statistiche(int valori[], int n);

int main()
{
    int crono[N] = {10000, 9000, 12000, 8500, 11500};
    statistiche(crono, N);
    return 0;
}

int converti(int ms)
{
    int minuti;
    int secondi;
    int tmp = ms;

    if (ms < 0)
        return -1;

    minuti = tmp / 60000;

    tmp = tmp - (minuti * 60000);

    secondi = tmp / 1000;

    tmp = tmp - (secondi * 1000);

    /*printf("valore originale %d", ms);*/
    printf("%02d:%02d.%02d\n", minuti, secondi, tmp);

    return 0;
}

void statistiche(int valori[], int n)
{
    int giro_veloce = valori[0];
    float media = 0;

    for(int i = 0; i < n; i++) {
        if(valori[i] < giro_veloce) {
            giro_veloce = valori[i];
        }
        media += valori[i];
    }
    media = media / (float)n;
    printf("giro piu' veloce: ");
    converti(giro_veloce);
    printf("passo gara ");
    converti(media);
}
