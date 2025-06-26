#include "game.h"
#include "logic.h"

void player_turn(game_t *game, int row, int column)
{

}

void reset_game(game_t *game)
{
    game->player = PLAYER_X;
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
