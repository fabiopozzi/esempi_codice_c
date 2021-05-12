#include <stdio.h>
#include <string.h>

typedef struct {
	int num_studenti;
	int num_promossi;
	float media;
} stats_t;

stats_t leggi_file(FILE *fp)
{
	char riga[12];
	int n;
	int matricola, voto;
	stats_t tmp = {0};

	fscanf(fp, "%d", &n);
	/* fgets(riga, 12, fp); */
	/* sscanf(riga, "%d", &n); */
	for(int i = 0; i < n; i++){
		fscanf(fp, "%d %d", &matricola, &voto);
		if ((voto >= 18) && (voto <= 30)) {
			tmp.num_promossi++;
			tmp.media += voto;
		}
	}
	tmp.media = tmp.media / tmp.num_promossi;
	tmp.num_studenti = n;
	return tmp;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	stats_t pippo;

	if (argc < 2) {
		printf("manca argomento\n");
		return -1;
	}
	if (strcmp("stat", argv[1]) == 0) {
		  fp = fopen("registro.txt", "r");
		  if (fp == NULL) {
			printf("ERRORE FOPEN");
			return -1;
		  }
		  pippo = leggi_file(fp);
		  printf("numero promossi %d", pippo.num_promossi);
          printf("media voti %.1f", pippo.media);
          fclose(fp);
	}
}
