#include <stdio.h>
/* data una stringa di max 100 caratteri inseriti dall'utente
CONTARE IL NUMERO DI PAROLE contenute nella stringa.
Stampare a video il conteggio
*/
#include<ctype.h>
#include<string.h>

int main(void) {
  char s[100];
  int conto = 0;

  // leggo una riga
  fgets(s, 100, stdin);
  s[strlen(s)-1] = '\0';

  int i;
  int inizio_parola = 0;
  for(i = 0; s[i] != '\0'; i++){
      if(isalpha(s[i])) {
          printf("ho trovato una lettera\n");
          inizio_parola = 1;
      } else {
          printf("spazio o simbolo\n");
          if(inizio_parola == 1) {
              // una parola era
              // iniziata, ora e' finita
              conto++;
              inizio_parola = 0;
              printf("Fine parola\n");
          }
      }
  }
  if(inizio_parola == 1) {
      conto++;
  }
  printf("numero parole %d", conto);
  return 0;
}
