#include <stdio.h>

#define MAX_ALUMNOS 10
#define MAX_CALIFICACIONES 10

void iniciarRegistro();
void imprimirResultados(char nombresDeLosAlumnos[MAX_ALUMNOS][100], char boletas[MAX_ALUMNOS][100], 
                        float tareas[MAX_ALUMNOS][MAX_CALIFICACIONES], 
                        float trabajos[MAX_ALUMNOS][MAX_CALIFICACIONES], 
                        float examenes[MAX_ALUMNOS][MAX_CALIFICACIONES], 
                        int contadorDeAlumnos, char nombreDelProfesor[100]);
float calcularPromedio(float calificaciones[MAX_CALIFICACIONES]);

void iniciarRegistro() {
    char nombreDelProfesor[100];
    char nombresDeLosAlumnos[MAX_ALUMNOS][100];
    char boletas[MAX_ALUMNOS][100];
    float tareas[MAX_ALUMNOS][MAX_CALIFICACIONES];
    float trabajos[MAX_ALUMNOS][MAX_CALIFICACIONES];
    float examenes[MAX_ALUMNOS][MAX_CALIFICACIONES];
    int contadorDeAlumnos = 0;
    int continuar;
    int i, j;

    printf("Introducir el nombre del profesor: ");
    scanf("%s", nombreDelProfesor);

    for (i = 0; i < MAX_ALUMNOS; i++) {
        printf("Introducir el nombre del alumno %d: ", i + 1);
        scanf("%s", nombresDeLosAlumnos[i]);

        printf("Introducir el numero de boleta de %s: ", nombresDeLosAlumnos[i]);
        scanf("%s", boletas[i]);

        printf("Introducir las calificaciones de tareas para %s (10 calificaciones):\n", nombresDeLosAlumnos[i]);
        for (j = 0; j < MAX_CALIFICACIONES; j++) {
            printf("Tarea %d: ", j + 1);
            scanf("%f", &tareas[i][j]);
        }

        printf("Introducir las calificaciones de trabajos para %s (10 calificaciones):\n", nombresDeLosAlumnos[i]);
        for (j = 0; j < MAX_CALIFICACIONES; j++) {
            printf("Trabajo %d: ", j + 1);
            scanf("%f", &trabajos[i][j]);
        }

        printf("Introducir las calificaciones de examenes para %s (10 calificaciones):\n", nombresDeLosAlumnos[i]);
        for (j = 0; j < MAX_CALIFICACIONES; j++) {
            printf("Examen %d: ", j + 1);
            scanf("%f", &examenes[i][j]);
        }

        contadorDeAlumnos++;
        printf("¿Continuar con el registro? (1 para continuar, 2 para detener): ");
        scanf("%d", &continuar);
        if (continuar == 2) {
            break;
        }
    }

    imprimirResultados(nombresDeLosAlumnos, boletas, tareas, trabajos, examenes, contadorDeAlumnos, nombreDelProfesor);
}

void imprimirResultados(char nombresDeLosAlumnos[MAX_ALUMNOS][100], char boletas[MAX_ALUMNOS][100], float tareas[MAX_ALUMNOS][MAX_CALIFICACIONES], float trabajos[MAX_ALUMNOS][MAX_CALIFICACIONES], float examenes[MAX_ALUMNOS][MAX_CALIFICACIONES], int contadorDeAlumnos, char nombreDelProfesor[100]) {
    int i, j;
    float promedioTareas, promedioTrabajos, promedioExamenes, promedioTotal;

    printf("Profesor: %s\n", nombreDelProfesor);

    for (i = 0; i < contadorDeAlumnos; i++) {
        promedioTareas = calcularPromedio(tareas[i]);
        promedioTrabajos = calcularPromedio(trabajos[i]);
        promedioExamenes = calcularPromedio(examenes[i]);
        promedioTotal = (promedioTareas + promedioTrabajos + promedioExamenes) / 3;

        printf("Alumno %d: %s\n", i + 1, nombresDeLosAlumnos[i]);
        printf("Boleta: %s\n", boletas[i]);

        printf("Tareas: ");
        for (j = 0; j < MAX_CALIFICACIONES; j++) {
            printf("%.1f", tareas[i][j]);
            if (j < MAX_CALIFICACIONES - 1) {
                printf(", ");
            }
        }
        printf("\nPromedio de Tareas: %.2f\n", promedioTareas);

        printf("Trabajos: ");
        for (j = 0; j < MAX_CALIFICACIONES; j++) {
            printf("%.1f", trabajos[i][j]);
            if (j < MAX_CALIFICACIONES - 1) {
                printf(", ");
            }
        }
        printf("\nPromedio de Trabajos: %.2f\n", promedioTrabajos);

        printf("Examenes: ");
        for (j = 0; j < MAX_CALIFICACIONES; j++) {
            printf("%.1f", examenes[i][j]);
            if (j < MAX_CALIFICACIONES - 1) {
                printf(", ");
            }
        }
        printf("\nPromedio de Examenes: %.2f\n", promedioExamenes);

        printf("Promedio Total: %.2f\n\n", promedioTotal);
    }
}

float calcularPromedio(float calificaciones[MAX_CALIFICACIONES]) {
    float suma = 0.0;
    int k;

    for (k = 0; k < MAX_CALIFICACIONES; k++) {
        suma += calificaciones[k];
    }
    return suma / MAX_CALIFICACIONES;
}

int main(int argc, char *argv[]) {
    iniciarRegistro();
    return 0;
}

