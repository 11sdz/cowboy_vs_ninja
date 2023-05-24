//
// Created by mintsdz on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_SMARTTEAM_HPP
#include "Team.hpp"

namespace ariel {

    class SmartTeam :public Team{
    public:
        SmartTeam(Character *leader);

        void attack(Team *opponent) override;

        void print() override;

        Character *getTarget(Team *opponent) override;
    };
} // ariel

#endif //COWBOY_VS_NINJA_SMARTTEAM_HPP
