#include <stdio.h>
#include <string.h>

struct atleta {
	char cognome[20];
	int peso;
};

void swap_atleta (struct atleta *a1, struct atleta *a2)
{
	struct atleta tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

void stampa_atleta(struct atleta a)
{
	printf("Atleta\nCognome: %s\nPeso: %d\n\n", a.cognome, a.peso);
}

void ordina_atleti(struct atleta el[], int N)
{
	int i, j;
	int scambi = 1;

    for (i = 0 ; (i < N - 1) && scambi; i++)
    {
        scambi = 0;
        for (j = 0 ; j < N - i - 1; j++)
        {
            // se voglio ordinamento decrescente userò '<'
            if (strcmp(el[j].cognome, el[j+1].cognome) > 0)
            {
				scambi = 1;
				// SCAMBIO ELEMENTI
				swap_atleta(&el[j], &el[j+1]);
			}
        }
    }


}

int main()
{
	struct atleta elenco[4] = {{"Zorloni", 80}, {"Rossi", 50}, {"Rizzi", 80}, {"Antani", 60}};
	int i;

	for(i = 0; i < 4; i++)
		stampa_atleta(elenco[i]);

	ordina_atleti(elenco, 4);

	for(i = 0; i < 4; i++)
		stampa_atleta(elenco[i]);

	return 0;
}
