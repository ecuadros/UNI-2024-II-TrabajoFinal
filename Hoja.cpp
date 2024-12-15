#include "Hoja.h"
#include <iostream>

using namespace std;

void Hoja::establecerCelda(int fila, int columna, Celda* celda) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        tabla[fila][columna] = celda;
    }
}

void Hoja::mostrar() const {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (tabla[i][j]) {
                cout << tabla[i][j]->obtenerValor() << "\t";
            } else {
                cout << "Vacía\t";
            }
        }
        cout << endl;
    }
}
