#include <stdio.h>
#include "quitarenter.h"
#include "quitarenter.c" 

void ejecutarPrograma() {
    CadenaTexto texto;

    printf("Ingresa un texto:\n");
    fgets(texto.cadena, MAX_CADENA, stdin);  

    quitarEnter(&texto); 

    printf("Texto sin salto de linea:\n  %s \n", texto.cadena);  
}

int main(int argc, char *argv[]) {
    ejecutarPrograma(); 
    return 0;  
}

