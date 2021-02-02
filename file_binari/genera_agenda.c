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

	fp = fopen("agenda.bin", "wb");

	for(int i = 0; i < 10; i++) {
		scanf("%19s", a.cognome);
		scanf("%19s", a.nome);
		scanf("%d", &a.giorno);
		scanf("%d", &a.mese);
		scanf("%d", &a.anno);
		fwrite(&a, sizeof(a), 1, fp);
	}
	fclose(fp);
	return 0;

}
