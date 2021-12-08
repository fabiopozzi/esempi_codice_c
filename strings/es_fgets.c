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
    // si veda https://man.openbsd.org/strcspn.3
    // perche' non va bene usare
    // nome[strlen(nome) - 1] = '\0';
    // nel caso in cui la stringa sia vuota (ovvero inizi con '\0') strlen mi restituirà 0,
    // quindi andrei ad eseguire nome[-1] = '\0' che è errato
    // strcspn se non trova la stringa cercata mi restituisce la posizione
    // del terminatore di stringa, e questo gestisce tutti i casi possibili
    printf("Ti chiami -%s-\n", nome);
}
