//main.c
#include <stdio.h>
#include "sumaDivTrei.c"
#include "produsDivDoi.c"
int main() {
    int n, v[1000], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    int s = sumaDivTrei(n, v);
    int p = produsDivDoi(n, v);
    printf("Suma este %d\n", s);
    printf("Produsul este %d", p);
    return 0;
}

//sumaDivTrei.c
int sumaDivTrei(int nrElem, int a[1000]) {
    int i, s = 0;
    for (i = 0; i < nrElem; i++)
        if (a[i] % 3 == 0)
            s += a[i];
    return s;
}

//produsDivDoi.c
int produsDivDoi(int nrElem, int a[1000]) {
    int i, p = 1;
    for (i = 0; i < nrElem; i++)
        if (a[i] % 2 == 0)
            p *= a[i];
    return p;
}
