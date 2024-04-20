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

  string get_actor_symbol() const override;
  void collision(Actor* other) override;

 private:
  AlienSpawner& spawnerRef;
  unsigned int counter = 0;
};

#endif