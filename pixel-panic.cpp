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
#include <list>

#include "game.hpp"
#include "graphics.hpp"
#include "actor.hpp"
#include "player.hpp"

using namespace std;

int main() {
  int count = 0;
  int i = 0;
  Game g = Game();
  list<Actor*> actors;

  int px = BOARD_WIDTH / 2;
  int py = BOARD_HEIGHT - 1;

  Player plr = Player(px, py);
  actors.push_back(&plr);

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

    Inputs inputs;
    inputs.input = c;
    inputs.hasInput = true;

    list<Actor*>::iterator iter = actors.begin();

    for (; iter != actors.end(); iter++) {
      *iter->tick(inputs);  // Compute...

      // Then draw
      int x, y = *iter->get_pos_x(), *iter->get_pos_y();

      switch (*iter->get_actor_type()) {
        case 1:  // Player
          g.board[x][y] = GRAPHICS_PLAYER;
          break;
        case 2:  // Alien 
          g.board[x][y] = GRAPHICS_ALIEN;
          break;
        default:
        g.board[x][y] = GRAPHICS_NEUTRAL;
          break;
      } 
    }


    /*
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
    */

    usleep(100000);
  }

  tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
  return 0;
}