#include <stdio.h>

float somma(float a, float b);
float sottrazione(float a, float b);
float moltiplicazione(float a, float b);
float divisione(float a, float b);

int main() {
  char op;
  float n1, n2;
  float risultato;
      
    switch(op) {
    case '+':
      risultato = somma(n1, n2);
      break;
    case '-':
      risultato = sottrazione(n1, n2);
      break;
    case '*':
      risultato = moltiplicazione(n1, n2);
      break;
    case '/':
      risultato = divisione(n1, n2);
      break;
  }
    printf("risultato: %f", risultato);

  return 0;
}

float somma(float a, float b)
{
  return a+b;
}
float sottrazione(float a, float b)
{
  return a-b;
}
float moltiplicazione(float a, float b)
{
  return a*b;
}
float divisione(float a, float b)
{
  return a/b;
}
