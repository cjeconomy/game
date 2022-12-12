#pragma once

#include "weapon.h"

class Sword_big : public Weapon {
public:
    Sword_big(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};