#include "staff_red.h"
#include "hit.h"
#include "engine.h"

Staff_red::Staff_red(int damage) : Weapon{"staff_red", damage} {}

void Staff_red::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}