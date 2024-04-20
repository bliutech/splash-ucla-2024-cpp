#include "bullet.hpp"

Bullet::Bullet(int x, int y) : Actor(x, y) {}

void Bullet::tick(Inputs inputs) {
  counter++;

  set_pos_y(get_pos_y() - 1);

  if (get_pos_y() < 0) {
    Destroy();
  }
}

string Bullet::get_actor_symbol() const { return COLOR_RED "|"; }
