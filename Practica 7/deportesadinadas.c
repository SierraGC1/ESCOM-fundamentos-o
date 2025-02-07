#include <stdio.h>
#include <string.h>

#define MAX_ATLETAS 20
#define MAX_NOMBRE 60
#define MAX_PAIS 36
#define MAX_DEPORTE 30
#define MAX_ENTRENADOR 60
#define MAX_ESTADIO 100

struct Persona {
    char nombre[MAX_NOMBRE];
    char pais[MAX_PAIS];
};

struct Entrenador {
    char nombre[MAX_ENTRENADOR];
    int experiencia;
};

struct Estadio {
    char nombre[MAX_ESTADIO];
    int capacidad;
};

struct Atleta {
    char deporte[MAX_DEPORTE];
    struct Persona persona;         //Estructura anidada vertical
    int numeroMedallas;
    struct Entrenador entrenador;  // Estructura anidada horizontal
    struct Estadio estadio;        // Estructura anidada horizontal
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

void solicitarEntrenador(char *nombre, int *experiencia) {
    printf("Entrenador: ");
    fgets(nombre, MAX_ENTRENADOR, stdin);
    quitarEnter(nombre);
    printf("Years de experiencia: ");
    scanf("%d", experiencia);
    while (getchar() != '\n');
}

void solicitarEstadio(char *nombre, int *capacidad) {
    printf("Nombre del Estadio: ");
    fgets(nombre, MAX_ESTADIO, stdin);
    quitarEnter(nombre);
    printf("Capacidad: ");
    scanf("%d", capacidad);
    while (getchar() != '\n');
}

void asignarDatosAtleta(struct Atleta *ptrAtletas, int indice, char *nombre, char *pais, char *deporte, int medallas, char *entrenador, int experiencia, char *estadio, int capacidad) {
    if (indice != -1) {
        strcpy((ptrAtletas + indice)->persona.nombre, nombre);
        strcpy((ptrAtletas + indice)->persona.pais, pais);
        strcpy((ptrAtletas + indice)->deporte, deporte);
        (ptrAtletas + indice)->numeroMedallas = medallas;
        strcpy((ptrAtletas + indice)->entrenador.nombre, entrenador);
        (ptrAtletas + indice)->entrenador.experiencia = experiencia;
        strcpy((ptrAtletas + indice)->estadio.nombre, estadio);
        (ptrAtletas + indice)->estadio.capacidad = capacidad;
    } else {
        printf("El atleta '%s' no existe.\n", nombre);
    }
}

void mostrarDatos(struct Atleta atleta) {
    printf("\nNombre: %s\n", atleta.persona.nombre);
    printf("Pais: %s\n", atleta.persona.pais);
    printf("Deporte: %s\n", atleta.deporte);
    printf("Medallas: %d\n", atleta.numeroMedallas);
    printf("Entrenador: %s\n", atleta.entrenador.nombre);
    printf("Anos de experiencia del entrenador: %d\n", atleta.entrenador.experiencia);
    printf("Estadio: %s\n", atleta.estadio.nombre);
    printf("Capacidad del estadio: %d\n", atleta.estadio.capacidad);
}

void agregarAtleta(struct Atleta *ptrAtletas) {
    char nombre[MAX_NOMBRE], pais[MAX_PAIS], deporte[MAX_DEPORTE], entrenador[MAX_ENTRENADOR], estadio[MAX_ESTADIO];
    int medallas, experiencia, capacidad;
    int indice;
    struct Atleta *atleta = ptrAtletas;
    
    for (atleta = ptrAtletas; atleta < ptrAtletas + MAX_ATLETAS; atleta++) {
        if (strcmp(atleta->persona.nombre, "") == 0) {
            indice = atleta - ptrAtletas; 
            printf("Espacio disponible en %d\n", indice);
            solicitarNombre(nombre, indice);
            solicitarPais(pais, indice);
            solicitarDeporte(deporte, indice);
            solicitarMedallas(&medallas, indice);
            solicitarEntrenador(entrenador, &experiencia);
            solicitarEstadio(estadio, &capacidad);
            asignarDatosAtleta(ptrAtletas, indice, nombre, pais, deporte, medallas, entrenador, experiencia, estadio, capacidad);
            break;
        }
    }
}

void mostrarAtletas(struct Atleta *ptrAtletas) {
    struct Atleta *atleta = ptrAtletas;
    
    for (atleta = ptrAtletas; atleta < ptrAtletas + MAX_ATLETAS; atleta++) {
        if (strcmp(atleta->persona.nombre, "") != 0) {
            mostrarDatos(*atleta);
        }
    }
}

void inicializarAtletas(struct Atleta *ptrAtletas) {
    struct Atleta *atleta = ptrAtletas;
    
    for (atleta = ptrAtletas; atleta < ptrAtletas + MAX_ATLETAS; atleta++) {
        strcpy(atleta->persona.nombre, "");
        strcpy(atleta->persona.pais, "");
        strcpy(atleta->deporte, "");
        atleta->numeroMedallas = 0;
        strcpy(atleta->entrenador.nombre, "");
        atleta->entrenador.experiencia = 0;
        strcpy(atleta->estadio.nombre, "");
        atleta->estadio.capacidad = 0;
    }
}

int buscarAtleta(struct Atleta *ptrAtletas, char *nombre) {
    struct Atleta *atleta = ptrAtletas;
    for (atleta = ptrAtletas; atleta < ptrAtletas + MAX_ATLETAS; atleta++) {
        if (strcmp(atleta->persona.nombre, nombre) == 0) {
            return atleta - ptrAtletas; 
        }
    }
    return -1;
}

void actualizarAtleta(struct Atleta *ptrAtletas) {
    char nombre[MAX_NOMBRE];
    int indice;
    printf("Introduce el nombre del atleta a modificar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    quitarEnter(nombre);

    indice = buscarAtleta(ptrAtletas, nombre);
    if (indice != -1) {
        char pais[MAX_PAIS], deporte[MAX_DEPORTE], entrenador[MAX_ENTRENADOR], estadio[MAX_ESTADIO];
        int medallas, experiencia, capacidad;
        solicitarPais(pais, indice);
        solicitarDeporte(deporte, indice);
        solicitarMedallas(&medallas, indice);
        solicitarEntrenador(entrenador, &experiencia);
        solicitarEstadio(estadio, &capacidad);
        asignarDatosAtleta(ptrAtletas, indice, nombre, pais, deporte, medallas, entrenador, experiencia, estadio, capacidad);
    } else {
        printf("El atleta '%s' no existe.\n", nombre);
    }
}

void mostrarMejorAtleta(struct Atleta *ptrAtletas) {
    struct Atleta *atleta = ptrAtletas;
    int mejorIndice = -1;
    int maxMedallas = -1;
    for (atleta = ptrAtletas; atleta < ptrAtletas + MAX_ATLETAS; atleta++) {
        if (atleta->numeroMedallas > maxMedallas) {
            maxMedallas = atleta->numeroMedallas;
            mejorIndice = atleta - ptrAtletas;
        }
    }
    if (mejorIndice != -1) {
        printf("\nEl mejor atleta es:\n");
        mostrarDatos(ptrAtletas[mejorIndice]);
    } else {
        printf("No hay atletas registrados.\n");
    }
}

void ejectarPrograma() {
    int opcion;
    char nombre[MAX_NOMBRE];
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
                {
                    printf("Introduce el nombre del atleta a buscar: ");
                    fgets(nombre, MAX_NOMBRE, stdin);
                    quitarEnter(nombre);
                    int indice = buscarAtleta(ptrAtletas, nombre);
                    if (indice != -1) {
                        mostrarDatos(ptrAtletas[indice]);
                    } else {
                        printf("El atleta '%s' no existe.\n", nombre);
                    }
                }
                break;
            case 4:
                actualizarAtleta(ptrAtletas);
                break;
            case 5:
                mostrarMejorAtleta(ptrAtletas);
                break;
            case 6:
                printf("Adi�s.\n");
                break;
            default:
                printf("Opci�n inv�lida. Intenta de nuevo.\n");
        }
    } while (opcion != 6);
}

int main(int argc, char *argv[]) {
    ejectarPrograma();
    return 0;
}

