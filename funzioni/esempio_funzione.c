#include <stdio.h>
#include <stdlib.h>

int somma(int s1, int s2); // PROTOTIPO della funzione

int main()
{
	int j;
	j = 20;

	j = somma(10, 20); // 10 e 20 sono PARAMETRI ATTUALI
	if (somma(100, 20) > 40) {
		printf("AAAAAAAAAA");
	}

	int aaa = 40;
	int bbb = -20;
	j = somma(aaa, bbb); // s1 ed s2 sono parametri ATTUALI

	return -1;
}


int somma(int s1, int s2) // parametri FORMALI
{
    s1 = 120;
  if (s2 > 10) {
    // uscire da tutto il programma
    exit(1);
  }
  return s1 + s2;
}
