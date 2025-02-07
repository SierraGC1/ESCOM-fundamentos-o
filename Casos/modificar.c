#include <stdio.h>

char *modificacion(modificar *mod) {
    int i = 0;
    while (i < mod->longitudTexto) {
        if (mod->texto[i] == mod->viejoCaracter) {
            mod->texto[i] = mod->nuevoCaracter; 
        }
        i++;
    }
    return mod->texto; 
}

