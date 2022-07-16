#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DECK_SIZE 54
#define HAND_SIZE 5

#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14
#define JOKER 15


#define CLUB 1
#define SPADE 2
#define HEART 3
#define DIAMOND 4

#define BLACK 5
#define RED 6


typedef struct {
    unsigned short int value;
    unsigned short int lear;
} poker_card;


unsigned int get_pseudo_random_number(unsigned int begin, unsigned int end, int additional_entropy)
{
    srand(time(NULL) * additional_entropy);
    return rand() % end + begin;
}

void init_card_deck(poker_card deck[])
{
    int i, j;
    int x = 0;
    poker_card card;
    for (i = CLUB; i <= DIAMOND; i++) {
        for (j = 2; j <= ACE; j++) {
            card.lear = i;
            card.value = j;
            deck[x] = card;
            x++;
        }
    }
    card.value = JOKER;
    card.lear = BLACK;
    deck[x] = card;
    x++;
    card.lear = RED;
    deck[x] = card;
}

void deal_the_cards(poker_card hand[], poker_card deck[], unsigned int hand_size)
{
    int i, x;
    for (i = 0; i < hand_size; i++) {
        x = get_pseudo_random_number(0, DECK_SIZE - 1, i + 1);
        hand[i] = deck[x];
    }
}

char* print_tr_card_lear(unsigned short int lear)
{
    char* s;
    switch(lear) {
        case CLUB:
            s = "clubs"; 
            break;
        case SPADE:
            s = "spades";
            break;
        case HEART:
            s = "hearts";
            break;
        case DIAMOND:
            s = "diamonds";
            break;
        case BLACK:
            s = "black";
            break;
        case RED:
            s = "red";
            break;
        default:
            s = "";
            break;
    }
    printf("%s", s);
}

void print_tr_card_value(unsigned short int value)
{
    char* s;
    if (value <= 10) {
        printf("%d", value);
    }
    switch (value) {
        case JACK:
            s = "jack";
            break;
        case QUEEN:
            s = "queen";
            break;
        case KING:
            s = "king";
            break;
        case ACE:
            s = "ace";
            break;
        case JOKER:
            s = "joker";
            break;
        default:
            s = "";
            break;
    }
    printf("%s", s);
}

void sort_hand(poker_card hand[], unsigned int size)
{
    int i, j;
    poker_card sort_buf;
    for (j = 0; j < size - 1; j++) {
        for (i = 0; i < size - j - 1; i++) {
            if (hand[i].value > hand[i + 1].value) {
                sort_buf = hand[i];
                hand[i] = hand[i + 1];
                hand[i + 1] = sort_buf;
            }
        }
    }
}

void print_detected_combination(poker_card hand[], unsigned int size)
{
    int repeat_value = 0;
    int repeat_lear = 0;
    int set = 0;
    int kare = 0;
    int i;

    for (i = 0; i < size - 1; i++) {
        if (hand[i].value == hand[i + 1].value || hand[i].value == JOKER || hand[i + 1].value == JOKER) {
            repeat_value++;
            if ((hand[i].value == hand[i + 1].value) &&
            (hand[i + 1].value == hand[i + 2].value)) set++;
            if ((hand[i].value == hand[i + 1].value) &&
                (hand[i + 1].value == hand[i + 2].value) &&
                (hand[i + 2].value == hand[i + 3].value)) kare++;
        }
        if (hand[i].lear == hand[i + 1].lear || hand[i].value == JOKER || hand[i + 1].value == JOKER) {
            repeat_lear++;
        }
    }
    if (repeat_value == 1) {
        printf("Pair detected!\n");
    } else if ((repeat_value == 2) && (set == 1)) {
        printf("Set detected!\n");
    } else if (repeat_value == 2) {
        printf("Two pairs detected!\n");
    } else if ((repeat_value == 3) && (kare == 1)) {
        printf("Kare detected!\n");
    } else if (repeat_value == 3) {
        printf("Full house detected!\n");
    } else if (repeat_value == 4) {
        printf("Poker detected!\n");
    } else if (repeat_lear == 4) {
        printf("Flash detected!\n");
    } else if (repeat_value < 1) {
        printf("No combinations detected...\n");
    }
}

void print_tr_card(poker_card card)
{
    print_tr_card_lear(card.lear);
    printf(" ");
    print_tr_card_value(card.value);
    printf("\n");
}

int main(int argc, char* argv[])
{
    poker_card deck[DECK_SIZE];
    init_card_deck(deck);
    poker_card hand[5];
    deal_the_cards(hand, deck, HAND_SIZE);
    sort_hand(hand, HAND_SIZE);
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_tr_card(hand[i]);
    }
    printf("\nCombinations:\n");
    print_detected_combination(hand, HAND_SIZE);
    return 0;
}