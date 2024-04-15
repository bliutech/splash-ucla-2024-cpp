/*
 * Pixel Panic
 *
 * A game designed to teach C++.
 *
 * Written by Benson Liu & Ming Zhu.
 *
 * Splash at UCLA 2024.
 */

#include <unistd.h>

#include <iostream>

#include "game.hpp"
#include "graphics.hpp"

using namespace std;

int main() {
  Game g = Game();
  g.board[0][0] = ".";
  clearScreen();
  printScreen(g);
  cout << "Count: " << 0 << endl;
  for (int i = 1; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
    usleep(25000);
    g.board[i / BOARD_WIDTH][i % BOARD_WIDTH] = GRAPHICS_PLAYER;
    g.board[(i - 1) / BOARD_WIDTH][(i - 1) % BOARD_WIDTH] = GRAPHICS_NEUTRAL;
    clearScreen();
    printScreen(g);
    cout << "Count: " << i << endl;
  }
  return 0;
}