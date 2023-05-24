//
// Created by mintsdz on 5/15/23.
//

#include "Ninja.hpp"
namespace ariel{
    Ninja::Ninja(const string &name, int _hp, const Point &location, int speed) : Character(name, _hp , location),
                                                                                  _speed(speed) {}

    Ninja::Ninja() {
        this->_speed=0;
        this->_damage=40;
    }

    Ninja::Ninja(const Ninja& other){
        this->_speed=other._speed;
        this->_damage=other._damage;
    }

    Ninja::Ninja(Ninja&& other) noexcept{
        this->_speed=other._speed;
        this->_damage=other._damage;
    }

    Ninja& Ninja::operator=(const Ninja& other) {
        this->_speed=other._speed;
        this->_damage=other._damage;
        return *this;
    }

    Ninja& Ninja::operator=(Ninja&& other) noexcept{
        this->_speed=other._speed;
        this->_damage=other._damage;
        return *this;
    }

    void Ninja::move(Character *enemy) {
        if(!this->isAlive()){
            throw runtime_error("move:dead ninja");
        }
        Point location=Point::moveTowards(this->getLocation(),enemy->getLocation(),_speed);
        this->setLocation(location);
    }

    void Ninja::slash(Character *enemy) {
        if(enemy==this){
            throw runtime_error("slash:self harm");
        }else if((!this->isAlive()) || (!enemy->isAlive())){
            throw runtime_error("slash:dead ninja");
        }if(this->distance(enemy)>1){
            return;
        }
        enemy->hit(_damage);
    }

    string Ninja::print() {
        string str("N{");
        if(isAlive()){
            str=str+this->getName()+",\"HP\":"+ to_string(getHp())+",\"location\":"+getLocation().print()+",\"Speed\":"+to_string(this->_speed)+"}";
        }else{
            str=str+this->getName()+",\"location\":"+getLocation().print()+",\"Speed\":"+to_string(this->_speed)+"}";
        }
        return str;
    }

}