#include "elliptic_curves.h"

Point::Point(int x, int y, int a, int b){
    if (y * y!= x * x * x + a * x + b){
        throw std::invalid_argument("The point is not on the curve");
    }
    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
}

bool Point::operator==(Point &other){
    return this->x == other.x && this->y == other.y &&
        this->a == other.a && this->b == other.b;
}

bool Point::operator!=(Point &other){
    return this->x != other.x || this->y != other.y ||
        this->a != other.a || this->b != other.b;
}

Point Point::operator+(Point &other){
    if (this->a != other.a || this->b != other.b){
        throw std::invalid_argument("The point is not on the curve");
    }
    if (this->x == 0 && this->y == 0) 
        return other;
    if (other.x == 0 && other.y == 0) 
        return *this;
    if (this->x == other.x && this->y != other.y){
        return Point(0, 0, this->a, this->b);
    }
    if (this->x != other.x){
        int s = (other.y - this->y) / (other.x - this->x);
        int x3 = pow(s, 2) - this->x - other.x;
        int y3 = s * (this->x - x3) - this->y;
        return Point(x3, y3, this->a, this->b);
    }
    if (*this == other){
        int s = (3 * pow(this->x, 2) + this->a) / (2 * this->y);
        int x3 = pow(s, 2) - (2 * this->x);
        int y3 = s * (this->x - x3) - this->y;
        return Point(x3, y3, this->x, this->b);
    }
    if (*this == other && this->y == 0){
        return Point(0, 0, this->a, this->b);
    }
}