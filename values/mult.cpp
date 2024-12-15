#include "mult.h"
mult::~mult()
{
    delete mult1;
    delete mult2;
}
Complex mult::eval()
{
    return (mult1->eval() * mult2->eval());
}