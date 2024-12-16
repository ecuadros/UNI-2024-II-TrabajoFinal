#include<iostream>
#include"celda.h"
#include"matrizceld.h"

using namespace std;

CELDA **genMatrizDinCeldas1(const int fila, const int colu)
{
    CELDA **matriz = new CELDA *[fila];
    for (auto i = 0; i < fila; i++)
    {
        matriz[i] = new CELDA [colu];
    }
    return matriz;
}

void eliminarMatrizDinCeldas1(int filas, CELDA **matriz)
{
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}


