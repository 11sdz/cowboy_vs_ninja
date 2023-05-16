//
// Created by mintsdz on 5/15/23.
//

#include "Point.hpp"
#include <math.h>
#include <iostream>

using namespace std;
namespace ariel{

    Point::Point() {
        this->_x=0;
        this->_y=0;
    }

    Point::Point(double x, double y) : _x(x), _y(y) {

    }

    double Point::getX() const {
        return _x;
    }

    double Point::getY() const {
        return _y;
    }


    double Point::distance(Point other) {
        return 0;
    }

    string Point::print() {
       return string("hey");
    }

    Point Point::moveTowards(Point source,Point dest,double distance) {
        return Point(0, 0);
    }

    bool operator==(Point lhs, Point rhs) {
        return false;
    }

} //ariel