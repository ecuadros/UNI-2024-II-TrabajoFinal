#include "cell.h"
#include <iostream>
#include <string>

using namespace std;

void Cell::setValue(double val) {
    value = val;
    isFormula = false;
}

void Cell::setFormula(const string &f) {
    formula = f;
    isFormula = true;
}

double Cell::getValue() const {
    return value;
}

string Cell::getFormula() const {
    return formula;
}

bool Cell::hasFormula() const {
    return isFormula;
}