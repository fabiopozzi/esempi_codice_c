#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int x;
    char prova[] = "123";

    sscanf(prova, "%d", &x); // ho una versione alternativa di atoi()
    printf("prova vale %d\n", x);

    char giorno_settimana[20], mese[20];
    int giorno_mese, anno;
    char data[] = "Giovedì cinque Novembre";
    int n;

    n = sscanf(data, "%s %d %s %d", giorno_settimana, &giorno_mese, mese, &anno);
    if (n == 4) {
        printf("n vale %d\n", n);
        // anno ha dentro un valore a caso
        printf("il %d %s, %d era di %s\n", giorno_mese, mese, anno, giorno_settimana);
    } else {
        printf("errore \n");
    }

    return 0;
}
