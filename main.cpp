#include <iostream>
#include "Hoja.h"

//g++ -std=c++17 main.cpp Hoja.cpp Celda.cpp -o main

int main(){
    Hoja PrimerExcel;

    PrimerExcel.mostrarmatriz();
    PrimerExcel.IngresarDatos();
    

    return 0;
}