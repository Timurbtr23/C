#include <stdio.h>

int vstup(char* a){
    printf("Zadej radu zavorek:\n");
    if(scanf("%s", a) != 1)
    {
        printf("Chyba!\n");
        return 1;
    }
    return 0;
} 

int main(){

    int length = 8; // you can also use a macro
    char *arr = malloc(length * sizeof *arr);
    if(arr) {
        // malloc call successful
        // do stuff with arr
    } 
    if (vstup(arr) == 1) return 1;

    int length = sizeof(arr) / sizeof(arr[0]);
    char *zavorky = malloc(length * sizeof *arr);;
    if(arr) {
        // malloc call successful
        // do stuff with arr
    } 

    for(int i = 0; i<100; i++){
        if ((a[i] != "(") || (a[i] != ")")){
            printf("Chyba!\n");
            return 1;
        }
    }

    return 0;
}