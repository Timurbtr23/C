#include <stdio.h>
#include <stdlib.h>


int vstup(int* g, int p){
    if (p==1) printf("Zadej pocet sloupcu (x): "); else printf("Zadej pocet radku (y): ");
    if(scanf("%d", g) != 1 || (*g<=0))
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}


int vstup_penize(int* penize){
    printf("Zadej penize na nakup bonbonu: ");
    if(scanf("%d", penize) != 1 || (*penize <= 0))
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
            if(scanf("%d", &pole[j][i]) != 1 || (pole[j][i]<=0))
            {
                printf("Chyba!\n");
                return 1;
            }
        }
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


void find_min(int x, int y, int pole[y][x], int* min){
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if ((i==0)&&(j==0)){
                *min = pole[j][i];
            }
            if (pole[j][i] < *min) *min = pole[j][i];
        }
    }
}


void vysledek(int cena, int pocet, int reseni, int x, int y, int pole[y][x], int var){
    printf("Reseni - cena za bonbony: %dKc, pocet bonbonu %d, pocet reseni %d\n", cena, pocet, reseni);
    printf("Sourednice prvniho bonbonu [slopec][radek]:\n");

    if (var != 0){
        for (int i=0; i<y; i++) {
            for (int j=0; j<x; j++) {
                if (pole[j][i] == var) printf("[%d][%d]\n", j, i);
            }
        }
    }
    else{
        printf("[%d][%d]\n", x, y);
    }
}


void vysledek1(int cena, int pocet, int reseni, int* res_x, int* res_y){
    printf("Reseni - cena za bonbony: %dKc, pocet bonbonu %d, pocet reseni %d\n", cena, pocet, reseni);
    printf("Sourednice prvniho bonbonu [slopec][radek]:\n");
    for (int i=0; i<reseni; i++ ) {
        printf("[%d][%d]\n", res_x[i], res_y[i]);
    }
}


void min_vetsi(int x, int y, int pole[y][x], int min){
    int count = 0;
    int cena;

    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if (pole[j][i] == min) {count++; cena = pole[j][i];}
        }
    }

    vysledek(cena, 1, count, x, y, pole, min);
}


void min_mene(int x, int y, int pole[y][x], int penize){
    int sum, i, j, m, n, count, last_count = 0, last_sum, reseni;
    int summa;
    int* res_x = (int*)malloc(10 * sizeof(int));
    int* res_y = (int*)malloc(10 * sizeof(int));
    int o_pole[2];

    for (i=0; i<y; i++) {
        for (j=0; j<x; j++) {

            for (m=i; m<y; m++) {
                for (n=j; n<x; n++) {

                    sum = 0; count = 0;
                    for (int k = i; k <= m; k++ ){
                        for (int l = j; l <= n; l++ ){
                            sum += pole[l][k];
                            count++;
                        }
                    }
                    if (sum <= penize) {
                        if (count>last_count){
                            summa = sum; 
                            res_x[0] = j; res_y[0] = i;

                            last_count = count;
                            last_sum = sum;
                            reseni = 1;
                        }
                        else if ((count==last_count) && (sum <= last_sum)) {
                            if (sum == last_sum){
                                reseni++;
                                if(reseni % 10 == 9){
                                    res_x = realloc(res_x, (reseni+10)*sizeof(int));
                                    res_y = realloc(res_y, (reseni+10)*sizeof(int));
                                }
                                res_x[reseni-1] = j; 
                                res_y[reseni-1] = i; 
                            }
                            else {
                                reseni = 1;
                                summa = sum; 
                                res_x[0] = j; res_y[0] = i;

                                last_count = count;
                                last_sum = sum;
                            }
                        }
                    }
                }
            }
        }
    }
    if (reseni == 1) vysledek(summa, last_count, reseni, res_x[0], res_y[0], pole, 0);
    if (reseni > 1) vysledek1(summa, last_count, reseni, res_x, res_y);
    free(res_x);
    free(res_y);
}


int main(){

    int x, y;
    if (vstup(&x, 1) == 1) return 1;
    if (vstup(&y, 2) == 1) return 1;

    int pole[y][x];

    int penize;
    if (vstup_penize(&penize) == 1) return 1;

    vstup_hodnot(x, y, pole);

    print_array(x, y, pole);

    int min;
    find_min(x, y, pole, &min);

    if ((min > penize/2) && (min <= penize)) min_vetsi(x, y, pole, min);
    else if (min > penize) printf("Nema reseni.\n");
    else                                     min_mene(x, y, pole, penize);

    return 0;
}