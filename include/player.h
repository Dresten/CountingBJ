
#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

/* --------------------------
   Tipi e enumerazioni
---------------------------*/
typedef enum {
    MOVE_QUIT = 0,
    MOVE_CARD,
    MOVE_DOUBLE,
    MOVE_SPLIT,
    MOVE_STAY
} PlayerMove;

typedef struct {
    unsigned int saldo;
    unsigned int bet;
    unsigned int points;
    PlayerMove move;
} Player;

/* --------------------------
   Lifecycle
---------------------------*/
void player_init(Player* p, unsigned int saldo_iniziale);

/* --------------------------
   Setters (con validazione)
---------------------------*/
bool player_set_bet(Player* p, unsigned int bet);
void player_set_move(Player* p, PlayerMove move);

/* --------------------------
   Getters
---------------------------*/
unsigned int player_get_saldo(const Player* p);
unsigned int player_get_bet(const Player* p);
unsigned int player_get_points(const Player* p);
PlayerMove  player_get_move(const Player* p);

#endif /* PLAYER_H */
