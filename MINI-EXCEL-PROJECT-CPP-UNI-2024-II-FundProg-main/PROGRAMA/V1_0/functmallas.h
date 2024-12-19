#ifndef __FUNCTMALLAS_H__
#define __FUNCTMALLAS_H__

#include<iostream>
#include"mallas.h"
#include <string>

using namespace std;

struct RESULMALLA
{
    Tam filas;
    Tam columnas;
    char caracter;
};

RESULMALLA pedirMalla();


string ceStringFormat(const string &, int);
string ceStringFormat(const char &, int);

#endif //__FUNCTMALLAS_H__