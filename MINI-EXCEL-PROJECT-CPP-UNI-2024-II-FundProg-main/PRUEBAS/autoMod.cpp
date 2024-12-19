#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addSelfModifyingCode() {
    string fileName = "autoMod.cpp";
    ifstream inputFile(fileName);
    ofstream outputFile("autoMod.cpp");
    string line;
    bool inserted = false;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (getline(inputFile, line)) {
            outputFile << line << "\n";
            if (!inserted && line.find("// Punto de inserción") != std::string::npos) {
                outputFile << "// Código agregado automáticamente\n";
                outputFile << "std::cout << \"Nuevo código agregado\" << std::endl;\n";
                inserted = true;
            }
        }
        inputFile.close();
        outputFile.close();

        remove(fileName.c_str());
        rename("temp.cpp", fileName.c_str());
    } else {
        cerr << "Error al abrir los archivos." << endl;
    }
}

int main() {
    addSelfModifyingCode();
    return 0;
}