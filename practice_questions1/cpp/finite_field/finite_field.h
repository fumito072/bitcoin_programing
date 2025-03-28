#ifndef FINITE_FIELD_H
#define FINITE_FIELD_H

#include <iostream>
#include <string>

class FieldElement{
    public:
        void init(long long num, long long prime);
        std::string __repr__();
        bool __ne__(const FieldElement& other);
        bool __eq__(const FieldElement& other);
    
    private:
        long long num;
        long long prime;
};

#endif