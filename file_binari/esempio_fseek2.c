#include <stdio.h>

int main() {
    FILE* fp = fopen("sample.txt", "r");

    // Sposta l'indice nel file (il puntatore) all'offset 6 a partire da inizio file
    fseek(fp, 6, SEEK_SET);

    char buffer[512];

    // leggi dal file usando fread()
    fread(buffer, sizeof(buffer), sizeof(char), fp);

    printf("%s\n", buffer);

    fclose(fp);
    return 0;
}
