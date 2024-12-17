#ifndef __HOJADECALCULO_H__
#define __HOJADECALCULO_H__

#include "Cuadricula.h"
#include <map>
#include <stack>
#include <string>

class HojaDeCalculo {
    Cuadricula cuadricula;
    float evaluarExpresion(const std::string &expresion, std::map<std::string, float> &valores);

public:
    HojaDeCalculo(size_t filas, size_t columnas);
    void mostrar() const;
    void procesarEntrada(const std::string &entrada);
    void inicializarAleatoriamente();
    void exportarACSV(const std::string &nombreArchivo) const;
};

#endif 
