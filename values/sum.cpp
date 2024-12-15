#include "sum.h"
sum::~sum()
{
    delete sum1;
    delete sum2;
}
Complex sum::eval()
{
    return (sum1->eval() + sum2->eval());
}