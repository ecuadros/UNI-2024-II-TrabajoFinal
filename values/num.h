#ifndef __NUM_H__
#define __NUM_H__
#include "values.h"
class num : public val
{
public:
    Complex num;
    virtual ~num();
    virtual Complex eval();
};
#endif