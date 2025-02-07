#include <stdio.h>
#include "operaciones.h"
#include "operaciones.c"

void mostrarMenu() {
    printf("Operaciones Basicas:\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Potencia\n");
    printf("6. Raíz Cuadrada\n");
    printf("7. Salir\n");
}

void solicitarNumeros(struct Operaciones *op) {
    printf("Ingrese el primer numero: ");
    scanf("%f", &op->num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &op->num2);
}

void ejecutarPrograma() {
    struct Operaciones op;
    int opcion;

    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                solicitarNumeros(&op);
                op.resultado = sumar(&op);
                printf("Resultado: %.2f\n", op.resultado);
                break;
            case 2:
                solicitarNumeros(&op);
                op.resultado = restar(&op);
                printf("Resultado: %.2f\n", op.resultado);
                break;
            case 3:
                solicitarNumeros(&op);
                op.resultado = multiplicar(&op);
                printf("Resultado: %.2f\n", op.resultado);
                break;
            case 4:
                solicitarNumeros(&op);
                op.resultado = dividir(&op);
                if (op.num2 != 0) {
                    printf("Resultado: %.2f\n", op.resultado);
                }
                break;
            case 5:
                printf("Ingrese el numero base: ");
                scanf("%f", &op.num1);
                printf("Ingrese el exponente: ");
                scanf("%d", &op.exponente);
                op.resultado = potencia(&op);
                printf("Resultado: %.2f\n", op.resultado);
                break;
            case 6:
                printf("Ingrese el numero: ");
                scanf("%f", &op.num1);
                op.resultado = raizCuadrada(&op);
                if (op.resultado != -1) {
                    printf("Resultado: %.2f\n", op.resultado);
                }
                break;
            case 7:
                printf("Salir......\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 7);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

