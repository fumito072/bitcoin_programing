#include "finite_field.h"

void FieldElement::init(long long num, long long prime){
    if (num >= prime || num < 0){
        std::string error = "Num" + std::to_string(num) +
         "not in field range 0 to" + std::to_string(prime - 1);
        throw std::invalid_argument(error);
    }
    this->num = num;
    this->prime = prime;
}

std::string FieldElement::__repr__(){
    return "FieldElement_" + std::to_string(prime) + std::to_string(num);
}

bool FieldElement::__ne__(const FieldElement &other){
    return (this->num != other.num || this->num != other.prime);
}

bool FieldElement::__eq__(const FieldElement &other){
    return this->num == other.num && this->prime == other.prime;
}

