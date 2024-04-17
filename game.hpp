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
  // game board in row-major order [# rows, # columns]
  string board[BOARD_HEIGHT][BOARD_WIDTH];

  Game();
  Game(const Game &g);
  ~Game();

  int width() { return BOARD_WIDTH; }
  int height() { return BOARD_HEIGHT; }
  int get_score() { return score; }

 private:
  int score = 0;
};

#endif