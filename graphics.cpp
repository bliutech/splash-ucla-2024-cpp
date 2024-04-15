#include <cstdlib>
#include <cstring>
#include <iostream>

#include "constants.hpp"

using namespace std;

/*
 * printScreen implementation
 *
 * Prints the game board;
 *
 * TODO: Pass in a Game object as a parameter and print out the board.
 */
void printScreen() {
  string edge = "";
  for (int i = 0; i < BOARD_WIDTH + 2; ++i) {
    edge += "=";
  }
  cout << edge << endl;
  for (int i = 0; i < BOARD_HEIGHT; ++i) {
    string line = "";
    for (int j = 0; j < BOARD_WIDTH; ++j) {
      line += ".";
    }
    cout << "|" << line << "|" << endl;
  }
  cout << edge << endl;
}

/*
 * clearScreen implementation
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