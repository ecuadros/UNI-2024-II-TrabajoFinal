#ifndef __CELDA_H__
#define __CELDA_H__

#include <vector>
#include <string>
#include <map>

class Celdas 
{
public:
    Celdas(); //Constructor
    virtual ~Celdas();

    void asignarValorCelda(const std::string&, int);
    bool ValidarCelda(const std::string&);
    int obtenerValorCelda(const std::string&);
    int calcularOperacion(const std::string&);
    bool esOperador(char);
    bool esNumero(const std::string&);
    int realizarOperacion(int, int, char);
    std::vector<std::string> dividirOperacion(const std::string&);
    bool tieneMayorPrioridad(char, char);

private:
    void matrizInicialHoja();
    std::map<std::string, int> mapadeceldas; // Mapa de celdas
};


#endif