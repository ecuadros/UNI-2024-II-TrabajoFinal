#ifndef UTILIDAD_H
#define UTILIDAD_H
using namespace std;

namespace utilidad {
    inline bool esDigito(char c) {
        return (c >= '0' && c <= '9');
    }

    inline bool esCaracter(char c) {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
    }

    inline bool cadenaInt(const string& str, int& valor) {
        try {
            valor = stoi(str);
            return true;
        } catch (... ) {
            return false;
        }
    }

    inline double cadenaDouble(const string& str) {
        try {
            return stod(str);
        } catch (...) {
            return 0.0;
        }
    }

    inline char convierteMayuAminu(char c) {     //convierte carácter mayúscula a minúscula
        return (c >= 'A' && c <= 'Z') ? c +32 : c;
    }
}

#endif // UTILIDAD_H