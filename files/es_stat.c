/**
 * Esempio di programma C in grado di stampare dimensione, permessi, date di creazione ed ultima modifica di un
 * dato file.
 * Adattato da https://codeforwin.org/2018/03/c-program-find-file-properties-using-stat-function.html
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>


void stampaProprietaFile(struct stat stats);


int main()
{
    char percorso_file[100];
    struct stat stats;

    printf("Inserisci nome file o path completo: ");
    scanf("%s", percorso_file);


    // stat() restituisce 0 se e' andato tutto bene,
    // altrimenti restituisce -1
    // (se non e' stato in grado di ottenere le proprieta' di un file)
    if (stat(percorso_file, &stats) == 0) {
        stampaProprietaFile(stats);
    } else {
        printf("Impossibile ottere le proprieta' del file %s.\n", percorso_file);
    }

		return 0;
}


void stampaProprietaFile(struct stat stats)
{
    struct tm *datetime;

    printf("\nPermessi di accesso al file: ");
    if (stats.st_mode & R_OK)
        printf("lettura ");
    if (stats.st_mode & W_OK)
        printf("scrittura ");
    if (stats.st_mode & X_OK)
        printf("esecuzione");

    // Dimensione file
    printf("\nDimensione file: %ld", stats.st_size);

    // Data di creazione (in secondi dal 1 gennaio 1900)
    // Stampa convertendo in formato data "normale"
    // tm_mday = giorno
    // tm_mon = mese
    // tm_year = anno (a partire dal 1900)
    // tm_hour, tm_min, tm_sec = ora, minuti, secondi
    datetime = gmtime(&stats.st_ctime);
    printf("\nCreated on: %d-%d-%d %d:%d:%d", datetime->tm_mday, datetime->tm_mon + 1, datetime->tm_year + 1900,
                                              datetime->tm_hour, datetime->tm_min, datetime->tm_sec);

    // Data e ora di ultima modifica
    datetime = gmtime(&stats.st_mtime);
    printf("\nModificata il: %d-%d-%d %d:%d:%d", datetime->tm_mday, datetime->tm_mon + 1, datetime->tm_year + 1900,
                                              datetime->tm_hour, datetime->tm_min, datetime->tm_sec);

}
