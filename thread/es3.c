#include <stdio.h>
#include <pthread.h>
#include <time.h>

void stampaA()
{
	int i = 0;

	while(i < 100)
	{
		printf("A");
		i++;
	}
}

void stampaB()
{
	int i = 0;

	while(i < 100)
	{
		printf("B");
		i++;
	}
}

int main()
{
	pthread_t tA, tB;
	time_t start,end;

	time (&start);
	pthread_create(&tA, NULL, (void *)stampaA, NULL);
	pthread_create(&tB, NULL, (void *)stampaB, NULL);

	pthread_join(tA, NULL); // aspetto che stampaA termini
	pthread_join(tB, NULL); // aspetto che stampaB termini
	time (&end);
	double deltaT = difftime(end, start);
	printf("Tempo impiegato e' di %.2lf s.", deltaT);

	return 0;
}
/* appunti: ore 17.30 - 19.30 riunione simone? */
