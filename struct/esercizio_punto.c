/*
come memorizzo le informazioni di un punto nello spazio
calcolare e restituire la distanza tra due punti
funzione che mi dice se due punti sono allineati sull'asse x
funzione che mi dice se due punti sono allineati sull'asse y
funzione di traslazione sull'asse x
funzione di traslazione sull'asse y
distanza di un punto dall'origine (0, 0)

*/
#include <stdio.h>

struct punto {
	int x;
	int y;
};

int allinea_ascisse(struct punto p1, struct punto p2)
{
	if (p1.x == p2.x) {
		return 1;
	}
	return 0;
}

struct punto trasla_ascisse(int delta, struct punto p)
{
	p.x = p.x + delta;
	return p;
}

int ascissa_primo_quadrante(struct punto p, int *x)
{
	if (p.x < 0) {
		printf("non sono nel primo quadrante");
		return -1;
	}
	*x = p.x;

	return 0;
}

int main() {
	/* struct punto punti[2] = {{ 10, 20} , {10, 120}}; */
	struct punto punto1 = {-10, 20};
	struct punto punto2 = {0, 120};
	int var = 0;

	if (allinea_ascisse(punto1, punto2) != 0)
		printf("SONO ALLINEATI\n");

	if (ascissa_primo_quadrante(punto1, &var) != 0) {
		printf("errore");
		return -1;
	}
	printf("var %d\n", var);

	printf("p1.x %d p1.y %d\n", punto1.x, punto1.y);
	punto1 = trasla_ascisse(10, punto1);
	printf("p1.x %d p1.y %d\n", punto1.x, punto1.y);

	return 0;
}

