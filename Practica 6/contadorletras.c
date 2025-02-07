#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quitarEnter(char cadena[]) {
    int longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
}

char *cargar(void) {
    static char texto[1000];
    printf("Ingrese el texto (maximo 1000 caracteres):\n");
    fgets(texto, sizeof(texto), stdin);  
    quitarEnter(texto); 
    return texto;
}

void esVocal(char ca, int *ptrEsVocal) {
    if (ca >= 'A' && ca <= 'Z') {
        ca = ca + ('a' - 'A');  
    }
    *ptrEsVocal = (ca == 'a' || ca == 'e' || ca == 'i' || ca == 'o' || ca == 'u');
}

int esConsonante(char ca) {
    if (ca >= 'A' && ca <= 'Z') {
        ca = ca + ('a' - 'A');  
    }
    if (ca >= 'a' && ca <= 'z') {
        return !(ca == 'a' || ca == 'e' || ca == 'i' || ca == 'o' || ca == 'u');
    }
    return 0;  
}

void contarVocales(char *ptrtexto) {
    int contador = 0;
    char *ptr = ptrtexto;
    int siVocal;

    while (*ptr != '\0') {
        esVocal(*ptr, &siVocal); 
        if (siVocal) {
            contador++;
        }
        ptr++;
    }

    printf("\nNumero de vocales: %d\n", contador);
}

void contarConsonantes(char *ptrtexto) {
    int contador = 0;
    char *ptr = ptrtexto;

    while (*ptr != '\0') {
        if (esConsonante(*ptr)) {
            contador++;
        }
        ptr++;
    }

    printf("\nNumero de consonantes: %d\n", contador);
}

void desplegarMenu(void) {
    printf("\n\t***** MENU *****\n");
    printf("1. Contar vocales\n");
    printf("2. Contar consonantes\n");
    printf("3. Ingresar nuevo texto\n");
    printf("4. Salir\n\n");
    printf("Selecciona una opcion: ");
}

void ejecutarPrograma(void) {
    char *texto = cargar();
    int opcion;

    do {
        desplegarMenu();
        scanf("%d", &opcion);
        while (getchar() != '\n');  

        switch (opcion) {
            case 1:
                contarVocales(texto);
                break;
            case 2:
                contarConsonantes(texto);
                break;
            case 3:
                texto = cargar();
                break;
            case 4:
                printf("Hasta luego\n");
                break;
            default:
                printf("ERROR:Opcion invalida, intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

