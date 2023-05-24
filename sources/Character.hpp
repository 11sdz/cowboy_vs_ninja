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
        int _hp;
        Point _location;
        string _name;

    public:

        Character(const string &name, int _hp, const Point &location);

        Character();

        Character(const Character& other);

        Character& operator=(const Character& other);

        Character(Character&& other) noexcept;

        Character& operator=(Character&& other) noexcept;

        [[nodiscard]] Point getLocation() const;

        [[nodiscard]] int getHp() const;

        void hit(int damage);

        [[nodiscard]] bool isAlive() const;

        double distance(Character *other);

        string getName();

        virtual string print()=0;

        [[nodiscard]] Team *getTeam() const;

        void setTeam(Team *team);

        virtual ~Character()=0;

        void setLocation(const Point &location);


    };

} // ariel

#endif //COWBOY_VS_NINJA_CHARACTER_HPP
