#include<stdio.h>
#include<string.h>

typedef struct
{
int x;
int y;
} vpunti[10];


typedef int pippo[10];

pippo p;

void stampa(pippo p)
{
	printf("pippo %d", p[0]);
}

int main() {
  vpunti v1;
  v1[0].x = 127;
}
