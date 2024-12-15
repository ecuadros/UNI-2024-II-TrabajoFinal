#include "spreadsheet.h"
#include <iostream>
#include <sstream>
#include <cctype>
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

    if (isdigit(value[0]) || value[0] == '-') { // Es un valor numérico
        grid[key].setValue(stod(value));
    } else { // Es una fórmula
        grid[key].setFormula(value);
    }
}

double Spreadsheet::evaluateCell(const string &key) {
    if (!isCellValid(key)) throw invalid_argument("Celda inválida");
    Cell &cell = grid[key];
    if (!cell.hasFormula()) return cell.getValue();

    // Evaluar fórmula simple (solo soporta operaciones básicas)
    istringstream iss(cell.getFormula());
    string token;
    double result = 0, temp;
    char op = '+';

    while (iss >> token) {
        if (isCellValid(token)) {
            temp = evaluateCell(token);
        } else {
            temp = stod(token);
        }

        switch (op) {
            case '+': result += temp; break;
            case '-': result -= temp; break;
            case '*': result *= temp; break;
            case '/': result /= temp; break;
        }

        iss >> op;
    }

    cell.setValue(result); // Cachear resultado
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
            string key = string(1, c) + to_string(r);
            string value;
            if (grid[key].hasFormula()){
                value = to_string(grid[key].getValue());
            } else{
                value = to_string(grid[key].getValue());
        }
        cout << setw(cellWidth) << value << " ";
    }
    cout << endl;
    }
}
