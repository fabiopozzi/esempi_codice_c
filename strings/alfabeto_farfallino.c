/*
Data una stringa, stamparla in alfabeto farfallino.
Consiste nel raddoppiare ogni vocale con l'aggiunta di una f interposta; quindi a
diventa afa, e diventa efe, e così via.
Esempio.
"ciao" --> "cifiafaofo"
"alfabeto farfallino" --> "afalfafabefetofofafarfafallifinofo"
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char stringa[100];
    char vocali[] = "aeiouAEIOU";
    char risultato[300];

    int j = 0;

    printf("inserisci stringa: ");
    scanf("%99s", stringa);
    //fgets

    for(int i = 0; i < strlen(stringa); i++) {
       //if (stringa[i] == 'a' || stringa[i] == 'e'|| stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u')
       if(strchr(vocali, stringa[i]) != NULL) // e' una vocale
       {
           risultato[j] = stringa[i];
           risultato[j+1] = 'f';
           risultato[j+2] = stringa[i];
           j=j+3;
	   //oppure
           /* risultato[j] = stringa[i]; */
	   /* j++; */
           /* risultato[j] = 'f'; */
	   /* j++; */
           /* risultato[j] = stringa[i]; */
	   /* j++; */
           //printf("%c%c%c", stringa[i], 'f', stringa[i]);
       } else {
           risultato[j] = stringa[i];
           j++;
           //printf("%c", stringa[i]);
       }
    }
    risultato[j] = '\0';
    printf("%s\n", risultato);
       //printf("\n");
    return 0;
}
