//
// Created by mintsdz on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_POINT_HPP
#define COWBOY_VS_NINJA_POINT_HPP

namespace ariel {
    class Point {
    private:
        double _x, _y;
    public:
        Point(double x, double y);

        double distance(Point other);

        void print();

        static Point moveTowards(Point source,Point dest,double distance);
    };
}

#endif //COWBOY_VS_NINJA_POINT_HPP
