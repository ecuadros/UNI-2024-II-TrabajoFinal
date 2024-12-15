#ifndef __FRAC_H__
#define __DIV_H__
#include "values.h"
class frac : public val
{
public:
    val *frac1;
    val *frac2;
    virtual ~frac();
    virtual Complex eval();
};
#endif