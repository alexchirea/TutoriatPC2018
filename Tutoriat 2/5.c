#include <stdio.h>

#define MAX_SIR 150

int main() {
    char sir[MAX_SIR];
    char *ptr = &sir[0]; // echiv. cu char *ptr = sir;
    int k = 0;

    gets(sir);

    char c = *ptr;
    while (c != '\0') {
        ptr++;
        c = *ptr;
        k++;
    }

    printf("%d", k);
    return 0;
}