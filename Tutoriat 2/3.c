#include <stdio.h>

void swap(int *x, int * y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Inainte de interschimbare a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("Dupa interschimbare a = %d, b = %d", a, b);
    return 0;
}
