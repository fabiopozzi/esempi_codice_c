#include <stdio.h>

int main()
{
	int n;
	int i = 0;

	printf("Inserisci un numero ");
	scanf("%d", &n);

	int prima_cifra = n % 10;
	/* calcola il numero di cifre decimali che il numero contiene */
	while(n > 10) {
		i++;
		n = n / 10;
	}
	printf("Prima cifra %d\n", prima_cifra);
	printf("Ultima cifra %d\n", n);
	printf("Somma prima ed ultima cifra %d\n", prima_cifra + n);

	return 0;

}
