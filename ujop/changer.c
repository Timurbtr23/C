#include <stdio.h>

int input(){
    int sum;
    
    printf("Zadej castku: ");
    if(scanf("%d",&sum)!=1 || sum <= 0) {
        printf("Chyba!\n");
        return 0;
    }
    return sum;
}

void count(int* P, int sum, int len) {
    int i, div, pocet;

    for (i = 0; i < len; i++)
    {
        pocet = 0;
        while (sum/P[i] > 0) // остаток от деления попробовать, чтобы разом было sum / P[i],  div = sum/P[i],  sum -= P[i] * div
        {
            div = sum / P[i];
            sum -= P[i] * div;
            pocet += div;
        }
        if (pocet > 0) printf("%4d kc - %2d\n", P[i], pocet);
    }
    return;
}

int main (void) {
    
    int sum = input();
    if (sum == 0) return 0;

    int Penize[]={5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 2, 1};
    int len_of_arr = sizeof(Penize)/sizeof(Penize[0]);

    count(Penize, sum, len_of_arr);

    return 0;
}