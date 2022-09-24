#include <stdio.h>

typedef struct PODLAHA {
    int a;
    int b;
} podlaha;

typedef struct ANSWER {
    int pocet;
    float spara;
} answer;


int vstup(podlaha* pol){
    printf("Zadej sirku a delku podlahy v cm (oddelene carkou): ");
    if((scanf("%d,%d", &pol->a, &pol->b) != 2) || (((pol->a< 30)&&(pol->b<20)) || ((pol->b< 30)&&(pol->a<20))))
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
}


void vystup(answer* ans){
    ans->spara *= 10;
    printf("Pocet dlazdic: %d, spara: %d\n", ans->pocet, (int)ans->spara);
    return;
}


answer pocet_dlazdic(podlaha pol, int a, int b, double* spara){
    int i, m, t=0;

    int len = pol.a / a;
    int wid = pol.b / b;

    answer ans;

    for (i = 3; i >= 0; i--)
    {
        if ((pol.a - ((len*a)  +  ((len-1) * spara[i]))) > spara[i]) {
            ans.spara = spara[i];
            m = i;
            break;
        }
    }

    while (t!=1)
    {
        for (i = m; i >= 0; i--)
        {
            if ((pol.b - ((wid*b)  +  ((wid-1) * spara[i]))) > spara[i]) {
                t=1;
                ans.spara = spara[i];
                break;
            }
        }
        if (t!=1) wid--;
    }

    ans.pocet = len*wid;
    printf("pocet %d, spara %f\n", ans.pocet, ans.spara);

    return ans;
}


int main (void){

    double spara[] = {0.2, 0.3, 0.4, 0.5};

    int dlazdice_a = 20;
    int dlazdice_b = 30;

    podlaha pol;
    answer odpoved1, odpoved2;

    if (vstup(&pol) == 1) return 1;

    odpoved1 = pocet_dlazdic(pol, dlazdice_a, dlazdice_b, spara);
    odpoved2 = pocet_dlazdic(pol, dlazdice_b, dlazdice_a, spara);

    if (odpoved1.pocet > odpoved2.pocet) vystup(&odpoved1);
    else if (odpoved1.pocet == odpoved2.pocet) {
        if (odpoved1.spara > odpoved2.spara) vystup(&odpoved1);
        else if (odpoved1.spara < odpoved2.spara) vystup(&odpoved2);
        else vystup(&odpoved1);}
    else if (odpoved1.pocet < odpoved2.pocet) vystup(&odpoved2);

    return 0;
}
