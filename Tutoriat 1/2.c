/*
 * Se consideră un șir de caractere format doar din litere mici ale alfabetului englez.
 * Scrieți un program care să transforme fiecare litera mică aflată pe poziție pară
 * în literă mare.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    char v[100];
    getchar();
    for (i = 0; i < n; i++) {
        v[i] = getchar();
    }
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) v[i] = v[i] - 32;
        printf("%c", v[i]);
    }
    return 0;
}