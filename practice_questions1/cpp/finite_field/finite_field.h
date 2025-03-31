#ifndef FINITE_FIELD_H
#define FINITE_FIELD_H

#include <iostream>
#include <string>
#include <math.h>

class FieldElement{
    public:
        FieldElement(long long num, long long prime);
        std::string repr();
        bool operator!=(const FieldElement& other);
        bool operator==(const FieldElement& other);
        FieldElement *operator+(const FieldElement &other);
        FieldElement *operator-(const FieldElement &other);
        FieldElement *operator*(const FieldElement &other);
        FieldElement *Pow(const FieldElement &other,int number);
    
    private:
        long long num;
        long long prime;
};

#endif