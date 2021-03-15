#include <stdio.h>
#include <string.h>

void swap_stringhe(char s1[], char s2[])
{
	char tmp[10];

	strcpy(tmp, s1);
	strcpy(s1, s2);
	strcpy(s2, tmp);
}

void swap_valori(int *v1, int *v2)
{
	int tmp;
	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void ordina_atleti(char cognomi[][10], int pesi[], int N)
{
	int i, j;
	int scambi = 1;

    for (i = 0 ; (i < N - 1) && scambi; i++)
    {
        scambi = 0;
        for (j = 0 ; j < N - i - 1; j++)
        {
            // se voglio ordinamento decrescente userò '<'
            if (strcmp(cognomi[j], cognomi[j+1]) > 0)
            {
				scambi = 1;
				// SCAMBIO ELEMENTI
				swap_stringhe(cognomi[j], cognomi[j+1]);
				swap_valori(&pesi[j], &pesi[j+1]);
			}
        }
    }

}

int main()
{
	char cognomi[4][10] = {"Pino", "Pozzi", "Gino", "Antani"};
	int pesi[4] = {80, 60, 30, 40};


	ordina_atleti(cognomi, pesi, 4);
	for(int i = 0; i < 4; i++){
		printf("atleta: %s peso: %d\n", cognomi[i], pesi[i]);
	}
	return 0;
}
