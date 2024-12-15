#include "Celda.h"
#include <cctype>

void Celda::establecerValor(const std::string& valorNuevo) {
    valor = valorNuevo;
    if (valorNuevo.find_first_not_of("0123456789.") == std::string::npos) {
        tipo = Tipo::Numero;
    } else {
        tipo = Tipo::Texto;
    }
}

std::string Celda::obtenerValor() const {
    return valor;
}

Celda::Tipo Celda::obtenerTipo() const {
    return tipo;
}
