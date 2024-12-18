#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include "cell.h"
#include <map>
#include <string>

class Spreadsheet {
private:
    std::map<std::string, Cell> grid; // Almacena celdas indexadas por su nombre (ej: "A1")
    int rows, cols;                   // Tamaño de la hoja

public:
    Spreadsheet(int r, int c);
    void setCell(const std::string &key, const std::string &value); // Asigna valor o fórmula
    double evaluateCell(const std::string &key);  // Evalúa el valor de una celda
    void display();                              // Muestra la cuadrícula
    bool isCellValid(const std::string &key);    // Valida si una celda existe
};

#endif
