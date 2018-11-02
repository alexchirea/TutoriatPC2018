#include <stdio.h>
#include <string.h>

int main() {
    FILE *f;
    f = fopen("/Users/alexchirea/CLionProjects/TutoriatPC/text.in", "r");
    if (f == NULL) {
        printf("Fisierul nu exista!");
        return 0;
    }
    int n, i, k = 0;
    char s[1000];
    fscanf(f, "%d", &n);
    while(fgets(s, 1000, f)) {
        for (i = 0; i < strlen(s) - 1; i++) {
            if (k == n) {
                printf("\n");
                k = 0;
            }
            printf("%c", s[i]);
            k++;
            if (i == strlen(s) - 2 && k < n && s[strlen(s)-1] == '\n') {
                k++;
                printf(" ");
            }
        }
        if (s[strlen(s)-1] != '\n')
            printf("%c", s[strlen(s)-1]);
    }
    fclose(f);
    return 0;
}