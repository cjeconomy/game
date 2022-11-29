#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include "monstertype.h"
#include "monster.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::wizard);  
    MonsterType new_monster_type = goblin();  
    engine.create_monster(new_monster_type);    
    engine.run();
}
