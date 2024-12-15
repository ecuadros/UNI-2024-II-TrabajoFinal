#include "cell.h"

void Cell::setValue(double val) {
    value = val;
    isFormula = false;
}

void Cell::setFormula(const std::string &f) {
    formula = f;
    isFormula = true;
}

double Cell::getValue() const {
    return value;
}

std::string Cell::getFormula() const {
    return formula;
}

bool Cell::hasFormula() const {
    return isFormula;
}
