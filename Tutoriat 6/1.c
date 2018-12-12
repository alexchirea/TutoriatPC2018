#include <stdio.h>
#include <stdlib.h>

struct nod {
    int val;
    struct nod *urm;
};

struct nod *prim, *ultim;

void adaugaNod(int x) {
    struct nod *noulNod = (struct nod*)malloc(sizeof(struct nod));
    noulNod->val = x;
    noulNod->urm = NULL;
    if (prim == NULL) {
        prim = noulNod;
        ultim = noulNod;
    }
    else {
        ultim->urm = noulNod;
        ultim = noulNod;
    }
}

void sterge() {
    struct nod* p = prim;
    prim = prim->urm;
    if (prim == NULL) ultim = NULL;
    free(p);
}

void afisare(FILE* out) {
    struct nod *p = prim;
    while (p != NULL) {
        fprintf(out, "%d ", p->val);
        p = p->urm;
    }
}

int main() {
    FILE *f, *g;
    f = fopen("/Users/alexchirea/Desktop/lista.in", "r");
    g = fopen("/Users/alexchirea/Desktop/lista.out", "w");
    prim = ultim = NULL; // SAU prim = ultim = 0;
    int k, i, x;
    fscanf(f, "%d", &k);
    while (fscanf(f, "%d", &x) != EOF) {
        adaugaNod(x);
    }
    for(i=0; i<k; i++) {
        if(prim != NULL) {
            adaugaNod(prim->val);
            sterge();
        }
    }
    afisare(g);
    fclose(f);
    fclose(g);
    return 0;
}