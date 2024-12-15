#ifndef CELDA_H
#define CELDA_H

#include <string>   
using namespace std;

class Celda 
{
private:
    string contenido; // Contenido de la celda}

public:
    Celda(); // contructor de la celda
    void EstablecerContenido(const string& valor);
    string ObtenerContenido() const;
    auto ObtenerValorNumerico() const; //convierte el contenido a número, si aplica
};

#endif //CELDA_H