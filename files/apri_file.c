#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    char nome_file[] = "prova.txt";
    int i = 42;

    fp = fopen(nome_file, "w");
    if (fp != NULL) {
        fprintf(fp, "ciao Pino, come stai? %d\n", i);

        fclose(fp);
    }
    return EXIT_SUCCESS;
}
