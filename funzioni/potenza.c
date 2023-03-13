/*
** Scrivere una funzione potenza che riceva in ingresso due numeri interi a e b
(b >= 0)
** e restituisca il risultato della potenza a^b (a elevato alla potenza b).
** Utilizzare la funzione per visualizzare il valore delle potenze 5^4, 12^3, 20^2, 15^0.
*/
#include <stdio.h>

int potenza(int a, int b);

int main()
{
  int risultato = potenza(5, 4);

  printf("5 ^ 4 = %d\n", risultato);

  risultato = potenza(15, 0);

  printf("15 ^ 0 = %d\n", risultato);

  return 0;
}

int potenza(int a, int b)
{
  int i;
  int risultato = 1;

  for(i = 0; i < b; i++) {
    risultato = risultato * a;
  }
  return risultato;
}
