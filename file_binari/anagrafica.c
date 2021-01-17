 /********************************************************
  * Memorizzazione di informazioni anagrafiche a blocchi
  * e ricerca
  * cc Daniele Scarpazza - www.scarpaz.com
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* tipo di informazione da memorizzare nel file */
typedef struct {
    char nome[30];
    char cognome[30];
    char codfis[16];
}
anagr;

/* funzione per l'inserimento dei dati */
int get_persona(anagr * temp) {
    char more;
    printf("Vuoi inserire una nuova persona (Y or N)? ");
    fflush(stdin);
    scanf("%c", &more);

    if (more == 'N' || more == 'n')
        return 0;
    printf("Cognome        : ");
    scanf("%s", temp->cognome);
    printf("Nome           : ");
    scanf("%s", temp->nome);
    printf("Codice fiscale : ");
    scanf("%s", temp->codfis);
    return 1;
}

/* funzione per la visualizzazione dei dati */
void mostra_persona(anagr * temp) {
    printf("Cognome        : %s\n", temp->cognome);
    printf("Nome           : %s\n", temp->nome);
    printf("Codice fiscale : %s\n", temp->codfis);
}

int main() {
    char *name = "anagra.bin";
    char *name_filtro = "filtro.bin";
    FILE *pfile = NULL, *pfiltro = NULL;

    anagr persona;
    char cerca[20] = "";

    /* apertura file di destinazione */
    if ((pfile = fopen(name, "ab")) == NULL) {
        /* errore in apertura del file */
        printf("Impossibile aprire %s in scrittura.\n", name);
        exit(1);
    }

    /* inserimento dati anagrafici delle persone */
    while (get_persona(&persona))
        /* memorizzazione su file dell'anagrafica inserita */
        fwrite(&persona, sizeof(persona), 1, pfile);

    /* chiusura file destinazione */
    fclose(pfile);

    /* apertura dello stesso file in lettura */
    if ((pfile = fopen(name, "rb")) == NULL) {
        /* errore in apertura del file */
        printf("Impossibile aprire il file");
        exit(1);
    } else {
        /* apertura del file in scrittura	*/
        if ((pfiltro = fopen(name_filtro, "wb")) == NULL)
            /* errore in apertura del file	*/
            printf("Impossibile aprire il file per la scrittura");
        else {
            printf("Quale cognome vuoi cercare? ");
            scanf("%s", cerca);

            while (fread(&persona, sizeof(anagr), 1, pfile) != 0) {
                /* verifica cognome cercato */
                if (strcmp(persona.cognome, cerca) == 0) {
                    /* visualizzazione del record desiderato */
                    mostra_persona(&persona);
                    /* scrittura sul secondo file */
                    fwrite(&persona, sizeof(anagr), 1, pfiltro);
                }
            }
            fclose(pfiltro);
        }
    }
    fclose(pfile);
    return 0;
}
