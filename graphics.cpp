#include "graphics.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "constants.hpp"

using namespace std;

// Prints the game board;
void printScreen(Game& g) {
  string edge = "\e[0;32m";
  for (int i = 0; i < BOARD_WIDTH + 2; ++i) {
    edge += "=";
  }
  edge += "\e[0m";
  cout << edge << endl;
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
    cout << "\e[0;32m|\e[0m" << line << "\e[0;32m|\e[0m" << endl;
  }
  string base_line = "\e[0;32m|";
  for (int i = 0; i < BOARD_WIDTH; ++i) {
    base_line += "-";
  }
  base_line += "|\e[0m";
  cout << base_line << endl;
  cout << "\e[0;32m|                              BASE                         "
          "     |\e[0m"
       << endl;
  cout << edge << endl;
  cout << "Score: " << g.get_score() << endl;
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