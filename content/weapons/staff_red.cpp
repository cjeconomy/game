#include "staff_red.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Staff_red::Staff_red(int damage) : Weapon{"staff_red", damage} {}

void Staff_red::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}