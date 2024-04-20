#include "alien.hpp"

#include "constants.hpp"
#include "game.hpp"
using namespace std;

Alien::Alien(int x, int y, AlienSpawner& spawner)
    : Actor::Actor(x, y), spawnerRef(spawner) {}

void Alien::tick(Inputs input) {
  counter++;

  /*
   * TODO: Add alien zig-zagging.
   *
   * Current, in the code below, the alien falls straight down
   * towards the player. To make the game more challenging, we want
   * the aliens to zig-zag instead. Implement adding zig-zagging to
   * the aliens fall.
   *
   * Hint: use the provided functions...
   *  - set_pos_x(), set_pos_y(): sets the position of the alien.
   *  - get_pos_x(), get_pos_y(): gets the current position of the alien.
   *
   * Note: Currently, this is called for every 5 ticks but feel free
   * to adjust this number depending on how you think the game should
   * look like.
   */
  // ============== YOUR CODE HERE ================

  // Example. Alien falling down directly.
  if (counter % 5 == 0) {
    set_pos_y(get_pos_y() + 1);
  }

  // ==============================================

  if (get_pos_y() >= BOARD_HEIGHT) {
    spawnerRef.alien_killed();
    Destroy();

    // hits base
    Game::dying();
  }
}

string Alien::get_actor_symbol() const { return COLOR_BLUE "A"; }
void Alien::collision(Actor* other) {
  Destroy();
  Game::scoring();
}
