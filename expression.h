#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <stack>
#include <map>
#include <stdexcept>

class Expression {
private:
    std::string formula;
    std::map<std::string, double> cellValues; // Mapa de celdas con sus valores

public:
    Expression(const std::string& f, const std::map<std::string, double>& values) : formula(f), cellValues(values) {}

    double evaluate(); // Evalúa la expresión con la jerarquía de operaciones y paréntesis
    double applyOperator(double a, double b, char op); // Aplica el operador entre dos números
    int precedence(char op); // Devuelve la precedencia del operador
    std::string toPostfix(); // Convierte la expresión infija a postfija
    double evaluatePostfix(const std::string& postfix); // Evalúa la expresión postfija
};

#endif