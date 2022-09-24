#include <stdio.h>

typedef struct OBDELNIK {
    int x1;
    int y1;
    int x2;
    int y2;
} Obdelnik; 

short success = 1;

void input_data(Obdelnik* Data) {
    if (!success) return;

    printf("Zadejte 4 celych cisel ");
    if((scanf("%d,%d,%d,%d", &Data->x1, &Data->y1, &Data->x2, &Data->y2) != 4) ||
    ((Data->x2 < Data->x1) || (Data->y2 < Data->y1)) ||                              // podminka obdelnika
    ((Data->x1<0) || (Data->y1<0) || (Data->x2<0) || (Data->y2<0)) ||                // >0
    ((Data->x1>79) || (Data->y1>79) || (Data->x2>79) || (Data->y2>79)))              //<79
    {
        printf("Chyba!\n");
        success = 0;
        return;
    }
    return;
}

void draw_obdelnik (Obdelnik* obdelnik1, Obdelnik* obdelnik2) {
    if (!success) return;

    int j, i, znak, main_x2, main_y2;

    int x11 = obdelnik1->x1;
    int y11 = obdelnik1->y1;
    int x21 = obdelnik1->x2;
    int y21 = obdelnik1->y2;

    int x12 = obdelnik2->x1;
    int y12 = obdelnik2->y1;
    int x22 = obdelnik2->x2;
    int y22 = obdelnik2->y2;

    main_x2 = (obdelnik1->x2 > obdelnik2->x2) ? obdelnik1->x2 : obdelnik2->x2;
    main_y2 = (obdelnik1->y2 > obdelnik2->y2) ? obdelnik1->y2 : obdelnik2->y2;

    for (j = 0; j <= main_y2; j++)
    {
        for (i = 0; i <= main_x2; i++)
        {
            znak = 32;

            if (((i==x11) && (j==y11)) || ((i==x12) && (j==y12))) znak=218; //left top
            if (((i==x21) && (j==y11)) || ((i==x22) && (j==y12))) znak=191; //right top
            if (((i==x11) && (j==y21)) || ((i==x12) && (j==y22))) znak=192; //bottom left
            if (((i==x21) && (j==y21)) || ((i==x22) && (j==y22))) znak=217; //bottom right

            if (((i>x11) && (i<x21)  &&  ((j==y11) || (j==y21)))      ||  ((i>x12) && (i<x22)  &&  ((j==y12) || (j==y22)))) znak=196;   // ---
            if ((((i==x11) || (i == x21))  &&  ((j>y11) && (j<y21)))  ||  ((i==x12) || (i == x22))  &&  ((j>y12) && (j<y22))) znak=179; // |  |
            if (((i==x11) && (i == x21)  &&  (j==y11) && (j==y21))    ||  ((i==x12) && (i == x22)  &&  (j==y12) && (j==y22))) znak=197; // krizek pro tecku

            if (((i>x12) && (i<x22)  &&  ((j==y12) || (j==y22)))   &&   ((i==x11) || (i == x21))  &&  ((j>y11) && (j<y21))) znak=197; // krizek1
            if (((i>x11) && (i<x21)  &&  ((j==y11) || (j==y21)))   &&   ((i==x12) || (i == x22))  &&  ((j>y12) && (j<y22))) znak=197; // krizek2

            //          left top                 right top                    ------------------------------------------------
            if ((((i==x11) && (j==y11)) || ((i==x21) && (j==y11)))       &&   ((i>x12) && (i<x22)  &&  ((j==y12) || (j==y22)))) znak=194; //  T
            if ((((i==x12) && (j==y12)) || ((i==x22) && (j==y12)))       &&   ((i>x11) && (i<x21)  &&  ((j==y11) || (j==y21)))) znak=194; //  T
            //          left bottom               right bottom                
            if ((((i==x11) && (j==y21)) || (((i==x21) && (j==y21))))     &&   ((i>x12) && (i<x22)  &&  ((j==y12) || (j==y22)))) znak=193; // opacna T
            if ((((i==x12) && (j==y22)) || (((i==x22) && (j==y22))))     &&   ((i>x11) && (i<x21)  &&  ((j==y11) || (j==y21)))) znak=193; // opacna T

            //          left top                left bottom                   |||||||||||||||||||||||||||||||||||||||||||||||||||
            if ((((i==x11) && (j==y11)) || (((i==x11) && (j==y21))))     &&   ((i==x12) || (i == x22))  &&  ((j>y12) && (j<y22))) znak=195; // |-
            if ((((i==x12) && (j==y12)) || (((i==x12) && (j==y22))))     &&   ((i==x11) || (i == x21))  &&  ((j>y11) && (j<y21))) znak=195; // |-
            //          right top               right bottom         
            if ((((i==x21) && (j==y11)) || ((((i==x21) && (j==y21)))))   &&   ((i==x12) || (i == x22))  &&  ((j>y12) && (j<y22))) znak=180; // -|
            if ((((i==x22) && (j==y12)) || ((((i==x22) && (j==y22)))))   &&   ((i==x11) || (i == x21))  &&  ((j>y11) && (j<y21))) znak=180; // -|

            putchar(znak);
        }
        printf("\n");
    }
    return;
}

int main (void){
    Obdelnik obd1, obd2;

    input_data(&obd1);
    input_data(&obd2);
    draw_obdelnik(&obd1, &obd2);
    
    return 0;
}
