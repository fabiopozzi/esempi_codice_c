#include<stdio.h>
#include<string.h>

#define N_STRINGHE 3
#define LUNGHEZZA 78

int main()
{
  char a[N_STRINGHE][LUNGHEZZA];
  char riga[100];

  printf("inserisci una riga");
  fgets(riga, 100, stdin);

  int val;
  int pos = 0;
  sscanf(riga,"%s%s%s", a[0],a[1],a[2]);


  printf("%s\n", a[0]);
  printf("%s\n", a[1]);
  printf("%s\n", a[2]);


}
