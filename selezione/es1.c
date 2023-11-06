/*
  Scrivere un programma che richieda il numero di ore, minuti e secondi che compongono
  un tempo e visualizzi quindi l'equivalente espresso in secondi.
  Controllare e validare che ore, minuti, secondi siano in formato valido.
  Ore > 0
  0 <= minuti < 60
  0 <= secondi < 60
  Se i valori non sono validi stampare un messaggio di errore ed uscire dal programma.
*/
#include<stdio.h>

int main()
{
    int ore;
    int minuti;
    int secondi;

    printf("inserisci numero ore: ");
    scanf("%d", &ore);
    if (ore < 0) {
        printf("Ore non valide\n");
        return 0;
    }
    printf("inserisci numero minuti: ");
    scanf("%d", &minuti);
    if (minuti < 0) {
        printf("Minuti non validi\n");
        return 0;
    }
    if (minuti >= 60) {
        printf("Minuti non validi\n");
        return 0;
    }
    printf("inserisci numero secondi: ");
    scanf("%d", &secondi);
    if (secondi < 0) {
        printf("Secondi non validi\n");
        return 0;
    }
    if (secondi >= 60) {
        printf("Secondi non validi\n");
        return 0;
    }
    int totale = (ore * 3600) + (minuti * 60) + secondi;
    printf("Totale secondi %d\n", totale);
    return 0;
}
