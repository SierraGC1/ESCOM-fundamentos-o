#include <stdio.h>

void sumar(int a, int b, int *ptr) {
    *ptr = a + b;
}

void dividir(int a, int b, float *ptr) {
    if (b == 0) {
        printf("Error: No se puede dividir por cero.\n");
    } else {
        *ptr = (float)a / b;
    }
}

void multiplicar(int a, int b, int *ptr) {
    *ptr = a * b;
}

void restar(int a, int b, int *ptr) {
    *ptr = a - b;
}

void obtenerModulo(int a, int b, int *ptrC) {
    *ptrC = a % b;
}

void ejecutarPrograma() {
    int arreglo[14] = {23, 5, 98, 65, 3, 55, 73, 9, 21, 85,10,33,55,49};
    int *ptr = arreglo; 
    int sumaResultado, modResultado;
    float divisionResultado;
    int multiplicacionResultado, restaResultado;

    sumar(*(ptr + 0), *(ptr + 1), &sumaResultado);
    dividir(*(ptr + 2), *(ptr + 3), &divisionResultado);
    multiplicar(*(ptr + 4), *(ptr + 5), &multiplicacionResultado);
    restar(*(ptr + 6), *(ptr + 7), &restaResultado);
    obtenerModulo(*(ptr + 8), *(ptr + 9), &modResultado);

    printf("Suma: %d\n", sumaResultado);
    if (ptr[3] != 0) {
        printf("Division: %.2f\n", divisionResultado);
    } else {
        printf("Division: Error (division por cero)\n");
    }
    printf("Multiplicacion: %d\n", multiplicacionResultado);
    printf("Resta: %d\n", restaResultado);
    printf("Modulo: %d\n", modResultado);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}
