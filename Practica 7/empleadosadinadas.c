#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_SEXO 30
#define MAX_PUESTO 30
#define MAX_EMPLEADO 30
#define MAX_CALLE 50
#define MAX_CIUDAD 50
#define MAX_CODIGO_POSTAL 20
#define MAX_FECHA 11
#define VACIO " "

struct Direccion {
    char calle[MAX_CALLE];
    char ciudad[MAX_CIUDAD];
    char codigoPostal[MAX_CODIGO_POSTAL];
};

struct PerfilProfesional {
    float sueldo;
    char puesto[MAX_PUESTO];
    char fechaIngreso[MAX_FECHA];  // Fecha en formato dd/mm/yyyy
};

struct Persona {
    char nombre[MAX_NOMBRE];
    char sexo[MAX_SEXO];
    struct Direccion direccion;  // Estructura anidada horizontal
};

struct Empleado {
    struct Persona persona;  // Estructura anidada vertical
    struct PerfilProfesional perfilProfesional;  // Estructura anidada vertical
};

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void solicitarNombre(char nombre[MAX_NOMBRE], int indice) {
    printf("Nombre[%d]: ", indice);
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = 0;
}

void solicitarSexo(char sexo[MAX_SEXO], int indice) {
    printf("Sexo[%d]: ", indice);
    fgets(sexo, MAX_SEXO, stdin);
    sexo[strcspn(sexo, "\n")] = 0;
}

void solicitarPuesto(char puesto[MAX_PUESTO], int indice) {
    printf("Puesto[%d]: ", indice);
    fgets(puesto, MAX_PUESTO, stdin);
    puesto[strcspn(puesto, "\n")] = 0;
}

void solicitarSueldo(float *sueldo, int indice) {
    printf("Sueldo[%d]: ", indice);
    scanf("%f", sueldo);
    limpiarBuffer();
}

void solicitarDireccion(struct Direccion *direccion) {
    printf("Calle: ");
    fgets(direccion->calle, MAX_CALLE, stdin);
    direccion->calle[strcspn(direccion->calle, "\n")] = 0;

    printf("Ciudad: ");
    fgets(direccion->ciudad, MAX_CIUDAD, stdin);
    direccion->ciudad[strcspn(direccion->ciudad, "\n")] = 0;

    printf("Codigo Postal: ");
    fgets(direccion->codigoPostal, MAX_CODIGO_POSTAL, stdin);
    direccion->codigoPostal[strcspn(direccion->codigoPostal, "\n")] = 0;
}

void actualizarEmpleado(struct Empleado *empleados, int i, const char *nombre, const char *sexo, float sueldo, const char *puesto) {
    if (nombre != NULL && nombre[0] != '\0') {
        strncpy((empleados + i)->persona.nombre, nombre, MAX_NOMBRE - 1);
        (empleados + i)->persona.nombre[MAX_NOMBRE - 1] = '\0';
    }

    if (sexo != NULL && sexo[0] != '\0') {
        strncpy((empleados + i)->persona.sexo, sexo, MAX_SEXO - 1);
        (empleados + i)->persona.sexo[MAX_SEXO - 1] = '\0';
    }

    if (puesto != NULL && puesto[0] != '\0') {
        strncpy((empleados + i)->perfilProfesional.puesto, puesto, MAX_PUESTO - 1);
        (empleados + i)->perfilProfesional.puesto[MAX_PUESTO - 1] = '\0';
    }

    (empleados + i)->perfilProfesional.sueldo = sueldo;
}

void resetearArreglo(struct Empleado *empleados) {
    struct Empleado *empleado; 
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        actualizarEmpleado(empleados, empleado - empleados, VACIO, VACIO, 0.0, VACIO);
        strcpy(empleado->persona.direccion.calle, VACIO);
        strcpy(empleado->persona.direccion.ciudad, VACIO);
        strcpy(empleado->persona.direccion.codigoPostal, VACIO);
    }
}


int buscarEspacioDisponible(struct Empleado *empleados) {
	struct Empleado *empleado;
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (strcmp(empleado->persona.nombre, VACIO) == 0) {
            return empleado - empleados;
        }
    }
    return -1;
}

void rellenarDatosEmpleado(struct Empleado *empleado, int indice) {
    printf("Se tiene un espacio disponible en %d\n", indice);
    solicitarNombre(empleado->persona.nombre, indice);
    solicitarSexo(empleado->persona.sexo, indice);
    solicitarPuesto(empleado->perfilProfesional.puesto, indice);
    solicitarSueldo(&(empleado->perfilProfesional.sueldo), indice);
    solicitarDireccion(&empleado->persona.direccion);
}

void agregarEmpleado(struct Empleado *empleados) {
    int indice = buscarEspacioDisponible(empleados);

    if (indice != -1) {
        rellenarDatosEmpleado(empleados + indice, indice);
    } else {
        printf("No hay espacio disponible para agregar un nuevo empleado.\n");
    }
}

void mostrarInformacion(struct Empleado *empleado, int indice) {
    printf("Nombre[%d]: %s\n", indice, empleado->persona.nombre);
    printf("Sexo[%d]: %s\n", indice, empleado->persona.sexo);
    printf("Calle: %s\n", empleado->persona.direccion.calle);
    printf("Ciudad: %s\n", empleado->persona.direccion.ciudad);
    printf("Codigo Postal: %s\n", empleado->persona.direccion.codigoPostal);
    printf("Puesto[%d]: %s\n", indice, empleado->perfilProfesional.puesto);
    printf("Sueldo[%d]: %.2f\n", indice, empleado->perfilProfesional.sueldo);
    printf("\n");
}

void listarEmpleados(struct Empleado *empleados) {
	struct Empleado *empleado ;
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (strcmp(empleado->persona.nombre, VACIO) != 0) {
            mostrarInformacion(empleado, empleado - empleados);
        }
    }
}

void buscarEmpleado(struct Empleado *empleados, int *i) {
    char nombre[MAX_NOMBRE];
    struct Empleado *empleado;
    *i = -1;

    printf("Ingrese el nombre del empleado a buscar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (strcmp(empleado->persona.nombre, nombre) == 0) {
            *i = empleado - empleados;
            return;
        }
    }
}

void verProgramadores(struct Empleado *empleados) {
	struct Empleado *empleado;
    printf("\nLista de programadores:\n");
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (strcmp(empleado->perfilProfesional.puesto, "Programador") == 0 &&
            strcmp(empleado->persona.nombre, VACIO) != 0) {
            mostrarInformacion(empleado, empleado - empleados);
        }
    }
}

void editarEmpleado(struct Empleado *empleados) {
    int i;
    buscarEmpleado(empleados, &i);

    if (i != -1) {
        printf("------ ACTUALIZACION DE DATOS DEL EMPLEADO -----\n");
        rellenarDatosEmpleado(empleados + i, i);
    } else {
        printf("Empleado no encontrado\n");
    }
}

void borrarEmpleado(struct Empleado *empleados) {
    int i;
    buscarEmpleado(empleados, &i);

    if (i != -1) {
        actualizarEmpleado(empleados, i, VACIO, VACIO, 0.0, VACIO);
    } else {
        printf("Empleado no encontrado\n");
    }
}

void empleadosConMayorSueldo(struct Empleado *empleados, float *mayorSueldo) {
    int primerEmpleado = 1;
    struct Empleado *empleado;
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (strcmp(empleado->persona.nombre, VACIO) != 0) {
            if (primerEmpleado) {
                *mayorSueldo = empleado->perfilProfesional.sueldo;
                primerEmpleado = 0;
            } else if (empleado->perfilProfesional.sueldo > *mayorSueldo) {
                *mayorSueldo = empleado->perfilProfesional.sueldo;
            }
        }
    }

    if (primerEmpleado) {
        *mayorSueldo = -1;
    }
}

void empleadosConMenorSueldo(struct Empleado *empleados, float *menorSueldo) {
    int primerEmpleado = 1;
    struct Empleado *empleado;
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (strcmp(empleado->persona.nombre, VACIO) != 0) {
            if (primerEmpleado) {
                *menorSueldo = empleado->perfilProfesional.sueldo;
                primerEmpleado = 0;
            } else if (empleado->perfilProfesional.sueldo < *menorSueldo) {
                *menorSueldo = empleado->perfilProfesional.sueldo;
            }
        }
    }

    if (primerEmpleado) {
        *menorSueldo = -1;
    }
}

void mostrarEmpleadosConSueldo(struct Empleado *empleados, float sueldo) {
	struct Empleado *empleado;
    for (empleado = empleados; empleado < empleados + MAX_EMPLEADO; empleado++) {
        if (empleado->perfilProfesional.sueldo == sueldo && strcmp(empleado->persona.nombre, VACIO) != 0) {
            mostrarInformacion(empleado, empleado - empleados);
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
    struct Empleado empleados[MAX_EMPLEADO];
    resetearArreglo(empleados);

    int opcion;
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
        limpiarBuffer();
        printf("\n");

        switch (opcion) {
            case 1:
                agregarEmpleado(empleados);
                break;
            case 2:
                listarEmpleados(empleados);
                break;
            case 3: {
                int i;
                buscarEmpleado(empleados, &i);
                if (i != -1) {
                    mostrarInformacion(empleados + i, i);
                } else {
                    printf("Empleado no encontrado\n");
                }
                break;
            }
            case 4:
                editarEmpleado(empleados);
                break;
            case 5:
                borrarEmpleado(empleados);
                break;
            case 6:
                verProgramadores(empleados);
                break;
            case 7:
                imprimirEmpleadosConSueldoExtremos(empleados);
                break;
            case 8:
                printf("Hasta Luego\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 8);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

