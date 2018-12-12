#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int hour, min, sec;
    char m[3];
    scanf("%d:%d:%d%s", &hour, &min, &sec, m);
    if ((strcmp(m, "PM") == 0 && hour != 12) || (strcmp(m, "AM") == 0 && hour == 12))
        hour += 12;
    hour %= 24;
    printf("%02d:%02d:%02d", hour, min, sec);
    return 0;
}