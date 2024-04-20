
#include "alienspawner.hpp"

#include "alien.hpp"

AlienSpawner::AlienSpawner(list<Actor*>& actorQueue)
    : masterQueue(actorQueue) {}

void AlienSpawner::tick(Inputs inputs) {
  counter++;

  if (counter % 50 == 0) {
    spawn_alien(counter % BOARD_WIDTH, 0);
  }
}

void AlienSpawner::spawn_alien(int x, int y) {
  Alien* newalien = new Alien(x, y, *this);
  numAlive++;
  masterQueue.push_back(newalien);

  // aliens.push_back(&newalien);
}

void AlienSpawner::alien_killed() {
  numAlive--;
  numKilled++;
}
