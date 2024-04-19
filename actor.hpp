#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "constants.hpp"
using namespace std;

struct Inputs {  // We simplify amount of inputs acquired to one per tick
  bool hasInput;
  char input;
  Inputs() {
    hasInput = false;
    input = 0;
  }
};

class Actor {
 public:
  Actor() = default;
  Actor(const Actor& a) = default;
  Actor(int x, int y) {
    pos_x = x;
    pos_y = y;
  };
  virtual ~Actor() = default;

  void set_pos_x(int pos) { pos_x = pos; }
  void set_pos_y(int pos) { pos_y = pos; }

  int get_pos_x() { return pos_x; }
  int get_pos_y() { return pos_y; }

  void move_left() { pos_x -= 1; }
  void move_right() { pos_x += 1; }

  // Note: remember that (0, 0) is the upper-left hand corner.
  void move_up() { pos_y -= 1; }
  void move_down() { pos_y += 1; }

  virtual void tick(Inputs inputs){};

  virtual void collision(Actor* other) { Destroy(); };

  void Destroy() { toDestroy = true; }

  bool toDestroy = false;

  virtual string get_actor_symbol() const { return " "; }

  bool is_out_of_bounds() {
    return pos_x < 0 || pos_x >= BOARD_WIDTH || pos_y < 0 ||
           pos_y >= BOARD_HEIGHT;
  }

 protected:
  int pos_x = 0, pos_y = 0;
};

#endif