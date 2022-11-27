#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp, *fp1;
    char nome_file[] = "prova.txt";
    int i = 42;

    fp = fopen(nome_file, "w");

    if (fp != NULL) {
        //fprintf(fp, "SONO UNA CAROTA %d\n", i);
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
