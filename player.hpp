#ifndef PLAYER_H
#define PLAYER_H

#include "constants.hpp"

class Player {
 public:
  Player();
  Player(const Player &p);
  ~Player();

  int get_pos_x() { return pos_x; }
  int get_pos_y() { return pos_y; }

  int get_num_bullets() { return num_bullets; }
  int get_health() { return health; }

  void move_left() { pos_x -= 1; }
  void move_right() { pos_y -= 1; }

  void shoot() { num_bullets -= 1; }
  void take_damage(int damage) {
    health = health - damage < 0 ? 0 : health - damage;
  }

 private:
  int pos_x, pos_y;
  int num_bullets;
  int health;
};

#endif