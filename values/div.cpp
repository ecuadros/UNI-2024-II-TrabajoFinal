#include "div.h"
frac::~frac()
{
    delete frac1;
    delete frac2;
}
Complex frac::eval()
{
    return (frac1->eval() / frac2->eval());
}