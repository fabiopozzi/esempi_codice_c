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
	agenda_t a[10];

	fp = fopen("agenda.bin", "wb");

	for(int i = 0; i < 2; i++) {
		scanf("%19s", a[i].cognome);
		scanf("%19s", a[i].nome);
		scanf("%d", &a[i].giorno);
		scanf("%d", &a[i].mese);
		scanf("%d", &a[i].anno);
	}
	fwrite(a, sizeof(agenda_t), 2, fp);

	fclose(fp);
	return 0;

}
