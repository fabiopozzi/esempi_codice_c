#include<stdio.h>

// scrivi una funzione che restituisca il MINIMO
// tra i valori di un array di interi di dimensione N = 10

//1 tipo del valore di ritorno int
//2 nome funzione
//3 numero e tipo di parametri
#define N 5

int minimo(int array[], int n);

int main()
{
     int v[N] = {1, 2, 3, 4, -20};
     int a[10] = {1, 2, 3, 4, -20, 5, 6, 7, 8, 9};
     int r;

     r = minimo(v, N);
     printf("il minimo dell'array vale %d\n", r);
     printf("%d\n", v[0]);

     r = minimo(a, 10);
     printf("il minimo dell'array vale %d\n", r);
     printf("%d\n", a[0]);

     return 0;
}

int minimo(int array[], int n)
{
     int i;
     int min;

     min = array[0];
     for(i = 0; i < n; i++) {
          if (array[i] < min) {
               min = array[i];
          }
     }

     return min;
}
