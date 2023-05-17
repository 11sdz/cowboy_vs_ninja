//
// Created by mintsdz on 5/15/23.
//

#include "Character.hpp"

namespace ariel {
    Character::Character(const string &name, int hp, const Point &location) : _name(name), _hp(hp), _location(location)
                                                                               {}

    int Character::getHp() const {
        return _hp;
    }

    Character::~Character() {

    }

    void Character::hit(int damage) {

    }

    bool Character::isAlive() {
        return false;
    }

    double Character::distance(Character *other) {
        return 0;
    }

    string Character::getName() {
        return std::string();
    }

    Point Character::getLocation() {
        return Point();
    }

} // ariel