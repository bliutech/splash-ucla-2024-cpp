#include "player.hpp"
using namespace std;

Player::Player() : Actor::Actor() { actor_type = 1; }

Player::Player(const Player &p) : Actor::Actor(p) {}

Player::Player(int x, int y) : Actor::Actor(x, y) {}


void Player::tick(Inputs inputs) {
    switch (inputs.input) {
      case 'W':  // Up key
      case 'w':
        if (pos_y <= 0) {
          pos_y = 0;
          break;
        }
        pos_y--;
        break;
      case 'A':  // Left key
      case 'a':
        if (pos_x <= 0) {
          pos_x = 0;
          break;
        }
        pos_x--;
        break;
      // Right key
      case 'D':
      case 'd':
        if (pos_x >= BOARD_WIDTH - 1) {
          pos_x = BOARD_WIDTH - 1;
          break;
        }
        pos_x++;
        break;
      case 'S':
      case 's':  // Down key
        if (pos_y >= BOARD_HEIGHT - 1) {
          pos_y = BOARD_HEIGHT - 1;
          break;
        }
        pos_y++;
        break;
      default:
        break;
    }
}
