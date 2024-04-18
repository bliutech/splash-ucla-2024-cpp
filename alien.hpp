#ifndef ALIEN_H
#define ALIEN_H

#include "actor.hpp"

class Alien : public Actor {
 public:
  Alien();
  Alien(const Alien &a);
  Alien(int x, int y);

  void tick(Inputs inputs);
  /*
  int get_pos_x() { return pos_x; }
  int get_pos_y() { return pos_y; }

  void move_left() { pos_x -= 1; }
  void move_right() { pos_x += 1; }

  // Note: remember that (0, 0) is the upper-left hand corner.
  void move_up() { pos_y -= 1; }
  void move_down() { pos_y += 1; }
  */

 private:
  // int pos_x, pos_y;
};

#endif