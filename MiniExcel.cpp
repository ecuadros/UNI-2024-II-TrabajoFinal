#include <iostream>
#include "Hoja.h"
#include "Celda.h"
#include "CeldaOperacion.h"
#include "CeldaMakefile.h"

int main() {
    Hoja hoja(3, 3);  // Crear una hoja de 3x3

    // Establecer valores en algunas celdas
    Celda* celda1 = new Celda();
    celda1->establecerValor("100");
    hoja.establecerCelda(0, 0, celda1);

    Celda* celda2 = new Celda();
    celda2->establecerValor("200");
    hoja.establecerCelda(0, 1, celda2);

    Celda* celda3 = new CeldaOperacion();
    dynamic_cast<CeldaOperacion*>(celda3)->establecerFormula("100 + 200");
    hoja.establecerCelda(1, 0, celda3);

    Celda* celda4 = new CeldaMakefile();
    dynamic_cast<CeldaMakefile*>(celda4)->establecerComando("echo '¡Ejecutando comando de Makefile!'");
    hoja.establecerCelda(1, 1, celda4);

    // Mostrar la hoja
    hoja.mostrar();

    return 0;
}
