#include <stdio.h>

typedef struct {
	char cognome[20];
	char nome[20];
	int giorno;
	int mese;
	int anno;
} agenda_t;

int main()
{
	FILE *fp;
	agenda_t a;

	fp = fopen("agenda.bin", "rb");

	while(fread(&a, sizeof(a), 1, fp)) {
		printf("nome: %s\t %s\t nato il %d/%d/%d\n",
			   a.nome, a.cognome, a.giorno, a.mese, a.anno);
	}
	fclose(fp);
	return 0;
}
