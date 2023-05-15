//
// Created by mintsdz on 5/15/23.
//

#include "Cowboy.hpp"
namespace ariel{

    Cowboy::Cowboy( const string &name, const Point &location) : Character(name,110 , location),
                                                                                  _ammo(6) {

    }

    void Cowboy::shoot(Character *enemy) {

    }

    bool Cowboy::hasboolets() {
        return false;
    }

    void Cowboy::reload() {

    }


}