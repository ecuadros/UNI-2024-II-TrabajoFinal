#include<iostream>
#include"mallas.h"
#include"functmallas.h"
#include"demosMallas.h"

void demoMalla1()
{
    RESULMALLA resultados = pedirMalla();
    genMalla1(resultados.filas, resultados.columnas, resultados.caracter);
}

void demoMalla2()
{
    genMalla2(9,9,16);
}

void demoMalla3()
{
    int contador=1;
    Tam Fi=4, Co=7, AN=16;
    string **matriz1 = nullptr;
    matriz1 = new string *[Fi];
    for (int i = 0; i < Fi; i++)
    {
        matriz1[i] = new string [Co];
    }

    for (int i = 0; i < Fi; i++)
    {
        for (int j = 0; j < Co; j++)
        {
            matriz1[i][j] = to_string(contador);
            contador++;
        }
    }
    
    
    //genMalla3(Fi,Co,AN, matriz1);
    genMalla4(Fi,Co,AN, matriz1);
    for (int i = 0; i < Fi; i++)
    {
        delete matriz1[i];
    }
    delete matriz1;
    matriz1=nullptr;
}