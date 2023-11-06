#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char cognome[20];
	char nome[20];
	int giorno;
	int mese;
	int anno;
} agenda_t;

agenda_t *leggi_da_file_binario(int n) {
  agenda_t *pa;
  FILE *fp;

  pa = (agenda_t *)malloc(n * sizeof(agenda_t));

  fp = fopen("agenda.bin", "rb");
  if (fp != NULL) {

    /* fseek(fp, 0, SEEK_SET); // mi sposto di 0 byte dopo l'inizio del file */
    fseek(fp, -1 * (sizeof(agenda_t)), SEEK_END); // mi sposto all'ultimo record
    fread(pa, sizeof(agenda_t), 1, fp); 
    if(feof(fp)) {
      printf("IL FILE e' FINITO\n");
    }
    fclose(fp);

    return pa;
  } else {
    return NULL;
  }
}
int main()
{
	agenda_t *a;
	a = leggi_da_file_binario(2);
	
	printf("nome: %s\n", a[0].nome);
	printf("nome: %s\n", a[1].nome);
	free(a);
	return 0;
}
