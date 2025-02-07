#include <stdio.h>
#include <string.h>

#define MIN_TEXTO 3500
#define MAX_TEXTO 4500

char *cargarTexto(int *tamanoTexto) {
    static char texto[MAX_TEXTO];
    int longitud;
    do {
        printf("Ingrese un texto (minimo %d caracteres):\n", MIN_TEXTO);
        fgets(texto, MAX_TEXTO, stdin);

        longitud = strlen(texto);
        if (texto[longitud - 1] == '\n') {
            texto[longitud - 1] = '\0';
            longitud--; 
        }

        if (longitud < MIN_TEXTO) {
            printf("El texto es demasiado corto. Debe tener al menos %d caracteres.\n", MIN_TEXTO);
        } else if (longitud > MAX_TEXTO) {
            printf("El texto es demasiado largo. No debe exceder los %d caracteres.\n", MAX_TEXTO);
        }
    } while (longitud < MIN_TEXTO || longitud > MAX_TEXTO);

    return texto;
}

char *modificar(char *ptrTexto, int longitudTexto, char nuevoCaracter, char viejoCaracter) { 
    int i = 0;
    while (i < longitudTexto) {
        if (*(ptrTexto + i) == viejoCaracter) {
            *(ptrTexto + i) = nuevoCaracter;
        }
        i++;
    }
    return ptrTexto;
}

void contarTexto(char *ptrTexto, int longitudTexto, char caracterContar, int *cuantos) {
    int i = 0;
    while (i < longitudTexto) {
        if (*(ptrTexto + i) == caracterContar) {
            (*cuantos)++;
        }
        i++;
    }
}

char *buscar(char *ptrTexto, int longitudTexto) { 
    char caracterBuscar;
    int i = 0;
    printf("Ingrese el caracter a buscar: ");
    scanf(" %c", &caracterBuscar);

    while (i < longitudTexto) {
        if (*(ptrTexto + i) == caracterBuscar) {
            return (ptrTexto + i);
        }
        i++;
    }
    return NULL;
}

void mostrarMenu() {
    printf("\n****** MENU ******\n");
    printf("1. Modificar\n");
    printf("2. Contar\n");
    printf("3. Buscar\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
}

void procesarOpcion(int opcion, char *ptrTexto, int longitudTexto) {
    char *ptrBuscado, caracterBuscado, nuevoCaracter;
    int cuantos = 0;

    switch (opcion) {
        case 1:
            printf("Ingrese caracter nuevo: ");
            scanf(" %c", &nuevoCaracter);
            ptrBuscado = buscar(ptrTexto, longitudTexto);

            if (ptrBuscado == NULL) {
                printf("El caracter no existe\n");
            } else {
                caracterBuscado = *ptrBuscado;
                contarTexto(ptrTexto, longitudTexto, caracterBuscado, &cuantos);
                modificar(ptrTexto, longitudTexto, nuevoCaracter, caracterBuscado);
                printf("Texto modificado:\n%s\n", ptrTexto);
                printf("El caracter '%c' se modifico %d veces\n", caracterBuscado, cuantos);
            }
            break;

        case 2:
            printf("Ingrese caracter a contar: ");
            scanf(" %c", &caracterBuscado);
            contarTexto(ptrTexto, longitudTexto, caracterBuscado, &cuantos);
            printf("El caracter '%c' se encontro %d veces\n", caracterBuscado, cuantos);
            break;

        case 3:
            ptrBuscado = buscar(ptrTexto, longitudTexto);
            if (ptrBuscado == NULL) {
                printf("El caracter no existe\n");
            } else {
                printf("El caracter se encontro en la direccion %ld\nTexto a partir de la posicion: %s\n", (long)ptrBuscado, ptrBuscado);
            }
            break;

        case 4:
            printf("Hasta luego\n");
            break;

        default:
            printf("ERROR: Opcion invalida, intente de nuevo.\n");
    }
}

void ejecutarPrograma() {
    int opcion, longitudTexto = MAX_TEXTO;
    char *ptrTexto;
    ptrTexto = cargarTexto(&longitudTexto);
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        while (getchar() != '\n'); 
        procesarOpcion(opcion, ptrTexto, longitudTexto);
    } while (opcion != 4);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

