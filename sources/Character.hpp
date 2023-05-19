//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_CHARACTER_HPP
#define COWBOY_VS_NINJA_CHARACTER_HPP

#include "Point.hpp"
#include <ostream>


namespace ariel {
    class Team;
    class Character {
    private:
        Team *_team;
    protected:
        int _hp;
        Point _location;
        string _name;

    public:

        Character( const string &name, int hp, const Point &location);

        [[nodiscard]] int getHp() const;

        void hit(int damage);

        bool isAlive();

        double distance(Character *other);

        string getName();

        Point getLocation();

        virtual string print()=0;

        Team *getTeam() const;

        void setTeam(Team *team);

        virtual ~Character()=0;


    };

} // ariel

#endif //COWBOY_VS_NINJA_CHARACTER_HPP
