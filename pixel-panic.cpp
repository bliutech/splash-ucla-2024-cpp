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
  int i = 0;
  Game g = Game();
  int px = 0, py = 0;
  g.board[px][py] = GRAPHICS_PLAYER;
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

    tv.tv_sec = 0;
    tv.tv_usec = 50000;

    FD_ZERO(&set);
    FD_SET(fileno(stdin), &set);

    count += 1;
    clearScreen();
    printScreen(g);
    cout << "Count: " << count << endl;

    // Dummy alien.
    g.board[i / BOARD_WIDTH][i % BOARD_HEIGHT] = GRAPHICS_NEUTRAL;
    i = count % (BOARD_WIDTH * BOARD_HEIGHT);
    g.board[i / BOARD_WIDTH][i % BOARD_HEIGHT] = GRAPHICS_ALIEN;

    int res = select(fileno(stdin) + 1, &set, NULL, NULL, &tv);
    if (res < 0) {
      perror("Error handling keypress.");
      break;
    } else if (res == 0) {
      cout << "Timeout" << endl;
      // Currently, this sleep is not necessary but maybe need to handle this
      // later on. usleep(5000000);
      continue;
    }

    char c;
    cout << "Input available." << endl;
    read(fileno(stdin), &c, 1);
    cout << c << endl;

    // TODO: Add switch statement to handle certain key presses as movement.
    // TODO: Make sure alien movement is different than player movement.
    // Currently, each cycle through the loop is essentially determined by
    // whether or not a player made a keypress.
    switch (c) {
      case 'A':  // Up key
      case 'w':
        if (py <= 0) {
          py = 0;
          break;
        }
        g.board[py][px] = GRAPHICS_NEUTRAL;
        g.board[py - 1][px] = GRAPHICS_PLAYER;
        py--;
        break;
      case 'D':  // Left key
      case 'a':
        if (px <= 0) {
          px = 0;
          break;
        }
        g.board[py][px] = GRAPHICS_NEUTRAL;
        g.board[py][px - 1] = GRAPHICS_PLAYER;
        px--;
        break;
      case 'C':  // Right key
      case 'd':
        if (px >= BOARD_WIDTH - 1) {
          px = BOARD_WIDTH - 1;
          break;
        }
        g.board[py][px] = GRAPHICS_NEUTRAL;
        g.board[py][px + 1] = GRAPHICS_PLAYER;
        px++;
        break;
      case 'B':
      case 's':  // Down key
        if (py >= BOARD_HEIGHT - 1) {
          py = BOARD_HEIGHT - 1;
          break;
        }
        g.board[py][px] = GRAPHICS_NEUTRAL;
        g.board[py + 1][px] = GRAPHICS_PLAYER;
        py++;
        break;
      default:
        break;
    }

    usleep(100000);
  }

  tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
  return 0;
}