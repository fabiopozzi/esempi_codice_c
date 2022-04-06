/*
** Scrivere una funzione potenza che riceva in ingresso due numeri interi a e b (b >= 0)
** e restituisca il risultato della potenza a^b (a elevato alla potenza b).
** Utilizzare la funzione per visualizzare il valore delle potenze 5^4, 12^3, 20^2, 15^0.
*/
#include<stdio.h>

int potenza(int a, int b);
void stampa_dieci_volte_ciao(void);

int main()
{
	int c, d;
	int risultato;

	do {
		printf("inserire base ed esponente");
		scanf("%d %d", &c, &d);
	} while(d < 0);

	risultato = potenza(c, d);
	printf("risultato: %d\n", risultato);
	stampa_dieci_volte_ciao();
	return 0;
}

void stampa_dieci_volte_ciao(void)
{
	int i;
	for(i = 0; i < 10; i++)
		printf("CIAO\n");
}

int potenza(int a, int b)
{
	int i;
	int risultato = 1;
	for(i = 0; i < b; i++){
		risultato = risultato * a;
	}
	return risultato;
}
