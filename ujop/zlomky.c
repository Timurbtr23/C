 #include <stdio.h>
#include <math.h>

int vstup(double* a){
    printf("Zadej cislo: ");
    if((scanf("%lf", a) != 1))
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}

int mocnina(double a){
    int e = 0;
    int i = a;
    double d = a;

    while (1.0*i != d)
    {
        d *= 10;
        e++;
        i = d;
    }
    return e;
}

int cislo_int(double a){
    int i = a;
    double d = a;

    while (1.0*i != d)
    {
        d *= 10;
        i = d;
    }
    return i;
}

void gcd(int a, int b){
    int gcd;
    int minus;

    if ((a<0) || (b<0)) minus = 1;
    else minus = 0;

    for(int i=1; i <= a && i <= b; ++i)
    {
        // Checks if i is factor of both integers
        if(a%i==0 && b%i==0)
            gcd = i;
    }

    if (minus == 1) printf("-%d / %d\n", a/gcd, b/gcd);
    if (minus == 0) printf("%d / %d\n", a/gcd, b/gcd);
}


int main(){
    double a;
    int n=1, f;

    if (vstup(&a) == 1) return 1;

    for (int i = 1; i <= mocnina(a); i++) n *= 10;
    f = cislo_int(a);

    printf("%d / %d\n", f, n);
    gcd(f, n);

    return 0;
}