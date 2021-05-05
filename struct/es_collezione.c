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
int ricerca(figurina_t c[], int n, char nome[])
{
	for(int i = 0; i < n; i++) {
		if (strcmp(c[i].nome, nome) == 0) {
			// l'ho trovato!!
			return i;
		}
	}
	// se arrivo qui vuol dire che non l'ho trovata
	return -1;
}


// in questo modo *pos mi indica la prima posizione libera
// in cui posso aggiungere una nuova figurina
void aggiungi_collezione(figurina_t c[], int *pos)
{
	char nome_tmp[N];

	printf("inserisci il nome della figurina: ");
	scanf("%99s", nome_tmp);

	int posaman = ricerca(c, *pos, nome_tmp);

	if (posaman >= 0){
		// ce l'ho già (ed e' in posizione posaman)
		c[posaman].conto++; // incremento il numero
		printf("ne ho gia' una\n");
	} else {
		// non ce l'ho, quindi ne inserisco una nuova
		strcpy(c[*pos].nome, nome_tmp);
		c[*pos].conto = 1;
		(*pos) += 1; // quindi aggiorno la posizione nel mio array delle figurine
	}

}

int main()
{
	figurina_t collezione[200]; // ARRAY di 200 figurine
	int quante_figurine_ho = 0;

	// quante_figurine_ho vale 0
	aggiungi_collezione(collezione, &quante_figurine_ho);
	// quante_figurine_ho == 1
	aggiungi_collezione(collezione, &quante_figurine_ho);
	// quante_figurine_ho == 2
	aggiungi_collezione(collezione, &quante_figurine_ho);
	// quante_figurine_ho == 3
	// stampa
	for(int i= 0; i < quante_figurine_ho; i++){
		printf("figurina: %s : conto : %d\n", collezione[i].nome, collezione[i].conto);
	}

	return 0;
}
