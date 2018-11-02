#include <stdio.h>

int main() {
    FILE *fin, * fout;
    fin = fopen("/Users/alexchirea/CLionProjects/TutoriatPC/date.in", "r");
    fout = fopen("/Users/alexchirea/CLionProjects/TutoriatPC/date.out", "w");
    if (!fin || !fout) {
        printf("Fisierele nu exista!");
        return 0;
    }
    float v[500];
    int i, n;
    float suma = 0;
    float *pointer;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%f", &v[i]);
    pointer = v;
    for (i = 0; i < n; i++) {
        suma += *pointer;
        pointer++;
    }
    fprintf(fout, "Suma este %.2f", suma);
    fclose(fin);
    fclose(fout);
    return 0;
}