#include <stdio.h>
#include <stdlib.h>

struct punto {
    int x;
    int y;
    int z;
};

int main() {
    FILE *fd;
    struct punto p[3];
    int res;

    /* apre il file in lettura */
    fd = fopen("test.dat", "rb");
    if (fd == NULL) {
        perror("Errore in apertura del file");
        exit(1);
    }

    /* ciclo di lettura */
    while (1) {
        res = fread(&p, sizeof(struct punto), 1, fd);
        if (res != 1)
            break;

        printf("coord. punto x:%d y:%d z:%d\n", p[0].x, p[0].y, p[0].z);
    }

    /* chiude il file */
    fclose(fd);

    return 0;
}
