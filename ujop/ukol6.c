#include <stdio.h>

int main (void){
    int i,j,c,x=0;

    if(scanf("%d",&c)!=1) {
        printf("Chyba!\n");
        return 1;
    }

    for(i=0;i<=c;i++)
    {
        j=-1;
        while(j<i)
        {
            int p;
            if (i < 3)
            {
                p = 3;
                x = i * p * i;
            }
            else if (i >= 3)
            {
                x = i * (3 + p + (i+1));
                p += i+1;
            }
            j += i+1;
        }
    }
    printf("%d\n",x);
    return 0;
}
            