#include <stdio.h>

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
    printf("Ti chiami %s\n", nome);
    // N.B. c'e' qualcosa da sistemare?
}