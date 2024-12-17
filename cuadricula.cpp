#include "Cuadricula.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;

Cuadricula::Cuadricula(size_t filas, size_t columnas) : filas(filas), columnas(columnas) {
    celdas.resize(filas, vector<Celda>(columnas));
}

void Cuadricula::mostrar() const {
    cout << "   ";
    for (char col = 'A'; col < 'A' + columnas; ++col) {
        cout << "     " << col;
    }
    cout << endl;

    for (size_t i = 0; i < filas; ++i) {
        cout << setw(3) << i + 1;
        for (size_t j = 0; j < columnas; ++j) {
            cout << setw(6) << celdas[i][j].getValor();
        }
        cout << endl;
    }
}

bool Cuadricula::esCeldaValida(const string &celda) const {
    if (celda.length() < 2 || !isalpha(celda[0]) || !isdigit(celda[1])) {
        return false;
    }

    char col = toupper(celda[0]);
    int fila = stoi(celda.substr(1));

    return col >= 'A' && col < 'A' + columnas && fila >= 1 && fila <= filas;
}

pair<size_t, size_t> Cuadricula::obtenerPosicion(const string &celda) const {
    char col = toupper(celda[0]);
    int fila = stoi(celda.substr(1)) - 1;
    return {fila, col - 'A'};
}

void Cuadricula::actualizarCelda(const string &celda, float valor) {
    auto [fila, col] = obtenerPosicion(celda);
    celdas[fila][col].setValor(valor);
}

float Cuadricula::obtenerValor(const string &celda) const {
    auto [fila, col] = obtenerPosicion(celda);
    return celdas[fila][col].getValor();
}

size_t Cuadricula::obtenerFilas() const { return filas; }

size_t Cuadricula::obtenerColumnas() const { return columnas; }

void Cuadricula::inicializarAleatoriamente() {
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            celdas[i][j].setValor(rand() % 100);
        }
    }
}

void Cuadricula::exportarACSV(const string &nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            archivo << celdas[i][j].getValor();
            if (j < columnas - 1) archivo << ",";
        }
        archivo << endl;
    }

    archivo.close();
    cout << "Cuadrícula guardada en " << nombreArchivo << endl;
} // Faltaba esta llave (único cambio del 17/12)
