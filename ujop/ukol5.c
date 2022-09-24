#include <stdio.h>

int main(void) {
    printf("Zadej cele cislo ");
    int c, i;
    int check = 0;

    if (scanf("%d",&c) != 1)
    {
        printf("Chyba!\n");
        return 1;
    }
    
    int prvocisla[] = {2, 3, 5, 7}; 
    int prvocislaDelka = sizeof(prvocisla)/sizeof(prvocisla[0]);
    
    for (i = 0; i < prvocislaDelka; i++)
    {
        if (c % prvocisla[i] == 0)
        {
            printf("Cislo se deli beze zbytku na: %d\n", prvocisla[i]);
            check = 1;
        }
    }
    if (check == 0)
        {
            printf("Cislo se nedeli beze zbytku\n");
        }
    
    return 0;
}