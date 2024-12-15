#ifndef __CUADRICULA_H__
#define __CUADRICULA_H__

#include <vector>
#include <string>
#include "Celda.h"

class Cuadricula {
    std::vector<std::vector<Celda>> celdas;
    size_t filas, columnas;

public:
    Cuadricula(size_t filas, size_t columnas);
    void mostrar() const;
    bool esCeldaValida(const std::string &celda) const;
    std::pair<size_t, size_t> obtenerPosicion(const std::string &celda) const;
    void actualizarCelda(const std::string &celda, float valor);
    float obtenerValor(const std::string &celda) const;
    size_t obtenerFilas() const;
    size_t obtenerColumnas() const;
    void inicializarAleatoriamente();
    void exportarACSV(const std::string &nombreArchivo) const;
};

#endif
