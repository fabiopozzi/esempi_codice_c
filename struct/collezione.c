#include <stdio.h>
#include <string.h>

/* vogliamo definire una struttura dati per memorizzare la nostra collezione
 * di schede telefoniche / figurine / francobolli e tenere traccia di quanti
 * ne possediamo.
 * Vogliamo scrivere poi un programma che permetta di aggiungere un elemento
 * alla nostra collezione senza avere doppioni
 * Vogliamo anche avere una funzionalita' di ricerca che ci dica
 * se un elemento con un dato nome e' presente nella nostra collezione
 */
#define N 50
#define DIM 10

struct collezione {
	char nome[N];
	int conto;
};


void aggiungi_collezione(struct collezione c[], int *pos);
int ricerca(struct collezione c[], int n,  char nome[]);

int main()
{
	struct collezione figurine[DIM];
	int i = 0;

	aggiungi_collezione(figurine, &i);
	aggiungi_collezione(figurine, &i);
	aggiungi_collezione(figurine, &i);

	return 0;
}

void aggiungi_collezione(struct collezione c[], int *pos)
{
	char nome[N];
	int i;

	printf("Inserisci nome: ");
	fgets(nome, N, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	i = ricerca(c, *pos + 1, nome);
	if (i > 0) {
		printf("duplicato, incremento count\n");
		// nome e' gia' nella collezione, alla posizione i
		  c[i].conto += 1;
	} else {
		printf("nuovo elemento!\n");
		// non trovato, incremento la posizione dell'ultimo elemento e lo
		// aggiungo
		  (*pos)++;
		  strcpy(c[*pos].nome, nome);
		  c[*pos].conto = 1;
	}
}

int ricerca(struct collezione c[], int n,  char nome[])
{
	for(int i = 0; i < n; i++){
		if (strcmp(nome, c[i].nome) == 0){
			return i;
		}
	}
	return -1;
}
