/*
  Legge interi da un file binario,
  fino alla fine del file.
  cc Paolo Liberatore
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fd;
    int x;
    int res;

    /* apre il file in lettura */
    fd = fopen("test.dat", "r");
    if (fd == NULL) {
        perror("Errore in apertura del file");
        exit(1);
    }

    /* ciclo di lettura */
    while (1) {
        res = fread(&x, sizeof(int), 1, fd);
        if (res != 1)
        break;

        printf("%d\n", x);
    }

    /* chiude il file */
    fclose(fd);

    return 0;
}
