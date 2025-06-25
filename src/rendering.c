#include <SDL3/SDL.h>

#include "game.h"
#include "rendering.h"

const SDL_Color GRID_COLOR = { .r = 255, .g = 255, .b = 255 };
const SDL_Color PLAYER_X_COLOR = { .r = 255, .g = 50, .b = 50 };
const SDL_Color PLAYER_O_COLOR = { .r = 50, .g = 100, .b = 255 };
const SDL_Color TIE_COLOR = { .r = 100, .g = 100, .b = 100 };

void render_grid(SDL_Renderer *renderer, const SDL_Color *color)
{
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);
    for (int i = 1; i < N; ++i) {
        SDL_RenderLine(renderer,
                       i * CELL_WIDTH, 0,
                       i * CELL_WIDTH, SCREEN_HEIGHT);
    }
}

void render_board(SDL_Renderer *renderer,
                  const Board *board,
                  const SDL_Color *player_x_color,
                  const SDL_Color *player_o_color)
{

}

void render_running_state(SDL_Renderer *renderer, const game_t *game)
{
    render_grid(renderer, &GRID_COLOR);
    render_board(renderer,
                 game->board,
                 &PLAYER_X_COLOR,
                 &PLAYER_O_COLOR);
}

void render_game_over_state(SDL_Renderer *renderer, const game_t *game, const SDL_Color *color)
{
    render_grid(renderer, color);
    render_board(renderer,
                 game->board,
                 color,
                 color);
}

void render_game(SDL_Renderer *renderer, const game_t *game)
{
    switch(game->state) {
    case RUNNING_STATE:
        render_running_state(renderer, game);
        break;
    case PLAYER_X_WON_STATE:
        render_game_over_state(renderer, game, &PLAYER_X_COLOR);
        break;
    case PLAYER_O_WON_STATE:
        render_game_over_state(renderer, game, &PLAYER_O_COLOR);
        break;
    case TIE_STATE:
        render_game_over_state(renderer, game, &TIE_COLOR);
        break;
    default: {}
    }
}
