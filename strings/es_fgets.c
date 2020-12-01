#include <stdio.h>
#include <string.h>

#define N 50

int main()
{
    char nome[N];
    printf("Inserisci il tuo nome e il tuo cognome: ");
    /*
    le costanti stdin, stdout, stderr sono definite in stdio.h
    std == standard
    stdin = INPUT
    stout = OUTPUT
    stderr = MESSAGGI ERRORE
    */
    fgets(nome, N, stdin);

    /*
    0 è un numero
    '\0' come carattere io sto dicendo che non voglio il carattere '0'
    ma voglio il codice ASCII 0 che è equivalente al valore numerico 0
    'A' === 65
    '\0' === 0
    */
    nome[strcspn(nome, "\n")] = '\0';
    printf("Ti chiami -%s-\n", nome);
    // N.B. c'e' qualcosa da sistemare?
}