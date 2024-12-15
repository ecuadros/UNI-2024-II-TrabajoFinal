//empezando el miniExcel
#include <iostream>
#include "menu.h"
#include "editCelda.h"

using namespace std;
int main()
{
    int filas = 26, columnas = 7; //numero inicial de filas y columnas
    HojaCalculo hoja(filas, columnas); //creando objeto

    bool running = true;
    while (running) {
        Menu();

        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nContenido de la hoja:\n";
            hoja.mostrar();
            break;

        case 2:
            EditCelda(hoja);
            break;

        case 3:
            running = false;
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion no valida. Intentalo de nuevo.\n";
        }
    }

    return 0;
    return 0;

}
