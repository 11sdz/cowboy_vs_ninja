//
// Created by mintsdz on 5/15/23.
//

#include "Character.hpp"

namespace ariel {
    Character::Character(const string &name, int hp, const Point &location) : _name(name), _hp(hp), _location(location)
                                                                               {}

    Character::~Character() {

    }

    int Character::getHp() const {
        return _hp;
    }
} // ariel