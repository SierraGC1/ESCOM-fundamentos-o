#include <stdio.h>
#include "modificar.h"  
#include "modificar.c" 
void ejecutarPrograma() {
    modificar mod;  
    printf("Ingrese el texto: ");
    fgets(mod.texto, MAX_CADENA, stdin);  
    
    mod.longitudTexto = 0;
    while (mod.texto[mod.longitudTexto] != '\0') {
        mod.longitudTexto++;
    }

    printf("Ingrese el caracter a reemplazar: ");
    scanf(" %c", &mod.viejoCaracter);

    printf("Ingrese el caracter nuevo: ");
    scanf(" %c", &mod.nuevoCaracter);

    modificacion(&mod);
    printf("Texto modificado: %s\n", mod.texto);
}
int main(int argc, char *argv[]) {
    ejecutarPrograma(); 
    return 0;
}

