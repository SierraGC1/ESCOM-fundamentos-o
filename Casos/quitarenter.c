
#include <string.h>

void quitarEnter(CadenaTexto *texto) {
    int longitud = strlen(texto->cadena);
    if (longitud > 0 && texto->cadena[longitud - 1] == '\n') {
        texto->cadena[longitud - 1] = '\0';
    }
}

