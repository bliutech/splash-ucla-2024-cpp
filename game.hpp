#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "constants.hpp"

using namespace std;

struct Bullet {
  int pos_x, pos_y;
};

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