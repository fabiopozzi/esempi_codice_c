#include<stdio.h>
#include <string.h>

typedef struct {
    char nome[10];
    char cognome[10];
} persona_t;

typedef struct {
    char modello[10];
    persona_t proprietario;
    char targa[10];
} automobile_t;

/*
  scrivere le funzioni in grado di:
  - creare e restituire una nuova auto
  - stampare le informazioni su di una data auto
*/
automobile_t nuova_auto(void)
{
    automobile_t a;

    fgets(a.modello, 10, stdin);
    fgets(a.proprietario.nome, 10, stdin);
    fgets(a.proprietario.cognome, 10, stdin);
    fgets(a.targa, 10, stdin);

    return a;
}

void stampa_auto(automobile_t a)
{
    printf("modello: %s, proprietario:\n `nome: %s cognome:%s targa:%s",
           a.modello, a.proprietario.nome, a.proprietario.cognome,
           a.targa);
}

int main()
{
    // inizializzazione struct annidata
    automobile_t auto1 = {"VW Polo", {"Mario", "Rossi"}, "EG123PN"};
    automobile_t auto2 = nuova_auto();

    stampa_auto(auto1);
    stampa_auto(auto2);

    return 0;
}
