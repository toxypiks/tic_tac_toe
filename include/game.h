#ifndef GAME_H_
#define GAME_H_

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef enum Board {
    EMPTY,
    BOARD_PLAYER_X,
    BOARD_PLAYER_O
} Board;

typedef enum Player {
    PLAYER_X,
    PLAYER_O
} Player;

typedef enum State {
    RUNNING_STATE,
    PLAYER_X_WON_STATE,
    PLAYER_O_WON_STATE,
    TIE_STATE,
    QUIT_STATE
} State;

typedef struct game_t {
    Board board[N*N];
    Player player;
    State state;
} game_t;

#endif // GAME_H
