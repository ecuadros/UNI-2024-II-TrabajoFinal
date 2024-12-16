#ifndef __OPERADORES_H__
#define __OPERADORES_H__

#include<iostream>
#include<string>
#include"celda.h"

using namespace std;

string strOPERADORES[] = {"=", "+", "-", "*", "/", "sen", "cos", "tan"};

double OPERADOR_Asignacion(string, CELDA **);

double OPERADOR_Adicion(string, CELDA **);

double OPERADOR_Sustraccion(string, CELDA **);

double OPERADOR_Multiplicacion(string, CELDA **);

double OPERADOR_Division(string, CELDA **);

double OPERADOR_Seno(string, CELDA **);

double OPERADOR_Coseno(string, CELDA **);

double OPERADOR_Tangente(string, CELDA **);

double (*fOpe[])(string, CELDA **) = {&OPERADOR_Asignacion, &OPERADOR_Adicion, &OPERADOR_Sustraccion, &OPERADOR_Multiplicacion, &OPERADOR_Division, &OPERADOR_Seno, &OPERADOR_Coseno, &OPERADOR_Tangente};

#endif //__OPERADORES_H__