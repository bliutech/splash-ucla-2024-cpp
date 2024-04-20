#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "actor.hpp"
#include "constants.hpp"

using namespace std;

struct Bullet {
  int pos_x, pos_y;
};

class Game {
 public:
  // game board in row-major order [# rows, # columns]
  Actor* board[BOARD_HEIGHT][BOARD_WIDTH];

  Game();
  Game(const Game& g);
  ~Game();

  int width() { return BOARD_WIDTH; }
  int height() { return BOARD_HEIGHT; }
  static int get_score() { return score; }
  static int get_lives() { return lives; }

  static void scoring() { score++; }
  static void dying() {
    if (lives <= 0) {
      lives = 0;
      return;
    }
    lives--;
  }

 private:
  static int score;
  static int lives;
};

#endif