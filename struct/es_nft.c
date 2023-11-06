#include <stdio.h>
#include <string.h>
/**
  Vogliamo definire una struttura dati per memorizzare la nostra collezione di NFT e tenere traccia di quanti ne possediamo.
Definire la struttura dati necessaria per la memorizzazione di:
- nome
- autore
- URL
- prezzo acquisto

Vogliamo scrivere poi un programma che permetta di:
- aggiungere un elemento alla nostra collezione senza avere doppioni

- ricerca che ci dica se un elemento con un dato nome e' presente nella nostra collezione
- visualizzare in formato tabellare la nostra collezione

Isolare le funzionalità in appropriate funzioni.
*/

#define L_STR 50
#define DIM_COLLEZIONE 10

#define E_COLLEZIONE_PIENA -2
#define E_DUPLICATO -1

typedef struct {
	char nome[L_STR];
	char autore[L_STR];
	char URL[L_STR*2];
	float prezzo;
} nft_t;

int ricerca(nft_t c[], int len, char nome[], nft_t *valore_trovato)
{
	int risultato = 0;

	for (int i = 0; i < len; i++) {
		if (strcmp(c[i].nome, nome) == 0) {
			risultato = 1;
			strcpy(valore_trovato->nome , c[i].nome);
			strcpy(valore_trovato->autore , c[i].autore);
			strcpy(valore_trovato->URL , c[i].URL);
			valore_trovato->prezzo = c[i].prezzo;
			break; // esco al primo match
		}
	}

	return risultato;
}

void funzione(nft_t *elemento, char nome[])
{
	char s[100];

	strcpy(elemento->nome, nome);

	printf("inserisci autore");
	fgets(s, 50, stdin);
	s[strlen(s)-1] = '\0';

	strcpy(elemento->autore, s);

	printf("inserisci url");
	fgets(s, 100, stdin);
	s[strlen(s)-1] = '\0';
	strcpy(elemento->URL, s);

	printf("inserisci prezzo");
	scanf("%f", &elemento->prezzo);
	getchar();

}

int aggiungi_elemento(nft_t c[], int *num_elementi, int dim)
{
	// passo num_elementi per indirizzo (quindi ho un puntatore al suo valore)
	// perche' dopo l'inserimento voglio poter aggiornare il valore di num_elementi
	// (incrementandolo di 1)
	// non modifichero' num_elementi se la collezione e' gia' piena
	char nome[100];
	int pos = *num_elementi;

	if (pos == dim) {
		printf("collezione piena!\n");
		return E_COLLEZIONE_PIENA;
	}

	printf("inserisci nome");
	fgets(nome, 50, stdin);
	nome[strlen(nome)-1] = '\0';
	nft_t valore_trovato;

	int trovato = ricerca(c, pos, nome, &valore_trovato);
	if(trovato) {
		printf("il nome inserito è già presente nella collezione: ");
		printf("%s %s %s %f\n", valore_trovato.nome, valore_trovato.autore, valore_trovato.URL, valore_trovato.prezzo);
		return E_DUPLICATO;
	}

	funzione(&c[pos], nome);

	*num_elementi += 1;

	return 0;
}

int main()
{
	nft_t collezione[DIM_COLLEZIONE] = {0};
	int n_collezione = 0;
        int r;

	while(1) {
            if(aggiungi_elemento(collezione, &n_collezione, DIM_COLLEZIONE)) {
                // gestione errori
                printf("ci sono stati problemi\n");
                break;
            }
            // TUTTO BENE
            printf("ho aggiunto qualcosa\n");
            printf("%s %s %s %f\n", collezione[0].nome, collezione[0].autore, collezione[0].URL, collezione[0].prezzo);
            printf("numero elementi %d\n", n_collezione);
	}
	return 0;
}
