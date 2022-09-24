#include <stdio.h>

int main (void) {
    int i, soucet;

    for (i = 0; i < 1001; i+=3)
    {
        soucet += i;
    }
    for (i = 0; i < 1001; i+=5)
    {
        soucet += i;
    }
    printf("%d", soucet);
    return 0;
}