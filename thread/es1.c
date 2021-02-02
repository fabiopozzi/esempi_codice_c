#include <stdio.h>
#include <pthread.h>

void stampaA()
{
	int i = 0;

	while(i < 100)
	{
		printf("A%d", i);
		i++;
	}
}

int main()
{
	pthread_t t;

	pthread_create(&t, NULL, (void *)stampaA, NULL);
	int j = 0;

	while(j < 100)
	{
		printf("B%d", j);
		j++;
	}
	return 0;
}
