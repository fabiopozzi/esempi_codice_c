#include <stdio.h>

struct punto {
	int x;
	int y;
};

void stampa_punto(struct punto p)
{
	printf("Coordinate punto:\nx: %d\ny: %d\n", p.x, p.y);
}

int main()
{
	struct punto p1;
	p1.x = 5;
	p1.y = 7;

	stampa_punto(p1);
	return 0;
}
