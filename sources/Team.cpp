//
// Created by mintsdz on 5/15/23.
//

#include "Team.hpp"



namespace ariel {

    Team::Team(Character *leader) : _leader(leader) {
        if(_leader->getTeam()!= nullptr){
            throw runtime_error("captain:already assigned in a team");
        }
        _members.push_back(leader);
        leader->setTeam(this);
    }

    Team::Team(){
        this->_leader=NULL;
    }

    Team::Team(const Team& other){
        this->_members=other._members;
        this->_leader=other._leader;
    }

    Team& Team::operator=(Team other){
        this->_members=other._members;
        this->_leader=other._leader;
        return *this;
    }

    Team::Team(Team &&other) noexcept{
        this->_members=other._members;
        this->_leader=other._leader;
    }

    Team& Team::operator=(Team&& other) noexcept{
        this->_members=other._members;
        this->_leader=other._leader;
        return *this;
    }

    void Team::add(Character *fighter){
        if(_members.size()>=_maxTeamSize){
            throw runtime_error("add:more then maximum size");
        }else if(fighter->getTeam()!= nullptr){
            throw runtime_error("add:already assigned in a team");
        }
        _members.push_back(fighter);
        fighter->setTeam(this);
        std::rotate(_members.rbegin(), _members.rbegin()+1,_members.rend());
    }

    int Team::stillAlive() {
        vector<Character*>::iterator it=_members.begin();
        int alive=0;
        while(it!=_members.end()){
            if(it.operator*()->isAlive()){
                alive++;
            }
            it++;
        }
        return alive;
    }

    Character* Team::getTarget(Team *opponent){
        if(!opponent->_leader->isAlive()) {
            opponent->setLeader();
        }
        vector<Character*>::iterator enemyIterator=opponent->_members.begin();
        double minDistance=std::numeric_limits<double>::max();
        Character *target=NULL;
        while(enemyIterator!=opponent->_members.end()){
            Character *c = enemyIterator.operator*();
            if(c->isAlive()) {
                double d = c->getLocation().distance(_leader->getLocation());
                if(d!=minDistance) {
                    minDistance = std::min(minDistance, d);
                    if (minDistance == d) {
                        target = c;
                    }
                }
            }
            enemyIterator++;
        }
        return target;
    }

    void Team::attack(Team *opponent) {
        if(opponent== nullptr){
            throw invalid_argument("attack:nullptr");
        }
        if(opponent->stillAlive()<=0){
            throw runtime_error("other team is dead");
        }
        this->setLeader();
        queue<Character*> cowboys;
        queue<Character*> ninjas;
        vector<Character*>::iterator teamIterator=_members.begin();
        while(teamIterator!=_members.end()){
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

    void Team::print() {
        queue<Character*> cowboys;
        queue<Character*> ninjas;
        vector<Character*>::iterator teamIterator=_members.begin();
        while(teamIterator!=_members.end()){
            auto *ch=teamIterator.operator*();
            if (dynamic_cast<Ninja*>(ch)!= nullptr) {
                ninjas.push(ch);
            } else if (typeid((*ch)) == typeid(Cowboy)) {
                cowboys.push(ch);
            }
            teamIterator++;
        }

        while(!cowboys.empty()){
            Cowboy *cowboy=dynamic_cast<Cowboy*>(cowboys.front());
            cout<<cowboy->print()<<endl;
            cowboys.pop();
        }
        while(!ninjas.empty()){
            Ninja *ninja=dynamic_cast<Ninja*>(ninjas.front());
            cout<<ninja->print()<<endl;
            ninjas.pop();
        }
    }

    Character * Team::getLeader() const {
        return _leader;
    }

    void Team::setLeader() {
        if(_leader->isAlive()){
            return;
        }
        vector<Character*>::iterator it=_members.begin();
        double minDistance=std::numeric_limits<double>::max();
        Character *leader=NULL;
        while(it!=_members.end()){
            Character *c = it.operator*();
            if(c->isAlive()) {
                double d = c->getLocation().distance(_leader->getLocation());
                if(d!=minDistance) {
                    minDistance = std::min(minDistance, d);
                    if (minDistance == d) {
                        leader = c;
                    }
                }
            }
            it++;
        }
        this->_leader=leader;
    }
} // ariel