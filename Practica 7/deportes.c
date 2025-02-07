#include <stdio.h>
#include <string.h>

#define MAX_ATLETAS 20
#define MAX_NOMBRE 60
#define MAX_PAIS 36
#define MAX_DEPORTE 30

struct Informacion {
    char nombre[MAX_NOMBRE];
    char pais[MAX_PAIS];
};

struct Atleta {
    char deporte[MAX_DEPORTE];
    struct Informacion personal;
    int numeroMedallas;
};

void quitarEnter(char cadena[]) {
    int longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
}

void solicitarNombre(char *nombre, int indice) {
    printf("\nNombre[%d]: ", indice);
    fgets(nombre, MAX_NOMBRE, stdin);
    quitarEnter(nombre);
}

void solicitarPais(char *pais, int indice) {
    printf("Pais[%d]: ", indice);
    fgets(pais, MAX_PAIS, stdin);
    quitarEnter(pais);
}

void solicitarDeporte(char *deporte, int indice) {
    printf("Deporte[%d]: ", indice);
    fgets(deporte, MAX_DEPORTE, stdin);
    quitarEnter(deporte);
}

void solicitarMedallas(int *medallas, int indice) {
    printf("Medallas[%d]: ", indice);
    scanf("%d", medallas);
    while (getchar() != '\n');
}

void buscarAtleta(struct Atleta *ptrAtletas, int *posicion) {
    int i;
    char nombre[MAX_NOMBRE];
    *posicion = -1;
    printf("Ingrese el nombre del atleta a buscar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    quitarEnter(nombre);

    for (i = 0; i < MAX_ATLETAS; i++) {
        if (strcmp((ptrAtletas + i)->personal.nombre, nombre) == 0) {
            *posicion = i;
            break;
        }
    }
}


void asignarDatosAtleta(struct Atleta *ptrAtletas, int indice, char *nombre, char *pais, char *deporte, int medallas) {
    if (indice != -1) {
        strcpy((ptrAtletas + indice)->personal.nombre, nombre);
        strcpy((ptrAtletas + indice)->personal.pais, pais);
        strcpy((ptrAtletas + indice)->deporte, deporte);
        (ptrAtletas + indice)->numeroMedallas = medallas;
    } else {
        printf("El atleta '%s' no existe.\n", nombre);
    }
}

void actualizarAtleta(struct Atleta *ptrAtletas) {
    char nombre[MAX_NOMBRE], pais[MAX_PAIS], deporte[MAX_DEPORTE];
    int posicionAtleta, medallas;

    buscarAtleta(ptrAtletas, &posicionAtleta);

    if (posicionAtleta != -1) {
        printf("------ INGRESA LOS NUEVOS DATOS ------\n");

        solicitarNombre(nombre, posicionAtleta);
        solicitarPais(pais, posicionAtleta);
        solicitarDeporte(deporte, posicionAtleta);
        solicitarMedallas(&medallas, posicionAtleta);

        asignarDatosAtleta(ptrAtletas, posicionAtleta, nombre, pais, deporte, medallas);
    } else {
        printf("El atleta no existe.\n");
    }
}

void mostrarDatos(struct Atleta *atleta) {
    printf("\nNombre: %s\n", atleta->personal.nombre);
    printf("Pais: %s\n", atleta->personal.pais);
    printf("Deporte: %s\n", atleta->deporte);
    printf("Medallas: %d\n", atleta->numeroMedallas);
}

void mostrarAtletas(struct Atleta *ptrAtletas) {
    struct Atleta *atleta = ptrAtletas;
    int i;
    for (i = 0; i < MAX_ATLETAS; i++) {
        if (strcmp(atleta->personal.nombre, "") != 0) {
            mostrarDatos(atleta);
        }
        atleta++;
    }
}

void inicializarAtletas(struct Atleta *ptrAtletas) {
    struct Atleta *atleta = ptrAtletas;
    int i;
    for (i = 0; i < MAX_ATLETAS; i++) {
        strcpy(atleta->personal.nombre, ""); 
        strcpy(atleta->personal.pais, "");
        strcpy(atleta->deporte, "");
        atleta->numeroMedallas = 0;
        atleta++; // Aritmética de puntero
    }
}

void agregarAtleta(struct Atleta *ptrAtletas) {
    char nombre[MAX_NOMBRE], pais[MAX_PAIS], deporte[MAX_DEPORTE];
    struct Atleta *atleta = ptrAtletas;
    int i, medallas;
    for (i = 0; i < MAX_ATLETAS; i++) {
        if (strcmp(atleta->personal.nombre, "") == 0) {
            printf("Espacio disponible en %d\n", i);
            solicitarNombre(nombre, i);
            solicitarPais(pais, i);
            solicitarDeporte(deporte, i);
            solicitarMedallas(&medallas, i);
            asignarDatosAtleta(ptrAtletas, i, nombre, pais, deporte, medallas);
            break;
        }
        atleta++;
    }
}

void mostrarAtletasConMedallas(struct Atleta *ptrAtletas, int medallas) {
    struct Atleta *atleta = ptrAtletas;
    int i;
    for (i = 0; i < MAX_ATLETAS; i++) {
        if (atleta->numeroMedallas == medallas && strcmp(atleta->personal.nombre, "") != 0) {
            mostrarDatos(atleta);
        }
        atleta++; 
    }
}

void mostrarMejorAtleta(struct Atleta *ptrAtletas) {
    struct Atleta *atleta = ptrAtletas;
    int i, medallas = 0;
    for (i = 0; i < MAX_ATLETAS; i++) {
        if (strcmp(atleta->personal.nombre, "") != 0) {
            if (atleta->numeroMedallas > medallas) {
                medallas = atleta->numeroMedallas;
            }
        }
        atleta++; 
    }
    printf("\n-----ATLETA CON MAS MEDALLAS------\n");
    mostrarAtletasConMedallas(ptrAtletas, medallas);
}

void ejectarPrograma() {
    int opcion;
    struct Atleta atletas[MAX_ATLETAS], *ptrAtletas;
    ptrAtletas = atletas;
    inicializarAtletas(ptrAtletas);
    do {
        printf("\t*****MENU*****\n");
        printf("1. Agregar atleta\n");
        printf("2. Mostrar Atletas\n");
        printf("3. Buscar Atleta\n");
        printf("4. Modificar Atleta\n");
        printf("5. Mejor Atleta\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n');
        switch (opcion) {
            case 1:
                agregarAtleta(ptrAtletas);
                break;
            case 2:
                mostrarAtletas(ptrAtletas);
                break;
            case 3:
                buscarAtleta(ptrAtletas, &opcion);
                if (opcion != -1) {
                    mostrarDatos(ptrAtletas + opcion);
                } else {
                    printf("El atleta no existe.\n");
                }
                break;
            case 4:
                actualizarAtleta(ptrAtletas);
                break;
            case 5:
                mostrarMejorAtleta(ptrAtletas);
                break;
        }
    } while (opcion != 6);
}

int main(int argc, char *argv[]) {
    ejectarPrograma();
    return 0;
}

