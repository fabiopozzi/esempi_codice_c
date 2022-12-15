#include<stdio.h>

struct punto {
	int x;
	int y;
};

int inlinea_x(struct punto p1, struct punto p2);

int main()
{
	struct punto p1 = {10, 20};
	struct punto p2 = {5, 5};

	if (inlinea_x(p1, p2) != 0)
		printf("i due punti sono allineati sull'asse x");
	else
		printf("i due punti NON sono allineati sull'asse x");

	int r = inlinea_x(p1, p2);
	if(r != 0)
		printf("VEDI SOPRA");
	else
		printf("NON SONO ALLINEATI");

	return 0;
}

int inlinea_x(struct punto p1, struct punto p2)
{
	if(p1.y == p2.y)
		return 1;
	else
		return 0;
}
