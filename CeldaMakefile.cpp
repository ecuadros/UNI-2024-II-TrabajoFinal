#include "CeldaMakefile.h"
#include <cstdlib>

void CeldaMakefile::ejecutarComando() {
    std::system(comando.c_str());
}
