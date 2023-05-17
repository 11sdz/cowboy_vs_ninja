//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_TEAM_HPP
#define COWBOY_VS_NINJA_TEAM_HPP

#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"

#include <vector>


namespace ariel {
    class Team{
    protected:
        const int _maxTeamSize=10;
        vector<Character> _members;
        Character *_leader;
        virtual void setLeader(Character *leader);
    public:
        Team(Character *leader);

        Character *getLeader() const;

        virtual void add(Character *fighter);

        virtual void attack(Team *opponent);

        virtual void print();

        int stillAlive();

        virtual ~Team();

    };

} // ariel

#endif //COWBOY_VS_NINJA_TEAM_HPP
