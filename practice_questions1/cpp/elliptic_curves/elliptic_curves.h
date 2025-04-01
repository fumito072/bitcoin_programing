#ifndef ELLIPTIC_CURVES_H
#define ELLIPTIC_CURVES_H

#include <iostream>
#include <string>
#include <math.h>

class Point{
    public:
        Point(int x, int y, int a, int b);
        bool operator==(Point &other);
        bool operator!=(Point &other);
        Point Point::operator+(Point &other);
    private:
        int x;
        int y;
        int a;
        int b;
};

#endif