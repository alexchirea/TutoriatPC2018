#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k = 1;
    scanf("%d", &n);
    int **v;
    v = (int**)malloc(sizeof(int*)*n);
    for (i = 1; i <= n; i++) {
        v[i-1] = (int*)malloc(sizeof(int)*i);
        for (j = 1; j <= i; j++) {
            v[i-1][j-1] = k;
            printf("%d ", v[i-1][j-1]);
            k++;
        }
        printf("\n");
    }
    return 0;
}