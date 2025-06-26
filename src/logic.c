#include "game.h"
#include "logic.h"
#include <stdio.h>

void switch_player(game_t *game)
{
    if (game->player == PLAYER_X) {
        game->player = PLAYER_O;
    } else if (game->player == PLAYER_O) {
        game->player = PLAYER_X;
    }
}

void player_turn(game_t *game, int row, int column)
{
    if (game->board[row * N + column] == EMPTY) {
        game->board[row * N + column] = game->player;
        switch_player(game);
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
