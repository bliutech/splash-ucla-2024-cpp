#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <string>

#include "actor.hpp"

using namespace std;

class Player : public Actor {
 public:
  Player(const Player& p);
  Player(int x, int y, list<Actor*>& master);

  void tick(Inputs inputs);

  void shoot();
  void shoot_missile();

  string get_actor_symbol() const override;
  void collision(Actor* other) override;

 private:
  list<Actor*>& masterRef;
};

#endif