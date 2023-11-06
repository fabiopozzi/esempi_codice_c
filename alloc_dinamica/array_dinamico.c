#include<stdlib.h>
#include<stdio.h>
/*
Si scriva una funzione int *array_dinamico(int n) in grado di allocare dinamicamente un array in grado di contenere n interi e restituisca il puntatore al primo elemento.
Si implementino controlli per gestire il caso in cui n non sia un valore valido.
In caso l'allocazione fallisca o n non abbia valore valido la funzione deve restituire NULL.
*/
int *array_dinamico(int n)
{
    int *p;

    if (n <= 0) {
        printf("Hai inserito una dimensione non valida\n");
        return NULL;
    }

    p = (int *)malloc(sizeof(int) * n);
    if (p == NULL) {
        printf("ALLOCAZIONE FALLITA\n");
        return NULL;
    }
    return p;
}


    

int main()
{
    int *puntatore;

    puntatore = array_dinamico(10);
    if (puntatore != NULL) {
        puntatore[0] = 10;
        puntatore[1] = 20;
    }
    printf("%d %d\n", puntatore[0], puntatore[1]);
    free(puntatore);

    puntatore = array_dinamico(-20);
    printf("puntatore vale %p", puntatore);

    return 0;
}
