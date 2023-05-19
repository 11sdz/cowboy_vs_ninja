//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_COWBOY_HPP
#define COWBOY_VS_NINJA_COWBOY_HPP


#include "Character.hpp"
#define BULLET_DAMAGE 10;
namespace ariel {
    class Cowboy : public Character{
    private:
        int _ammo;
        const int _damage=BULLET_DAMAGE;

    public:

        Cowboy(const string &name, const Point &location);

        void shoot(Character *enemy) ;

        bool hasboolets() const;

        void reload();

        string print() override;


    };
}

#endif //COWBOY_VS_NINJA_COWBOY_HPP
