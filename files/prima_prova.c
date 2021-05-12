#include <stdio.h>

int leggi_da_file()
{
	FILE *fp;
	int val = 200;

	// APRIRE FILE
	fp = fopen("/tmp/pippo.txt", "r");
	if (fp == NULL) {
		// FAIL
		printf("Errore fopen\n");
		return -1;
	}
	fscanf(fp, "%d", &val);

	char c = fgetc(fp);
	printf("Hai vinto %d caramelle al caffe\n", val);

	// faccio roba
	fclose(fp);

	return 0;
}


int main()
{
	// 1000000
	leggi_da_file();
	return 0;
}
