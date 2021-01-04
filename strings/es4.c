/*
Si scriva un programma che chieda all'utente il numero di parole da leggere,
legga ognuna delle parole (una per una),
calcoli la lunghezza di ogni parola ed infine concateni le parole creando una frase,
stampando infine la lunghezza totale della frase.
*/
#include <stdio.h>
#include <string.h>

#define MAX_PAROLA 10
#define MAX_STR 20
int main()
{
    int n;
    int lunghezza_totale = 0;
    int tronc = 0;
    char parola[MAX_PAROLA] = { 0 };
    char frase[MAX_STR] = { 0 };

    printf("num parole: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("parola %d: ", i + 1);
        scanf("%9s", parola);
        lunghezza_totale += strlen(parola);
        // spazio disponibile:
        // dimensione_array - lunghezza_stringa_gia_copiata - 1(terminatore)
        //strncat(frase, parola, MAX_STR - strlen(frase) - 1);
        /* oppure
        strncat(frase, parola, sizeof(frase) - strlen(frase) - 1);
        */
        /* versione con controllo */
        if (strlen(parola) + 1 > MAX_STR - strlen(frase)) {
            printf("stringa troncata, quindi lunghezza frase 19\n");
            tronc = 1;
        }
        strncat(frase, parola, MAX_STR - strlen(frase) - 1);

    }
    printf("frase: -%s-\n", frase);
    if (!tronc) {
        printf("lunghezza frase: %d\n", lunghezza_totale);
    }
}
