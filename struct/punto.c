#include <stdio.h>

struct punto {
	int x;
	int y;
};

void stampa_punto(struct punto p)
{
	printf("Coordinate punto:\nx: %d\ny: %d\n", p.x, p.y);
}

struct punto nuovo_punto(int v1, int v2)
{
    struct punto p;
    p.x = v1;
    p.y = v2;
    return p;
}

void cambia_punto(struct punto *p)
{
    // uso operatore -> per accedere a campo di struct attraverso puntatore
    p->x = 1;
    p->y = 1;
}

int main()
{
	struct punto p1;
	p1.x = 5;
	p1.y = 7;

        // esempio di funzione che restituisce una struttura dati
        struct punto p2 = nuovo_punto(10, 20);

        // struct passata per indirizzo
        cambia_punto(&p2);

	stampa_punto(p2);
	return 0;
}
