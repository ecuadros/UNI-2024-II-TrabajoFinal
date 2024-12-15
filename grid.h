#ifndef __GRID_H__
#define __GRID_H__
#include <string>
#include "complex.h"
#include "values/values.h"
#include "values/sum.h"
#include "values/res.h"
#include "values/mult.h"
#include "values/div.h"
#include "values/num.h"
#include "values/functions.h"
void display(std::ostream &, Complex **, size_t, size_t);
val *read(const std::string &, Complex **);
size_t find_noParenth(const std::string &, const std::string &);
bool correctParenth(const std::string &);
void deleteSpaces(std::string &);
void start();
#endif