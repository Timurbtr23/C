#include <stdio.h>


int vstup(int* g, int p){
    if (p==1) printf("Zadej pocet sloupcu (x): "); else printf("Zadej pocet radku (y): ");
    if(scanf("%d", g) != 1 || (*g<=0))
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}

int vstup_hodnot(int x, int y, int pole[y][x]){
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            printf("Zadej hodnotu bunky [%d][%d]: ", j, i);
            if(scanf("%d", &pole[j][i]) != 1)
            {
                printf("Chyba!\n");
                return 1;
            }
        }
    }
    return 0;
}

int souradnice(int* x1, int* y1, int* x2, int* y2, int* x, int* y){
    printf("Zadej souradnice leve hodni pozice odddelene carkou 0..%d,0..%d: ", *x-1, *y-1);
    if(scanf("%d,%d", x1, y1) != 2 || (*x1>*x-1) || (*y1>*y-1) || *x1<0 || *y1<0)
    {
        printf("Chyba!\n");
        return 1;
    }
    printf("Zadej souradnice prave spodni pozice odddelene carkou 0..%d,0..%d: ", *x-1, *y-1);
    if(scanf("%d,%d", x2, y2) != 2 || (*x2>*x-1) || (*y2>*y-1) || *x2<*x1 || *y2<*y1)
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}

void print_array(int x, int y, int pole[y][x]){
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            printf("%4d, ", pole[j][i]);
        }
        printf("\n");
    }
}


int main(){
    int x, y;
    if (vstup(&x, 1) == 1) return 1;
    if (vstup(&y, 2) == 1) return 1;

    int pole[y][x];

    vstup_hodnot(x, y, pole);

    print_array(x, y, pole);

    int x1, y1, x2, y2;
    if (souradnice(&x1, &y1, &x2, &y2, &x, &y) == 1) return 1;

    int count = 0;
    for (int i=y1; i<=y2; i++) {
        for (int j=x1; j<=x2; j++) {
            count += pole[j][i];
        }
    }
    printf("soucet prvku oblasti je : %d\n", count);

    return 0;
}