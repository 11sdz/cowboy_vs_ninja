//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_NINJA_HPP
#define COWBOY_VS_NINJA_NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character{
    protected:
        int _speed;

    public:
        Ninja( const string &name, int hp, const Point &location, int speed);

        void move(Character *enemy);

        void slash(Character *enemy);

        ~Ninja() override;

    };
}

#endif //COWBOY_VS_NINJA_NINJA_HPP
