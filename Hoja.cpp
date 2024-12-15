#include "Hoja.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

Hoja::Hoja(){}
Hoja::~Hoja(){}

void Hoja::mostrarmatriz()
{
    cout << "   ";
    for (auto i = 'A'; i <= 'Z'; i++)
    {
        cout << " " << i << " ";
    }
    cout << endl;

    for (auto j = 1; j <= 9; j++)
    {
        cout << j << " ";
        for (auto k = 'A'; k <= 'Z'; k++)
        {
            stringstream ss;
            ss << k << j;
            cout << "  " << celdas.obtenerValorCelda(ss.str());
        }
        cout << endl;
    }
        
}

bool Hoja::ingresarOperacion(const string& CadenaIngresada)
{
    size_t posicion_igual = CadenaIngresada.find('='); //busca '=', size_t ayuda saber el tamaño del vector hasta encontrar '='
    if (posicion_igual == string::npos) // si no encuentra '=' retorna false
    {
        return false;
    }
    string celdaD = CadenaIngresada.substr(0, posicion_igual); // extraemos la cadena que va desde 0 hasta la posición de '='
    string expresion = CadenaIngresada.substr(posicion_igual + 1); // extraemos la cadena que va desde la posición siguiente a '=' hasta el final de la cadena

    if (!celdas.ValidarCelda(celdaD)) // si celdaD no es una celda, retorna false
    {
        return false;
    }
    
    int resultado = celdas.calcularOperacion(expresion);
    celdas.asignarValorCelda(celdaD, resultado);
    return true;
}

void Hoja::IngresarDatos(){
    string CadenaIngresada;
    while (true)
    {
        cout << "Ingrese una operacion: ";
        getline(cin, CadenaIngresada);

        if (ingresarOperacion(CadenaIngresada))
        {
            cout << "Cadena ingresada correctamente" << endl;
        }
        else 
        {
            cout << "Error, intente nuevamente" << endl;
        }
        
        mostrarmatriz();
    } 
}