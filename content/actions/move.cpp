#include "move.h"

#include <iostream>

#include "actor.h"
#include "attack.h"
#include "closedoor.h"
#include "door.h"
#include "dungeon.h"
#include "engine.h"
#include "opendoor.h"
#include "tile.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    actor->change_direction(direction);

    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall() || tile.actor) {
        return failure();
    } else if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(new_position);
        if (!door.is_open()) {
            return alternative(OpenDoor{new_position});
        }
    } else {
        actor->move_to(new_position);
        return success();
    };  // always return something (success, failure,
        // alternative.)
    /* if (tile.actor) {
        return alternative(Attack{tile.actor});
    } */
}
