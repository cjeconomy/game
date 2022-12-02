#include "opendoor.h"

#include <iostream>

#include "actor.h"
#include "dungeon.h"
#include "engine.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Vec position) : position{position} {}

Result OpenDoor::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        door.open();
        tile.walkable = true;
        engine.events.add(UpdateFOV{});
        return success();
    } else {
        return failure();
    }
}
