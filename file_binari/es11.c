/*
** Scrivere un programma che effettui la creazione
di un file binario e la sua successiva lettura.
Il file binario dovrà contenere i dati relativi
alle partite di calcio: il nome della squadra ospitante
(max 20 caratteri), il nome della squadra ospite
(max 20 caratteri) e il punteggio di ogni partita.
Permettere lettura squadre, modifica e stampa valori
nel file.
 */
#include<stdio.h>
#include<string.h>


typedef struct {
    char squadra_casa[20];
    char squadra_ospite[20];
    int punteggio_casa;
    int punteggio_ospite;
} partita_t;


int modifica_partita_file(FILE *fp, int num_partita)
{
	partita_t p;
	// mi posiziono all'inizio della partita da modificare
    fseek(fp, num_partita * sizeof(partita_t), SEEK_SET);

    // leggo la partita da modificare
    fread(&p, sizeof(partita_t), 1, fp);

    //modifica punteggio in variabile p
    printf("inserisci punteggio casa: ");
    scanf("%d", &p.punteggio_casa);
    printf("inserisci punteggio ospite: ");
    scanf("%d", &p.punteggio_ospite);

    //riposizionare
	fseek(fp, -1 * sizeof(partita_t), SEEK_CUR);

    // sovrascrivo con il valore aggiornato
    return fwrite(&p, sizeof(partita_t), 1, fp);
}

void stampa_partita(int i, partita_t p)
{
    printf("partita %d: %s %d - %d %s\n",
        i, p.squadra_casa, p.punteggio_casa,
        p.punteggio_ospite, p.squadra_ospite);
}

int leggi_partita_file(FILE *fp, partita_t *p)
{
    return fread(p, sizeof(partita_t), 1, fp);
}

int main()
{
    partita_t p;
    char risposta = 'Y';
    FILE *fp;
	int num_partita;
	int i = 0;

    fp = fopen("dati.dat", "r+b");
    if (fp == NULL){
        perror("fopen1");
        return -1;
    }

	// stampa elenco partite
    while(leggi_partita_file(fp, &p)){
        stampa_partita(i, p);
		i++;
    }

    if(truncate(...)) {
        // gestione errore
        perror("truncate");
    }

	// chiedi quale partita modificare
	do {
		  printf("Quale partita vuoi modificare? ");
		  scanf("%d", &num_partita);
	} while (num_partita < 0 || num_partita >= i);

	// fai modifica
	modifica_partita_file(fp, num_partita);

	// ritorna ad inizio file e stampa file modificato
	rewind(fp);
	i = 0;
    while(leggi_partita_file(fp, &p)){
        stampa_partita(i, p);
		i++;
    }
	// posso riscrivere queste 4 righe in una nuova funzione?

    fclose(fp);
    return 0;
}
