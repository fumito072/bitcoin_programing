#include "finite_field.h"

int main(){
    FieldElement base(7, 13);
    int element = 3;

    FieldElement *res = base.Pow(base, element);

    std::cout << res->repr() << std::endl;
    delete res;
    return 0;
}