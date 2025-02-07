#include <stdio.h>
#include <math.h>


float sumar(struct Operaciones *op) {
    return op->num1 + op->num2;
}

float restar(struct Operaciones *op) {
    return op->num1 - op->num2;
}

float multiplicar(struct Operaciones *op) {
    return op->num1 * op->num2;
}

float dividir(struct Operaciones *op) {
    if (op->num2 != 0) {
        return op->num1 / op->num2;
    } else {
        printf("Error: no se puede dividir por cero\n");
        return 0.0;
    }
}

float potencia(struct Operaciones *op) {
    op->resultado = 1;
    for (op->i = 0; op->i < op->exponente; op->i++) {
        op->resultado *= op->num1;
    }
    return op->resultado;
}

float raizCuadrada(struct Operaciones *op) {
    if (op->num1 < 0) {
        printf("Error: No se puede calcular la raíz cuadrada de un número negativo\n");
        return -1;
    }
    return sqrt(op->num1);
}

