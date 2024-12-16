#include <iostream>
#include "Excel.h"

int main() {
    Excel miExcel(8, 9);

    miExcel.ingresarDato(2, 3, 12.5);
    miExcel.ingresarDato(1, 4, 9.3);
    miExcel.ingresarDato(1, 0, 7.2);
    miExcel.ingresarDato(5, 4, 8.4);
    miExcel.ingresarDato(0, 3, 57.8);
    miExcel.ingresarDato(7, 2, 12.8);
    miExcel.ingresarDato(2, 1, 2.2);
    miExcel.ingresarDato(4, 3, 22.4);
    miExcel.ingresarDato(3, 3, 12.5);
    miExcel.ingresarDato(0, 1, 32.1);
    miExcel.ingresarDato(1, 3, 72.7);
    miExcel.ingresarDato(0, 8, 32.1);

    // Mostrar la hoja de cálculo
    std::cout << "Proyecto MiniExcel - Kristopher Ortiz: " << std::endl;
    std::cout << "Hoja de calculo:\n";
    std::cout << "Filas y columnas: \n" << std::endl;
    miExcel.mostrarHoja();

    // Sumar una fila y una columna
    std::cout << "\nLa suma de los elementos de la fila 0 es :\n";
    miExcel.sumarFilas(0);

    std::cout << "\nLa suma de los elementos de la columna 1 es: \n";
    miExcel.sumarColumnas(1);

    return 0;
}
