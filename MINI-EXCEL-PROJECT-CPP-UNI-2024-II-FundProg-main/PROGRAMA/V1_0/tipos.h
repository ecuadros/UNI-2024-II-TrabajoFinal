#ifndef __TIPOS_H__
#define __TIPOS_H__

#include<iostream>
#include<string>
#include"celda.h"

using namespace std;

struct CAD_OBJETIVO
{
    string cad;
    int inicio;
    string c_operador;
};

struct POSICIONESMATRIZ
{
    int pos[2];
};
#endif //__TIPOS_H__
