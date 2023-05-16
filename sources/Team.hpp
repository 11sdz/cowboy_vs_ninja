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
#include "Team2.hpp"
#include "SmartTeam.hpp"

#include <vector>


namespace ariel {

    class Team {
    private:
        int _maxTeamSize=10;
        vector<Character> _members;
        Character *_leader;

    public:

        explicit Team(Character *leader);

        void add(Character *fighter);

        void attack(Team *opponent);

        int stillAlive();

        virtual void print();

        virtual ~Team();

    };

} // ariel

#endif //COWBOY_VS_NINJA_TEAM_HPP
