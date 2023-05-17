//
// Created by mintsdz on 5/15/23.
//

#include "TrainedNinja.hpp"
namespace ariel{

    TrainedNinja::TrainedNinja( const string &name, const Point &location) : Ninja(name, 120 , location,
                                                                                                     12) {}

    string TrainedNinja::print() {
        return string("hey");
    }
}