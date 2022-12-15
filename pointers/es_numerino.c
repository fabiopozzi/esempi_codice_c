/*
Si scriva una funzione alfabeto_numerino con prototipo
char *alfabeto_numerino( char s[] ) che riceva come parametri
una stringa s
La funzione deve restituire il puntatore
ad una nuova stringa ottenuta ripetendo
n volte ogni cifra che compone la stringa

NB: usare atoi() per convertire la cifra in un numero
Esempio
"1 4 6 " -> "14444666666"
*/
#include<stdio.h>
#include<stdlib.h>

char *alfabeto_numerino( char s[] )
{
    int i = 0;
    int j = 0;
    int val;
    int dim = 10;

    char *ris = (char *)malloc(dim * sizeof(char));
    if (ris == NULL)
        return NULL;

    while(s[i] != '\0') {
        val = atoi(&s[i]);
        //printf("%d ", val);
        for(int k = 0; k < val; k++) { // k volte ripeto un carattere
            ris[j] = s[i];
            j++;
            if (j == dim) {
                dim = dim * 2;
                ris = (char *)realloc(ris, dim * sizeof(char));
                if (ris == NULL)
                    return NULL;
                printf("ho riallocato a dimensione %d", dim);
            }
        }
        i = i + 2;
    }
    return ris;
}

int main()
{
    char s[] = "1 4 6 8 9 4 3 2 1"; // 14444666666
    char *p;

    p = alfabeto_numerino(s);
    printf("%s", p);
    free(p);
}