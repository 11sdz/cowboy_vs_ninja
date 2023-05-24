//
// Created by mintsdz on 5/16/23.
//

#include "SmartTeam.hpp"

namespace ariel {

    SmartTeam::SmartTeam(ariel::Character *leader) : Team(leader) {

    }

    Character* SmartTeam::getTarget(ariel::Team *opponent) {
        return NULL;
    }

    void SmartTeam::attack(Team *opponent) {
        if(opponent== nullptr){
            throw invalid_argument("attack:nullptr");
        }
        if(opponent->stillAlive()<=0){
            throw runtime_error("other team is dead");
        }
        this->setLeader();
        bool leaderNinja=false;
        if (dynamic_cast<Ninja*>(this->getLeader())!= nullptr) {
            leaderNinja= true;
        }
        queue<Character*> cowboys;
        queue<Character*> ninjas;
        vector<Character*>::iterator teamIterator=getMembers().begin();
        while(teamIterator!=getMembers().end()){
            auto *ch=teamIterator.operator*();
            if(ch->isAlive()) {
                if (dynamic_cast<Ninja*>(ch)!= nullptr) {
                    ninjas.push(ch);
                } else if (typeid((*ch)) == typeid(Cowboy)) {
                    cowboys.push(ch);
                }
            }
            teamIterator++;
        }
        Character *target= getTarget(opponent);

        while(!cowboys.empty() && opponent->stillAlive()){
            Cowboy *cowboy=dynamic_cast<Cowboy*>(cowboys.front());
            if(cowboy->hasboolets()) {
                cowboy->shoot(target);
            }else{
                cowboy->reload();
            }
            if(!target->isAlive()){
                target= getTarget(opponent);
            }
            cowboys.pop();
        }
        while(!ninjas.empty() && opponent->stillAlive()){
            Ninja *ninja=dynamic_cast<Ninja*>(ninjas.front());
            if(ninja->distance(target)>1){
                ninja->move(target);
            }else{
                ninja->slash(target);
            }
            if(!target->isAlive()){
                target= getTarget(opponent);
            }
            ninjas.pop();
        }
    }

    void SmartTeam::print() {

    }

} // ariel