#include<iostream>
#include<string>
#include<cmath>
#include"celda.h"
#include"operadores.h"
#include"funciones.h"


using namespace std;

string strOPERADORES[8] = {"=", "+", "-", "*", "/", "sen", "cos", "tan"};

double OPERADOR_Asignacion(string CAD, CELDA **matriz)
{
    string subcad = CAD.substr(1);
    double operando;
    if (esNombreDeCelda(subcad))
    {
        operando = stod(matriz[convertirCeldaAMatriz(subcad).pos[0]][convertirCeldaAMatriz(subcad).pos[1]].extraerValor());
    }else{
        operando = stod(subcad);
    }
    return operando;
}

double OPERADOR_Adicion(string CAD, CELDA **matriz)
{
    double operando1, operando2;
    size_t pos = CAD.find('+');
    string subcad1 = CAD.substr(0, pos);
    string subcad2 = CAD.substr(pos + 1);

    if (esNombreDeCelda(subcad1))
    {
        operando1 = stod(matriz[convertirCeldaAMatriz(subcad1).pos[0]][convertirCeldaAMatriz(subcad1).pos[1]].extraerValor());
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }else{
        operando1 = stod(subcad1);
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }

    return operando1 + operando2;
}

double OPERADOR_Sustraccion(string CAD, CELDA **matriz)
{
    double operando1, operando2;
    size_t pos = CAD.find('-');
    string subcad1 = CAD.substr(0, pos);
    string subcad2 = CAD.substr(pos + 1);

    if (esNombreDeCelda(subcad1))
    {
        operando1 = stod(matriz[convertirCeldaAMatriz(subcad1).pos[0]][convertirCeldaAMatriz(subcad1).pos[1]].extraerValor());
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }else{
        operando1 = stod(subcad1);
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }

    return operando1 - operando2;
}

double OPERADOR_Multiplicacion(string CAD, CELDA **matriz)
{
    double operando1, operando2;
    size_t pos = CAD.find('*');
    string subcad1 = CAD.substr(0, pos);
    string subcad2 = CAD.substr(pos + 1);

    if (esNombreDeCelda(subcad1))
    {
        operando1 = stod(matriz[convertirCeldaAMatriz(subcad1).pos[0]][convertirCeldaAMatriz(subcad1).pos[1]].extraerValor());
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }else{
        operando1 = stod(subcad1);
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }

    return operando1 * operando2;
}

double OPERADOR_Division(string CAD, CELDA **matriz)
{
    double operando1, operando2;
    size_t pos = CAD.find('/');
    string subcad1 = CAD.substr(0, pos);
    string subcad2 = CAD.substr(pos + 1);

    if (esNombreDeCelda(subcad1))
    {
        operando1 = stod(matriz[convertirCeldaAMatriz(subcad1).pos[0]][convertirCeldaAMatriz(subcad1).pos[1]].extraerValor());
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }else{
        operando1 = stod(subcad1);
        if (esNombreDeCelda(subcad2))
            {
                operando2 = stod(matriz[convertirCeldaAMatriz(subcad2).pos[0]][convertirCeldaAMatriz(subcad2).pos[1]].extraerValor());
            }else{
                operando2 = stod(subcad2);
            }
    }

    return operando1 / operando2;
}

double OPERADOR_Seno(string CAD, CELDA **matriz)
{
    double operando;
    if (!existeOperador(CAD))
    {
        if (esNombreDeCelda(CAD))
        {
            operando = stod(matriz[convertirCeldaAMatriz(CAD).pos[0]][convertirCeldaAMatriz(CAD).pos[1]].extraerValor());

        }else{
            operando = stod(CAD);
        }
        return sin(operando);
    }else{
        return sin(evaluar(CAD,matriz));
    }
}

double OPERADOR_Coseno(string CAD, CELDA **matriz)
{
    double operando;
    if (!existeOperador(CAD))
    {
        if (esNombreDeCelda(CAD))
        {
            operando = stod(matriz[convertirCeldaAMatriz(CAD).pos[0]][convertirCeldaAMatriz(CAD).pos[1]].extraerValor());

        }else{
            operando = stod(CAD);
        }
        return cos(operando);
    }else{
        return cos(evaluar(CAD,matriz));
    }
}

double OPERADOR_Tangente(string CAD, CELDA **matriz)
{
    double operando;
    if (!existeOperador(CAD))
    {
        if (esNombreDeCelda(CAD))
        {
            operando = stod(matriz[convertirCeldaAMatriz(CAD).pos[0]][convertirCeldaAMatriz(CAD).pos[1]].extraerValor());

        }else{
            operando = stod(CAD);
        }
        return tan(operando);
    }else{
        return tan(evaluar(CAD,matriz));
    }
}

double (*fOpe[8])(string, CELDA **matriz) = {&OPERADOR_Asignacion, &OPERADOR_Adicion, &OPERADOR_Sustraccion, &OPERADOR_Multiplicacion, &OPERADOR_Division, &OPERADOR_Seno, &OPERADOR_Coseno, &OPERADOR_Tangente};