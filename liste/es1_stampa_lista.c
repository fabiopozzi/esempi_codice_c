/*Scrivi una funzione che permetta di stampare tutto il
contenuto di una lista collegata.*/
#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int valore;
	struct nodo* next;
};

// mi aspetto che il chiamante passi il valore della testa
// della lista
void stampa_lista(struct nodo *ptr)
{
    // finche' non ho terminato la lista
	while (ptr != NULL) {
		printf("%d\n", ptr->valore);
		ptr = ptr->next;
	}
}

int main(){
	struct nodo* head = NULL;
	struct nodo* ptr;
	int valore, i;
	do {
		printf("INSERIRE VALORE --> ");
		scanf("%d", &valore);
		ptr = (struct nodo*)malloc(sizeof(struct nodo));
		if (ptr == NULL) {
            printf("errore malloc");
			return -1;
		}
        // inserisco in testa
		ptr->valore = valore;
		ptr->next = head;
		head = ptr;
	} while (valore > 0);

    stampa_lista(head);
}