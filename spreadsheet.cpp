#include "spreadsheet.h"
#include "utils.h"
#include "expression.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>

using namespace std;

Spreadsheet::Spreadsheet(int r, int c) : rows(r), cols(c) {}

bool Spreadsheet::isCellValid(const string &key) {
    if (key.empty()) return false;
    char col = key[0];
    int row = stoi(key.substr(1));
    return (col >= 'A' && col < 'A' + cols) && (row > 0 && row <= rows);
}

void Spreadsheet::setCell(const string &key, const string &value) {
    if (!isCellValid(key)) {
        cerr << "Error: Celda inválida " << key << endl;
        return;
    }

    if (isDigitManual(value[0]) || value[0] == '-') { // Es un valor numérico
        grid[key].setValue(stod(value));
    } else { // Es una fórmula
        grid[key].setFormula(value);
    }
}

double Spreadsheet::evaluateCell(const string &key) {
    if (!isCellValid(key)) throw invalid_argument("Celda inválida");
    Cell &cell = grid[key];

    if (!cell.hasFormula()) return cell.getValue();

    // Crear un mapa de celdas con sus valores (no con objetos Cell)
    map<string, double> cellValues;
    for (const auto& entry : grid) {
        if (!entry.second.hasFormula()) {  // Solo tomar celdas con valores, no fórmulas
            cellValues[entry.first] = entry.second.getValue();
        }
    }
    
    // Verificar si todas las referencias en la fórmula tienen un valor definido
    for (std::size_t i = 0; i < cell.getFormula().size(); ++i) {
        if (isAlphaManual(cell.getFormula()[i])) { // Detecta referencia de celda
            std::string ref;
            while (i < cell.getFormula().size() && (isAlphaManual(cell.getFormula()[i]) || isDigitManual(cell.getFormula()[i]))) {
                ref += cell.getFormula()[i++];
            }
            --i; // Retrocede un carácter
            
            if (cellValues.find(ref) == cellValues.end()) {
                throw runtime_error("Error: La celda '" + ref + "' no tiene un valor definido.");
            }
        }
    }

    // Crear un objeto Expression para evaluar la fórmula
    Expression expr(cell.getFormula(), cellValues);  // Pasar la fórmula y los valores de las celdas
    double result = expr.evaluate();  // Evaluar la fórmula respetando la jerarquía de operaciones

    // Cachear el resultado
    cell.setValue(result);
    return result;
}

void Spreadsheet::display() {
    const int cellWidth = 10;
    cout << "    ";
        for (char c = 'A'; c < 'A' + cols; ++c){
            cout << setw(cellWidth) << c << " "; // Encabezados de las columnas
        }
    cout << endl;

    for (int r = 1; r <= rows; ++r) {
        cout <<setw(2)<< r << " | ";
        for (char c = 'A'; c < 'A' + cols; ++c) {
            string key = string(1, c) + std::to_string(r);
            double cellValue = grid[key].getValue();

            if (grid[key].hasFormula()){
                cellValue = evaluateCell(key);
            } 

            string value;

            if(cellValue == static_cast<int>(cellValue)){
                value = to_string(static_cast<int>(cellValue));
            } else {
                ostringstream stream;
                stream << fixed << setprecision(2) << cellValue;
                value = stream.str();
            }
            cout << setw(cellWidth) << value << " ";
    }
    cout << endl;
    }
}
