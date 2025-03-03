#include "wander.h"


#include "randomness.h"

#include "actor.h"
#include "engine.h"
#include "monster.h"
#include "move.h"
#include "tile.h"
#include "rest.h"




Result Wander::perform(Engine& engine) {
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    // randomize directions
    shuffle(std::begin(neighbors), std::end(neighbors));
    for (const Vec& neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (!tile.is_wall() && !tile.actor) {
            Vec direction = neighbor - position;
            return alternative(Move{direction});
        }
    }
    return alternative(Rest());
}