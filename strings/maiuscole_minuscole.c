#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "ziao";
    char s2[] = "miao";

    int n = strcmp(s1, s2);
    //strcmp() -> 0 se sono uguali, < 0 se s1 viene prima di s2, > 0 se s1 viene dopo s2
    if (n == 0) { // sono uguali??
        printf("sono uguali\n");
    } else {
        if (n < 0) {
            printf("s1 in ordine alfabetico (E ASCII) viene prima di s2\n");
        } else {
            printf("s1 in ordine alfabetico (E ASCII) viene dopo di s2\n");
        }
        printf("sono diverse\n");
        printf("strcmp ha restituito %d\n", n);
    }
    char c = getchar();
    /*  Questa lettera è maiuscola??      ->        if(isupper(c))  */
    if (isupper(c)) {
        printf("vero\n");
    } else {
        printf("falso\n");
    }
    /*  Questa lettera è minuscola??      ->        if(islower(c))  */
    char d = getchar();
    if (islower(d)) {
        printf("ho una lettera minuscola\n");
    } else {
        // qui non so se è una lettera oppure no
        printf("qualsiasi cosa sia, non è minuscolo\n");
    }

    // Questo carattere è una lettera??    ->        if(isalpha(c))
    if (isalpha(d)) {
        printf("lettera\n");
    } else {
        printf("non e' una lettera\n");
    }

    char e = getchar();
    if (isalpha(e)) { // c è una lettera?
        if (islower(e)) { // c è minuscola?
            printf("lettera minuscola\n");
            char n = toupper(e); // converto la lettera in maiuscolo
            printf("nuova lettera %c\n", n);
        } else { // no non è minuscola, è una lettera maiuscola
            printf("lettera maiuscola\n");
            char n = tolower(e); // converto la lettera in minuscolo
            printf("nuova lettera %c\n", n);
        }
    } else {
        // caratteri non alfabetici (cifre [0,1,2,3,4,5,6,7,8,9], simboli)
        printf("non e' una lettera\n");
    }
    /* CONVERTIRE una lettera
        minuscolo -> maiuscolo        toupper('a')
        maiuscolo -> minuscolo        tolower('A')
    */

    return 0;
}
