//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_COWBOY_HPP
#define COWBOY_VS_NINJA_COWBOY_HPP

#include <ostream>
#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character{
    private:
        int _ammo;


    public:

        Cowboy(const string &name, const Point &location);

        void shoot(Character *enemy);

        bool hasboolets();

        void reload();

        string print() override;


    };
}

#endif //COWBOY_VS_NINJA_COWBOY_HPP
