//
// Created by mintsdz on 5/15/23.
//

#include "Team2.hpp"

namespace ariel {
    Team2::Team2(ariel::Character *leader) : Team(leader){
    }

    void Team2::attack(Team *opponent) {
        if(opponent== nullptr){
            throw invalid_argument("attack:nullptr");
        }
        if(opponent->stillAlive()<0){
            throw runtime_error("other team is dead");
        }
        this->setLeader();
        vector<Character*>::iterator teamIterator=getMembers().begin();
        Character *target= getTarget(opponent);
        while(teamIterator!=getMembers().end() && opponent->stillAlive()){
            Character *ch=teamIterator.operator*();
            if(ch->isAlive()) {
                if (dynamic_cast<Ninja *>(ch) != nullptr) {
                    Ninja *ninja = dynamic_cast<Ninja *>(teamIterator.operator*());
                    if (ninja->distance(target) <= 1) {
                        ninja->slash(target);
                    } else {
                        ninja->move(target);
                    }
                } else if (typeid((*ch)) == typeid(Cowboy)) {
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(teamIterator.operator*());
                    if (cowboy->hasboolets()) {
                        cowboy->shoot(target);
                    } else {
                        cowboy->reload();
                    }
                }
                if (!target->isAlive()) {
                    target = getTarget(opponent);
                }
            }
            teamIterator++;
        }

    }

    void Team2::print() {
        vector<Character*>::iterator teamIterator=getMembers().begin();
        while (teamIterator!=getMembers().end()){
            Character *ch=teamIterator.operator*();
            cout<<ch->print()<<endl;
            teamIterator++;
        }
    }

} // ariel