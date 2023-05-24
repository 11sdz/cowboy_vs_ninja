//
// Created by mintsdz on 5/16/23.
//

#include "SmartTeam.hpp"

namespace ariel {

    SmartTeam::SmartTeam(ariel::Character *leader) : Team(leader) {

    }

    Character* SmartTeam::getTarget(ariel::Team *opponent) {
        vector<Character*> members=getMembers();
        vector<Character*> enemyMembers=opponent->getMembers();
        double minDistance=std::numeric_limits<double>::max();
        Character *t=NULL;
        Character *target=NULL;
        for (Character *mem:members) {
            if(mem->isAlive()){
                for (Character* enemy:enemyMembers) {
                    if(enemy->isAlive() && dynamic_cast<Ninja*>(enemy)!= nullptr){
                        double d=mem->distance(enemy);
                            minDistance = std::min(minDistance, d);
                            if (minDistance == d) {
                                target=enemy;
                        }
                    }
                }
            }
        }
        minDistance=std::numeric_limits<double>::max();
        if(target==NULL){
            for (Character *mem:members) {
                if(mem->isAlive()){
                    for (Character* enemy:enemyMembers) {
                        if(enemy->isAlive()){
                            double d=mem->distance(enemy);
                                minDistance = std::min(minDistance, d);
                                if (minDistance == d) {
                                    target=enemy;
                                }
                        }
                    }
                }
            }
        }
        return target;
    }

    void SmartTeam::attack(Team *opponent) {
        if(opponent== nullptr){
            throw invalid_argument("attack:nullptr");
        }
        if(opponent->stillAlive()<=0){
            throw runtime_error("other team is dead");
        }
        this->setLeader();
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
        Character *target=NULL;
        vector<Character*> enemyTeam=opponent->getMembers();
        int alives=0;

        while((!ninjas.empty() || !cowboys.empty()) && opponent->stillAlive()>0) {
            alives=0;
            target= getTarget(opponent);
            while(target!=NULL && !cowboys.empty() && opponent->stillAlive()){
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
            while(target!=NULL && !ninjas.empty() && opponent->stillAlive()){
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
    }

    void SmartTeam::print() {
        queue<Character*> cowboys;
        queue<Character*> ninjas;
        vector<Character*>::iterator teamIterator=getMembers().begin();
        while(teamIterator!=getMembers().end()){
            auto *ch=teamIterator.operator*();
            if (dynamic_cast<Ninja*>(ch)!= nullptr) {
                ninjas.push(ch);
            } else if (typeid((*ch)) == typeid(Cowboy)) {
                cowboys.push(ch);
            }
            teamIterator++;
        }
    }

} // ariel