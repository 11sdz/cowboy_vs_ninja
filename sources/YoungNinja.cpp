//
// Created by mintsdz on 5/15/23.
//

#include "YoungNinja.hpp"

namespace ariel {

    YoungNinja::YoungNinja( const string &name, const Point &location) : Ninja(name, 100, location,
                                                                                                     14) {
    }

    string YoungNinja::print() {
        return string("hey");
    }
} // ariel