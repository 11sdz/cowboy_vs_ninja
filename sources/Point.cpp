//
// Created by mintsdz on 5/15/23.
//

#include "Point.hpp"
#include <math.h>
#include <iostream>

using namespace std;
namespace ariel{

    Point::Point(double x, double y) : _x(x), _y(y) {

    }

    double Point::distance(Point other) {
        return 0;
    }

    void Point::print() {
        cout<<"("<<_x<<","<<_y<<")"<<endl;
    }

    Point Point::moveTowards(Point source,Point dest,double distance) {
        return Point(0, 0);
    }


} //ariel