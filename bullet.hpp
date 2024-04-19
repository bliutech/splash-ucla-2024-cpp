#ifndef BULLET_H
#define BULLET_H

#include "actor.hpp"

class Bullet : public Actor {
 public:
  Bullet(int x, int y);

  void tick(Inputs inputs) override;

  string get_actor_symbol() const override;

 private:
  int counter = 0;
};

#endif