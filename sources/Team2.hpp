//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_TEAM2_HPP
#define COWBOY_VS_NINJA_TEAM2_HPP

#include "Team.hpp"

namespace ariel {

    class Team2 :public Team{
    public:
        Team2(Character *leader);

        void attack(Team *opponent) override;

        void print() override;

    };
} // ariel

#endif //COWBOY_VS_NINJA_TEAM2_HPP
