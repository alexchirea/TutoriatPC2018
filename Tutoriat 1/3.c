/*
 * Creați o structură denumită Produs care să conține câmpurile cod (int),
 * denumire (char[30]) și pret (număr real). Scrieți un program care citește de
 * la tastatură un număr natural n (1 ≤ n ≤ 1000) și datele a n produse. Afișați
 * costul pentru a cumpăra 10 produse de fiecare tip, cel mai ieftin și cel mai
 * scump produs. Realizați modificările necesare pentru ca structura creată să
 * poată fi apelată Produs, nu struct Produs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int cod;
    char denumire[30];
    float pret;
} Produs;

int main() {
    int n, i;
    scanf("%d", &n);
    Produs v[1000];
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i].cod);
        scanf("%s", v[i].denumire);
        scanf("%f", &v[i].pret);
    }
    int Min = INT_MAX;
    int Max = -1;
    int pMin, pMax;
    float suma = 0;
    for (i = 0; i < n; i++) {
        if (v[i].pret > Max) {
            Max = v[i].pret;
            pMax = i;
        }
        if (v[i].pret < Min) {
            Min = v[i].pret;
            pMin = i;
        }
        suma += 10 * v[i].pret;
    }
    printf("Produsul cel mai ieftin este %s si costa %.2f\n\n", v[pMin].denumire, v[pMin].pret);
    printf("Produsul cel mai scump este %s si costa %.2f\n\n", v[pMax].denumire, v[pMax].pret);
    printf("Este nevoie de %.2f lei pentru a cumpara 10 produse de fiecare tip", suma);
    return 0;
}