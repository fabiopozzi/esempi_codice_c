/* 18.22 */
/* 18.34  12 minuti */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *numerino(char orig[])
{
    int i = 0, j = 0;
    int val;
    int dim = 0;
    char *ris;

    for(int i = 0; i < strlen(orig); i++) {
        if (isdigit(orig[i])) {
            dim += atoi(&orig[i]);
        }
    }
    printf("numero caratteri %d\n", dim);
    dim++; // terminatore
    ris = (char *)malloc(dim * sizeof(char));
    if (ris == NULL)
        exit(1);

    while(orig[i] != '\0')
    {
        if (isdigit(orig[i])) {
            val = atoi(&orig[i]);
            printf("val vale %d\n", val);
            // posso spostarlo in una funzione dedicata
            for(int k = 0; k < val; k++) {
                ris[j] = orig[i];
                j++;
                printf("j=%d\n", j);
            }
        }
    }
    ris[j] = '\0';
    return ris;
}
int main()
{
    char s1[] = "1 2 5 4 ";

    char *r = numerino(s1);
    printf("%s\n", r);
    free(r);
    return 0;
}
