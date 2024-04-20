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
#include <iterator>
#include <list>

#include "actor.hpp"
#include "alienspawner.hpp"
#include "game.hpp"
#include "graphics.hpp"
#include "player.hpp"

using namespace std;

int main() {
  int count = 0;
  // int i = 0;
  Game g = Game();
  list<Actor*> actors;

  int px = BOARD_WIDTH / 2;
  int py = BOARD_HEIGHT - 1;

  // Player plr = Player(px, py);
  actors.push_back(new Player(px, py, actors));
  actors.push_back(new AlienSpawner(actors));

  // g.board[py][px] = GRAPHICS_PLAYER;
  clearScreen();
  printScreen(g);

  // cout << "Count: " << count << endl;

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

    Inputs inputs;
    inputs.hasInput = false;

    int res = select(fileno(stdin) + 1, &set, NULL, NULL, &tv);
    if (res < 0) {
      perror("Error handling keypress.");
      break;

    } else {
      char c;
      while (res > 0) {
        read(fileno(stdin), &c, 1);
        inputs.input = c;
        inputs.hasInput = true;

        res = select(fileno(stdin) + 1, &set, NULL, NULL, &tv);
      }
    }

    for (auto iter = actors.begin(); iter != actors.end();) {
      (*iter)->tick(inputs);

      if ((*iter)->toDestroy) {
        delete (*iter);
        iter = actors.erase(iter);
        continue;
      }

      // Then draw
      int x = (*iter)->get_pos_x();
      int y = (*iter)->get_pos_y();

      if (!(*iter)->is_out_of_bounds()) {
        if (g.board[y][x]) {
          g.board[y][x]->collision(*iter);
          (*iter)->collision(g.board[y][x]);
          g.board[y][x] = nullptr;
        } else {
          g.board[y][x] = *iter;
        }
      }

      ++iter;
    }

    if (g.get_lives() <= 0) {
      // Game over!
      break;
    }

    usleep(10000);
  }

  tcsetattr(fileno(stdin), TCSANOW, &oldSettings);

  clearScreen();

  // Cleanup
  for (auto iter = actors.begin(); iter != actors.end();) {
    delete (*iter);
    iter = actors.erase(iter);
  }
  return 0;
}