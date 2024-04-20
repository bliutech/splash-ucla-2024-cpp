#include "player.hpp"

#include "bullet.hpp"
#include "constants.hpp"
#include "missile.hpp"

using namespace std;

Player::Player(const Player& p) : Actor::Actor(p), masterRef(p.masterRef) {}

Player::Player(int x, int y, list<Actor*>& master)
    : Actor::Actor(x, y), masterRef(master) {}

void Player::tick(Inputs inputs) {
  if (inputs.hasInput) {
    /*
     * TODO: Add handling for shooting the laser.
     *
     * If the keyboard input is a space character (i.e. " "),
     * then you can call the shoot() function.
     */
    // ============== YOUR CODE HERE ================

    if (inputs.input == ' ') {
      shoot();
    }

    // ==============================================

    switch (inputs.input) {
      case 'A':  // Up key
      case 'w':
        if (pos_y <= 0) {
          pos_y = 0;
          break;
        }
        if (pos_y <= BOARD_HEIGHT - 8) {
          pos_y = BOARD_HEIGHT - 8;
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
      case 'f':
        shoot_missile();
        break;
      default:
        break;
    }
  }
}

void Player::shoot() {
  Bullet* blt = new Bullet(get_pos_x(), get_pos_y() - 1);
  masterRef.push_back(blt);
}

void Player::shoot_missile() {
  // TODO: Uncomment me once missile.hpp is finished.
  Missile* msl = new Missile(get_pos_x(), get_pos_y() - 1);
  masterRef.push_back(msl);
}

string Player::get_actor_symbol() const { return COLOR_RED "P" COLOR_WHITE; }

void Player::collision(Actor* other) {}