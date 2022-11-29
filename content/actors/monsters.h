#pragma once

#include <iostream>

#include "action.h"
#include "engine.h"
#include "monstertype.h"
#include "rest.h"
#include "move.h"
#include "none.h"
#include "wander.h"


std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me); 
MonsterType goblin(); 