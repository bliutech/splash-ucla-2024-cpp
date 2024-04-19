#ifndef ALIENSPAWNER_H
#define ALIENSPAWNER_H

#include <list>

#include "actor.hpp"

using namespace std;

class AlienSpawner : public Actor {
 public:
  AlienSpawner(list<Actor*>& actorQueue);

  void tick(Inputs inputs) override;

  void spawn_alien(int x, int y);

  void alien_killed();

 private:
  // vector<Alien*> aliens;
  int numAlive = 0;
  int numKilled = 0;
  unsigned int counter = 0;
  list<Actor*>& masterQueue;
};

#endif