#ifndef __SUM_H__
#define __SUM_H__
#include "values.h"
class sum : public val
{
public:
    val *sum1;
    val *sum2;
    virtual ~sum();
    virtual Complex eval();
};
#endif