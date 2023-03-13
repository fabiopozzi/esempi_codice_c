/*
** Esercizio
Scrivere una funzione con prototipo
int valore_assoluto(int)
che restituisca il valore assoluto dell'argomento
ricevuto.
Il valore assoluto di un numero è sempre positivo o nullo.
*/
#include <stdio.h>

int valore_assoluto(int); // Prototipo della funzione

int main()
{
  int risultato;
  int num;
  printf("inserisci numero: ");
  scanf("%d", &num);
  risultato = valore_assoluto(num);
  printf("il valore assoluto di %d vale %d\n", num, risultato);
  return 0;
}

int valore_assoluto(int val)
{
  int risultato;

  if (val < 0) {
    risultato = val * (-1);
  } else {
    risultato = val;
  }
  return risultato;
}
