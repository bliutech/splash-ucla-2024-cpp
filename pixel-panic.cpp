/*
 * Pixel Panic
 *
 * A game designed to teach C++.
 *
 * Written by Benson Liu & Ming Zhu.
 *
 * Splash at UCLA 2024.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

#include <iostream>

#include "game.hpp"
#include "graphics.hpp"

using namespace std;

int main() {
  int count = 0;
  Game g = Game();
  g.board[0][0] = GRAPHICS_PLAYER;
  clearScreen();
  printScreen(g);
  cout << "Count: " << count << endl;

  // Setup keyboard handling
  // https://stackoverflow.com/questions/18281412/check-keypress-in-c-on-linux
  struct termios oldSettings, newSettings;

  tcgetattr(fileno(stdin), &oldSettings);
  newSettings = oldSettings;
  newSettings.c_lflag &= (~ICANON & ~ECHO);
  tcsetattr(fileno(stdin), TCSANOW, &newSettings);
  while (1) {
    fd_set set;
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;

    FD_ZERO(&set);
    FD_SET(fileno(stdin), &set);

    count += 1;

    int res = select(fileno(stdin) + 1, &set, NULL, NULL, &tv);
    if (res < 0) {
      perror("Error handling keypress.");
      break;
    } else if (res == 0) {
      cout << "Timeout" << endl;
      // Currently, this sleep is not necessary but maybe need to handle this
      // later on. sleep(5000000);
      continue;
    }

    clearScreen();
    printScreen(g);
    cout << "Count: " << count << endl;

    char c;
    cout << "Input available." << endl;
    read(fileno(stdin), &c, 1);
    cout << c << endl;

    // TODO: Add switch statement to handle certain key presses as movement.
    // TODO: Make sure alien movement is different than player movement.
    // Currently, each cycle through the loop is essentially determined by
    // whether or not a player made a keypress.
  }

  tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
  return 0;
}