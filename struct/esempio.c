#include <stdio.h>

struct stato {
	unsigned int vivo : 1;    // vero o falso
	unsigned int in_salute : 1;
	unsigned int ha_chiave : 1;
	unsigned int stanza : 2;
};
// la dimensione sara' sempre un multiplo di un intero
// sizeof(struct stato) = 32 bit
union esempio {
	char c[4];
	int v;
};


int main()
{
	struct stato s;
	union esempio var;

	s.vivo = 1;
	s.stanza = 2;
	if( s.vivo != 0 ) {
		printf("flag settato");
	} else {
		printf("personaggio morto");
	}


	var.c[0] = 'a';
	var.c[1] = 'b';
	var.c[2] = 0;
	var.c[3] = 0;

	printf("union vale %d\n", var.v);
	return 0;
}
