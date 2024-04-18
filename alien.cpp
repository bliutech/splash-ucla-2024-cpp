#include "alien.hpp"

Alien::Alien() : Actor::Actor() { actor_type = 2; }

Alien::Alien(const Alien &a) : Actor::Actor(a) {}

Alien::Alien(int x, int y) : Actor::Actor(x, y) {}


void Alien::tick(Inputs input) {}