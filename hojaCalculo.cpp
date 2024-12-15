#include <iostream>
#include <cmath>
#include <iomanip>
#include "utilidad.h"
#include "hojaCalculo.h"
using namespace std;

//constructor
HojaCalculo::HojaCalculo(int filas, int columnas)
            :red(filas, vector<Celda>(columnas)){}

//asigando el contenido a las celda
void HojaCalculo::EstablecerContenidoCelda(int fila, int columna, const string& valor)
{
    if(fila >= 0 && columna >= 0 && fila < red.size() && columna < red[0].size())
    {
        return red[fila][columna].EstablecerContenido(valor);
    }
}

//obteniendo el contenido de la celda (cuerpo)
string HojaCalculo::ObtenerContenidoCelda(int fila, int columna) const
{
    if(fila >= 0 && columna >= 0 && fila < red.size() && columna < red[0].size())
    {
        return red[fila][columna].ObtenerContenido();
    }
    return "";
}

//obteniendo el valor numero de una celda
double HojaCalculo::ObtenerValorCelda(int fila, int columna) const
{
    string contenido = ObtenerContenidoCelda(fila, columna);
    //evaluar si es formula
    if(!contenido.empty() && contenido[0] == '=')
    {
        return EvaluarExpresion(contenido.substr(1));// quitamos el '='
    }

    //en el caso no sea formula, intentar convertirlo a numero
    return utilidad::cadenaDouble(contenido);
}

//generar etiquetas para las filas
string HojaCalculo::GenerarLetraFila(int indice) const
{
    string etiqueta;
    while (indice >= 0)
    {
        etiqueta = static_cast<char>('A' + (indice % 26)) + etiqueta;
        indice = (indice/26) - 1;
    }
    return etiqueta;
}

//conviertiendo una referencia de una celda
bool HojaCalculo::ConvertirCelda(const string& ref, int& fila, int& columna) const
{
    int posicion = 0;
    //leyendo letras de la fila
    while(posicion < ref.size() && utilidad::esCaracter(ref[posicion]))
    {
        posicion++;
    }

    string EtiquetaFila = ref.substr(0, posicion);
    string EtiquetaColumna = ref.substr(posicion);

    //convirtiendo fila(letras) a indices
    fila = 0;
    for(char c : EtiquetaFila)
    {
        fila = fila * 26 + ((utilidad::convierteMayuAminu(c) - 'a') + 1);
    }
    fila -= 1;

    //convirtiendo columna (numero) a indices
    if(!utilidad::cadenaInt(EtiquetaColumna, columna))
    {
        return false;
    }
    columna -= 1;

    return fila >= 0 && columna >= 0;
}

//conviertiendo una expresión infija a postfija
string HojaCalculo::InfijaAposFija(const string& expresion) const 
{
    char ops[100];
    int top = -1;
    string output;
    //prioridad de los operadores matematicos
    auto precedence = [](char op) 
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    };

    for (size_t i = 0; i < expresion.size(); ++i) 
    {
        char token = expresion[i];

        if (utilidad::esDigito(token) || token == '.') 
        {
            while (i < expresion.size() && (utilidad::esDigito(expresion[i]) || expresion[i] == '.')) 
            {
                output += expresion[i++];
            }
            output += " ";
            --i;
        } 
        else if (utilidad::esCaracter(token)) 
        {
            string celdaRef;
            while (i < expresion.size() && (utilidad::esCaracter(expresion[i]) || utilidad::esDigito(expresion[i]))) 
            {
                celdaRef += expresion[i++];
            }
            output += celdaRef + " ";
            --i;
        } 
        else if (token == '(') 
        {
            ops[++top] = token;
        } 
        else if (token == ')') 
        {
            while (top >= 0 && ops[top] != '(') 
            {
                output += ops[top--];
                output += " ";
            }
            --top;
        } 
        else 
        {
            while (top >= 0 && precedence(ops[top]) >= precedence(token)) 
            {
                output += ops[top--];
                output += " ";
            }
            ops[++top] = token;
        }
    }

    while (top >= 0) 
    {
        output += ops[top--];
        output += " ";
    }

    return output;
}

//evaluando una expresión postfija
double HojaCalculo::EvaluandoPosfija(const string& posfija) const 
{
    double valores[100];
    int top = -1;
    string token;

    for (size_t i = 0; i < posfija.size(); ++i) 
    {
        if (posfija[i] == ' ') continue;

        if (utilidad::esDigito(posfija[i]) || (posfija[i] == '-' && i + 1 < posfija.size() && utilidad::esDigito(posfija[i + 1]))) 
        {
            size_t start = i;
            while (i < posfija.size() && (utilidad::esDigito(posfija[i]) || posfija[i] == '.')) {
                ++i;
            }
            token = posfija.substr(start, i - start);
            valores[++top] = utilidad::cadenaDouble(token);
            --i;
        } else if (utilidad::esCaracter(posfija[i])) {
            token.clear();
            while (i < posfija.size() && (utilidad::esCaracter(posfija[i]) || utilidad::esDigito(posfija[i]))) {
                token += posfija[i++];
            }
            int fila, columna;
            if (ConvertirCelda(token, fila, columna)) {
                valores[++top] = ObtenerValorCelda(fila, columna);
            } else {
                return 0.0; // Referencia inválida
            }
            --i;
        } else {
            double b = valores[top--];
            double a = valores[top--];
            switch (posfija[i]) {
                case '+': valores[++top] = a + b; break;
                case '-': valores[++top] = a - b; break;
                case '*': valores[++top] = a * b; break;
                case '/': valores[++top] = b != 0 ? a / b : 0.0; break;
            }
        }
    }

    return valores[top];
}

//metodo principal para evaluar expresiones
double HojaCalculo::EvaluarExpresion(const string& expression) const 
{
    //si es una función como SUM(A1:B2), evaluala primero
    if (expression.rfind("SUM(", 0) == 0) 
    {
        size_t empezar = expression.find('(') + 1;
        size_t fin = expression.find(')');
        string rango = expression.substr(empezar, fin - empezar);
        return EvaluarFuncion("SUM", rango);
    }
    //si no es una funcion evalúa la expresión normal
    string postfija = InfijaAposFija(expression);
    return EvaluandoPosfija(postfija);
}

//soporte para funciones como SUM
double HojaCalculo::EvaluarFuncion(const string& funcion, const string& rango) const 
{
    if (funcion == "SUM") 
    {
        int filaInicial, columnaInicial, filaFinal, columnaFinal;
        string celdaInicial = rango.substr(0, rango.find(':'));
        string celdaFinal = rango.substr(rango.find(':') + 1);

        if (ConvertirCelda(celdaInicial, filaInicial, columnaInicial) && ConvertirCelda(celdaFinal, filaFinal, columnaFinal)) 
        {
            double sum = 0.0;
            for (int r = filaInicial; r <= filaFinal; ++r) 
            {
                for (int c = columnaInicial; c <= columnaFinal; ++c) 
                {
                    sum += ObtenerValorCelda(r, c);
                }
            }
            return sum;
        }
    }
    return 0.0; //por si no reconoce la función, retorna 0.0
}

//mostrar la hoja de cálculo
void HojaCalculo::mostrar() const 
{
    int columnas = red[0].size();
    int filas = red.size();

    // Mostrar encabezados de columnas
    cout << setw(9) << " "; // Espacio para etiquetas de filas
    for (int columna = 1; columna <= columnas; ++columna) 
    {
        cout << setw(12) << columna << " | ";  // Ajuste de espacio para mejor alineación
    }
    cout << "\n";

    //mostrar separador
    cout << string(6 + (columnas * 15), '-') << "\n";  // Ajustar longitud del separador

    // Mostrar filas con etiquetas
    for (int fila = 0; fila < filas; ++fila) 
    {
        cout << std::setw(6) << GenerarLetraFila(fila) << " | ";
        for (int col = 0; col < columnas; ++col) {
            try 
            {
                //evaluando el contenido si es fórmula
                string content = red[fila][col].ObtenerContenido();
                if (!content.empty() && content[0] == '=') 
                {
                    //asegurando que los números se impriman con decimales
                    cout << setw(12) << fixed << setprecision(2) 
                          << EvaluarExpresion(content.substr(1)) << " | ";
                } 
                else 
                {
                    cout << std::setw(12) << content << " | ";  //alineando las celdas
                }
            } 
            catch (const exception& e) 
            {
                cout << setw(12) << "ERR" << " | ";  //manejando los errores
            }
        }
        cout << "\n";

        //imprimiendo el  separador después de cada fila
        cout << string(6 + (columnas * 15), '-') << "\n";  // Ajustar longitud del separador
    }
}