#include <stdio.h>
#include <stdlib.h>

void rotunjire(int array_size, int *array) {
    int i, c;
    for (i = 0; i < array_size; i++) {
        c = array[i] / 5;
        if (array[i] % 5) {
            c++;
            if ((c * 5 - array[i]) < 3 && c*5 >= 40)
                array[i] = c * 5;
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *v = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    rotunjire(n, v);
    for (i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}