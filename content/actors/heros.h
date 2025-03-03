#pragma once

#include "closedoor.h"
#include "herotype.h"
#include "move.h"
#include "none.h"
#include "opendoor.h"
#include "rest.h"
#include "staff_red.h"

namespace Heros {
const std::unordered_map<std::string, Reaction> key_bindings = {
    {"Left",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"Right",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"Up",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"Down",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"Z", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }}};

constexpr int default_speed{8};
const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
const HeroType wizard{"wizard", default_speed, 10,
                      std::make_shared<Staff_red>(2), key_bindings};
// namespace Heros
}  // namespace Heros