#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_SEXO 30
#define MAX_PUESTO 30
#define MAX_EMPLEADO 30
#define VACIO " "

struct Empleado {
    char nombre[MAX_NOMBRE];
    char sexo[MAX_SEXO];
    char puesto[MAX_PUESTO];
    float sueldo;
};

void solicitarNombre(char *nombre, int indice) {
    printf("Nombre[%d]: ", indice);
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = 0;
}

void solicitarSexo(char *sexo, int indice) {
    printf("Sexo[%d]: ", indice);
    fgets(sexo, MAX_SEXO, stdin);
    sexo[strcspn(sexo, "\n")] = 0;
}

void solicitarPuesto(char *puesto, int indice) {
    printf("Puesto[%d]: ", indice);
    fgets(puesto, MAX_PUESTO, stdin);
    puesto[strcspn(puesto, "\n")] = 0;
}

void solicitarSueldo(float *sueldo, int indice) {
    printf("Sueldo[%d]: ", indice);
    scanf("%f", sueldo);
    while (getchar() != '\n');
}

int verificarEmpleado(struct Empleado *empleados, int i) {
    if (i == -1) {
        printf("Empleado no existe\n");
        return 0;  // 0 no existe empleado
    }
    return 1;  // 1 si el empleado existe
}

void actualizarEmpleado(struct Empleado *empleados, int i, const char *nombre, const char *sexo, float sueldo, const char *puesto) {
    if (nombre != NULL && nombre[0] != '\0') {
        strncpy((empleados + i)->nombre, nombre, MAX_NOMBRE - 1);
        (empleados + i)->nombre[MAX_NOMBRE - 1] = '\0';
    }

    if (sexo != NULL && sexo[0] != '\0') {
        strncpy((empleados + i)->sexo, sexo, MAX_SEXO - 1);
        (empleados + i)->sexo[MAX_SEXO - 1] = '\0';
    }

    if (puesto != NULL && puesto[0] != '\0') {
        strncpy((empleados + i)->puesto, puesto, MAX_PUESTO - 1);
        (empleados + i)->puesto[MAX_PUESTO - 1] = '\0';
    }

    (empleados + i)->sueldo = sueldo;
}

void resetearArreglo(struct Empleado empleados[MAX_EMPLEADO]) {
    struct Empleado *emp = empleados;
    int i;
    for (i = 0; i < MAX_EMPLEADO; i++) {
        actualizarEmpleado(empleados, i, VACIO, VACIO, 0.0, VACIO);
        emp++;
    }
}

int buscarEspacioDisponible(struct Empleado *empleados) {
    int i;
    for (i = 0; i < MAX_EMPLEADO; i++) {
        if (strcmp((empleados + i)->nombre, VACIO) == 0) {
            return i;  
        }
    }
    return -1;  // Si no encuentra espacio, retorna -1
}

void rellenarDatosEmpleado(struct Empleado *empleado, int indice) {
    printf("Se tiene un espacio disponible en %d\n", indice);
    solicitarNombre(empleado->nombre, indice);
    solicitarSexo(empleado->sexo, indice);
    solicitarPuesto(empleado->puesto, indice);
    solicitarSueldo(&(empleado->sueldo), indice);
}

void agregarEmpleado(struct Empleado empleados[MAX_EMPLEADO]) {
    int indice = buscarEspacioDisponible(empleados);

    if (indice != -1) {
        rellenarDatosEmpleado(empleados + indice, indice);
    } else {
        printf("No hay espacio disponible para agregar un nuevo empleado.\n");
    }
}

void mostrarInformacion(struct Empleado empleado, int indice) {
    printf("Nombre[%d]: %s\n", indice, empleado.nombre);
    printf("Sexo[%d]: %s\n", indice, empleado.sexo);
    printf("Puesto[%d]: %s\n", indice, empleado.puesto);
    printf("Sueldo[%d]: %.2f\n", indice, empleado.sueldo);
    printf("\n");
}

void listarEmpleados(struct Empleado empleados[MAX_EMPLEADO]) {
    struct Empleado *emp = empleados;
    int i;
    for (i = 0; i < MAX_EMPLEADO; i++) {
        if (strcmp((emp + i)->nombre, VACIO) != 0) {
            mostrarInformacion(*(emp + i), i);
        }
    }
}

void buscarEmpleado(struct Empleado empleados[MAX_EMPLEADO], int *i) {
    char nombre[MAX_NOMBRE];
    struct Empleado *emp = empleados;
    *i = -1;
    int j;

    printf("Ingrese el nombre del empleado a buscar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (j = 0; j < MAX_EMPLEADO; j++) {
        if (strcmp((emp + j)->nombre, nombre) == 0) {
            *i = j;
            break;
        }
    }
}

void editarEmpleado(struct Empleado empleados[MAX_EMPLEADO]) {
    int i;
    char nombre[MAX_NOMBRE], sexo[MAX_SEXO], puesto[MAX_PUESTO];
    float sueldo;

    buscarEmpleado(empleados, &i);

    if (verificarEmpleado(empleados, i)) {  // Verificamos si existe el empleado
        printf("------ ACTUALIZACION DE DATOS DEL EMPLEADO -----\n");
        solicitarNombre(nombre, i);
        solicitarSexo(sexo, i);
        solicitarPuesto(puesto, i);
        solicitarSueldo(&sueldo, i);
        actualizarEmpleado(empleados, i, nombre, sexo, sueldo, puesto);  // Actualizamos los datos
    } else {
        printf("Empleado no encontrado\n");
    }
}

void borrarEmpleado(struct Empleado empleados[MAX_EMPLEADO]) {
    int i;
    buscarEmpleado(empleados, &i);

    if (i != -1) {
        actualizarEmpleado(empleados, i, VACIO, VACIO, 0.0, VACIO);
    } else {
        printf("Empleado no encontrado\n");
    }
}

void verProgramadores(struct Empleado empleados[MAX_EMPLEADO]) {
    struct Empleado *emp = empleados;
    int i;
    printf("\nLista de programadores:\n");
    for (i = 0; i < MAX_EMPLEADO; i++) {
        if (strcmp((emp + i)->puesto, "Programador") == 0 && strcmp((emp + i)->nombre, VACIO) != 0) {
            mostrarInformacion(*(emp + i), i);
        }
    }
}

void empleadosConMayorSueldo(struct Empleado *empleados, float *mayorSueldo) {
    struct Empleado *emp = empleados;
    int primerEmpleado = 1;
    int i;
    for (i = 0; i < MAX_EMPLEADO; i++) {
        if (strcmp((emp + i)->nombre, VACIO) != 0) {
            if (primerEmpleado) {
                *mayorSueldo = (emp + i)->sueldo;
                primerEmpleado = 0;
            } else if ((emp + i)->sueldo > *mayorSueldo) {
                *mayorSueldo = (emp + i)->sueldo;
            }
        }
    }

    if (primerEmpleado) {
        *mayorSueldo = -1;  
    }
}

void empleadosConMenorSueldo(struct Empleado *empleados, float *menorSueldo) {
    struct Empleado *emp = empleados;
    int primerEmpleado = 1;
    int i;
    for (i = 0; i < MAX_EMPLEADO; i++) {
        if (strcmp((emp + i)->nombre, VACIO) != 0) {
            if (primerEmpleado) {
                *menorSueldo = (emp + i)->sueldo;
                primerEmpleado = 0;
            } else if ((emp + i)->sueldo < *menorSueldo) {
                *menorSueldo = (emp + i)->sueldo;
            }
        }
    }

    if (primerEmpleado) {
        *menorSueldo = -1; 
    }
}

void mostrarEmpleadosConSueldo(struct Empleado *empleados, float sueldo) {
    int i;
    for (i = 0; i < MAX_EMPLEADO; i++) {
        if (strcmp((empleados + i)->nombre, VACIO) != 0 && (empleados + i)->sueldo == sueldo) {
            mostrarInformacion(*(empleados + i), i);
        }
    }
}

void imprimirEmpleadosConSueldoExtremos(struct Empleado *empleados) {
    float mayorSueldo, menorSueldo;

    empleadosConMayorSueldo(empleados, &mayorSueldo);
    empleadosConMenorSueldo(empleados, &menorSueldo);

    if (mayorSueldo == -1 || menorSueldo == -1) {
        printf("No hay empleados registrados.\n");
        return;
    }

    printf("\nEmpleado(s) con mayor sueldo (%.2f):\n", mayorSueldo);
    mostrarEmpleadosConSueldo(empleados, mayorSueldo);

    printf("\nEmpleado(s) con menor sueldo (%.2f):\n", menorSueldo);
    mostrarEmpleadosConSueldo(empleados, menorSueldo);
}

void ejecutarPrograma() {
    struct Empleado arreglo[MAX_EMPLEADO];
    struct Empleado *ptrArreglo = arreglo;
    int i, opcion;
    resetearArreglo(ptrArreglo);
    do {
        printf("****MENU****\n");
        printf("1. Agregar Empleado\n");
        printf("2. Mostrar Empleados\n");
        printf("3. Buscar Empleado\n");
        printf("4. Modificar Empleado\n");
        printf("5. Eliminar Empleado\n");
        printf("6. Ver Programadores\n");
        printf("7. Ver Empleados con Mayor y Menor Sueldo\n");
        printf("8. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n');
        printf("\n");
        switch (opcion) {
            case 1:
                agregarEmpleado(ptrArreglo);
                break;
            case 2:
                listarEmpleados(ptrArreglo);
                break;
            case 3:
                buscarEmpleado(ptrArreglo, &i);
                if (i != -1) {
                    mostrarInformacion(*(ptrArreglo + i), i);
                }
                break;
            case 4:
                editarEmpleado(ptrArreglo);
                break;
            case 5:
                borrarEmpleado(ptrArreglo);
                break;
            case 6:
                verProgramadores(ptrArreglo);
                break;
            case 7:
                imprimirEmpleadosConSueldoExtremos(ptrArreglo);
                break;
            case 8:
                printf("Hasta Luego\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 8);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

