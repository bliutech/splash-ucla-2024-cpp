#include "game.hpp"
using namespace std;

Game::Game() {
  for (int i = 0; i < width(); ++i) {
    for (int j = 0; j < height(); ++j) {
      board[i][j] = ".";
    }
  }
};

Game::Game(const Game &g) {
  for (int i = 0; i < width(); ++i) {
    for (int j = 0; j < height(); ++j) {
      board[i][j] = g.board[i][j];
    }
  }
};

Game::~Game() { cout << "Game over!" << endl; };