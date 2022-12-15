#include <stdio.h>
// definire una struttura "data" che contenga giorno, mese - stringa, anno.
struct data {
	int giorno;
	char mese[20];
	int anno;
};

// definire una funzione leggi_data che riempia una struttura "data"
struct data leggi_data(){
	struct data d;

	/// riempio d con dei valori
	scanf("%d", &d.giorno);
	scanf("%19s", d.mese);
	scanf("%d", &d.anno);

	return d;
}

void leggi_data2(struct data *p_d)
{
	/// riempio p_d con dei valori
	scanf("%d", &p_d->giorno);
	scanf("%19s", p_d->mese);
	scanf("%d", &p_d->anno);
}

void leggi_data3(struct data ad[])
{
	for(int i = 0; i < 10; i++) {
		scanf("%d", &ad[i].giorno);
		scanf("%19s", ad[i].mese);
		scanf("%d", &ad[i].anno);
	}
}

// gestire tramite una funzione la necessita' di riempire un array
// di strutture "data"
//
int main()
{
	struct data a[10];

	for(int i = 0; i < 10; i++) {
		// uso leggi_data
		a[i] = leggi_data();
	}

	for(int i = 0; i < 10; i++) {
		leggi_data2(&a[i]);
	}

	leggi_data3(a);
}
