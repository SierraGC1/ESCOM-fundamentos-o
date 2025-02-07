#include <stdio.h>
#include <math.h>

#define VIENTO 8
#define TEMPERATURA 17

float calcularSensacionTermica(float velocidad, float temperatura) {
    return 13.12 + 0.6215 * temperatura - 11.37 * pow(velocidad, 0.16) + 0.3965 * pow(velocidad, 0.16) * temperatura;
}

void crearTabla(float tabla[VIENTO][TEMPERATURA]) {
    int i, j;
    float velocidad, temperatura;
    for (i = 0; i < VIENTO; i++) {
        velocidad = 8.0f + i * 8.0f;
        for (j = 0; j < TEMPERATURA; j++) {
            temperatura = 10.0f - j * 2.5f;
            tabla[i][j] = calcularSensacionTermica(velocidad, temperatura);
        }
    }
}

void desplegarTabla(float tabla[VIENTO][TEMPERATURA]) {
    int i, j;
    printf("Tabla de sensacion termica y enfriamiento por viento:\n\n");
    printf("   Vel/ Temp |");
    for (j = 0; j < TEMPERATURA; j++) {
        printf("%6.2f ", 10.0f - j * 2.5f);
    }
    printf("\n-------------|");
    for (j = 0; j < TEMPERATURA; j++) {
        printf("--------");
    }
    printf("\n");
    for (i = 0; i < VIENTO; i++) {
        printf("%8.1f km/h |", 8.0f + i * 8.0f);
        for (j = 0; j < TEMPERATURA; j++) {
            printf("%6.1f ", tabla[i][j]);
        }
        printf("\n");
    }
    printf("\t      | Riesgos de enfriamiento Moderado                | Riesgos de enfriamiento Grave           | Riesgos de enfriamiento Extremo \n");
}

void determinarRiesgo(float temperatura) {
    if (temperatura >= -5) {
        printf("\nRiesgo de enfriamiento: Moderado\n");
    } else if (temperatura >= -20) {
        printf("\nRiesgo de enfriamiento: Grave\n");
    } else {
        printf("\nRiesgo de enfriamiento: Extremo\n");
    }
}

void buscarTabla(float tabla[VIENTO][TEMPERATURA], float velocidad, float temperatura) {
    int fila, columna;
    fila = (int)((velocidad - 8.0f) / 8.0f);
    columna = (int)((10.0f - temperatura) / 2.5f);

    if (fila < 0 || fila >= VIENTO || columna < 0 || columna >= TEMPERATURA) {
        printf("Sensacion termica no encontrada en la tabla.\n");
        printf("Sensacion termica calculada: %.1f grados C\n", calcularSensacionTermica(velocidad, temperatura));
    } else {
        printf("Consulta en fila: %d, columna: %d\n", fila, columna);
        printf("La sensacion termica es: %.1f grados C\n", tabla[fila][columna]);
    }
    determinarRiesgo(temperatura);
}

void consultarTabla(float tabla[VIENTO][TEMPERATURA]) {
    float velocidad, temperatura;
    desplegarTabla(tabla);
    printf("\nConsulta a la tabla\n");
    printf("Ingrese la temperatura (grados Celsius): ");
    scanf("%f", &temperatura);
    printf("Ingrese la velocidad (km/h): ");
    scanf("%f", &velocidad);
    buscarTabla(tabla, velocidad, temperatura);
}

int desplegarMenu() {
    int opcion;
    printf("\t**** MENU ****\n");
    printf("1.- Mostrar la tabla\n");
    printf("2.- Consultar tabla\n");
    printf("3.- Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void ejecutarPrograma() {
    float tabla[VIENTO][TEMPERATURA];
    crearTabla(tabla);
    int opcion;
    do {
        opcion = desplegarMenu();
        switch (opcion) {
            case 1:
                desplegarTabla(tabla);
                break;
            case 2:
                consultarTabla(tabla);
                break;
            case 3:
                printf("Hasta luego\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 3);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

