#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned char cifra1;
	unsigned char r[4] = {0};
	int i;

	printf("inserisci cifra decimale");
	scanf("%hhu", &cifra1);

	if (cifra1 < 5) {
		// decimale to binario
		i = 0;
		while(cifra1 != 0) {
			printf("Cifra vale: %hhu\n", cifra1);
			r[i] =  cifra1 % 2;
			i++;
			cifra1 = cifra1 / 2;
		}
		for (i = 3; i >= 0; i--) {
			printf("%hhu ", r[i]);
		}
		printf("\n");

	} else {
		cifra1 = 9 - cifra1; // complemento a 9

		i = 0;
		while(cifra1 != 0) {
			printf("Cifra vale: %hhu\n", cifra1);
			r[i] =  cifra1 % 2;
			i++;
			cifra1 = cifra1 / 2;
		}
		for (i = 3; i >= 0; i--) {
			// inverti ogni bit
			if (r[i]){
				r[i] = 0;
			} else {
				r[i] = 1;
			}
			printf("%hhu ", r[i]);
		}
	}
}
