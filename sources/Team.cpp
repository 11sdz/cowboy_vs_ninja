//
// Created by mintsdz on 5/15/23.
//

#include "Team.hpp"


namespace ariel {

    Team::Team(Character *leader) : _leader(leader) {

    }

    void Team::add(Character *fighter){

    }

    int Team::stillAlive() {
        return 0;
    }


    void Team::attack(Team *opponent) {

    }

    void Team::print() {

    }

    Character * Team::getLeader() const {
        return _leader;
    }

    void Team::setLeader(Character *leader) {
        _leader = leader;
    }
} // ariel