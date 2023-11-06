/*
Scrivere una funzione che riceva in ingresso un numero float corrispondente al
prezzo iniziale di un articolo e un numero intero "sconto" rappresentante il
valore percentuale di sconto
voglio scontare solo i prezzi > 1000 e restituire il numero di valori scontati.
*/
#include<stdio.h>

int sconto(float prezzi[], int n, int percentuale, float prezzi_scontati[])
{
     int i;
     int numero_scontati = 0;

     for(i = 0; i < n; i++) {
          if (prezzi[i] > 1000) {

            prezzi_scontati[i] = prezzi[i] - (prezzi[i] * percentuale);
            numero_scontati++;
          } else {
               prezzi_scontati[i] = prezzi[i];
          }
     }
     return numero_scontati;
}

int main()
{
     float valori[] = {10000.0, 1500.0, 120.0 };
     float valori_scontati[3];

     int numero_valori_scontati = sconto(valori, 3, 20, valori_scontati);

     for(int i = 0; i < 3; i++) {
          printf("valore: %f\n", valori_scontati[i]);
     }
     printf("sono stati scontati %d articoli\n", numero_valori_scontati);
     return 0;
}

