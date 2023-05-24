//
// Created by mintsdz on 5/15/23.
//

#include "Cowboy.hpp"

namespace ariel{

    Cowboy::Cowboy( const string &name, const Point &location) : Character(name,110 , location),
                                                                                  _ammo(6) {
    }

    void Cowboy::shoot(Character *enemy) {
        if(enemy==this){
            throw runtime_error("shoot:self harm");
        }else if((!this->isAlive()) || (!enemy->isAlive())){
            throw runtime_error("shoot:dead enemy or dead cowboy");
        }
        if(this->hasboolets()){
            enemy->hit(_damage);
            this->_ammo=_ammo-1;
        }
    }

    bool Cowboy::hasboolets() const {
        return _ammo>0;
    }

    void Cowboy::reload() {
        if(!this->isAlive()){
            throw runtime_error("reload:dead cowboy");
        }
        this->_ammo=6;
    }

    string Cowboy::print() {
        string str("C{");
        if(isAlive()){
            str=str+this->getName()+",\"HP\":"+ to_string(getHp())+",\"location\":"+getLocation().print()+",\"Bullets\":"+to_string(this->_ammo)+"}";
        }else{
            str=str+this->getName()+",\"location\":"+getLocation().print()+",\"Bullets\":"+to_string(this->_ammo)+"}";
        }
        return str;
    }

}