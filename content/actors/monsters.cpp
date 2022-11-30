#include "monsters.h"

std::unique_ptr<Action> default_behavior(Engine&, Monster&) {
    return std::make_unique<Rest>();
}
int default_speed = 8;
MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior};
}
MonsterType orc_shaman() {
    int health = 3;
    return {"orc_shaman", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType demon_big() {
    int health = 5;
    return {"demon_big", default_speed, health, std::make_shared<None>(),
            default_behavior};
}