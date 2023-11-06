#include<stdio.h>
#include<string.h>

struct punto
{
    int x;
    int y;
};

void stampa(struct punto p[], int dim)
{
    for(int i = 0; i < dim; i++)
	printf("punto %d:\nx: %d y: %d\n", i, p[i].x, p[i].y);
}

// scrivi una funzione che riceva per indirizzo una struttura dati punto
// e ne incrementi entrambi i campi
void f(struct punto *p) {
    p->x += 1;
    p->y = p->y + 1;
}

int main() {
  struct punto vettore[5];
  struct punto a;

  struct punto *p; // puntatore ad una struct

  for(int i = 0; i < 5; i++) {
      vettore[i].x = i*2;
      vettore[i].y = i;
  }
  stampa(vettore, 5);

  p = &a;

  p->x = 42; // inserisce 42 nel campo x della variabile puntata da p
  p->y = 12;
  // la freccia segue il puntatore p (dereferenzia il puntatore)
  // poi accede al membro / campo x della struttura dati che ha raggiunto

    printf("punto :\nx: %d y: %d\n", p->x, p->y);

  return 0;
}
