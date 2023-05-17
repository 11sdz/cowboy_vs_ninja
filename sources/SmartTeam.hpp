//
// Created by mintsdz on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_SMARTTEAM_HPP
#include "Team.hpp"
namespace ariel {

    class SmartTeam :public Team{
    protected:
        void setLeader(Character* leader)override;
    public:
        SmartTeam(Character *leader);

        void add(Character *fighter) override;

        void attack(Team *opponent) override;

        void print() override;

        virtual ~SmartTeam();

    };
} // ariel

#endif //COWBOY_VS_NINJA_SMARTTEAM_HPP
