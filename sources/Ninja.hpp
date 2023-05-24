//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_NINJA_HPP
#define COWBOY_VS_NINJA_NINJA_HPP

#include "Character.hpp"
#define SLASH_DAMAGE 40;
namespace ariel {
    class Ninja : public Character{
    private:
        int _speed;
        int _damage=SLASH_DAMAGE;

    public:
        Ninja(const string &name, int _hp, const Point &location, int speed);

        Ninja();

        Ninja(const Ninja& other);

        Ninja(Ninja&& other) noexcept;

        Ninja& operator=(const Ninja& other);

        Ninja& operator=(Ninja&& other) noexcept;

        void move(Character *enemy);

        void slash(Character *enemy);

        string print() override;

    };
}

#endif //COWBOY_VS_NINJA_NINJA_HPP
