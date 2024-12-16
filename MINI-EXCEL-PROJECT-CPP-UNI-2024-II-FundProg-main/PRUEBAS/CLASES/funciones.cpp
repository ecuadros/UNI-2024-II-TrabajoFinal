#include<iostream>
#include<cctype>
#include<string>
#include<cmath>
#include"tipos.h"
#include"operadores.h"
#include"celda.h"
#include"funciones.h"

using namespace std;

bool esNombreDeCelda(const string &cad)
{
    int estado = 0;

    for (char c : cad) {
        switch (estado) {
            case 0:
                if (isalpha(c)) {
                    estado = 1;
                } else {
                    return false;
                }
                break;
            case 1:
                if (isalpha(c)) {
                    estado = 1;
                } else if (isdigit(c)) {
                    estado = 2;
                } else {
                    return false;
                }
                break;
            case 2:
                if (isdigit(c)) {
                    estado = 2;
                } else {
                    return false;
                }
                break;
        }
    }
    return (estado == 2);
}

POSICIONESMATRIZ convertirCeldaAMatriz(const string &celda)
{
    POSICIONESMATRIZ coordenadas;
    int fila = 0;
    int columna = 0;
    size_t i = 0;

    // Procesar las letras para obtener la columna.
    while (i < celda.size() && isalpha(celda[i])) {
        columna = columna * 26 + (toupper(celda[i]) - 'A' + 1);
        i++;
    }

    // Procesar los números para obtener la fila.
    while (i < celda.size() && isdigit(celda[i])) {
        fila = fila * 10 + (celda[i] - '0');
        i++;
    }

    // Ajustar índices para que empiecen en 0.
    coordenadas.pos[1] = fila - 1;
    coordenadas.pos[2] = columna - 1;
    return coordenadas;
}

string convertirMatrizACelda(int fila, int columna)
{
    string celda = "";
    columna++;
    int resto;

    while (columna > 0) {
        resto = (columna - 1) % 26;
        celda = char(resto + 'A') + celda;
        columna = (columna - 1) / 26;
    }

    celda += to_string(fila + 1);

    return celda;
}

bool existeOperador(const string &cad)
{
    string strOPERADORES[] = {"=", "+", "-", "*", "/", "sen", "cos", "tan"};

    for (const std::string& operador : strOPERADORES) {
        if (cad.find(operador) != string::npos) {
            return true;
        }
    }
    return false;
}

CAD_OBJETIVO buscarCadenaObj(const string &cadena)
{
    string strOPERADORES[] = {"=", "+", "-", "*", "/", "sen", "cos", "tan"};
    CAD_OBJETIVO RESULTADO;
    int maxPrioridad = -1;
    int posSubcadena = -1;
    string operadorCapturado = "";
    string subcadenaEncontrada = "";
    int numOperadores = sizeof(strOPERADORES) / sizeof(strOPERADORES[0]); 
    
    for (int prioridad = numOperadores - 1; prioridad >= 0; --prioridad) {
        size_t pos = cadena.find(strOPERADORES[prioridad]);
        while (pos != string::npos) {
            size_t finSubcadena = pos + strOPERADORES[prioridad].size();
            size_t inicioSubcadena = pos;

            
            if (strOPERADORES[prioridad].length() > 1) {                // Esto verifica si el operador es una función unaria con paréntesis.
                size_t parAbierto = cadena.find('(', finSubcadena);
                if (parAbierto != string::npos) {
                    int contadorParentesis = 1;
                    size_t parCerrado = parAbierto + 1;
                    while (contadorParentesis > 0 && parCerrado < cadena.size()) {
                        if (cadena[parCerrado] == '(') contadorParentesis++;
                        if (cadena[parCerrado] == ')') contadorParentesis--;
                        parCerrado++;
                    }
                    finSubcadena = parCerrado;
                }
            } else {                        
                // Se extiende la subcadena para incluir números y letras a ambos lados del operador.
                while (inicioSubcadena > 0 && (isalnum(cadena[inicioSubcadena - 1]) || cadena[inicioSubcadena - 1] == '.')) {
                    inicioSubcadena--;
                }
                while (finSubcadena < cadena.size() && (isalnum(cadena[finSubcadena]) || cadena[finSubcadena] == '.')) {
                    finSubcadena++;
                }
            }

            string subcadena = cadena.substr(inicioSubcadena, finSubcadena - inicioSubcadena);

            
            if (prioridad > maxPrioridad) {                     // Hay que actualizar si se encuentra un operador de mayor prioridad.
                maxPrioridad = prioridad;
                subcadenaEncontrada = subcadena;
                posSubcadena = inicioSubcadena;
                operadorCapturado = strOPERADORES[prioridad];
            }

            
            pos = cadena.find(strOPERADORES[prioridad], finSubcadena);  // Ahora buscaremos la siguiente ocurrencia del mismo operador
        }
    }
    RESULTADO.cad = subcadenaEncontrada;
    RESULTADO.inicio = posSubcadena;
    RESULTADO.c_operador = operadorCapturado;
}

string operarCadena(const CAD_OBJETIVO &cadena, CELDA **matriz)
{
    int i=0;
    for (string ope : strOPERADORES)
    {
        if (cadena.c_operador == ope)
        {
            string nueva_subcad = to_string(fOpe[i](cadena.cad, matriz));
            return nueva_subcad;
        }
        i++;
    }
}

double evaluar(string cadena, CELDA **matriz)
{
    if (!existeOperador(cadena))
    {
        return stod(cadena);
    }else{
        CAD_OBJETIVO subcadena = buscarCadenaObj(cadena);
        string nueva_cadena = operarCadena(subcadena.cad, matriz);
        cadena.replace(subcadena.inicio, subcadena.cad.length(), nueva_cadena);
        evaluar(cadena, matriz);
    }
}
