#include "game.hpp"
using namespace std;

int Game::lives = MAX_LIVES;
int Game::score = 0;

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

Game::~Game() {
  cout << endl;
  cout << "Game over!" << endl;
  cout << "Final score: " << get_score() << endl;
  cout << "Thanks for playing!" << endl;
};