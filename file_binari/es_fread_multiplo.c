/*
  Lettura multipla da un file binario,
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fd;
    int x[3];
    int res;

    /* apre il file in lettura */
    fd = fopen("test.dat", "rb");
    if (fd == NULL) {
        perror("Errore in apertura del file");
        exit(1);
    }

    /* ciclo di lettura */
    while (1) {
        res = fread(x, sizeof(int), 3, fd);
        if (res != 3)
            break;

    }

    printf("%d\n", x[0]);
    printf("%d\n", x[1]);
    printf("%d\n", x[2]);
    /* chiude il file */
    fclose(fd);

    return 0;
}
