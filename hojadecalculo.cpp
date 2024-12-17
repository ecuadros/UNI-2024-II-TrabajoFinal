#include "HojaDeCalculo.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stack>
#include <map>
#include <cctype>

using namespace std;

HojaDeCalculo::HojaDeCalculo(size_t filas, size_t columnas) : cuadricula(filas, columnas) {}

void HojaDeCalculo::mostrar() const {
    cuadricula.mostrar();
}

void HojaDeCalculo::procesarEntrada(const string &entrada) {
    size_t igual = entrada.find('=');
    if (igual == string::npos) {
        throw invalid_argument("Comando inválido");
    }

    string celdaDestino = entrada.substr(0, igual);
    string formula = entrada.substr(igual + 1);

    if (!cuadricula.esCeldaValida(celdaDestino)) {
        throw invalid_argument("Celda destino inválida: " + celdaDestino);
    }

    map<string, float> valores;
    for (char col = 'A'; col < 'A' + cuadricula.obtenerColumnas(); ++col) {
        for (int fila = 1; fila <= cuadricula.obtenerFilas(); ++fila) {
            string celda = string(1, col) + to_string(fila);
            if (cuadricula.esCeldaValida(celda)) {
                valores[celda] = cuadricula.obtenerValor(celda);
            }
        }
    }

    float resultado = evaluarExpresion(formula, valores);
    cuadricula.actualizarCelda(celdaDestino, resultado);
    cout << "Celda " << celdaDestino << " actualizada a " << resultado << endl;
}

void HojaDeCalculo::inicializarAleatoriamente() {
    cuadricula.inicializarAleatoriamente();
}

void HojaDeCalculo::exportarACSV(const string &nombreArchivo) const {
    cuadricula.exportarACSV(nombreArchivo);
}

float HojaDeCalculo::evaluarExpresion(const string &expresion, map<string, float> &valores) {
    stack<float> numeros;
    stack<char> operadores;

    auto aplicarOperacion = [&]() {
        if (numeros.size() < 2 || operadores.empty()) throw invalid_argument("Expresión inválida");

        float b = numeros.top(); numeros.pop();
        float a = numeros.top(); numeros.pop();
        char op = operadores.top(); operadores.pop();

        switch (op) {
            case '+': numeros.push(a + b); break;
            case '-': numeros.push(a - b); break;
            case '*': numeros.push(a * b); break;
            case '/':
                if (b == 0) throw invalid_argument("División por cero");
                numeros.push(a / b);
                break;
            default: throw invalid_argument("Operador desconocido");
        }
    };

    size_t posInicio;
    size_t posFin;
    if ((posInicio = expresion.find("SUMA(")) != string::npos) {
        posInicio += 5;
        posFin = expresion.find(")", posInicio);
        string listaCeldas = expresion.substr(posInicio, posFin - posInicio);
        float suma = 0;
        stringstream ss(listaCeldas);
        string celda;
        while (getline(ss, celda, ',')) {
            suma += valores[celda];
        }
        numeros.push(suma);
        return suma;
    } 
    else if ((posInicio = expresion.find("PROMEDIO(")) != string::npos) {
        posInicio += 9;
        posFin = expresion.find(")", posInicio);
        string listaCeldas = expresion.substr(posInicio, posFin - posInicio);
        float suma = 0;
        int count = 0;
        stringstream ss(listaCeldas);
        string celda;
        while (getline(ss, celda, ',')) {
            suma += valores[celda];
            count++;
        }
        float promedio = suma / count;
        numeros.push(promedio);
        return promedio;
    }

    for (size_t i = 0; i < expresion.size(); ++i) {
        char c = expresion[i];

        if (isspace(c)) continue;

        if (isdigit(c) || (c == '-' && (i == 0 || expresion[i - 1] == '('))) {
            size_t j = i;
            while (j < expresion.size() && (isdigit(expresion[j]) || expresion[j] == '.')) ++j;
            numeros.push(stof(expresion.substr(i, j - i)));
            i = j - 1;
        } 
        else if (isalpha(c)) {
            size_t j = i;
            while (j < expresion.size() && isalnum(expresion[j])) ++j;
            string celda = expresion.substr(i, j - i);
            if (valores.find(celda) == valores.end()) {
                throw invalid_argument("Referencia a celda inválida: " + celda);
            }
            numeros.push(valores[celda]);
            i = j - 1;
        } 
        else if (c == '(') {
            operadores.push(c);
        } 
        else if (c == ')') {
            while (!operadores.empty() && operadores.top() != '(') {
                aplicarOperacion();
            }
            if (operadores.empty() || operadores.top() != '(') throw invalid_argument("Paréntesis desbalanceados");
            operadores.pop();
        } 
        else if (string("+-*/").find(c) != string::npos) {
            while (!operadores.empty() && string("+-*/").find(operadores.top()) <= string("+-*/").find(c)) {
                aplicarOperacion();
            }
            operadores.push(c);
        } 
        else {
            throw invalid_argument("Carácter inválido en la expresión");
        }
    }

    while (!operadores.empty()) {
        aplicarOperacion();
    }

    if (numeros.size() != 1) throw invalid_argument("Expresión inválida");

    return numeros.top();
}
