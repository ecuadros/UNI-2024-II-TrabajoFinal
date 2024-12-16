#ifndef UTILS_H
#define UTILS_H

// Función para verificar si un carácter es un dígito
inline bool isDigitManual(char c) {
    return (c >= '0' && c <= '9');
}

// Función para verificar si un carácter es una letra
inline bool isAlphaManual(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

#endif // UTILS_H
