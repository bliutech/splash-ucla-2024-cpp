#include "alien.hpp"

#include "constants.hpp"
#include "game.hpp"
using namespace std;

Alien::Alien(int x, int y, AlienSpawner& spawner)
    : Actor::Actor(x, y), spawnerRef(spawner) {}

void Alien::tick(Inputs input) {
  counter++;

  if (counter % 5 == 0) {
    set_pos_y(get_pos_y() + 1);
    if (get_pos_y() >= BOARD_HEIGHT) {
      spawnerRef.alien_killed();
      Destroy();

      // hits base
      Game::dying();
    }
  }
}

string Alien::get_actor_symbol() const { return COLOR_BLUE "A"; }
void Alien::collision(Actor* other) {
  Destroy();
  Game::scoring();
}
