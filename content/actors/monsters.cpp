#include "monsters.h"

#include "knife.h"
#include "monster.h"
#include "monstertype.h"
#include "randomness.h"
#include "sword.h"
#include "sword_big.h"

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (me.is_visible() && engine.hero) {
        Vec from = me.get_position();
        Vec to = engine.hero->get_position();
        std::vector<Vec> path = engine.dungeon.calculate_path(from, to);
        if (path.size() > 1) {
            if (me.is_fearful()) {
                Vec direction = path.at(0) - path.at(1);
                Tile& tile = engine.dungeon.tiles(from + direction);
                if (tile.is_wall()) {
                    return std::make_unique<Rest>();
                }
                return std::make_unique<Move>(direction);
            }
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    // Monster doesn't see Hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}

constexpr int default_speed = 8;
MonsterType goblin() {
    int health = 6;
    return {"goblin", default_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}
MonsterType orc_shaman() {
    int health = 6;
    return {"orc_shaman", default_speed, health, std::make_shared<Sword>(1),
            default_behavior};
}

MonsterType demon_big() {
    int health = 5;
    return {"demon_big", default_speed, health, std::make_shared<Sword_big>(3),
            default_behavior};
}