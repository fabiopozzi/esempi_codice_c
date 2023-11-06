#include <stdio.h>

//fnzione
//  tipo_ritorno nome_funzione(PARAMETRI)
void mario(int mattia, char c)
{
	// istruzione1
	// istruzione 2
	mattia = 100;
	printf("%c %d\n", c, mattia);
}

int doppio(int j)
{
	j = j*2;
	/* printf("%d", j); */

	return j;
}

int main()
{
	int j = 100;
	int mattia = 5;
	int y;

	/* mario('a', 5); */
	j = 42;
	/* mario('z', mattia); */

	/* printf("%d", mattia); */

	y = doppio(10);
	printf("%d", y);

	return 0;
}

