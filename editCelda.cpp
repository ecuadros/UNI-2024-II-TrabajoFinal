#include "editCelda.h"

using namespace std;

void EditCelda(HojaCalculo& hoja)
{
    string letraFila;
    int columna;
    string contenido;

    cout << "Digite la fila (A,B,C,..): ";
    cin >> letraFila;
    cout << "Digite la columna (1,2,3,...): ";
    cin >> columna;
    cin.ignore();
    cout << "Ingrese el contenido de la celda (string, '=A1+A2', numero): ";
    getline(cin, contenido);

    //conviertiendo las letras en numeros
    int fila = 0;
    for(char c : letraFila)
    {
        fila = fila * 26 + (c - 'A' + 1);
    }
    fila -= 1; //ajustando el indice a 0

    //asignando el contenido a la celda
    hoja.EstablecerContenidoCelda(fila, columna - 1, contenido);
    cout << "Celda actualizada correctamente.\n";
}