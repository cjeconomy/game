#include "engine.h"
#include "heros.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::wizard);
    MonsterType new_monster_type = Monsters::goblin(); 
    engine.create_monster(new_monster_type); 
    MonsterType new_monster_type = Monsters::orc_shaman(); 
    engine.create_monster(new_monster_type); 
    MonsterType new_monster_type = Monsters::demon_big(); 
    engine.create_monster(new_monster_type); 
    engine.run();
}
