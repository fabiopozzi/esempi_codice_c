#include <stdio.h>
#include <string.h>

/* definizione struttura dati */
struct studente {
    int classe;
    int matricola;
    int eta;
    char nome[100];
};

struct punto {
	int x;
	int y;
};

void stampa_studente(struct studente tmp)
{
    printf("Nome: %s", tmp.nome);
    printf("classe: %d, eta %d, matricola %d\n",
           tmp.classe, tmp.eta, tmp.matricola);
}

int main()
{
    struct studente s = { 4, 12345, 40, "boh"};
    struct studente gianni;

    s.classe = 3; // normale accesso al campo classe

    gianni = s; // copia

    strcpy(gianni.nome, "Gianni");
    /* for(int i = 0; i < 10; i++) */
    /*     printf("%c ", s.nome[i]); */

    /* s.eta = 42; */
    /* s.matricola = 1234567; */

    stampa_studente(s);
    stampa_studente(gianni);
    return 0;
}
