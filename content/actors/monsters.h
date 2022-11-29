#pragma once

#include <iostream>

#include "action.h"
#include "engine.h"
#include "monstertype.h"
#include "rest.h"
#include "move.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);
MonsterType goblin();
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    return std::make_unique<Rest>();
}
constexpr int default_speed{8};
MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType orc_shaman() {
    int health = 4;
    return {"orc_shaman", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType demon_big() {
    int health = 5;
    return {"demon_big", default_speed, health, std::make_shared<None>(),
            default_behavior};
}
}  