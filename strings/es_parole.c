/*
Si scriva un programma che chieda all'utente il numero di parole da leggere,
legga ognuna delle parole (una per una),
calcoli la lunghezza di ogni parola ed infine concateni le parole
creando una frase,
stampando infine la lunghezza totale della frase.
*/
#include <stdio.h>
#include <string.h>

#define MAXL 500

int main()
{
    char stringa[MAXL] = { 0 };
    char parola[50];
    int n;
    int l;
    int l_tot = 0;

    printf("Inserisci il numero di parole: ");
    scanf("%d", &n);

    // %c  come char
    // %s  come stringa
    for (int i = 0; i < n; i++) {
        printf("scrivi la parola: ");
        scanf("%49s", parola);
        l = strlen(parola);
        l_tot = l_tot + l;
        strcat(stringa, parola);
        // inserisco uno spazio dopo ogni parola
        strcat(stringa, " ");
    }
    stringa[strlen(stringa) - 1] = '\0';
    printf("---%s---\n", stringa);
    printf("Lunghezza totale stringa %ld\n", strlen(stringa));

    return 0;
}