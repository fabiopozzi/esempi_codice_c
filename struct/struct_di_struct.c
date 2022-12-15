#include<stdio.h>
#include <string.h>

struct persona {
	char nome[10];
	char cognome[10];
};

struct automobile {
	char modello[10];
	struct persona proprietario;
	char targa[10];
};

struct automobile nuova_auto()
{
	struct automobile tmp;

	strcpy(tmp.modello, "TOYOTA");
	strcpy(tmp.proprietario.nome, "Mario");
	strcpy(tmp.proprietario.cognome, "Verdi");
	strcmp(tmp.targa, "AG123GG");

	return tmp;
}

void stampa_auto(struct automobile a)
{
	printf("Modello: %s, targa %s", a.modello, a.targa);
	printf("proprietario: %s %s", a.proprietario.nome, a.proprietario.cognome);
}

int main() {
	struct automobile auto1 = {"VW Polo", {"Mario", "Rossi"}, "EG123PN"};

	struct automobile auto2 = nuova_auto();

	stampa_auto(auto1);
	stampa_auto(auto2);

	return 0;
}
