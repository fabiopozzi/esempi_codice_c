#include <stdio.h>

#define N 10

void incrementa(int *v)
{
	printf("v in memoria ha l'indirizzo: %p\n", v);
	(*v)++;
}

void modifica_array(int array[], int n)
{
	for(int i = 0; i < n; i++){
		array[i] = 42;
	}
	n = 127;
}

void modifica_matrice(int matrice[][N], int x)
{
	int c = 0;
	for (int i = 0; i < x; i++) {
		for(int j = 0; j < N; j++){
			matrice[i][j] = c;
			c++;
		}
	}
}

int main()
{
	int z = 0;
	int vettore[10] = {0};
	int m[10][10] = {0};

	printf("prima z vale %d\n", z);
	incrementa(&z);
	incrementa(&z);
	incrementa(&z);
	printf("dopo z vale %d\n", z);
	printf("prima vettore[4] vale %d\n", vettore[4]);
	modifica_array(vettore, 10);
	printf("dopo vettore[4] vale %d\n", vettore[4]);

	modifica_matrice(m, 10);

	for (int i = 0; i < 10; i++) {
		for(int j = 0; j < N; j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
