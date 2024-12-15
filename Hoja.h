#ifndef HOJA_H
#define HOJA_H

#include "Celda.h"
#include "CeldaOperacion.h"
#include "CeldaMakefile.h"
#include <vector>
#include <iostream>

using namespace std;

class Hoja {
public:
    Hoja(int filas, int columnas) : filas(filas), columnas(columnas) {
        tabla.resize(filas, vector<Celda*>(columnas, nullptr));
    }

    void establecerCelda(int fila, int columna, Celda* celda) {
        if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
            tabla[fila][columna] = celda;
        }
    }

    void mostrar() const {
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

private:
    int filas, columnas;
    vector<vector<Celda*>> tabla;
};

#endif
