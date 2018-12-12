#include <stdio.h>
#include <stdlib.h>
void conjCollatz(int n, int *x) {
    if (n != 1) {
        (*x)++;
        if (n % 2) conjCollatz(3*n+1, x);
        else conjCollatz(n/2, x);
    }
}
int main() {
    int n, x = 0;
    scanf("%d", &n);
    conjCollatz(n, &x);
    printf("%d", x);
    return 0;
}