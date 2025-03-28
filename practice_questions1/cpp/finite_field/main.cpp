#include "finite_field.h"

int main(){
    FieldElement a;
    a.init(7, 13);
    FieldElement b;
    b.init(6, 13);
    std::cout << a.__eq__(b) << std::endl;
    std::cout << a.__eq__(a) << std::endl;
    return 0;
}