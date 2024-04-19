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

    // event loop
    // for all bullets, bullet.move() <- bullets only move in a straight line up
    // for all aliens, alien.fall() <- aliens only move down in a straight line
    // check if the location of any bullet is in the location of any alien.
    // Destroy an alien if it does. player keyboard logic check if the location
    // of any alien is > some y value (if they hit the base, then the player
    // loses a life) or if they specifically hit the player, then they lose a
    // life

    // Implementation Notes:
    // probably just need to add a couple of vectors of aliens and bullets to
    // iterate over in each event loop there is a bug where the player's sprite
    // get's temporarily overrided by the blank that is added there by the
    // alien's graphics loop.

    count += 1;
    clearScreen();
    printScreen(g);
    cout << "Count: " << count << endl;

    // Dummy alien.
    /*
    g.board[i / BOARD_WIDTH][i % BOARD_WIDTH] = GRAPHICS_NEUTRAL;
    i = count % (BOARD_WIDTH * BOARD_WIDTH);
    g.board[i / BOARD_WIDTH][i % BOARD_WIDTH] = GRAPHICS_ALIEN;
    */

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
      // TODO: Add switch statement to handle certain key presses as movement.
      // TODO: Make sure alien movement is different than player movement.
      // Currently, each cycle through the loop is essentially determined by
      // whether or not a player made a keypress.
    }

    for (auto iter = actors.begin(); iter != actors.end();) {
      (*iter)->tick(inputs);  // Compute...

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

      // cout << x << ", " << y << endl;

      ++iter;
    }

    usleep(10000);
  }

  tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
  return 0;
}