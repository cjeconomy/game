#pragma once

#include "move.h"

class Attack : public Action {
public:
    Attack(Actor& defender);
    Result perform(Engine&) override;
    Actor& defender;
};