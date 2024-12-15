#include "spreadsheet.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <stdexcept>

Spreadsheet::Spreadsheet(int r, int c) : rows(r), cols(c) {}

bool Spreadsheet::isCellValid(const std::string &key) {
    if (key.empty()) return false;
    char col = key[0];
    int row = std::stoi(key.substr(1));
    return (col >= 'A' && col < 'A' + cols) && (row > 0 && row <= rows);
}

void Spreadsheet::setCell(const std::string &key, const std::string &value) {
    if (!isCellValid(key)) {
        std::cerr << "Error: Celda inválida " << key << std::endl;
        return;
    }

    if (std::isdigit(value[0]) || value[0] == '-') { // Es un valor numérico
        grid[key].setValue(std::stod(value));
    } else { // Es una fórmula
        grid[key].setFormula(value);
    }
}

double Spreadsheet::evaluateCell(const std::string &key) {
    if (!isCellValid(key)) throw std::invalid_argument("Celda inválida");
    Cell &cell = grid[key];
    if (!cell.hasFormula()) return cell.getValue();

    // Evaluar fórmula simple (solo soporta operaciones básicas)
    std::istringstream iss(cell.getFormula());
    std::string token;
    double result = 0, temp;
    char op = '+';

    while (iss >> token) {
        if (isCellValid(token)) {
            temp = evaluateCell(token);
        } else {
            temp = std::stod(token);
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
    std::cout << "    ";
    for (char c = 'A'; c < 'A' + cols; ++c) std::cout << c << "      ";
    std::cout << std::endl;

    for (int r = 1; r <= rows; ++r) {
        std::cout << r << " | ";
        for (char c = 'A'; c < 'A' + cols; ++c) {
            std::string key = std::string(1, c) + std::to_string(r);
            if (grid[key].hasFormula())
                std::cout << "[" << grid[key].getValue() << "] ";
            else
                std::cout << grid[key].getValue() << "      ";
        }
        std::cout << std::endl;
    }
}
