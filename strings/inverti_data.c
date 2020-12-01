/*
il programma riceve in input una stringa che rappresenta una data nella forma
MM/GG/AA  -> GG/MM/AA
*/
#include <stdio.h>

int main()
{
    //              01234567
    char data[9];
    //                    01234567
    char nuova_data[9];

    scanf("%8s", data);

    nuova_data[0] = data[3];
    nuova_data[1] = data[4];
    nuova_data[2] = data[5]; // '/'
    nuova_data[3] = data[0];
    nuova_data[4] = data[1];
    nuova_data[5] = data[2];
    nuova_data[6] = data[6];
    nuova_data[7] = data[7];
    nuova_data[8] = '\0';

    printf("%s\n", nuova_data);
    return 0;
}