#include "res.h"
dif::~dif()
{
    delete dif1;
    delete dif2;
}
Complex dif::eval()
{
    return (dif1->eval() - dif2->eval());
}