#include <iostream>
#include <string>
#include <memory>
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
void escribirEnCelda(unique_ptr<CELDA[]>* & , Tam, Tam);
void mostrarContenidoCelda(unique_ptr<CELDA[]>* & , Tam, Tam);
void demo1(unique_ptr<CELDA[]>* & );
// g++ main.cpp celda.cpp funciones.cpp functmallas.cpp mallas.cpp operadores.cpp matrizceld.cpp -o main

int main() {
    // 
    Tam filas = 5, columnas = 6, ancho = 10;
    unique_ptr<CELDA[]>* Matriz = genMatrizDinCeldas1(filas,columnas);
    //int tamano = size(CELDA);
    //Matriz[0][1].establecerValor(to_string(3.14));
    //demo1(Matriz);

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
    
    //eliminarMatrizDinCeldas1(filas, Matriz);
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
void escribirEnCelda(unique_ptr<CELDA[]>* & matriz, Tam filas, Tam columnas) {
    Tam fila, columna;
    string valor;

    cout<<"Ingrese celda a modificar: ";
    cin>>valor;
    rewind(stdin);
    cout<<endl;
    
    POSICIONESMATRIZ coordenadas = ::convertirCeldaAMatriz(valor);
    
    string ecuacion;
    cout<<"Ingrese ecuacion: ";
    cin>>ecuacion;
    rewind(stdin);
    cout<<ecuacion;

    matriz[coordenadas.pos[0]][coordenadas.pos[1]].establecerContenido(ecuacion);
    //matriz[coordenadas.pos[0]][coordenadas.pos[1]].establecerVisible(ecuacion);
    matriz[coordenadas.pos[0]][coordenadas.pos[1]].actualizarCelda(matriz);
}


void mostrarContenidoCelda(unique_ptr<CELDA[]>* & matriz,Tam filas,Tam columnas){
    genMalla4(filas, columnas, 16, matriz);
}


void demo1(unique_ptr<CELDA[]>* & mat)
{
    double resul=-1;
    string cad1="=B1", cad2="5";
    resul=::OPERADOR_Asignacion(cad1, mat);
    cout<<resul<<endl;
}