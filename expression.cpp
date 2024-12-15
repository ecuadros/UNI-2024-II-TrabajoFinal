#include "expression.h"
#include <sstream>
#include <iostream>

using namespace std;

// Convierte una fórmula infija a postfija
string Expression::toPostfix() {
    stringstream result;
    stack<char> operators;
    for (size_t i = 0; i < formula.size(); i++) {
        char token = formula[i];

        if (isdigit(token)) {
            result << token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result << " " << operators.top();
                operators.pop();
            }
            operators.pop(); // Quitar el '('
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                result << " " << operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    // Vaciar los operadores restantes
    while (!operators.empty()) {
        result << " " << operators.top();
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
            if (b == 0) throw invalid_argument("Error: División por cero");
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
        if (isdigit(token[0])) { // Si el token es un número
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
        size_t pos = 0;
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
