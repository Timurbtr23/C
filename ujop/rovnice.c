#include <stdio.h>
#include <math.h>

int vstup(int* a, int* b, int* c){
    printf("Zadej parametry rovnice a,b,c (oddelene carkou): ");
    if(scanf("%d,%d,%d", a, b, c) != 3)
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}

int diskriminant(int a, int b, int c){
    return b*b - 4*a*c;
}

int main(){
    int a, b, c;
    if (vstup(&a, &b, &c) == 1) return 1;

    if (a==0 && b==0 && c==0)
    {
        printf("X = R\n");
        return 0;
    }
    if (a==0 && b==0)
    {
        printf("Nema reseni\n");
        return 0;
    }
    if (a==0)
    {
        float x = (float)-c/b;
        printf("Reseni rovnice: x = %f\n", x);
        return 0;
    }

    double diskrim = (double)diskriminant(a, b, c);

    if (diskrim < 0) 
    {
        printf("Rovnice nema reseni v oboru R");
    }
    else if (diskrim == 0)
    {
        float x = -b/(2*a);
        printf("Reseni rovnice: x = %f", x);
    }
    else if (diskrim > 0)
    {
        float x1 = (-b + sqrt(diskrim)) / (2*a);
        float x2 = (-b - sqrt(diskrim)) / (2*a);
        printf("Reseni rovnice: x1 = %f, x2 = %f", x1, x2);
    }
    printf("\n");
    return 0;
}