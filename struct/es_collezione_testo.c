#include <stdio.h>
#include <string.h>

/* vogliamo definire una struttura dati per memorizzare la nostra collezione
 * di figurine / francobolli e tenere traccia di quanti
 * ne possediamo.
 * Vogliamo scrivere poi un programma che permetta di aggiungere un elemento
 * alla nostra collezione senza avere doppioni
 * Vogliamo anche avere una funzionalita' di ricerca che ci dica
 * se un elemento con un dato nome e' presente nella nostra collezione
 */
#define N 100
#define DIM 2

typedef struct {
	char nome[N];
	int conto;
} figurina_t;
// il suffisso _t aiuta a distinguere i TIPI dai nomi VARIABILI

/*
**  c -> collezione dove cercare il mio elemento
**  n -> dimensione della collezione
**  nome -> LA STRINGA da cercare
**
**  return -1 se non la trovo
**  return posizione se la trovo
*/
int ricerca(figurina_t c[], int dim, char nome[])
{
    for(int i = 0; i < dim; i++) {
        if (strcmp(nome, c[i].nome) == 0) {
            return i;
        }
    }
    return -1;
}



/* aggiungi collezione
**  c -> collezione dove inserire
**  pos -> prima posizione libera (per semplificare gestione)
**
**  return 2 in caso di incremento conto (figurina gia' presente)
**  return 1 se inserimento fatto
**  return 0 in caso di errore
*/
int aggiungi_collezione(figurina_t c[], int pos)
{
    char nome_figurina[N];
    if (pos < 0) // valore non valido
        return 0;

    if (pos > DIM) // collezione piena (non c'e' posto per un nuovo elemento)
        return 0;

    printf("Inserisci nome della figurina: ");
    fgets(nome_figurina, N, stdin);
    int r = ricerca(c, pos + 1, nome_figurina);
    if (r == -1) {
        // non c'e', lo inserisco
        strcpy(c[pos].nome, nome_figurina);
        c[pos].conto = 1;
        return 1;
    } else {
        c[r].conto++;
        return 2;
    }
}



int main()
{
	figurina_t collezione[DIM]; 
	int pos_libera = 0;
        int r;

	// pos_libera vale 0
        for(int j = 0; j < 5; j++) {
            r = aggiungi_collezione(collezione, pos_libera);
            if (r == 1)
                pos_libera++;
            if (r == 0) {
                printf("ERRORE");
                break;
            }
        }

	// stampa
	for(int i= 0; i < pos_libera; i++){
		printf("figurina: %s : conto : %d\n", collezione[i].nome, collezione[i].conto);
	}

	return 0;
}
