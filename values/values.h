#ifndef __VALUES_H__
#define __VALUES_H__
#include "../complex.h"
class val
{
public:
    virtual ~val();
    virtual Complex eval();
};
#endif