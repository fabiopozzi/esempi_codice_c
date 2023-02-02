/*
Data una stringa contenente nome, cognome ed eta' separate da uno spazio,
salvare e poi stampare i dati separatamente
Esempio
Input: "Valentino Rossi 46"
nome: Valentino
cognome: Rossi
Eta: 46

Il programma deve segnalare il caso in cui la stringa di input sia errata
Input: "Mario Verdi trentadue"
Output: Errore

Input: "Mario,Verdi,32"
Output: Errore 
*/
#include<stdio.h>
#include<string.h>
#define N 100

int main()
{
  char riga[N];
  char nome[50];
  char cognome[50];
  int eta = 0;
  int risultato;

  printf("Inserisci nome, cognome ed eta' separate da uno spazio: ");
  fgets(riga, N, stdin);
  riga[strlen(riga) - 1] = '\0';

  risultato = sscanf(riga, "%s%s%d", nome, cognome, &eta);
  if (risultato != 3) {
    printf("ERRORE! risultato = %d\n", risultato);
  } else {
    // se risultato == 3 allora tutto ok
    printf("Nome: %s\n", nome);
    printf("Cognome: %s\n", cognome);
    printf("Eta: %d\n", eta);
  }
  return 0;
}
