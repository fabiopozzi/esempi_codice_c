#include<stdio.h>
#include<string.h>

#define L_STR 100
#define L_PROV 3

struct indirizzo {
    char via[L_STR];
    int civico;
};

struct data {
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
};

typedef struct {
    //nome, cognome, provincia e anno di nascita
    char nome[L_STR];
    char cognome[L_STR];
    char prov[L_PROV];
    struct indirizzo i_residenza;
    struct data d_nascita;
} persona;

void stampa_persona(persona p)
{
    printf("--------------Persona-------------\n");
    printf("Nome: %s", p.nome);
    printf("Cognome: %s", p.cognome);
    printf("Prov: %s\n", p.prov);
    printf("Indirizzo: %s Civico: %d\n", p.i_residenza.via, p.i_residenza.civico);
    printf("Data nascita %d / %d / %d\n",
            p.d_nascita.giorno, p.d_nascita.mese, p.d_nascita.anno);
    printf("----------------------------------\n");
}

persona crea_persona()
{
    persona p;

    printf("Nome:");
    fgets(p.nome, L_STR, stdin);
    printf("Cognome:");
    fgets(p.cognome, L_STR, stdin);
    printf("Prov:");
    fgets(p.prov, L_PROV, stdin);
    getchar();
    printf("Indirizzo:");
    fgets(p.i_residenza.via, L_STR, stdin);
    printf("N civico:");
    scanf("%d", &p.i_residenza.civico);

    printf("anno nascita\n");
    printf("giorno:");
    scanf("%d", &p.d_nascita.giorno);
    printf("mese:");
    scanf("%d", &p.d_nascita.mese);
    printf("anno:");
    scanf("%d", &p.d_nascita.anno);

    return p;
}

int main()
{
    persona p2;

    p2 = crea_persona();
    stampa_persona(p2);
    return 0;
}