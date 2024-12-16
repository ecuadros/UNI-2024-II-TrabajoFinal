#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#include<iostream>
#include"tipos.h"
#include"operadores.h"
#include"celda.h"

using namespace std;

bool esNombreDeCelda(string);

POSICIONESMATRIZ convertirCeldaAMatriz(string);

string convertirMatrizACelda(POSICIONESMATRIZ);

bool existeOperador(const string&);

CAD_OBJETIVO buscarCadenaObj(const string&);

string operarCadena(string, CELDA **);

double evaluar(string, CELDA**);

#endif //__FUNCIONES_H__