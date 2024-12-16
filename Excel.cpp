#include "Excel.h"
#include <iostream>

// Constructor que inicializa la matriz con ceros
Excel::Excel(int filas, int columnas) {
    hoja.resize(filas, std::vector<double>(columnas, 0.0));
}

// Método para ingresar un dato en una celda específica
void Excel::ingresarDato(int fila, int columna, double dato) {
    if (fila >= 0 && columna >= 0 && fila < hoja.size() && columna < hoja[0].size()) {
        hoja[fila][columna] = dato;
    }
    else {
        std::cout << "Índice fuera de rango." << std::endl;
    }
}

// Método para obtener un dato de una celda específica
double Excel::obtenerDato(int fila, int columna) const {
    if (fila >= 0 && columna >= 0 && fila < hoja.size() && columna < hoja[0].size()) {
        return hoja[fila][columna];
    }
    else {
        std::cout << "Índice fuera de rango." << std::endl;
        return 0.0;
    }
}

// Método para mostrar la hoja de cálculo completa
void Excel::mostrarHoja() const {
    for (const auto& fila : hoja) {
        for (double dato : fila) {
            std::cout << dato << "\t";
        }
        std::cout << std::endl;
    }
}

// Método para sumar todos los valores de una fila
void Excel::sumarFilas(int fila) const {
    if (fila >= 0 && fila < hoja.size()) {
        double suma = 0.0;
        for (double valor : hoja[fila]) {
            suma += valor;
        }
        std::cout << "Suma de la fila " << fila << ": " << suma << std::endl;
    }
    else {
        std::cout << "Índice de fila fuera de rango." << std::endl;
    }
}

// Método para sumar todos los valores de una columna
void Excel::sumarColumnas(int columna) const {
    if (columna >= 0 && columna < hoja[0].size()) {
        double suma = 0.0;
        for (const auto& fila : hoja) {
            suma += fila[columna];
        }
        std::cout << "Suma de la columna " << columna << ": " << suma << std::endl;
    }
    else {
        std::cout << "Índice de columna fuera de rango." << std::endl;
    }
}
