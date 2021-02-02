/*
Data una stringa contenente nome ed eta' separate da ',' stampare i dati separatamente
Esempio
Stringa: "Rossi,46"

nome
Rossi
012345678

eta
46
012345678

Nome: Rossi
Eta': 46
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char stringa[] = "Rossi,46";

    char nome[100];
    char eta[100];
    int i;
    int j;
    int l;

    int pos = strcspn(stringa, ",");

    for(i = 0; i < strlen(stringa); i++) {
        if (stringa[i] == ',') {
            pos = i;
            break;
        }
    }

    if (stringa[pos] == '\0') {
        printf("errore, stringa senza virgola");
        return -1;
    } else {
        for(i = 0; i < pos; i++){
            nome[i] = stringa[i];
        }
        nome[i] = '\0';
        l = strlen(stringa) - pos;

        for(i = 0; i < l; i++){
            j = i + pos + 1;
            eta[i] = stringa[j];
        }
        eta[i] = '\0';
        printf("posizione della virgola %d\n", pos);
        printf("%s\n", nome);
        printf("%s\n", eta);
    }
    return 0;
}
