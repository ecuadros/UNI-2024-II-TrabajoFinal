#include "spreadsheet.h"
#include <iostream>

int main() {
    Spreadsheet sheet(5, 5); // Hoja de 5x5

    std::string input;
    while (true) {
        sheet.display();
        std::cout << "Ingrese celda y valor (ej: A1=10 o B1=A1+5), o 'exit' para salir: ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        auto pos = input.find('=');
        if (pos != std::string::npos) {
            std::string cell = input.substr(0, pos);
            std::string value = input.substr(pos + 1);
            sheet.setCell(cell, value);
        } else {
            std::cerr << "Entrada inválida." << std::endl;
        }
    }

    return 0;
}
