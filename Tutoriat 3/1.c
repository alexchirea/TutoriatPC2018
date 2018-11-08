#include <stdio.h>
void f(int *x,int *y) {
    int s, d;
    s = (*x) + (*y);
    d = (*x) - (*y);
    if (d < 0) d = -1 * d;
    *x = s;
    *y = d;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    f(&a, &b);
    printf("%d %d", a, b);
    return 0;
}