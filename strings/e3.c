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
    char frase[MAX_STR];

    printf("inserisci frase: ");
    // scanf("%[^\n]%*c", frase); // non e' sicura
    fgets(frase, MAX_STR, stdin);
    int posizione = strcspn(frase, "\n");
    frase[posizione] = '\0';

    int parole = 1;
    int conto_vocali = 0;
    int conto_consonanti = 0;
    //  abbiamo una frase
    int n = strlen(frase);
    char l;
    for (int i = 0; i < n; i++) { // attraverso tutta la frase
        // parole
        if (isspace(frase[i]))
            parole++;
        // vocali
        l = tolower(frase[i]);
        // if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
        //    conto_vocali++;

        if (isalpha(l)) { // SE abbiamo una lettera dell'alfabeto
            // entro qui solo se ho una lettera
            if (strchr("aeiou", l)) // se trovo la lettera nelle vocali
                conto_vocali++;
            else
                conto_consonanti++;
        }
    }
    printf("Lunghezza frase: %d\n", n);
    printf("Numero parole: %d\n", parole);
    printf("Numero vocali: %d\n", conto_vocali);
    printf("Numero consonanti: %d\n", conto_consonanti);

    return 0; // 0 vuol dire TUTTO BENE
}

//https://github.com/esseks/monicelli
