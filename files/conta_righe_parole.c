#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80

int main(void) {
	FILE* fp;
	char file[N];
	char riga[N];
	char parola[N];
	int righe = 0, parole = 0, i = 0;

	printf("Nome file: ");
	fgets(file, N, stdin);
	file[strcspn(file, "\n")] = '\0';

	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("file error");
		return EXIT_FAILURE;
	}

	while (fgets(riga, N, fp) != NULL) {
		righe++;
	}

	rewind(fp);

	while (fscanf(fp, "%s", parola) != EOF) {
		parole++;
	}

	fclose(fp);
	printf("righe:%d\n", righe);
	printf("parole:%d\n", parole);

	return 0;
}
