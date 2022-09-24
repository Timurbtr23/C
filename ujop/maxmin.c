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
    int a, i, x, max, min;
    double prumer=0;

    if (vstup(&a) == 1) return 1;

    for(i = 0; i < a; i++){
        printf("Zadej %d. cele cislo: ", i+1);
        if(scanf("%d", &x)!=1) {
            printf("Chyba!\n");
            return 1;
        }
        if (i==0){
            min = x;
            max = x;
        }
        else{
            if (max = x) max = x; else if (x < min) min = x;
        }
        prumer += x;
    }

    prumer /= (double)a;
    printf("Max je %d, min je %d, prumer je %f", max, min, 1.0*prumer/a);

    return 0;
}
