#ifndef GAME_H_
#define GAME_H_

#define N 3
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define RUNNING_STATE 0
#define TIE_STATE 3
#define QUIT_STATE 4

typedef enum Player {
    PLAYER_X_WON_STATE,
    PLAYER_O_WON_STATE
} Player;

typedef enum State {
    EMPTY,
    PLAYER_X,
    PLAYER_O
} State;

typedef struct game_t {
    int board[N*N];
    Player player;
    State state;
} game_t;

#endif // GAME_H
