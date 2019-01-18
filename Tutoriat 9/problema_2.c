#include <stdio.h>
#include <stdlib.h>

struct elev
{
    char nume[30], prenume[30];
    float medie;
};

struct clasa
{
    int clasa;
    char litera;
    struct elev **elevi;
    int nrElevi;
    float medie;
};

struct registru
{
    struct clasa **clase;
    int nrClase, nrPromovati, nrTotal;
};

struct elev* elevNou(char *n, char *p)
{
    struct elev *e = (struct elev*) malloc(sizeof(struct elev));
    strcpy(e->nume, n);
    strcpy(e->prenume, p);
    return e;
}

void asignare(struct clasa *c, struct elev *e)
{
    c->elevi = (struct elev**) realloc(c->elevi, sizeof(struct elev*) * (c->nrElevi + 1));
    c->elevi[c->nrElevi] = e;
    c->nrElevi = c->nrElevi + 1;
    return;
}

void asignare_r(struct registru* r, struct clasa *c)
{
    r->clase = (struct clasa**) realloc(r->clase, sizeof(struct clasa*) * (r->nrClase + 1));
    r->clase[r->nrClase] = c;
    r->nrClase = r->nrClase + 1;
    return;
}

void mediaClasei(struct clasa* c)
{
    float m = 0;
    int i;
    for (i=0; i < c->nrElevi; i++)
        m += c->elevi[i]->medie;
    c->medie = m/c->nrElevi;
    printf("Media clasei %d%c: %.2f\n", c->clasa, c->litera, c->medie);
    return;
}

int verif(struct elev* e, struct registru *r)
{
    int nrClase = r->nrClase, i;
    for (i=0; i<nrClase; i++)
    {
        int nrElevi = r->clase[i]->nrElevi, j;
        struct clasa *c = r->clase[i];
        for (j=0; j<nrElevi; j++)
            if (e == c->elevi[j])
                return 1;
    }
    return 0;
}

void registru(struct registru *r)
{
    int nrClase = r->nrClase, i;
    int promovati = 0, total = 0;
    for (i=0; i<nrClase; i++)
    {
        int nrElevi = r->clase[i]->nrElevi, j;
        struct clasa *c = r->clase[i];
        for (j=0; j<nrElevi; j++)
        {
            if (c->elevi[j]->medie >= 5)
                promovati++;
            total++;
        }
    }
    r->nrPromovati = promovati;
    r->nrTotal = total;
    printf("Numar elevi promovati %d (din %d)\n", r->nrPromovati, r->nrTotal);
}

int main()
{
    /* Initializare registru */
    struct registru R;
    R.nrClase = 0;
    R.nrPromovati = 0;
    R.nrTotal = 0;
    R.clase = NULL;
    
    /* Initializare clasa */
    struct clasa C, C2;
    C.nrElevi = 0;
    C.medie = 0;
    C.elevi = NULL;
    C.clasa = 9;
    C.litera = 'G';
    C2.nrElevi = 0;
    C2.medie = 0;
    C2.elevi = NULL;
    C2.clasa = 12;
    C2.litera = 'A';
    
    struct elev *e1 = elevNou("Popescu", "Andrei");
    e1->medie = 9.50;
    
    struct elev *e2 = elevNou("Ionescu", "Ioana");
    e2->medie = 8.50;
    
    struct elev *e3 = elevNou("Marinescu", "Maria");
    e3->medie = 3.75;
    
    struct elev *e4 = elevNou("Gigi", "Maria");
    e4->medie = 10;
    
    struct elev *e5 = elevNou("Jiji", "Andrei");
    e5->medie = 4.75;
    
    struct elev *e6 = elevNou("Mimi", "Ioana");
    e6->medie = 7.55;
    
    /* Asignare clasa C in registru R */
    asignare_r(&R, &C);
    asignare_r(&R, &C2);
    
    /* Asignare elevi e1, e2, e3 in clasa C */
    asignare(&C, e1);
    asignare(&C, e2);
    asignare(&C, e3);
    
    asignare(&C2, e4);
    asignare(&C2, e5);
    asignare(&C2, e6);
    
    /* Media clasei C */
    mediaClasei(&C);
    mediaClasei(&C2);
    
    /* Verificare asignare elev */
    if (verif(e1, &R) == 1)
        printf("Elevul este deja asignat!\n");
    else
        printf("Elevul nu este asignat!\n");
    
    registru(&R);
    
    return 0;
}
