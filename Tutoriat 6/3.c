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

void sterge(int x, lista* start) {
    nod *p = start->primulElement;
    while (p->urm != NULL) {
        nod *aux;
        if (p->val == x && p->urm->urm != NULL) {
            //primul nod din lista
            if (start->primulElement == p) {
                aux = start->primulElement;
                start->primulElement = start->primulElement->urm;
                free(aux);
                return;
            }
            //oricare alt nod
            else {
                aux = start->primulElement;
                while (aux->urm->val != p->val) {
                    aux = aux->urm;
                }
                aux->urm = aux->urm->urm;
                free(p);
                return;
            }
        }
        //ultimul nod din lista
        if (p->urm->urm == NULL && p->urm->val == x) {
            aux = p->urm;
            p->urm = NULL;
            free(aux);
            return;
        }
        p = p->urm;
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
    int x, k, n, i;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &x);
        adaugaNod(x, &Lista);
    }
    scanf("%d", &k);
    afisare(&Lista);
    sterge(k, &Lista);
    printf("\n");
    afisare(&Lista);
    return 0;
}