#ifndef CELDAMAKEFILE_H
#define CELDAMAKEFILE_H

#include "Celda.h"
#include <cstdlib>

class CeldaMakefile : public Celda {
public:
    void establecerComando(const std::string& comandoNuevo) {
        this->comando = comandoNuevo;
    }

    void ejecutarComando() {
        std::system(comando.c_str());
    }

private:
    std::string comando;
};

#endif
