#include "expression.h"
#include "utils.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

// Convierte una fórmula infija a postfija
string Expression::toPostfix() {
    stringstream result;
    stack<char> operators;
    for (std::size_t i = 0; i < formula.size(); ++i) {
        if (isAlphaManual(formula[i])) { // Detecta referencia de celda
            string ref;
            while (i < formula.size() && (isAlphaManual(formula[i]) || isDigitManual(formula[i]))) {
                ref += formula[i++];
            }
            --i; // Retrocede un carácter
            
            // Reemplaza la referencia por su valor
            if (cellValues.find(ref) != cellValues.end()) {
                result << cellValues.at(ref) << " ";
            } else {
                throw std::runtime_error("Error: Referencia de celda invalida '" + ref + "'");
            }
        }
        else if (isDigitManual(formula[i]) || formula[i] == '.') { // Números
            while (i < formula.size() && (isDigitManual(formula[i]) || formula[i] == '.')) {
                result << formula[i++];
            }
            --i;
            result << " ";
        }
        else if (formula[i] == '(') {
            operators.push(formula[i]);
        }
        else if (formula[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result << operators.top() << " ";
                operators.pop();
            }
            operators.pop(); 
        }
        else { // Operadores
            while (!operators.empty() && precedence(operators.top()) >= precedence(formula[i])) {
                result << operators.top() << " ";
                operators.pop();
            }
            operators.push(formula[i]);
        }
    }

    while (!operators.empty()) {
        result << operators.top() << " ";
        operators.pop();
    }

    return result.str();
}

// Devuelve la precedencia de un operador
int Expression::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Aplica el operador entre dos números
double Expression::applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw invalid_argument("Error: Division por cero");
            return a / b;
        default: throw invalid_argument("Operador desconocido");
    }
}

// Evalúa una expresión postfija
double Expression::evaluatePostfix(const string& postfix) {
    stack<double> operands;
    stringstream ss(postfix);
    string token;
    while (ss >> token) {
        if (isDigitManual(token[0])) { // Si el token es un número
            operands.push(stod(token));
        } else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            double b = operands.top(); operands.pop();
            double a = operands.top(); operands.pop();
            operands.push(applyOperator(a, b, token[0]));
        }
    }

    return operands.top(); // El resultado final
}

// Evalúa la fórmula con los valores de las celdas
double Expression::evaluate() {
    // Reemplazar las celdas con sus valores en la fórmula
    string modifiedFormula = formula;
    for (auto& cell : cellValues) {
        std::size_t pos = 0;
        while ((pos = modifiedFormula.find(cell.first, pos)) != string::npos) {
            modifiedFormula.replace(pos, cell.first.length(), to_string(cell.second));
            pos += to_string(cell.second).length();
        }
    }

    // Convertir la fórmula infija a postfija
    string postfix = toPostfix();

    // Evaluar la expresión postfija
    return evaluatePostfix(postfix);
}