#ifndef __MULT_H__
#define __MULT_H__
#include "values.h"
class mult : public val
{
public:
    val *mult1;
    val *mult2;
    virtual ~mult();
    virtual Complex eval();
};
#endif