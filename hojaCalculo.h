#ifndef HOJACALCULO_H
#define HOJACALCULO_H

#include <vector> // para hacer las celdas
#include <string>
#include <stdexcept> // libreria para manejar excepciones
#include "Celda.h"

class HojaCalculo
{
    private:
    vector<vector<Celda>> red; // generar las celdas y que cada celda contenga un objeto de class celda
    //generando las etiquetas para las filas (A,B,..)
    string GenerarLetraFila(int indice) const;
    //evaluar las expresiones =A1+B2
    double EvaluarExpresion(const string& expresion) const;
    //covirtiendo uan referencia de una celda a indices de fila y columna
    bool ConvertirCelda( const string& ref, int& fila, int& columna) const;
    //convertir una expresion de una celda infija a posfija para evaluarla 
    string InfijaAposFija(const string& expresion) const;
    //evaluando la expresion posfija
    double EvaluandoPosfija(const string& postfija) const;
    //validand rangos de celda
    bool CeldaEnRango(int fila, int columna) const;
    //creando soporte para funciones
    double EvaluarFuncion(const string& funcion, const string& rango) const;

    public:
    HojaCalculo(int fila, int columna); //aqui esta el constructor que inicializa la hoja de calculo
    //asignando contenido a una celda
    void EstablecerContenidoCelda(int fila, int colummna, const string& valor);
    //para obtener el contenido textual de la celda
    string ObtenerContenidoCelda(int fila, int columna) const;
    //obteniendo el valor numerico elavuado de una celda
    double ObtenerValorCelda(int fila, int columna) const;
    //mostrando la hoja de calcula en la pantalla
    void mostrar() const;

};

#endif //HOJACALCULO_H