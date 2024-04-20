#include "graphics.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "constants.hpp"

using namespace std;

int scoreSize(int n) {
  if (n == 0) return 1;

  int length = 0;
  while (n > 0) {
    length++;
    n /= 10;
  }
  return length;
}

// Prints the game board;
void printScreen(Game& g) {
  string edge = "\e[0;32m";
  for (int i = 0; i < BOARD_WIDTH + 2; ++i) {
    edge += "=";
  }
  edge += "\e[0m";
  string base_line = "\e[0;32m|";
  for (int i = 0; i < BOARD_WIDTH; ++i) {
    base_line += "-";
  }
  base_line += "|\e[0m";
  cout << edge << endl;
  cout << "\e[0;32m|                          \e[0mPixel Panic\e[0;32m         "
          "                  |\e[0m"
       << endl;
  cout << base_line << endl;
  string board_string = "";
  for (int i = 0; i < BOARD_HEIGHT; ++i) {
    string line = "";
    for (int j = 0; j < BOARD_WIDTH; ++j) {
      if (g.board[i][j]) {
        line += g.board[i][j]->get_actor_symbol();
        g.board[i][j] = nullptr;
      } else {
        line += GRAPHICS_NEUTRAL;
      }
    }
    board_string += "\e[0;32m|\e[0m" + line + "\e[0;32m|\e[0m\n";
  }
  cout << board_string;
  cout << base_line << endl;
  cout << "\e[0;32m|                              BASE                         "
          "     |\e[0m"
       << endl;
  cout << base_line << endl;

  string score_padding = "";
  for (int i = 0; i < 9 - scoreSize(g.get_score()); ++i) {
    score_padding += " ";
  }
  string lives_padding = "";
  for (int i = 0; i < 9 - scoreSize(g.get_lives()); ++i) {
    lives_padding += " ";
  }
  cout << "\e[0;32m|\e[0m"
       << "                 "
       << "Score: " << g.get_score() << score_padding << "       "
       << "Lives: " << g.get_lives() << lives_padding << "        "
       << "\e[0;32m|\e[0m" << endl;
  cout << edge << endl;
}

/*
 * Clears the terminal screen.
 *
 * Credit given to David Smallberg (UCLA) for this code.
 */
void clearScreen() {
  static const char* term = getenv("TERM");
  if (term == nullptr || strcmp(term, "dumb") == 0)
    cout << endl;
  else {
    static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
    cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
  }
}