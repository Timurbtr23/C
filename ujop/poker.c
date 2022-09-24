#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int len = 52;
int start = 0;

typedef struct CARD {
    int num;
    char* suit;
    char* name;
} card;


void make_cards(card* deck_of_cards) {

    char* names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char* suits[] = {"♥", "♣", "♠", "♦"};
    int k = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deck_of_cards[k].name = names[i];
            deck_of_cards[k].num = 2 + i;
            deck_of_cards[k].suit = suits[j];
            k++;
        }
    }
    return;
}


void swap(card* a, int i, int j) {
    card temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}
void shuffle_deck(card* deck_of_cards){
    srand((unsigned)time(NULL));
    for(int i = 35; i > 0; i--) {
        int random = rand() % (i);
        swap(deck_of_cards, i, random);
    }
    return;
}


int distribution_of_card(card* deck_of_cards, card* cards_of_player, card* cards_of_computer) {
    int i = 0, j = 0;
    while (i < 2)
    {
        cards_of_player[i] = deck_of_cards[j++];
        cards_of_computer[i] = deck_of_cards[j++];
        i++;
    }
    start = j+1;
    return start;
}


void show_cards_player(card* cards_of_player){
    printf("\n");
    printf("Your cards: ");
    for (int i = 0; i < 2; i++){
        printf("%s%s, ", cards_of_player[i].name, cards_of_player[i].suit);
    }
    printf("\n");
    return;
}
void show_cards_computer(card* cards_of_computer){
    printf("\n");
    printf("Cards of computer: ");
    for (int i = 0; i < 2; i++){
        printf("%s%s, ", cards_of_computer[i].name, cards_of_computer[i].suit);
    }
    printf("\n");
    return;
}
void show_deck(card* deck_of_cards){
    printf("\n");
    printf("All cards: ");
    for (int i = 0; i < 36; i++){
        printf("%s%s, ", deck_of_cards[i].name, deck_of_cards[i].suit);
    }
    printf("\n");
    return;
}
void show_the_table(card* table){
    printf("\n");
    printf("Cards on the table: ");
    for (int i = 0; i < 5; i++){
        printf("%s%s, ", table[i].name, table[i].suit);
    }
    printf("\n");
    return;
}


void sort(int* arr1){
    int i, j, tmp;
    for(i=0; i<5; i++)
    {
        for(j=i+1; j<5; j++)
        {
            if(arr1[j] <arr1[i])
            {
                tmp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = tmp;
            }
        }
    }
}


int create_table(card* deck_of_cards, int start, int type, card* cards_on_the_table){
    switch (type)
    {
        case 1:
            for (int i = start, j = 0; i < 8 || j<3; i++, j++) cards_on_the_table[j] = deck_of_cards[i];
            start = 9;
            break;
        case 2:
            cards_on_the_table[3] = deck_of_cards[start];
            start = 11;
            break;
        case 3:
            cards_on_the_table[4] = deck_of_cards[start];
            break;
    }
    return start;
}


char* pair_status(int pairs){
    char* status;
    switch (pairs) {
        case 0:
            status = "No pairs";
            break;
        case 1:
            status = "1 pair";
            break;
        case 2:
            status = "3 of a kind";
            break;
        case 3:
            status = "4 of a kind";
            break;
    }
    return status;
}

void combinations(card* table, card* two_cards){
    int pairs = 0;
    int pairs1 = 0, pairs2 = 0;
    int pairsT = 0;
    char* status, *status1, *status2, *status_table, *status_hidden;
    short hidden = 0;

// Looking for hidden pairs
    if (two_cards[0].name == two_cards[1].name) {
        pairs++;
        hidden = 1;

        // Looking for a set or kare
        for (int i = 0; i < 5; i++){
            if (table[i].name == two_cards[0].name) pairs++;
        }
        status_hidden = pair_status(pairs);
        printf("Hidden cards status: %s", status_hidden);
    }

// Looking for combinations on the table
    // Pair
    for (int i = 0; i < 5; i++){
        for (int j = i+1; j < 5-i+1; j++) {
            if (table[i].name == table[j].name) pairsT++;
        }
    }
    if (pairsT >= 2) status_table = pair_status(pairsT-1);
    else status_table = pair_status(pairsT);;

    // Looking for a Flush
    char* last_suit;
    int count_of_suits;
    for (int i = 0; i < 5; i++){
        if (i==0) {last_suit = table[i].suit; count_of_suits++;}
        else {
            if (table[i].suit == last_suit) count_of_suits++;
            else break;
        }
    }
    if (count_of_suits == 5) {
        status_table = "Flush";
        status = status_table;
    }

    // Looking for a Straight
    int strit[5];
    int count_of_sequence;

    for (int i = 0; i < 5; i++){
        strit[i] = table[i].num;
    }
    sort(strit);

    int last_num;
    for (int i = 0; i < 5; i++){
        if (i==0) {last_num = strit[i]; count_of_sequence++;}
        else {
            if ((strit[i] - last_num) == 1) count_of_sequence++;
            else break;
        }
    }
    if (count_of_sequence == 5) {
        status_table = "Straight";
        status = status_table;
    }

    printf("Status of the table %s\n", status_table);

// Standart situation
    if (hidden == 0) {
        for (int k = 0; k < 2; k++){
            for (int j = 0; j < 5; j++) {
                if (two_cards[k].name == table[j].name) {
                    if (k==0) pairs1++;
                    if (k==1) pairs2++;
                }
            }
        }
        status1 = pair_status(pairs1);
        printf("Status 1 is %s\n", status1);

        status2 = pair_status(pairs2);
        printf("Status 2 is %s\n", status2);

        if      ((strcmp(status1, "No pairs"))      || (strcmp(status2, "No pairs") == 0))      status = "No pairs";
        else if ((strcmp(status1, "1 pair") == 0)   && (strcmp(status2, "1 pair") == 0))        status = "2 pairs";
        else if (((strcmp(status1, "1 pair") == 0)    - (strcmp(status2, "1 pair") == 0)) != 0) status = "1 pair";

        else if ((strcmp(status1, "3 of a kind") == 0) && ((strcmp(status2, "No pairs") == 0)) || (strcmp(status2, "1 pair") == 0)) status = "3 of a kind";
        else if (((strcmp(status1, "No pairs") == 0) || (strcmp(status1, "1 pair") == 0)) && (strcmp(status2, "3 of a kind") == 0)) status = "3 of a kind";

        else if ((strcmp(status1, "3 of a kind") == 0)  && (strcmp(status2, "2 pair")) == 0)      status = "Full House";
        else if ((strcmp(status1, "2 pairs") == 0)      && (strcmp(status2, "3 of a kind")) == 0) status = "Full House";
    }
    printf("\nStatus is: %s", status);
    return;
}


int main(void)
{
    card* deck_of_cards;
    deck_of_cards = malloc(len*sizeof(card));
    card* cards_on_the_table;
    cards_on_the_table = malloc(5*sizeof(card));

    make_cards(deck_of_cards);
    shuffle_deck(deck_of_cards);

    //making cards for players
    card* cards_of_player;
    cards_of_player = malloc(2*sizeof(card));
    card* cards_of_computer;
    cards_of_computer = malloc(2*sizeof(card));

    // give cards
    int start = distribution_of_card(deck_of_cards, cards_of_player, cards_of_computer);

    show_cards_player(cards_of_player);
    show_cards_computer(cards_of_computer);
    printf("\n");

    for (int i = 1; i<4; i++) {
        start = create_table(deck_of_cards, start, i, cards_on_the_table);
    }

    show_the_table(cards_on_the_table);
    printf("\n");

    combinations(cards_on_the_table, cards_of_player);
    printf("\n");
    // combinations(cards_on_the_table, cards_of_computer);
    // printf("\n");

    return 0;
}
