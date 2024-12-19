#include<iostream>
#include<string>
#include"mallas.h"
#include"functmallas.h"

using namespace std;

RESULMALLA pedirMalla()
{
    Tam f, c;
    char carac;

    cout<<"\nDigite las filas, columnas y un caracter para generar la malla: ";
    cin>>f>>c;
    cin>>carac;

    RESULMALLA resultado = {f,c,carac};
    return resultado;
}

string ceStringFormat(const string & cstr=" ", int n = 16)
{
    string resultado = cstr.substr(0, n);
    resultado.resize(n, ' ');
    return resultado;
}

string ceStringFormat(const char & c='A', int n = 16)
{
    string cstr(1, c);
    string resultado = cstr.substr(0, n);
    resultado.resize(n, ' ');
    return resultado;
}