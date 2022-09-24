#include <stdio.h>

int vstup(int* a){
    printf("Zadej pocet cisel: ");
    if(scanf("%d", a) != 1 || *a < 1)
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}

int main(){
    int a, i, x;
    int max = -9999999, min = 9999999;
    double prumer;

    if (vstup(&a) == 1) return 1;

    for(i = 0; i < a; i++){
        printf("Zadej %d. cele cislo: ", i+1);
        scanf("%d", &x);

        if(x > max) max = x;
        if(x < min) min = x;
        prumer += (double)x;
    }

    prumer /= (double)a;
    printf("Max je %d, min je %d, prumer je %f", max, min, prumer);

    return 0;
}