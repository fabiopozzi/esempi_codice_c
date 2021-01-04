/*
Data una frase, stampare la lunghezza, il numero di parole contenute,
il numero di vocali e il numero di consonanti   
Esempio:
"Oggi vado a scuola"  ->
Lunghezza frase: 18
Numero parole: 4
Vocali: 9
Consonanti: 7
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR 200

int main()
{
    int n;
    int lunghezza_totale = 0;
    int fine_parola = 1;
    int parole = 0;
    int vocali = 0;
    int consonanti = 0;
    char frase[MAX_STR] = { 0 };

    printf("Inserisci frase: ");
    fgets(frase, MAX_STR, stdin);
    frase[strcspn(frase, "\n")] = 0;
    n = strlen(frase);
    for (int i = 0; i < n; i++) {
        if (isspace(frase[i]) || ispunct(frase[i])) { //separatori tra parole
            fine_parola = 1;
        }
        if (fine_parola && isalpha(frase[i])) { //inizio nuova parola
            fine_parola = 0;
            parole++;
        }
        if (isalpha(frase[i])) {
            if (strchr("aeiou", tolower(frase[i]))) // vocale
                vocali++;
            else
                consonanti++;
            /* alternativa:
            char l = tolower(frase[i]);
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l =='u')
            */
        }
    }
    printf("Lunghezza frase: %d\n", n);
    printf("Numero parole: %d\n", parole);
    printf("Numero vocali: %d\n", vocali);
    printf("Numero consonanti: %d\n", consonanti);
    return 0;
}
