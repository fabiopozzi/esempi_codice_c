#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp;
    char nome_file[] = "prova.txt";
    char stringa[10];
    int i = 42;
    float n;

    fp = fopen(nome_file, "r");
    if (fp != NULL) {
        //fgets(stringa, 79, fp);
        //stringa[strcspn(stringa, "\n")] = '\0';
        // fscanf(fp, "%s", stringa); // ci fermiamo al primo spazio
        // fscanf(fp, "%[^\n]", stringa); // leggiamo tutta la riga (buffer overflow)
        int i = 0;
        char c;
        // leggo una riga (ma se il file finisce sono problemoni)
        while ((c = fgetc(fp)) != '\n') {
            stringa[i] = c;
            i++;
            if (i == 9)
                break;
        }
        i = 0;
        // leggo una riga e gestisco la fine del file
        do {
            c = fgetc(fp);
            if (c != '\n' && c != EOF) {
                stringa[i] = c;
                i++;
                if (i == 9)
                    break;
            }
        } while (c != '\n' && c != EOF);

        stringa[9] = '\0';
        printf("stringa vale -%s-\n", stringa);
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
