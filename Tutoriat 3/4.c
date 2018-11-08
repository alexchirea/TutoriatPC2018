#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    int i, k;
    gets(s);
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            printf("%c", s[i]);
            if (k) k = 0;
        }
        else {
            if (!k) {
                printf("\n");
                k = 1;
            }
        }
    }
    return 0;
}