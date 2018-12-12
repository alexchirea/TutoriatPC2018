#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *urm;
} nod;

typedef struct list {
    nod *primulElement;
} lista;

void adaugaNod(int x, lista *start) {
    nod *noulNod = (nod*)malloc(sizeof(nod));
    noulNod->val = x;
    noulNod->urm = NULL;
    if (start->primulElement == NULL) {
        start->primulElement = noulNod;
    }
    else {
        nod* ultim = start->primulElement;
        while (ultim->urm != NULL) {
            ultim = ultim->urm;
        }
        ultim->urm = noulNod;
    }
}

void pare(lista *start) {
    nod *p = start->primulElement;
    while (p != NULL) {
        if (p->val % 2 == 0) {
            nod *x = (nod*)malloc(sizeof(nod));
            x->urm = p->urm;
            x->val = p->val/2;
            p->urm = x;
            p = p->urm->urm;
        }
        else {
            p = p->urm;
        }
    }
}

void afisare(lista *start) {
    nod *p = start->primulElement;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->urm;
    }
}

int main() {
    lista Lista = {NULL};
    int x, n, i;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &x);
        adaugaNod(x, &Lista);
    }
    afisare(&Lista);
    pare(&Lista);
    printf("\n");
    afisare(&Lista);
    return 0;
}