#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "rendering.h"

const Color GRID_COLOR = WHITE;
const Color PLAYER_X_COLOR = RED;
const Color PLAYER_O_COLOR = BLUE;
const Color TIE_COLOR = GRAY;

void render_grid(const Color color)
{
    for (int i = 1; i < N; ++i) {
        DrawLine(i * CELL_WIDTH, 0,
                 i * CELL_WIDTH, SCREEN_HEIGHT, color);
        DrawLine(0, i* CELL_HEIGHT,
                 SCREEN_WIDTH, i * CELL_HEIGHT, color);
             }
}

void render_x(int row, int column, Color color)
{
    const float half_box_side = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.25;
    const float center_x = CELL_WIDTH * 0.5 + column * CELL_WIDTH;
    const float center_y = CELL_HEIGHT * 0.5 + row * CELL_HEIGHT;

    Vector2 startPos = {center_x - half_box_side, center_y - half_box_side};
    Vector2 endPos = {center_x + half_box_side, center_y + half_box_side};
    DrawLineEx(startPos, endPos, 10, color);
}

void render_o(int row, int column, const Color color)
{

}

void render_board(const Board *board,
                  const Color player_x_color,
                  const Color player_o_color)
{
    for (size_t i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            switch(board[i * N + j]) {
            case BOARD_PLAYER_X:
                render_x(i, j, player_x_color);
                break;

            case BOARD_PLAYER_O:
                render_o(i , j, player_o_color);
                break;
            default: {}
            }
        }
    }
}

void render_running_state(const game_t *game)
{
    render_grid(GRID_COLOR);
    render_board(game->board,
                 PLAYER_X_COLOR,
                 PLAYER_O_COLOR);
}

void render_game_over_state(const game_t *game, Color color)
{
    render_grid(color);
    render_board(game->board,
                 color,
                 color);
}

void render_game(const game_t *game)
{
    switch(game->state) {
    case RUNNING_STATE:
        render_running_state(game);
        break;
    case PLAYER_X_WON_STATE:
        render_game_over_state(game, PLAYER_X_COLOR);
        break;
    case PLAYER_O_WON_STATE:
        render_game_over_state(game, PLAYER_O_COLOR);
        break;
    case TIE_STATE:
        render_game_over_state(game, TIE_COLOR);
        break;
    default: {}
    }
}
