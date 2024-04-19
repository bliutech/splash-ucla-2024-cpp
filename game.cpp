#include "game.hpp"
using namespace std;

Game::Game() {
  for (int i = 0; i < BOARD_HEIGHT; ++i) {
    for (int j = 0; j < BOARD_WIDTH; ++j) {
      board[i][j] = nullptr;
    }
  }
};

Game::Game(const Game &g) {
  for (int i = 0; i < BOARD_HEIGHT; ++i) {
    for (int j = 0; j < BOARD_WIDTH; ++j) {
      board[i][j] = g.board[i][j];
    }
  }
};

Game::~Game() { cout << "Game over!" << endl; };