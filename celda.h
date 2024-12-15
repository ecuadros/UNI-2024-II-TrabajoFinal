#ifndef CELDA_H
#define CELDA_H

#include <string>

class Celda {
public:
    enum class Tipo { Vacia, Numero, Texto };

    Celda() : tipo(Tipo::Vacia), valor("") {}

    void establecerValor(const std::string& valorNuevo) {
        valor = valorNuevo;
        if (valorNuevo.find_first_not_of("0123456789.") == std::string::npos) {
            tipo = Tipo::Numero;
        } else {
            tipo = Tipo::Texto;
        }
    }

    std::string obtenerValor() const {
        return valor;
    }

    Tipo obtenerTipo() const {
        return tipo;
    }

private:
    Tipo tipo;
    std::string valor;
};

#endif
