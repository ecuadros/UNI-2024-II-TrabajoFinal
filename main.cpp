#include "HojaDeCalculo.h"
#include <iostream>

using namespace std;

int main() {
    size_t filas, columnas;
    cout << "Ingrese el tamaño de la cuadrícula (Filas x Columnas): ";
    cin >> filas >> columnas;

    HojaDeCalculo hoja(filas, columnas);
    hoja.mostrar();
    string entrada;
    while (true) {
        cout << "\nOpciones disponibles:\n";
        cout << "1. Ingresar una fórmula (ejemplo: A1 = B1 + C1)\n";
        cout << "2. Inicializar celdas aleatoriamente\n";
        cout << "3. Exportar cuadrícula a archivo CSV\n";
        cout << "4. Mostrar cuadrícula\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese la fórmula: ";
                cin.ignore(); // Limpiar el buffer
                getline(cin, entrada);
                try {
                    hoja.procesarEntrada(entrada);
                } catch (const exception &e) {
                    cout << "Error: " << e.what() << endl;
                }
                hoja.mostrar();
                break;
            }
            case 2:
                hoja.inicializarAleatoriamente();
                cout << "Celdas inicializadas aleatoriamente." << endl;
                hoja.mostrar();
                break;
            case 3: {
                cout << "Ingrese el nombre del archivo CSV: ";
                string nombreArchivo;
                cin >> nombreArchivo;
                hoja.exportarACSV(nombreArchivo);
                hoja.mostrar();
                break;
            }
            case 4:
                hoja.mostrar();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
