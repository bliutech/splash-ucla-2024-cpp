
#include "alienspawner.hpp"

#include "alien.hpp"

static int previous = 0;

static int lcg() {
  int next = previous * 1103515245 + 12345;
  previous = next;
  return next;
}

AlienSpawner::AlienSpawner(list<Actor*>& actorQueue)
    : masterQueue(actorQueue) {}

void AlienSpawner::tick(Inputs inputs) {
  counter++;

  if (counter % 50 == 0) {
    spawn_alien(lcg() % BOARD_WIDTH, 0);
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

// Override this to allow the spawner to always generate aliens
void AlienSpawner::collision(Actor* other) {}