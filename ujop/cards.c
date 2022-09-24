#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int len = 36;
int start = 0;

typedef struct CARD {
    int num;
    char* suit;
    char* name;
} card; 


void make_cards(card* deck_of_cards) {

    char* names[] = {"6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char* suits[] = {"♥", "♣", "♠", "♦"};
    int k = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deck_of_cards[k].name = names[i];
            deck_of_cards[k].num = 6 + i;
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


void distribution_of_card(card* deck_of_cards, card* cards_of_player, card* cards_of_computer) {
    card random_card; 

    int i = 0, j = 0;
    while (i < 6)
    {
        cards_of_player[i] = deck_of_cards[j++];
        cards_of_computer[i] = deck_of_cards[j++];
        i++;
    }
    start = 12;
    return;
}


void trump_to_end(card* arr){
    card temp=arr[start];
    for(int i=start;i<len-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[len-1]=temp;
}
card choose_trump_suit(card *deck_of_cards){
    card trump_suit = deck_of_cards[start];
    printf("Trump suit is: ");
    printf("%s", trump_suit.suit);
    printf("\n");
    trump_to_end(deck_of_cards);
    return trump_suit;
}


void show_cards_player(card* cards_of_player){
    printf("\n");
    printf("Your cards: ");
    for (int i = 0; i < 6; i++){
        printf("%s%s, ", cards_of_player[i].name, cards_of_player[i].suit);
    }
    printf("\n");
    return;
}
void show_cards_computer(card* cards_of_computer){
    printf("\n");
    printf("Cards of computer: ");
    for (int i = 0; i < 6; i++){
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


char* who_is_first(card* computer, card* player, card trump){
    int min_trump = 23;
    char* who;

    for (int i = 0; i < 6; i++)
    {
        if ((computer[i].suit == trump.suit) && (computer[i].num < min_trump)) {
            min_trump = computer[i].num;
            who = "Computer";
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if ((player[i].suit == trump.suit) && (player[i].num < min_trump)) {
            min_trump = player[i].num;
            who = "Player";
        }
    }
    printf("\n");
    printf("%s move first\n", who);
    return who;
}


void delete_card(card* arr, int pos, int size){
    printf("%d", size);
    for(int i=pos-1; i<6-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // arr[-1] = NULL;
    return;
}


int player_defense(card* player, card card){
    int num, i = 0;
    show_cards_player(player);
    while (i != 1) {
        printf("Your move. Choose number of card: ");
        scanf("%d", &num);
        if ((player[num-1].num <= card.num) || (player[num-1].suit != card.suit)) {
            printf("\nWrong card. Try again.\n");
        }
        else
        {
            i = 1;
        }
        
    }
    printf("Your card is: %s%s\n", player[num-1].name, player[num-1].suit);
    return 1;
}
int computer_defence(card* computer, card* player, card card){
    for (int i = 0; i < 6; i++)
    {
        if ((computer[i].num > card.num) && (computer[i].suit == card.suit)) {
            printf("Computer's move %s%s", computer[i].name, computer[i].suit); return 1;
        }
    }
    return 0;
}


card player_attack(card* player, card* computer){
    int num;
    int len_of_player = sizeof(player)/sizeof(player[0]);
    card choice;

    show_cards_player(player);
    printf("Your move. Choose number of card: ");
    scanf("%d", &num); // TODO check wrong input
    choice = player[num-1];
    printf("Your choice is: %s%s\n", choice.name, choice.suit);
    delete_card(player, num, len_of_player);
    return choice;
}
card computer_attack(card* computer, card* player, card trump){
    card smallest;
    int count = 0, i;

    for (i = 0; i < 6; i++)
    {
        if (computer[i].suit != trump.suit) {
            smallest = computer[i];
            count = ++i;
            break;
        }
    }
    for (i = count; i < 6; i++){
        if ((computer[i].num < smallest.num) && (computer[i].suit != trump.suit)) smallest = computer[i];
    }
    show_cards_computer(computer);
    printf("Computer move... %s%s\n", smallest.name, smallest.suit);
    return smallest;
}


int main(void)
{
    card* deck_of_cards;
    deck_of_cards = malloc(len*sizeof(card));
    
    make_cards(deck_of_cards);
    shuffle_deck(deck_of_cards);
    
    //making cards for players
    card* cards_of_player;
    cards_of_player = malloc(6*sizeof(card));
    card* cards_of_computer;
    cards_of_computer = malloc(6*sizeof(card));

    // give cards
    distribution_of_card(deck_of_cards, cards_of_player, cards_of_computer);
    card trump_suit = choose_trump_suit(deck_of_cards);

    show_cards_player(cards_of_player);
    show_cards_computer(cards_of_computer);

    char* who = who_is_first(cards_of_computer, cards_of_player, trump_suit);
    
    while (1){
        card play_card;
        if (who == "Player") {
            play_card = player_attack(cards_of_player, cards_of_computer);
            if (computer_defence(cards_of_computer, cards_of_player, play_card)) continue;
            who == "Computer";
        }
        if (who == "Computer") {
            play_card = computer_attack(cards_of_computer, cards_of_player, trump_suit);
            if (player_defense(cards_of_player, play_card)) continue;
            who == "Player";
        }
    }
}