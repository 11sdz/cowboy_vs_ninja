//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_NINJA_HPP
#define COWBOY_VS_NINJA_NINJA_HPP

#include "Character.hpp"
#define SLASH_DAMAGE 40;
namespace ariel {
    class Ninja : public Character{
    protected:
        const int _speed;
        const int _damage=SLASH_DAMAGE;

    public:
        Ninja( const string &name, int hp, const Point &location, int speed);

        void move(Character *enemy);

        void slash(Character *enemy);

        ~Ninja()=default;

        string print() override;

    };
}

#endif //COWBOY_VS_NINJA_NINJA_HPP
