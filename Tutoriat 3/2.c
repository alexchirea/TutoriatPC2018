#include <stdio.h>
int main()
{
    int n, i, v[100];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", v + i);
    }
    for (i = 0; i < n / 2; i++) {
        int aux = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = aux;
    }
    for(i = 0; i < n; i++)
        printf("%d ", *(v + i));
    return 0;
}