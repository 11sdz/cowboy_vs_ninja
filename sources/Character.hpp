//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_CHARACTER_HPP
#define COWBOY_VS_NINJA_CHARACTER_HPP
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel {

    class Character {
    protected:
        int _hp;
        Point _location;
        string _name;

    public:

        Character( const string &name, int hp, const Point &location);

        bool isAlive();

        double distance(Character *other);

        void hit(int damage);

        string getName();

        Point getLocation();

        virtual string print()=0;

        virtual ~Character();


    };

} // ariel

#endif //COWBOY_VS_NINJA_CHARACTER_HPP
