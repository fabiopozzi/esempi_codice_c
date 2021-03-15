/*
I dati relativi ai correntisti di una banca sono memorizzati nei seguenti vettori:
numero_conto_corrente, cognome_correntista, saldo_conto_corrente.
Progettare un’applicazione che gestisca le seguenti richieste:
a) stampa dei dati relativi ad un determinato correntista il cui numero di conto corrente è fornito in
input
b) stampa dei dati relativi ad un determinato correntista il cui cognome è fornito in input
c) stampa dei dati relativi al correntista con saldo massimo e del correntista con saldo minimo
d) stampare i dati relativi ai correntisti in rosso
e) stampa della media dei saldi
f) stampare i dati relativi ai correntisti ordinando in ordine alfabetico sul campo cognome
g) stampare i dati relativi ai correntisti ordinando in ordine crescente di saldo
h) stampare i dati relativi ai correntisti ordinando in ordine decrescente di saldo

Risolvere l'esercizio isolando le diverse richieste in funzioni dedicate che vengano chiamate dalla funzione main().
*/
#include <stdio.h>
#include <string.h>

enum {
	NUM = 4,
	L_IBAN = 27,
	L_COGN = 50
};

char numero_conto_corrente[NUM][L_IBAN] = {"12", "13", "25", "42"};
char cognome_correntista[NUM][L_COGN] = {"Pozzi", "Bianchi", "Rossi", "Azzurri"};
float saldo_conto_corrente[NUM] = { 7.337, 42, 10, 3.14 };

void stampa_media();
void stampa_rosso();
void stampa_per_conto(char num_correntista[]);
void stampa_per_cognome(char cognome[]);
void stampa_persona(int pos);
void stampa_massimo_e_minimo();
void ordina_cognome();
void ordina_saldo_decrescente();
void ordina_saldo_crescente();

int main()
{
	/* stampa_per_conto("25"); */
	/* stampa_per_cognome("Azzurri"); */
	/* stampa_massimo_e_minimo(); */
	/* stampa_rosso(); */
	printf("ordina per cognome\n");
	ordina_cognome();
	printf("\nordina per saldo crescente\n");
	ordina_saldo_crescente();
	printf("\nordina per saldo decrescente\n");
	ordina_saldo_decrescente();

	return 0;
}

void stampa_rosso()
{
	printf("correntisti in rosso:\n");
	for(int i = 0; i < NUM; i++){
		if (saldo_conto_corrente[i] < 0) {
			stampa_persona(i);
		}
	}

}

void stampa_massimo_e_minimo()
{
	int max = 0, min = 0;

	for(int i = 0; i < NUM; i++){
		if (saldo_conto_corrente[i] > saldo_conto_corrente[max]) {
			max = i;
		} else if (saldo_conto_corrente[i] < saldo_conto_corrente[min]) {
			min = i;
		}
	}
	printf("\nil correntista con il saldo piu' alto e':\n");
	stampa_persona(max);

	printf("\nil correntista con il saldo piu' basso e':\n");
	stampa_persona(min);

}

void stampa_per_conto(char num_correntista[])
{
	for(int i = 0; i < NUM; i++){
		if (strcmp(num_correntista, numero_conto_corrente[i]) == 0){
			stampa_persona(i);
			return;
		}
	}

}

void stampa_per_cognome(char cognome[])
{
	for(int i = 0; i < NUM; i++){
		if (strcmp(cognome, cognome_correntista[i]) == 0){
			stampa_persona(i);
			return;
		}
	}

}

void stampa_persona(int pos)
{
  printf("Cognome:\t%s\nC. corrente\t%s\nSaldo:\t\t%f\n",
		 cognome_correntista[pos], numero_conto_corrente[pos],
		 saldo_conto_corrente[pos]);
}

void stampa_media()
{
	float media = 0;
	for(int i = 0; i < NUM; i++){
		media += saldo_conto_corrente[i];
	}
	media = media / NUM;
	printf("la media dei saldi vale %f\n", media);
}

void swap_strings(char s1[], char s2[])
{
	char tmp[L_COGN];

	strcpy(tmp, s1);
	strcpy(s1, s2);
	strcpy(s2, tmp);
}

void swap_values(float *v1, float *v2)
{
	float tmp;
	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void stampa_valori()
{
	for(int i = 0; i < NUM; i++) {
		stampa_persona(i);
	}
}

void ordina_cognome()
{
	for(int i = 0; i < NUM - 1; i++) {
		for(int j = 0; j < NUM - i - 1; j++) {
			if (strcmp(cognome_correntista[j], cognome_correntista[j+1]) > 0) {
				swap_strings(cognome_correntista[j], cognome_correntista[j+1]);
				swap_strings(numero_conto_corrente[j], numero_conto_corrente[j+1]);
				swap_values(&saldo_conto_corrente[j], &saldo_conto_corrente[j+1]);
			}
		}
	}

	stampa_valori();
}

void ordina_saldo_crescente()
{
	for(int i = 0; i < NUM - 1; i++) {
		for(int j = 0; j < NUM - i - 1; j++) {
			if (saldo_conto_corrente[j] > saldo_conto_corrente[j+1]) {
				swap_strings(cognome_correntista[j], cognome_correntista[j+1]);
				swap_strings(numero_conto_corrente[j], numero_conto_corrente[j+1]);
				swap_values(&saldo_conto_corrente[j], &saldo_conto_corrente[j+1]);
			}
		}
	}

	stampa_valori();
}

void ordina_saldo_decrescente()
{
	for(int i = 0; i < NUM - 1; i++) {
		for(int j = 0; j < NUM - i - 1; j++) {
			if (saldo_conto_corrente[j] < saldo_conto_corrente[j+1]) {
				swap_strings(cognome_correntista[j], cognome_correntista[j+1]);
				swap_strings(numero_conto_corrente[j], numero_conto_corrente[j+1]);
				swap_values(&saldo_conto_corrente[j], &saldo_conto_corrente[j+1]);
			}
		}
	}

	stampa_valori();
}
