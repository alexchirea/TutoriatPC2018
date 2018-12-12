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

int sterge(lista* start) {
    nod* p = start->primulElement;
    start->primulElement = start->primulElement->urm;
    int x = p->val;
    free(p);
    return x;
}

void afisare(lista *start) {
    nod *p = start->primulElement;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->urm;
    }
}

int main() {
    lista pare = {NULL};
    lista impare = {NULL};
    int i, n, x;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &x);
        if (x % 2) adaugaNod(x, &impare);
        else adaugaNod(x, &pare);
    }
    afisare(&pare);
    printf("\n");
    afisare(&impare);
    printf("\n");
    while (impare.primulElement != NULL) {
        adaugaNod(sterge(&impare), &pare);
    }
    afisare(&pare);
    printf("\n");
    return 0;
}