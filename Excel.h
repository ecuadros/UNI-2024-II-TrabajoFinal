#ifndef EXCEL_H
#define EXCEL_H

#include <vector>
#include <string>

class Excel {
public:
    // Constructor
    Excel(int filas, int columnas);

    // Métodos
    void ingresarDato(int fila, int columna, double dato);
    double obtenerDato(int fila, int columna) const;
    void mostrarHoja() const;
    void sumarFilas(int fila) const;
    void sumarColumnas(int columna) const;

private:
    // Representación de la hoja de cálculo (matriz)
    std::vector<std::vector<double>> hoja;
};

#endif // EXCEL_H
#pragma once
