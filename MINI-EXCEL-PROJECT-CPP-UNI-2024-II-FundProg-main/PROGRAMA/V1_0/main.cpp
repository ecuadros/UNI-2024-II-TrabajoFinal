#include <iostream>
#include <string>
#include "celda.h"
#include "funciones.h"
#include "matrizceld.h"
#include "operadores.h"
#include "mallas.h"
#include "functmallas.h"
#include "tipos.h"

using namespace std;

// Prototipos de las funciones
void mostrarMenu();
void escribirEnCelda(CELDA **, Tam, Tam);
void mostrarContenidoCelda(CELDA **, Tam, Tam);
// g++ main.cpp celda.cpp funciones.cpp functmallas.cpp mallas.cpp operadores.cpp matrizceld.cpp -o main

int main() {
    // 
    Tam filas = 5, columnas = 6, ancho = 10;
    CELDA **Matriz = genMatrizDinCeldas1(filas,columnas);
    

    int opcion = 0;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                escribirEnCelda(Matriz, filas, columnas);
                break;
            case 2:
                mostrarContenidoCelda(Matriz, filas, columnas);
                break;
            case 3:
                genMalla4(filas, columnas, ancho, Matriz);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
    
    eliminarMatrizDinCeldas1(filas, Matriz);
    return 0;
}

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n--- Menu Interactivo ---\n";
    cout << "1. Escribir en una celda\n";
    cout << "2. Mostrar contenido de una celda\n";
    cout << "3. Mostrar malla completa\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Función para escribir en una celda
void escribirEnCelda(CELDA **matriz, Tam filas, Tam columnas) {
    Tam fila, columna;
    string valor;

    cout<<"Ingrese celda a modificar: ";
    getline(cin,valor);
    
    POSICIONESMATRIZ coordenadas = convertirCeldaAMatriz(valor);
    
    string ecuacion;
    cout<<"Ingrese ecuacion: ";
    getline(cin,ecuacion);

    matriz[coordenadas.pos[0]][coordenadas.pos[1]].establecerContenido(ecuacion);

    matriz[coordenadas.pos[0]][coordenadas.pos[1]].actualizarCelda(matriz);
}


void mostrarContenidoCelda(CELDA **matriz,Tam filas,Tam columnas){
    genMalla4(filas, columnas, 16, matriz);
}