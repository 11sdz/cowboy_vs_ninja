//
// Created by mintsdz on 5/15/23.
//

#include "Team.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

namespace ariel {

    Team::Team(Character *leader) : _leader(leader) {

    }

    void Team::add(Character *fighter){

    }

    int Team::stillAlive() {
        vector<Character*>::iterator it=_members.begin();
        int alive=0;
        while(it!=_members.end()){
            if(it.operator*()->isAlive()){alive++;}
            it++;
        }
        return alive;
    }

    Character* Team::getTarget(Team *opponent){
        vector<Character*>::iterator enemyIterator=opponent->_members.begin();
        double minDistance=std::numeric_limits<double>::max();
        Character *target=NULL;
        while(enemyIterator!=opponent->_members.end()){
            Character *c = enemyIterator.operator*();
            double d=c->getLocation().distance(_leader->getLocation());
            minDistance=std::min(minDistance,d);
            if(minDistance==d){
                target=c;
            }
            enemyIterator++;
        }
        return target;
    }

    void Team::attack(Team *opponent) {
        Character *target= getTarget(opponent);
        queue<Character*> cowboys;
        queue<Character*> ninjas;
        vector<Character*>::iterator teamIterator=_members.begin();
        while(teamIterator!=_members.end()){
            auto *ch=teamIterator.operator*();
            if(typeid(*ch)== typeid(Ninja)){
                ninjas.push(ch);
            }else if(typeid((*ch))== typeid(Cowboy)){
                cowboys.push(ch);
            }
        }

    }

    void Team::print() {
        vector<Character*>::iterator it=_members.begin();
        while(it!=_members.end()) {
            cout << (*it)->print() << endl;
            it++;
        }
    }

    Character * Team::getLeader() const {
        return _leader;
    }

    void Team::setLeader(Character *leader) {
        _leader = leader;
    }
} // ariel