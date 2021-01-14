/*
Data una stringa contenente nome ed eta' separate da ',' stampare i dati separatamente
Esempio
Stringa: "Rossi,27"
Nome: Rossi
Eta': 27
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char stringa[] = "Rossi,46";

    char nome[100];
    char eta[100];

    int pos = strcspn(stringa, ",");
    int i;

    if (stringa[pos] == '\0') {
        printf("errore, stringa senza virgola");
        return -1;
    } else {
        for(i = 0; i < pos; i++){
            nome[i] = stringa[i];
        }
        nome[i] = '\0';

        printf("posizione della virgola %d\n", pos);
        printf("%s\n", nome);
    }
    return 0;
}
