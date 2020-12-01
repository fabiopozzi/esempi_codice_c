#include <stdio.h>
#include <string.h>

int main()
{
    char riga[10];
    int i;

    printf("inserisci una riga (a capo per terminare): ");
    /* lettura di una riga contenente più parole:
        opzione 1: uso di scanf
        pro: è una sola riga
        contro: devo sapere quanto è grande la mia riga ed inserire il numero nella stringa
        contro: %9[^\n]%*c non è proprio facile da ricordare
    */
    scanf("%9[^\n]%*c", riga);
    /*  opzione 2: uso di fgets + strcspn
        pro: è sempre uguale indipendentemente dalla lunghezza della stringa.
             devo solo passare il numero giusto a fgets (la dimensione della stringa)
             senza pensare al terminatore o ad altro
        contro: sono 2 istruzioni
        contro: non si usa mai strcspn()
    */
    fgets(riga, 10, stdin);
    //rimuovere il carattere \n dalla mia stringa letta con fgets
    riga[strcspn(riga, "\n")] = 0;

    if (strcmp(riga, "fabio") == 0) {
        printf("ciao fabio!");
    }

    for (i = 0; i < strlen(riga); i++) {
        printf("-%c-", riga[i]);
    }

    return 0;
}