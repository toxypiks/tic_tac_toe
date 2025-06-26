#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#include "game.h"
#include "logic.h"
#include "rendering.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "procedural");

    game_t game = {
        .board = {BOARD_PLAYER_O, EMPTY, EMPTY,
                  EMPTY, BOARD_PLAYER_X, EMPTY,
                  EMPTY, EMPTY, BOARD_PLAYER_X},
        .player = PLAYER_X,
        .state = RUNNING_STATE
    };

    while(!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_position = GetMousePosition();
            click_on_cell(&game,
                          mouse_position.y / CELL_HEIGHT,
                          mouse_position.x / CELL_WIDTH);
                      }
        BeginDrawing();
        render_game(&game);
        ClearBackground(GetColor(0x181818AA));
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
