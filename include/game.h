
#ifndef GAME_H
#define GAME_H
#include <stddef.h>

#define STANDARD_DECK_SIZE 52
#define DOUBLE_DECK_SIZE   105
#define QUAD_DECK_SIZE     209

typedef enum {
    SUIT_SPADES,
    SUIT_HEARTS,
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_RED
} Suit;

typedef struct {
    uint8_t value;   // 1–13, 0 = joker
    Suit suit;
} Card;

typedef struct {
    unsigned int dealer_points;
    int table_count;
} House;

// **************************************************
// CORE DEL DECK: INCAPSULATO NEL MODULE (game.c)
// **************************************************

// Inizializza il gioco (deck e mazzo)
void game_init(void);

// Shuffle del mazzo
void game_shuffle(void);

// Pesca una carta dal mazzo
Card game_draw_card(void);

// Reset del mazzo
void game_deck_reset(void);

// **************************************************
// HOUSE
// **************************************************
void house_init(House* h);
void house_set_points(House* h, unsigned int v);
unsigned int house_get_points(const House* h);

#endif // GAME_H
