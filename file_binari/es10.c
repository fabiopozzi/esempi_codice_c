/*
** Scrivere un programma che effettui la creazione di un file binario e la sua successiva lettura.
Il file binario dovrà contenere i dati relativi alle partite di calcio:il nome della squadra ospitante
(max 20 caratteri), il nome della squadra ospite(max 20 caratteri) e il punteggio di ogni partita.
Stampare il contenuto del file.
 */
#include<stdio.h>
#include<string.h>


typedef struct {
    char squadra_casa[20];
    char squadra_ospite[20];
    int punteggio_casa;
    int punteggio_ospite;
} partita_t;

void leggi_partita(partita_t *p)
{
    printf("inserisci squadra casa: ");
    scanf("%19s", p->squadra_casa);
    printf("inserisci squadra ospite: ");
    scanf("%19s", p->squadra_ospite);
    printf("inserisci punteggio casa: ");
    scanf("%d", &p->punteggio_casa);
    printf("inserisci punteggio ospite: ");
    scanf("%d", &p->punteggio_ospite);
}

int scrivi_partita(FILE *fp, partita_t p)
{
    return fwrite(&p, sizeof(partita_t), 1, fp);
}

void stampa_partita(partita_t p)
{
    printf("%s %d - %d %s\n", p.squadra_casa, p.punteggio_casa, p.punteggio_ospite, p.squadra_ospite);
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

    fp = fopen("dati.dat", "wb");
    if (fp == NULL){
        perror("fopen1");
        return -1;
    }

    while(risposta != 'N') {
        leggi_partita(&p);
        scrivi_partita(fp, p);
        getchar();
        printf("vuoi inserire un'altra partita (Y/N): ");
        scanf("%c%*c", &risposta);
    }
    fclose(fp);

    fp = fopen("dati.dat", "rb");
    if (fp == NULL){
        perror("fopen2");
        return -1;
    }
    while(leggi_partita_file(fp, &p)){
        stampa_partita(p);
    }
    fclose(fp);
    return 0;
}
