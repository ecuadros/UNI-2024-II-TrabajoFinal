#include<iostream>
#include <memory>
#include"celda.h"
#include"matrizceld.h"

using namespace std;

unique_ptr<CELDA[]>*  genMatrizDinCeldas1(const int fila, const int colu)
{
    unique_ptr<CELDA[]>*  matriz = new unique_ptr<CELDA[]> [fila];
    for (auto i = 0; i < fila; i++)
    {
        matriz[i] = make_unique <CELDA[]>(colu);
    }
    return matriz;
}


/*void eliminarMatrizDinCeldas1(int filas, CELDA **matriz)
{
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
} */


