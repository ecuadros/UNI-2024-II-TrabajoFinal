#include "spreadsheet.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Spreadsheet sheet(10, 10); 

    string input;
    while (true) {
        sheet.display();
        cout << "Ingrese celda y valor (ej: A1=10 o B1=A1+5), o 'exit' para salir: ";
        getline(cin, input);

        if (input == "exit") break;
        auto pos = input.find('=');
        if (pos != string::npos) {
            std::string cell = input.substr(0, pos);
            std::string value = input.substr(pos + 1);
            sheet.setCell(cell, value);
        } else {
            cerr << "Entrada inválida." << endl;
        }
    }
    return 0;
}
