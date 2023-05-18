//
// Created by mintsdz on 5/15/23.
//

#include "Ninja.hpp"
namespace ariel{
    Ninja::Ninja( const string &name, int hp, const Point &location, int speed) : Character(name, hp , location),
                                                                                 _speed(speed) {}

    void Ninja::move(Character *enemy) {
        this->_location=Point::moveTowards(_location,enemy->getLocation(),_speed);
    }

    void Ninja::slash(Character *enemy) {
        enemy->hit(_damage);
    }

    string Ninja::print() {
        string str("N{");
        if(isAlive()){
            str=str+this->getName()+",\"HP\":"+ to_string(_hp)+","+",\"location\":"+_location.print()+",\"Speed\":"+to_string(this->_speed)+"}";
        }else{
            str=str+this->getName()+",\"location\":"+_location.print()+",\"Speed\":"+to_string(this->_speed)+"}";
        }
        return str;
    }

    Ninja::~Ninja() {

    }


}