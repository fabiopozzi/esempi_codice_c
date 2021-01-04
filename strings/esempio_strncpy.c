#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
int main()
{
    long val;
    int lung = 4;
    char variabile_a_caso[80] = "ciao";
    strncpy(variabile_a_caso, "9999239458868", N);
    variabile_a_caso[N] = '\0';
    // prova con "9891234", "9898aaaa"   "9899   "
    val = atol(variabile_a_caso);
    // come faccio a sapere se c'è stato un errore??
    printf("%s = %ld\n", variabile_a_caso, val);

    return (0);
}