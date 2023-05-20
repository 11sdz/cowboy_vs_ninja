//
// Created by mintsdz on 5/15/23.
//

#include "Character.hpp"
#include "iostream"
namespace ariel {

    Character::Character(const string &name, int hitPoints, const Point &location) : _name(name), _hp(hitPoints), _location(location) , _team(
            nullptr)
                                                                               {}

    int Character::getHp() const {
        return _hp;
    }

    Character::~Character() = default;

    void Character::hit(int damage) {
        if(damage<0){
            throw invalid_argument("hit:negative damage");
        }
        this->_hp=((_hp-damage)<=0)?0:_hp-damage;
    }

    bool Character::isAlive() const{
        return (this->_hp>0);
    }

    double Character::distance(Character *other){
        if(this->_location==other->_location){
            return 0;
        }
        return this->_location.Point::distance(other->_location);
    }

    string Character::getName() {
        return this->_name;
    }

    Point Character::getLocation() {
        return this->_location;
    }

    Team *Character::getTeam() const {
        return _team;
    }

    void Character::setTeam(Team *team) {
        _team = team;
    }

} // ariel