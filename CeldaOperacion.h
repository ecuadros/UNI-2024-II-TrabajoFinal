#ifndef CELDAOPERACION_H
#define CELDAOPERACION_H

#include "Celda.h"
#include <string>

class CeldaOperacion : public Celda {
public:
    void establecerFormula(const std::string& formulaNueva) {
        this->formula = formulaNueva;
    }

    std::string obtenerFormula() const {
        return formula;
    }

    double calcular() const;

private:
    std::string formula;
};

#endif
