#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMP 10
#define MAX_NOMBRE 52
#define MAX_FECHA 12

struct Empleado {
    char *nombre;
    char *fechaNacimiento; // aaaa/mm/dd
};

struct Empleado *asignarMemoria(int max) {
    int n;
    struct Empleado *empleado;
    empleado = (struct Empleado *)malloc(sizeof(struct Empleado) * max);
    if (empleado == NULL) {
        printf("No se pudo asignar la memoria.\n");
        return NULL;
    }
    for (n = 0; n < max; n++) {
        (empleado + n)->nombre = (char *)malloc(sizeof(char) * MAX_NOMBRE);
        (empleado + n)->fechaNacimiento = (char *)malloc(sizeof(char) * MAX_FECHA);
    }
    return empleado;
}

void registrarEmpleado(struct Empleado *empleado, int *contador) {
    if (*contador >= MAX_EMP) {
        printf("No se pueden registrar mas empleados.\n");
        return;
    }
    printf("Empleado %d:\n", *contador + 1);
    printf("Ingrese nombre: ");
    fgets((empleado + *contador)->nombre, MAX_NOMBRE, stdin);
    printf("Ingrese fecha de nacimiento (aaaa/mm/dd): ");
    fgets((empleado + *contador)->fechaNacimiento, MAX_FECHA, stdin);
    (*contador)++;
}

void mostrarEmpleados(struct Empleado *empleado, int contador) {
    int n;
    printf("\nLista de empleados:\n");
    for (n = 0; n < contador; n++) {
        printf("Empleado %d:\n", n + 1);
        printf("Nombre: %s", (empleado + n)->nombre);
        printf("Fecha de nacimiento: %s", (empleado + n)->fechaNacimiento);
        printf("\n");
    }
}

void modificarEmpleado(struct Empleado *empleado, int contador) {
    int indice;
    printf("Ingrese el numero del empleado a modificar (1-%d): ", contador);
    scanf("%d", &indice);
    getchar();
    if (indice < 1 || indice > contador) {
        printf("Numero de empleado no valido.\n");
        return;
    }
    indice--;
    printf("Modificando empleado %d:\n", indice + 1);
    printf("Ingrese nuevo nombre: ");
    fgets((empleado + indice)->nombre, MAX_NOMBRE, stdin);
    printf("Ingrese nueva fecha de nacimiento (aaaa/mm/dd): ");
    fgets((empleado + indice)->fechaNacimiento, MAX_FECHA, stdin);
}

void eliminarEmpleado(struct Empleado *empleado, int *contador) {
    int indice, n;
    printf("Ingrese el numero del empleado a eliminar (1-%d): ", *contador);
    scanf("%d", &indice);
    getchar();
    if (indice < 1 || indice > *contador) {
        printf("Numero de empleado no valido.\n");
        return;
    }
    indice--;

    free((empleado + indice)->nombre);
    free((empleado + indice)->fechaNacimiento);

    for (n = indice; n < *contador - 1; n++) {
        *(empleado + n) = *(empleado + n + 1);
    }

    (*contador)--;

    printf("Empleado eliminado.\n");
}


void liberarMemoria(struct Empleado *empleado, int max) {
    int n;
    for (n = 0; n < max; n++) {
        free((empleado + n)->nombre);
        free((empleado + n)->fechaNacimiento);
    }
    free(empleado);
}

void desplegarMenu(struct Empleado *empleado) {
    int opcion, contador = 0;
    do {
        printf("*****MENU*****\n");
        printf("1. Dar de alta empleado\n");
        printf("2. Dar de baja empleado\n");
        printf("3. Modificar empleado\n");
        printf("4. Mostrar empleados\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                registrarEmpleado(empleado, &contador);
                break;
            case 2:
                eliminarEmpleado(empleado, &contador);
                break;
            case 3:
                modificarEmpleado(empleado, contador);
                break;
            case 4:
                mostrarEmpleados(empleado, contador);
                break;
            case 5:
                printf("Hasta luego.\n");
                break;
            default:
                printf("ERROR: Opcion no valida.\n");
        }
    } while (opcion != 5);
}

int ejecutarPrograma() {
    struct Empleado *ptrEmpleados;
    ptrEmpleados = asignarMemoria(MAX_EMP);
    if (ptrEmpleados == NULL) {
        return 1;
    }
    desplegarMenu(ptrEmpleados);
    liberarMemoria(ptrEmpleados, MAX_EMP);
    return 0;
}

int main(int argc, char *argv[]) {
    return ejecutarPrograma();
}

