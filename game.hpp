#include <iostream>
using namespace std;

#define BOARD_WIDTH 64
#define BOARD_HEIGTH 40

class Game {
 public:
  Game();
  Game(const Game &g);
  ~Game();

  int width() { return BOARD_WIDTH; }
  int height() { return BOARD_HEIGTH; }

 private:
  string board[BOARD_HEIGTH][BOARD_WIDTH];
};