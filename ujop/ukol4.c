#include <stdio.h>

int main (void) {
    int a, b;
    char c;
    
    printf("Insert two integer numbers and one char, delimiter beetwen inputs is space: "); 
    
    int count = scanf("%d %d %c", &a, &b, &c);

    if (count != 3) {
        printf("Chyba!\n");
        return 1;
    }

    printf("Your input is %d, %d, %c.\n", a, b, c);
    return 0;
}