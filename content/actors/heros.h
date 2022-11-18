#pragma once

#include "herotype.h"
#include "move.h"
#include "none.h"

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
    {"Z", []() {
         return std::make_unique<Move>(Vec{0, 0});
     }}};

constexpr int default_speed{8};
const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
const HeroType wizard{"wizard", default_speed, 1, std::make_shared<None>(),
                      key_bindings};
}  // namespace Heros
