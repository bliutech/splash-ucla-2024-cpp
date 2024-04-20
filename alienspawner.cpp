
#include "alienspawner.hpp"

#include "alien.hpp"

static int previous = 0;

// Returns a pseudorandomly generated number.
static int rand_lcg() {
  int next = abs(previous * 1103515245 + 12345);
  previous = next;
  return next % BOARD_WIDTH;
}

AlienSpawner::AlienSpawner(list<Actor*>& actorQueue)
    : masterQueue(actorQueue) {}

void AlienSpawner::tick(Inputs inputs) {
  counter++;

  if (counter % 50 == 0) {
    /*
     * TODO: Add spawning of alien enemies.
     *
     * Every 50 ticks, we want to generate 5 enemies on the board.
     * Write a for loop, which calls the spawn_alien(int x, int y)
     * function 5 times placing aliens in random starting positions
     * at the top of the board (y = 0).
     *
     * Hint: use the rand_lcg() function provided.
     *
     * Note: if 5 aliens seems too difficult for the player, feel free
     * to adjust this number.
     */
    // ============== YOUR CODE HERE ================

    for (int i = 0; i < 5; i++) {
      spawn_alien(rand_lcg(), 0);
    }

    // ==============================================
  }
}

void AlienSpawner::spawn_alien(int x, int y) {
  Alien* newalien = new Alien(x, y, *this);
  numAlive++;
  masterQueue.push_back(newalien);
}

void AlienSpawner::alien_killed() {
  numAlive--;
  numKilled++;
}

// Override this to allow the spawner to always generate aliens
void AlienSpawner::collision(Actor* other) {}