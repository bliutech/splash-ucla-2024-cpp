#include "missile.hpp"

// TODO: UN-COMMENT ME ONCE missile.hpp is finished.
Missile::Missile(int x, int y) : Actor(x, y) {}

/*
 * TODO: Add zig-zagging to the Missile.
 *
 * Current, in the code below, the Missile shoots straight up
 * towards the aliens. Help implement zig-zagging to the Missile.
 *
 * Hint: use the provided functions...
 *  - set_pos_x(), set_pos_y(): sets the position of the Missile.
 *  - get_pos_x(), get_pos_y(): gets the current position of the Missile.
 *
 * Note: Currently, this is called for every 5 ticks but feel free
 * to adjust this number depending on how you think the game should
 * look like.
 */

// TODO: UN-COMMENT ME ONCE missile.hpp is finished.
void Missile::tick(Inputs inputs) {
  counter++;

  // ============== YOUR CODE HERE ================

  // Example. Bullet flying.
  if (counter % 5 == 0) {
    set_pos_y(get_pos_y() - 1);
  } else if (counter % 5 == 1) {
    set_pos_x(get_pos_x() + 1);
    set_pos_y(get_pos_y() - 1);
  } else if (counter % 5 == 2) {
    set_pos_x(get_pos_x() - 1);
    set_pos_y(get_pos_y() - 1);
  } else if (counter % 5 == 3) {
    set_pos_x(get_pos_x() - 1);
    set_pos_y(get_pos_y() - 1);
  } else if (counter % 5 == 4) {
    set_pos_x(get_pos_x() + 1);
    set_pos_y(get_pos_y() - 1);
  }

  // ==============================================

  if (get_pos_y() < 0) {
    Destroy();
  }
}

// TODO: UN-COMMENT ME ONCE missile.hpp is finished.
string Missile::get_actor_symbol() const { return COLOR_RED "^"; }
