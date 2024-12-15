#include "Celda.h"

Celda::Celda() : valor(0.0f) {}

void Celda::setValor(float val) {
    valor = val;
}

float Celda::getValor() const {
    return valor;
}
