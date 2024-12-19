#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#include<iostream>
#include <memory>
#include"tipos.h"
#include"celda.h"
#include"operadores.h"

using namespace std;

bool esNombreDeCelda(const string&);

POSICIONESMATRIZ convertirCeldaAMatriz(const string&);

string convertirMatrizACelda(POSICIONESMATRIZ);

bool existeOperador(const string&);

CAD_OBJETIVO buscarCadenaObj(const string&);

double evaluar(string, unique_ptr<CELDA[]>* & );

#endif //__FUNCIONES_H__