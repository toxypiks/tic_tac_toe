#include "game.h"
#include "logic.h"
#include <stdio.h>

void player_turn(game_t *game, int row, int column)
{
    printf("game->board: %d\n", game->board[row * N + column]);
    if (game->board[row * N + column] == EMPTY) {
        game->board[row * N + column] = game->player;
        printf("game->board after klick: %d\n", game->board[row * N + column]);
    }
}

void reset_game(game_t *game)
{
    game->player = BOARD_PLAYER_X;
    game->state = RUNNING_STATE;
    for (int i = 0; i < N * N; ++i) {
        game->board[i] = EMPTY;
    }
}

void click_on_cell(game_t *game, int row, int column)
{
    if (game->state == RUNNING_STATE) {
        player_turn(game, row, column);
    } else {
        reset_game(game);
   }
}
