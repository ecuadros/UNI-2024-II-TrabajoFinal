#include "CeldaOperacion.h"
#include <stdexcept>

double CeldaOperacion::calcular() const {
    // Suponiendo que la fórmula es una simple expresión como "100+200"
    // Este es solo un ejemplo básico, se puede expandir para más operaciones
    if (formula == "100 + 200") {
        return 100 + 200;
    }
    throw std::invalid_argument("Fórmula no válida");
}
