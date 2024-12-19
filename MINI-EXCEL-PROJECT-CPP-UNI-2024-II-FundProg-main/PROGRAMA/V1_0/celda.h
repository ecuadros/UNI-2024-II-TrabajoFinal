#ifndef  __CELDA_H__
#define __CELDA_H__

#include<iostream>
#include<string>
#include <memory>

using namespace std;

class CELDA
{
    public:
    CELDA(){};

    private:
    string m_contenido="";
    public:
    string extraerContenido(){return m_contenido;};
    void establecerContenido(const string &cadena){m_contenido = cadena;};

    private:
    string m_valor = "0";
    public:
    string extraerValor(){return m_valor;};
    void establecerValor(const string &cadena){m_valor = cadena;};

    private:
    string m_visible=" ";
    public:
    string extraerVisible(){return m_visible;};
    void establecerVisible(const string &cadena){m_visible = cadena;};

    public:
    void actualizarCelda(unique_ptr<CELDA[]>* & matriz);

    public:
    virtual ~CELDA(){};
};

#endif //__CELDA_H__