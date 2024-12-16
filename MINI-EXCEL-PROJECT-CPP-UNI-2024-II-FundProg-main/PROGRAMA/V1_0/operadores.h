#ifndef __OPERADORES_H__
#define __OPERADORES_H__

#include<iostream>
#include<string>
#include"celda.h"

using namespace std;

//string strOPERADORES[8];

double OPERADOR_Asignacion(string, CELDA **);

double OPERADOR_Adicion(string, CELDA **);

double OPERADOR_Sustraccion(string, CELDA **);

double OPERADOR_Multiplicacion(string, CELDA **);

double OPERADOR_Division(string, CELDA **);

double OPERADOR_Seno(string, CELDA **);

double OPERADOR_Coseno(string, CELDA **);

double OPERADOR_Tangente(string, CELDA **);

double (*fOpe[8])(string, CELDA **);
#endif //__OPERADORES_H__