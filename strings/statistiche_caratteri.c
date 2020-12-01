/*
 il programma riceve in input una stringa e conta:
 il numero di caratteri alfabetici,
 il numero di cifre,
 il numero di simboli
 presenti in essa e li stampa a video
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //char esempio[] = "Qu3st4 e' un4 str1ng4. l33t";
    char esempio[100];
    int lettere = 0;
    int cifra = 0;
    int simbolo = 0;

    printf("inserisci stringa: ");
    scanf("%99s", esempio);
    // voglio attraversare la stringa
    for (int i = 0; i < strlen(esempio); i++) {
        // distinguiamo le lettere dal resto
        if (isalpha(esempio[i])) {
            lettere++;
        }
        // se non e' una lettera puo' essere una cifra oppure un simbolo
        if (isdigit(esempio[i])) {
            // se e' una cifra
            cifra++;
        } else {
            // se non e' una lettera, non e' una cifra, allora e' un simbolo
            simbolo++;
        }
    }
    printf("\nnumero lettere %d\nnumero cifre %d\nnumero simboli %d\n", lettere, cifra, simbolo);

    return 0;
}