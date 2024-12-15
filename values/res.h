#ifndef __RES_H__
#define __RES_H__
#include "values.h"
class dif : public val
{
public:
    val *dif1;
    val *dif2;
    virtual ~dif();
    virtual Complex eval();
};
#endif