#pragma once

#include "weapon.h"

class Staff_red : public Weapon {
public: 
    Staff_red(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};