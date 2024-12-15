#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include "values.h"

class expo : public val
{
public:
    val *input;
    virtual ~expo();
    virtual Complex eval();
};

class sine : public val
{
public:
    val *input;
    virtual ~sine();
    virtual Complex eval();
};

class cosine : public val
{
public:
    val *input;
    virtual ~cosine();
    virtual Complex eval();
};

class absolute : public val
{
public:
    val *input;
    virtual ~absolute();
    virtual Complex eval();
};

class loga : public val
{
public:
    val *input;
    virtual ~loga();
    virtual Complex eval();
};
#endif