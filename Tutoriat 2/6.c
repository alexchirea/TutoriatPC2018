#include <stdio.h>

typedef struct {
    char nume[30], prenume[30];
    int grupa;
    float medie;
} Elev;
int main() {
    FILE *fin = fopen("/Users/alexchirea/Desktop/date.in", "r");
    FILE *fout = fopen("/Users/alexchirea/Desktop/date.out", "w");

    if (fin == NULL || fout == NULL) {
        printf("Fisierul nu exista!");
        return 0;
    }

    int n, i;
    int grupe[51][2] = {{0}};
    float medie[51] = {0};
    /*
     * grupe[gr][0] stochez nr. de elevi nepromovati
     * grupe[gr][1] stochez nr. total de elevi
     * medie[gr] stochez suma notelor dintr-o grupa
     */
    Elev v[500];

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%s", v[i].nume);
        fscanf(fin, "%s", v[i].prenume);
        fscanf(fin, "%d", &v[i].grupa);
        fscanf(fin, "%f", &v[i].medie);
        grupe[v[i].grupa][1]++; // nr. elevi
        if (v[i].medie < 5)
            grupe[v[i].grupa][0]++; // nr. elevi cu media < 5
        medie[v[i].grupa] += v[i].medie;
    }

    for (i =  1; i <= 50; i++) {
        if (grupe[i][1]) { // exista grupa (are elevi)
            fprintf(fout, "%d ", i);
            fprintf(fout, "%.2f ", medie[i]/grupe[i][1]);
            fprintf(fout, "%d\n", grupe[i][0]);
        }
    }

    fclose(fin);
    fclose(fout);
}




