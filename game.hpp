#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "constants.h"

using namespace std;

class Game {
 public:
  Game();
  Game(const Game &g);
  ~Game();

  int width() { return BOARD_WIDTH; }
  int height() { return BOARD_HEIGHT; }

 private:
  string board[BOARD_HEIGHT][BOARD_WIDTH];
};

#endif