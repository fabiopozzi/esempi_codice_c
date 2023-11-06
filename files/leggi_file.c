#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main()
{
    FILE* fp;
    char nome_file[] = "prova.txt";
    char stringa[N];
    int i = 42;
    float n;

    fp = fopen(nome_file, "r");
    if (fp != NULL) {
        fgets(stringa, N, fp);
        stringa[strcspn(stringa, "\n")] = '\0';
        stringa[strlen(stringa)-1] = '\0'; // non sicura
        //fscanf(fp, "%s", stringa); // ci fermiamo al primo spazio
        //fscanf(fp, "%[^\n]", stringa); // leggiamo tutta la riga (buffer overflow)

        int i = 0;
        int c;
        // leggo una riga
        //(ma se il file finisce sono problemoni)
        while ((c = fgetc(fp)) != '\n') {
            stringa[i] = c;
            i++;
            if (i == (N-1)) {
                stringa[i] = '\0';
                break;
            }
        }

        i = 0;
        // leggo una riga e gestisco la fine del file
        do {
            c = fgetc(fp);
            if (c != '\n' && c != EOF) {
                stringa[i] = c;
                i++;
                if (i == N-1)
                    break;
            }
        } while (c != '\n' && c != EOF);

        stringa[N-1] = '\0';
        printf("stringa vale -%s-\n", stringa);
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
