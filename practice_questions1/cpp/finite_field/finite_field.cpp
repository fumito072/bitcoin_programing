#include "finite_field.h"

FieldElement::FieldElement(long long num, long long prime){
    if (num >= prime || num < 0){
        std::string error = "Num" + std::to_string(num) +
         "not in field range 0 to" + std::to_string(prime - 1);
        throw std::invalid_argument(error);
    }
    this->num = num;
    this->prime = prime;
}

std::string FieldElement::repr(){
    return "FieldElement_" + std::to_string(prime) + std::to_string(num);
}

bool FieldElement::operator!=(const FieldElement &other){
    return (this->num != other.num || this->num != other.prime);
}

bool FieldElement::operator==(const FieldElement &other){
    return this->num == other.num && this->prime == other.prime;
}

FieldElement *FieldElement::operator+(const FieldElement &other){
    if (this->prime != other.prime){
        throw std::invalid_argument("Cannot add two numbers in different Fields");
    }
    long long res = (this->num + other.num) % this->prime;
    return new FieldElement(res, this->prime);
}

FieldElement *FieldElement::operator-(const FieldElement &other){
    if (this->prime != other.prime){
        throw std::invalid_argument("Cannot add two numbers in different Fields");
    }
    long long res = (this->num - other.num) % this->prime;
    return new FieldElement(res, this->prime);
}

FieldElement *FieldElement::operator*(const FieldElement &other){
    if (this->prime != other.prime){
        throw std::invalid_argument("Cannot add two numbers in different Fields");
    }
    long long res = (this->num * other.num) % this->prime;
    return new FieldElement(res, this->prime);
}

FieldElement *FieldElement::Pow(const FieldElement &other,int number){
    long long res = 0;
    int i = 0;
    while (i < number){
        res = (res * other.num) % other.prime;
        i++;
    }
    return new FieldElement(res, other.prime);
}