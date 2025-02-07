
#include <stdio.h>
#include "buscar.h"
#include "buscar.c"
void ejecutarPrograma() {
    encontrar busqueda;  
    printf("Ingrese un texto: ");
    fgets(busqueda.texto, MAX_CADENA, stdin);  
    busqueda.longitudTexto = 0;
    while (busqueda.texto[busqueda.longitudTexto] != '\0' && busqueda.texto[busqueda.longitudTexto] != '\n') {
        busqueda.longitudTexto++;
    }

    printf("Ingrese el caracter a buscar: ");
    scanf(" %c", &busqueda.caracterBuscar); 
    
    char *resultado = buscar(&busqueda);
    if (resultado != NULL) {
        printf("El caracter '%c' fue encontrado en la posicion: %ld\n", busqueda.caracterBuscar, resultado - busqueda.texto);
    } else {
        printf("El caracter '%c' no fue encontrado.\n", busqueda.caracterBuscar);
    }
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

