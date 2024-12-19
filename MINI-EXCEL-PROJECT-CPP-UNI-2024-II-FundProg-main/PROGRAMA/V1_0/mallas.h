#ifndef __MALLAS_H__
#define __MALLAS_H__
#include "celda.h"
#include<iostream>
#include <memory>

using namespace std;

using Tam = int;

char mallacaracter1(char);


/*void genMalla1(Tam, Tam, char);

void genMalla2(Tam, Tam, Tam);

void genMalla3(Tam, Tam, Tam, string **); */
void genMalla4(Tam, Tam, Tam, unique_ptr<CELDA[]>* & );
#endif