#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#include "game.h"
#include "logic.h"
#include "rendering.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "imperative");

    game_t game = {
        .board = {EMPTY, EMPTY, EMPTY,
                  EMPTY, EMPTY, EMPTY,
                  EMPTY, EMPTY, EMPTY},
        .player = PLAYER_X,
        .state = RUNNING_STATE
    };

    while(!WindowShouldClose()) {

        BeginDrawing();
        render_game(&game);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_position = GetMousePosition();
            click_on_cell(&game, (int)(mouse_position.y / CELL_HEIGHT), (int)(mouse_position.x / CELL_WIDTH));
                      }
        ClearBackground(GetColor(0x181818AA));
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
