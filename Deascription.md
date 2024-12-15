#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;
//Se define dos constantes que definen el tamaño de la matriz
const int ROWS = 3;  //Filas
const int COLS = 4;  //Columnas (A-D)

//Matriz para almacenar los valores de las celdas
double sheet[ROWS][COLS] = {0};

//Función para convertir la columna de texto (A-D) a un índice entero
int columnToIndex(char col) {
    return col - 'A';  //Convierte A=0, B=1, C=2, D=3
}

//Función para asignar valores a las celdas
void assignValue(string input) {
    string cell;
    double value;

    //Separar la celda del valor
    size_t pos = input.find('=');
    if (pos != string::npos) {
        cell = input.substr(0, pos);
        value = atof(input.substr(pos + 1).c_str());

        //Extraer fila y columna
        char col = cell[0];
        int row = cell[1] - '1';

        int colIndex = columnToIndex(col);

        //Validar límites
        if (row >= 0 && row < ROWS && colIndex >= 0 && colIndex < COLS) {
            sheet[row][colIndex] = value;
        }
    }
}

//Función para evaluar expresiones respetando la precedencia de operadores
double evaluateExpression(string formula) {
    stack<double> values; //Pila para los valores
    stack<char> ops;      //Pila para los operadores

    auto applyOperator = [](double a, double b, char op) -> double {
        switch (op) {
            case '+': return a + b;//Para la suma de celdas
            case '-': return a - b;//Para la resta de celdas
            case '*': return a * b;//Para la multiplicación de celdas
            case '/': return a / b;//Para la división de celdas
        }
        return 0;
    };

    for (size_t i = 0; i < formula.length(); i++) {
        if (isdigit(formula[i]) || isalpha(formula[i])) {
            string token;
            while (i < formula.length() && (isalnum(formula[i]) || formula[i] == '.')) {
                token += formula[i++];
            }
            i--;

            if (isalpha(token[0])) { //Es una celda
                char tokenCol = token[0];
                int tokenRow = token[1] - '1';
                int tokenColIndex = columnToIndex(tokenCol);

                if (tokenRow >= 0 && tokenRow < ROWS && tokenColIndex >= 0 && tokenColIndex < COLS) {
                    values.push(sheet[tokenRow][tokenColIndex]);
                } else {
                    cout << "Referencia a celda invalida: " << token << endl;
                    return 0;
                }
            } else {    //Es un número
                values.push(atof(token.c_str()));
            }
        } else if (formula[i] == '+' || formula[i] == '-') {
            while (!ops.empty() && (ops.top() == '+' || ops.top() == '-' || ops.top() == '*' || ops.top() == '/')) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(formula[i]);
        } else if (formula[i] == '*' || formula[i] == '/') {
            while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(formula[i]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}

//Función para calcular valores basados en fórmulas
void calculateFormula(string input) {
    string cell;
    string formula;

    //Separar celda de la fórmula
    size_t pos = input.find('=');
    if (pos != string::npos) {
        cell = input.substr(0, pos);
        formula = input.substr(pos + 1);

        //Extraer celda objetivo
        char col = cell[0];
        int row = cell[1] - '1';

        int colIndex = columnToIndex(col);

        //Validar límites
        if (row >= 0 && row < ROWS && colIndex >= 0 && colIndex < COLS) {
            //Evaluar la fórmula
            double result = evaluateExpression(formula);
            sheet[row][colIndex] = result;
        }
    }
}

//Función para mostrar la hoja de cálculo
void displaySheet() {
    cout << "\nHoja de calculo actual:\n";
    cout << "   A       B       C       D\n";
    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; j < COLS; j++) {
            cout << sheet[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    string input;
    cout << "Trabajo final - Hoja de calculo en C++\n";

    while (true) {
        cout << "\nIngrese formula (o escriba 'salir' para terminar): ";
        getline(cin, input);

        if (input == "salir") break;

        if (input.find('=') != string::npos) {
            //Determinar si es asignación de valor o fórmula
            if (input.find_first_of("+-*/") != string::npos) {
                calculateFormula(input);
            } else {
                assignValue(input);
            }
            displaySheet();
        } else {
            cout << "Entrada invalida. Vuelva a intentarlo.\n";
        }
    }

    return 0;
}
