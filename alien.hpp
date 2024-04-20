#ifndef ALIEN_H
#define ALIEN_H

#include <string>

#include "actor.hpp"
#include "alienspawner.hpp"

using namespace std;

class Alien : public Actor {
 public:
  Alien(int x, int y, AlienSpawner& spawner);

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

  string get_actor_symbol() const override;
  void collision(Actor* other) override;

 private:
  // int pos_x, pos_y;
  AlienSpawner& spawnerRef;
  unsigned int counter = 0;
};

#endif