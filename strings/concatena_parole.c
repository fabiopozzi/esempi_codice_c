#include<stdio.h>
#include<string.h>

#define MAX_PAROLE 10
#define MAX_LUNG_PAROLA 100


int main()
{
    int n;
    char parola[MAX_LUNG_PAROLA];
    char frase[MAX_PAROLE * MAX_LUNG_PAROLA] = {0};
    int len = 0;


    do {
      printf("inserire numero parole (max 10):");
      scanf("%d", &n);
    } while( n < 0 || n > MAX_PAROLE);

    for(int i = 0; i < n; i++){
        printf("inserisci parola");
        scanf("%99s", parola);
        strcat(frase, parola);
        strcat(frase, " "); // aggiungo lo spazio
    }

    printf("la frase e' %s\n", frase);
    printf("la frase e' lunga %lu\n", strlen(frase) - 1);

    return 0;
}
