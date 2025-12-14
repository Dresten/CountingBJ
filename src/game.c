#include "game.h"
#include "input.h"

typedef struct {
    Card* cards;
    size_t size;
    size_t next_card;
} Deck;

static Deck deck;

void game_init(void) {
    Card* deck_storage;
    size_t deck_size;

    if (!gameModSelect()) {
        static Card storage_double[DOUBLE_DECK_SIZE];
        deck_storage = storage_double;
        deck_size = DOUBLE_DECK_SIZE;
    } else {
        static Card storage_quad[QUAD_DECK_SIZE];
        deck_storage = storage_quad;
        deck_size = QUAD_DECK_SIZE;
    }

    deck_generate(deck_storage, deck_size);
    deck_init(&deck, deck_storage, deck_size);
    game_shuffle();
}

void game_shuffle(void) {
    deck_shuffle(&deck);
}

Card game_draw_card(void) {
    return deck_draw(&deck);
}

void game_deck_reset(void) {
    deck_reset(&deck);
}

char card_label(const Card* c)
{
    if (c->value == 1)  return 'A';
    if (c->value == 11) return 'J'; // o J/Q/K a caso
    if (c->value == 12) return 'Q';
    if (c->value == 13) return 'K';
    if (c->value == 0)  return 'R';
    return '0' + c->value;
}

//**************************************
// METHODS TO SIMULATE INCAPSULATION AND
// PROTECT DATAS OF THE DECK AND HIS 
// BEHAVIOUR
//**************************************

//Genera carte del mazzo
static void deck_generate(Card* deck, size_t deck_size)
{
    size_t i = 0;

    for (int suit = SUIT_SPADES; suit <= SUIT_DIAMONDS; suit++) {

        if (i >= deck_size) return;
        deck[i++] = (Card){ 1, suit };   // Asso

        for (int v = 2; v <= 9; v++) {
            if (i >= deck_size) return;
            deck[i++] = (Card){ v, suit };
        }

        for (int c = 0; c < 4; c++) {
            if (i >= deck_size) return;
            deck[i++] = (Card){ 10, suit };
        }
    }

    if (i < deck_size) {
        deck[i++] = (Card){ 0, SUIT_SPECIAL };
    }
}

// assegna le carte al mazzo da gioco
static void deck_init(Deck* deck, Card* deck_storage, size_t deck_size){
  deck->cards = deck_storage;
  deck->size = deck_size;
  deck->next_card = 0;
}

//shuffle the cards in a randomic way and push the reshuffle card somewhere in the middle
static void deck_shuffle(Deck* deck){

}

//it draws a card
static Card deck_draw(Deck* deck)
{
    if (deck->next_card >= deck->size) {
        deck_shuffle(deck);
    }

    Card c = deck->cards[deck->next_card++];

    /* Carta reshuffle */
    if (c.value == 0 && c.suit == SUIT_SPECIAL) {
        deck_shuffle(deck);
        return deck_draw(deck);   // pesca la prossima vera carta
    }

    return c;
}


static void deck_reset(Deck* deck){
    deck->next_card = 0; //return to first card with pointer
    deck_shuffle(deck);
}
