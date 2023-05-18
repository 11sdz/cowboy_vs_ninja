//
// Created by mintsdz on 5/15/23.
//

#include "Cowboy.hpp"

namespace ariel{

    Cowboy::Cowboy( const string &name, const Point &location) : Character(name,110 , location),
                                                                                  _ammo(6) {
    }

    void Cowboy::shoot(Character *enemy) const {
        if(this->hasboolets()){
            enemy->hit(_damage);
        }
    }

    bool Cowboy::hasboolets() const {
        return _ammo>0;
    }

    void Cowboy::reload() {
        this->_ammo=6;
    }

    string Cowboy::print() {
        return string("C{"+this->getName()+",\"HP\":"+to_string(110)+
        ",\"location:\""+this->_location.print()+
        ",\"Bullets\":"+ to_string(this->_ammo)+"}");
    }

}