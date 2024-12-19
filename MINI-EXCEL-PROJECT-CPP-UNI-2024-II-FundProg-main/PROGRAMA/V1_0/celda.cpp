#include<iostream>
#include <memory>
#include<string>
#include"celda.h"
#include"funciones.h"

void CELDA::actualizarCelda(unique_ptr<CELDA[]>* & matriz)
{
    m_valor=to_string(evaluar(m_contenido,matriz));
    m_visible = m_valor;
}