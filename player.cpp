#include "player.hpp"
using namespace std;

Player::Player() { actor_type = 1; }

Player::Player(const Player &p) {}

Player::~Player() {}

void Player::tick(Inputs inputs) {
    switch (inputs.input) {
      case 'A':  // Up key
      case 'w':
        if (pos_y <= 0) {
          pos_y = 0;
          break;
        }
        pos_y--;
        break;
      case 'D':  // Left key
      case 'a':
        if (pos_x <= 0) {
          pos_x = 0;
          break;
        }
        pos_x--;
        break;
      case 'C':  // Right key
      case 'd':
        if (pos_x >= BOARD_WIDTH - 1) {
          pos_x = BOARD_WIDTH - 1;
          break;
        }
        pos_x++;
        break;
      case 'B':
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
