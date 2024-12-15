#include <stdexcept>
#include "Celda.h"
using namespace std;

Celda::Celda() : contenido("") {}

void Celda::EstablecerContenido(const string& valor) {
    contenido = valor;
}

std::string Celda::ObtenerContenido() const {
    return contenido;
}

auto Celda::ObtenerValorNumerico() const{
    try{
        return stod(contenido);//funcion para convertir el string a un double
    } catch( const invalid_argument&) {
        return 0.0;// si no es un número, retorna a 0   
    }
}