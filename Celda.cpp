#include <sstream> // permite construir cadenas de texto con cualquier tipo de dato
#include "Celda.h"
#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

Celdas::Celdas(){
    matrizInicialHoja();
}
Celdas::~Celdas(){}

void Celdas::matrizInicialHoja() // Hacemos nuestra matriz inicial
{
    for (auto i = 'A'; i <= 'Z'; i++)
    {
        for (auto j = 1; j <= 9; j++)
        {
            stringstream ss;
            ss << i << j; // ss recibe un entero j y luego un caracter i, así genera als celdas como: A1, E9, etc
            mapadeceldas[ss.str()] = 0; // ss.str() es la cadena Caracter-Entero que es la celda, y a esta le asigna el valor de 0
        }
    }
    
}

void Celdas::asignarValorCelda(const string& celda, int valor)
{
    cout << "Asignando valor " << valor << " a la celda " << celda << endl; // cerificar que el valor se a asignado correctamente
    mapadeceldas[celda] = valor; // cada celda tiene un valor
}

bool Celdas::ValidarCelda(const string& celda)
{
    return celda.size() == 2 && (celda[0] >= 'A' && celda[0] <= 'Z') && (celda[1] >= '1' && celda[1] <= '9');
}

int Celdas::obtenerValorCelda(const string& celda)
{
    return mapadeceldas[celda]; // Da el valor de la celda
}

bool Celdas::esOperador(char operador)
{
    return operador == '+' || operador == '-' || operador == '*' || operador == '/';
}

bool Celdas::esNumero(const string& Cadena)
{
    for (char Numero : Cadena)
    {
        if (Numero < '0' || Numero > '9')
        {
            return false;
        } 
    }
    return true; 
}

vector<string> Celdas::dividirOperacion(const string& CadenaIngresada)
{
    vector<string> elementos;
    string temp;
    for (auto i : CadenaIngresada) // Se va a dividir la cadena ingresada por el usuario, i toma cada elemento de CadenaIngresada
    {
        if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') || (i == '.'))
        {
            temp += i;
        }
        else if (esOperador(i)) // si "i" es un operador
        {
            if (!temp.empty()) // si temp no está vacío, ".empty returna true si no hay nada en el vector, pero se convierte en una negación gracias al !" 
            {
                elementos.push_back(temp); // agrega elementos al final del vector.
                temp.clear(); // elimina los elementos del contenedor.
            }
            string op(1, i); // crea una cadena llamada op, que tiene solo 1 wespacio y este es rellenado por i
            elementos.push_back(op);  
        }
    }
    if (!temp.empty()) // si temp no está vacío
    {
        elementos.push_back(temp); // Agrega el último número o celda
    }
    return elementos;
}

int Celdas::realizarOperacion(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
            return a - b;
    case '*':
        return a * b;
    case '/':
        return b != 0 ? a / b : 0; // se pregunta si b es diferente de cero, si es así, opera.
    default:
    return 0;
    }
}

int Celdas::calcularOperacion(const string& CadenaIngresada)
{
    vector<string> elementos = dividirOperacion(CadenaIngresada); // divide la cadena en partes
    vector<int> valores;
    vector<char> operadores;
    
    for (const auto& elem : elementos) {
    if (esNumero(elem)) {
        valores.push_back(stoi(elem));  // convierte el string a entero con stoi
    } else if (ValidarCelda(elem)) {
        valores.push_back(obtenerValorCelda(elem));  // obtiene el valor de la celda
    } else if (esOperador(elem[0])) {
        while (!operadores.empty() && tieneMayorPrioridad(operadores.back(), elem[0])) { // hace caso al signo con mayor prioridad
            int b = valores.back(); // obtiene una referencia del último elemento agregado al vector
            valores.pop_back(); // elimina el ultimo elemento del vector valores
            int a = valores.back();
            valores.pop_back();
            char oper = operadores.back(); // obtiene el ultimo signo agregado (+,-,*,/) 
            operadores.pop_back(); // elimina el ultimo signo del vector operadores
            valores.push_back(realizarOperacion(a, b, oper)); // hace la operación y seguidamente ingresa el resultado al vector valores
        }
        operadores.push_back(elem[0]);  // guarda el operador actual
    }
}


    while (!operadores.empty()) // si no está vacío
    {
         int b = valores.back();
        valores.pop_back();
        int a = valores.back();
        valores.pop_back();
        char oper = operadores.back();
        operadores.pop_back();
        valores.push_back(realizarOperacion(a, b, oper)); 
    }
    
    return valores.back(); // resultado final;
}

bool Celdas::tieneMayorPrioridad(char a, char b) {
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) {
        return true;  // '*' y '/' es más importante que '+' y '-'
    }
    return false; 
}