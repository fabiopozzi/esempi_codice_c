#include <stdio.h>

int main()
{
  char *p = "ciao come va";

  printf("%s\n", p);
  p[0] = 'C';
  printf("%s\n", p);
  // se eseguiamo questo codice una volta arrivati qui otterremo un errore
  // perche' tentare di modificare una stringa costante
  // causa COMPORTAMENTO INDEFINITO -> crash
  
  return 0;
}
