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
        if(damage<0){
            throw invalid_argument("hit:negative damage");
        }
        this->_hp=((_hp-damage)<=0)?0:_hp-damage;
    }

    bool Character::isAlive() {
        return (this->_hp>0);
    }

    double Character::distance(Character *other) {
        return this->_location.distance(other->_location);
    }

    string Character::getName() {
        return this->_name;
    }

    Point Character::getLocation() {
        return this->_location;
    }

} // ariel