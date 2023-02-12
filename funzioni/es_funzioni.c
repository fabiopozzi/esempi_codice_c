#include <stdio.h>

void leggi(int v[], int n);
float media(int v[], int n);
void ordina(int v[], int n);
void scrivi(int v[], int n);
#define N 10

int matrice[2][5];


int main(void) {
  int val[N] = {0};
  float array[10];
  float m;
  int n;
  
  do {
    printf("dammi un numero da 1 a 100");
    scanf("%d", &n);
  } while(n < 1 || n > 100);
  
  leggi(val, n);
  
  m = media(array, n);
  
  scrivi(val, n);
  
  ordina(val, n);
  
  scrivi(val, n);
  
  printf("La media dei valori vale %f\n", m);
  return 0;
}

void ordina(int v[], int n)
{
  
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++){
      
      if ( v[j] > v[j+1] ) {
        int tmp;
        tmp = v[j];
        v[j] = v[j+1];
        v[j+1] = tmp;
      }
    }
  }
}



float media(int v[], int n)
{
  float somma = 0;
  for(int i = 0; i < n; i++){
     somma = somma + v[i];
  }
  float media = somma / n;
  return media;
}



void scrivi(int v[], int n)
{
  printf("HAI INSERITO QUESTI NUMERI:\n");
  for(int i = 0; i < n; i++) {
     printf("%d\t", v[i]);   
  }
  printf("\n");
}


void leggi(int v[], int n) {
  for(int i = 0; i < n; i++) {
    // i esiste qui dentro
    printf("Droppa un numero: ");
    scanf("%d", &v[i]);
  }
  //qui i non esiste
}

/*
- la funzione leggi deve leggere dall'utente n valori inserendoli nel vettore v.
- la funzione media deve calcolare e restituire la media degli n valori presenti nel vettore v passato come parametro.
- la funzione ordina deve ordinare i valori all'interno dell'array (ordine crescente) usando un algoritmo a vostra scelta (es. bubble sort)
- la funzione scrivi deve semplicemente stampare a video il contenuto di tutto l'array
*/
