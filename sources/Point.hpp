//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_POINT_HPP
#define COWBOY_VS_NINJA_POINT_HPP
#include <string>

using namespace std;
namespace ariel {
    class Point {
    private:
        double _x, _y;

    public:
        Point();

        Point(double x, double y);

        double getX() const;

        double getY() const;

        double distance(Point other);

        string print();

        static Point moveTowards(Point src, Point dest, double distance);

        Point operator*(double scalar);

    friend Point operator+(Point lhs,Point rhs);

    friend Point operator-(Point lhs,Point rhs);

    friend bool operator==(Point lhs,Point rhs);

    };
}

#endif //COWBOY_VS_NINJA_POINT_HPP
