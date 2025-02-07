#include <stdio.h>

char *buscar(encontrar *busqueda) {
    int i = 0;
    while (i < busqueda->longitudTexto) {
        if (*(busqueda->texto + i) == busqueda->caracterBuscar) {
            return (busqueda->texto + i); 
        }
        i++;
    }
    return NULL; 
}

