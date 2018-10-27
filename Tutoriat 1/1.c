/*
 * Scrieți un program care citește de la tastaură un număr natural n (1 ≤ n ≤ 1000) care
 * reprezintă numărul de elemente al vectorului v și elementele acestuia (numere naturale).
 * Afișați, pe primul rând, elementele pare, iar, pe cel de-al doilea, rădăcina pătrată a
 * elementelor impare.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int v[1000];
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    //pare
    for (i = 0; i < n; i++)
        if (v[i] % 2 == 0)
            printf("%d ", v[i]);
    printf("\n");
    //impare
    for (i = 0; i < n; i++)
        if (v[i] % 2)
            printf("%.2f ", sqrt(v[i]));
    return 0;
}