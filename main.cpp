#include "engine.h"
#include "heros.h"
#include "monster.h"
#include "monsters.h"
#include "monstertype.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::wizard);
    MonsterType new_monster_type = goblin();
    engine.create_monster(new_monster_type);
    MonsterType shaman_orc = orc_shaman();
    engine.create_monster(shaman_orc);
    MonsterType big_demon = demon_big();
    engine.create_monster(big_demon);
    engine.run();
}
