#include<iostream>
#include"celda.h"
#include"funciones.h"

void CELDA::actualizarCelda(CELDA **matriz)
{
    m_valor=evaluar(m_contenido,matriz);
    m_visible = m_valor;
}