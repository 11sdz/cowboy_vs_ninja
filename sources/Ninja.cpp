//
// Created by mintsdz on 5/15/23.
//

#include "Ninja.hpp"
namespace ariel{
    Ninja::Ninja( const string &name, int hp, const Point &location, int speed) : Character(name, hp , location),
                                                                                 _speed(speed) {}

    void Ninja::move(Character *enemy) {

    }

    void Ninja::slash(Character *enemy) {

    }


}