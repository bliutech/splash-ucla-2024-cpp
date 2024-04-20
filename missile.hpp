#ifndef MISSILE_H
#define MISSILE_H

#include "actor.hpp"

/*
 * TODO: Implement the Missile class.
 *
 * We want to add a special new type of bullet that
 * the player can shoot called a Missile. What's special
 * about a Missile, is that it can zig-zag while shooting.
 *
 * Write the Missile class that inherits from the Actor class.
 * You will need to write a constructor
 *
 * Hint: check out the implementation of the Bullet class to get
 * a reference for how this might work.
 *
 * Note: You will have to add code to both missile.hpp and missile.cpp
 * and then uncommenting a couple of functions in player.hpp and player.cpp.
 */
// ============== YOUR CODE HERE ================

class Missile : public Actor {
 public:
  Missile(int x, int y);

  void tick(Inputs inputs) override;

  string get_actor_symbol() const override;

 private:
  int counter = 0;
};

// ==============================================

#endif