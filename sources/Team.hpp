//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_TEAM_HPP
#define COWBOY_VS_NINJA_TEAM_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"



namespace ariel {

    class Team{
    protected:
        const int _maxTeamSize=10;
        int size;
        vector<Character*> _members;
        Character *_leader;
        virtual void setLeader();
    public:
        explicit Team(Character *leader);

        [[nodiscard]] Character *getLeader() const;

        virtual void add(Character *fighter);

        virtual void attack(Team *opponent);

        virtual void print();

        virtual Character* getTarget(Team *opponent);

        int stillAlive();

        virtual ~Team(){
            for (auto & _member : _members) {
                delete _member;
            }
        }

    };

} // ariel

#endif //COWBOY_VS_NINJA_TEAM_HPP