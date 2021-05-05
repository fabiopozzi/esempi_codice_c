#include <stdio.h>

/* definizione struttura dati */
struct studente {
	int classe;
	int matricola;
	int eta;
};

struct punto {
	int x;
	int y;
};


int main()
{
	struct studente pino;
	struct studente fabio = pino;

	pino.classe = 3; // normale accesso al campo classe

	fabio.eta = 42;
	fabio.matricola = 1234567;

	printf("la classe e' %d \n", pino.classe);
	return 0;
}
