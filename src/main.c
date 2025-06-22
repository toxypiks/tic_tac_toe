#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL3/SDL.h>

#include "game.h"
#include "logic.h"
#include "rendering.h"

int main(void)
{
    SDL_Window *window;                    // Declare a pointer
    bool done = false;

    if (SDL_Init(SDL_INIT_VIDEO) != true) {
        fprintf(stderr, "Could not initialize sdl3: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Procedural", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    game_t game = {
        .board = {EMPTY, EMPTY, EMPTY,
                  EMPTY, EMPTY, EMPTY,
                  EMPTY, EMPTY, EMPTY},
        .player = PLAYER_X,
        .state = RUNNING_STATE
    };

    const float cell_width = SCREEN_WIDTH / N;
    const float cell_height = SCREEN_HEIGHT / N;

    SDL_Event event;
    while (game.state != QUIT_STATE) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                game.state = QUIT_STATE;
                break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                click_on_cell(&game,
                              event.button.y / cell_height,
                              event.button.x / cell_width);
                              break;
            }
        }

        // Do game logic, present a frame, etc.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render_game(renderer, &game);
        SDL_RenderPresent(renderer);
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
