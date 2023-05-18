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
        double diffX=(this->_x-other._x);
        double diffY=(this->_y-other._y);
        double result= std::sqrt(diffX*diffX+diffY*diffY);
        return result;
    }

    string Point::print() {
       return string("("+ to_string(this->_x)+","+ to_string(this->_y)+")");
    }


    //using this formula https://stackoverflow.com/a/2353289/21920092 found on StackOverflow
    Point Point::moveTowards(Point src, Point dest, double distance) {
        if(distance<0){
            throw invalid_argument("Negative distance");
        }
        double a2b=src.distance(dest);
        if(a2b <= distance){
            return dest;
        }
        Point res(0,0);
        res=(dest-src);

        double t= distance / a2b;
        res = src+res*t;

        return res;
    }


    Point Point::operator*(double scalar) {
        return Point(this->_x*scalar,this->_y*scalar);
    }

    Point operator+(Point lhs, Point rhs) {
        return Point(lhs._x+rhs._x,lhs._y+rhs._y);
    }

    Point operator-(Point lhs, Point rhs) {
        return Point(lhs._x-rhs._x,lhs._y-rhs._y);
    }

    bool operator==(Point lhs, Point rhs) {
        return ((lhs._x==rhs._x) && (lhs._y==rhs._y));
    }

} //ariel