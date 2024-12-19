#ifndef __OPERADORES_H__
#define __OPERADORES_H__

#include<iostream>
#include<string>
#include"celda.h"
#include"tipos.h"
#include"funciones.h"
#include <memory>

using namespace std;

//string strOPERADORES[8];

double OPERADOR_Asignacion(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Adicion(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Sustraccion(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Multiplicacion(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Division(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Seno(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Coseno(string, unique_ptr<CELDA[]>* & );

double OPERADOR_Tangente(string, unique_ptr<CELDA[]>* & );

string operarCadena(const CAD_OBJETIVO , unique_ptr<CELDA[]>* & );

#endif //__OPERADORES_H__