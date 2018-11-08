#include <stdio.h>
#include <string.h>
void solutie(char *S) {
    int frecv[10] = {0}, i;
    for (i = 0; i < strlen(S); i++) {
        if (S[i] >= '0' && S[i] <= '9') {
            frecv[S[i]-'0']++;
        }
    }
    for (i = 0; i < 10; i++)
        printf("%d ", frecv[i]);  
}
int main() {
    char S[1001];
    scanf("%s", S);
    solutie(S);
    return 0;
}