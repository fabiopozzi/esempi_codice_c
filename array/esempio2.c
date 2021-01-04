#include <stdio.h>
int main()
{
    char prova[10];
    int vett[10];
    scanf("%9s", &prova[0]); // s come STRINGA  =  TANTI CHAR

    printf("l'iniziale vale %c\n", prova[0]);
    if (prova[0] == 'A') {
        printf("ciao");
    } else {
        printf("il tuo nome non inizia con la A e quindi mi stai antipatico");
    }

    return 0;
}