#ifndef CELL_H
#define CELL_H
#include <string>
#include <cmath> //Para usar el NAN

class Cell {
private:
    std::string formula;  // Fórmula almacenada como texto (ej: "A1+B2")
    double value;         // Valor calculado de la celda
    bool isFormula;       // Indica si la celda contiene una fórmula o un valor directo
public:
    Cell() : value(NAN), isFormula(false) {}
    void setValue(double val);           // Asigna un valor directo
    void setFormula(const std::string &f); // Asigna una fórmula
    double getValue() const;             // Devuelve el valor calculado
    std::string getFormula() const;      // Devuelve la fórmula
    bool hasFormula() const;             // Devuelve true si tiene fórmula
    bool isValueDefined() const {        // Verifica si la celda tiene un valor válido (no NAN)
        return !std::isnan(value) || isFormula;
    }
};
#endif
