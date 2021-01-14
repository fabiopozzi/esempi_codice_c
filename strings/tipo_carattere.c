#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;

    do {
        printf("inserisci valore corrispondente a numero del codice ascii: ");
        scanf("%d", &n);
    }while( n < 0 || n > 255);

    if (isprint(n)) {
        if(islower(n)) {
            printf("il codice corrisponde ad una lettera minuscola %c\n", (char)n);
        } else if(isupper(n)) {
            printf("il codice corrisponde ad una lettera maiuscola %c\n", (char)n);
        } else if(isdigit(n)) {
            printf("il codice corrisponde alla cifra %c\n", (char)n);
        } else if(isspace(n)) {
            printf("il codice corrisponde ad uno spazio\n");
        } else if(ispunct(n)) {
            printf("il codice corrisponde ad un simbolo di punteggiatura %c\n", (char)n);
        }
    } else {
        printf("il codice inserito non corrisponde ad un carattere stampabile\n");
    }

    return 0;
}
