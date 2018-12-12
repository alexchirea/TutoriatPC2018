#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    char *s;
    scanf("%d", &n);
    s = (char*)malloc(n);
    scanf("%s", s);
    int rezultat = 0, i, h = 0, t = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'C') h--;
        else h++;
        if (h < 0) {
            if (!t) t = 1;
        }
        if (!h && t) {
            t = 0;
            rezultat++;
        }
    }
    printf("%d", rezultat);
    return 0;
}