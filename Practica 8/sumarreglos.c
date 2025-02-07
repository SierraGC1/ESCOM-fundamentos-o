#include <stdio.h>
#define MAX 15

int calcularArregloIterativo(int arreglo[MAX]) {
    int i, suma = 0;
    printf("Suma iterativa:\n");
    for (i = 0; i < MAX; i++) {
        suma = suma + *(arreglo + i);
        printf("Paso %d: Suma parcial = %d (suma %d)\n", i + 1, suma, *(arreglo + i));
    }
    return suma;
}

int calcularArregloRecursivo(int arreglo[MAX], int longitud) {
	int sumaTotal;
    if (longitud < 0) { // Caso base
        return 0;
    } else {
        sumaTotal = arreglo[longitud] + calcularArregloRecursivo(arreglo, longitud - 1);
        printf("Suma de arreglo hasta indice %d: %d\n", longitud, sumaTotal);
        return sumaTotal;
    }
}

void ejecutarPrograma() {
    int arreglo[MAX] = {5,55,666,1,3,777,908,9,20,11,555,15,13,14,10};
    int recursiva,interativa;
    printf("Suma recursiva:\n");
    recursiva = calcularArregloRecursivo(arreglo, MAX - 1);
    printf("Resultado de la suma recursiva: %d\n", recursiva);
	interativa = calcularArregloIterativo(arreglo);
    printf("Resultado de la suma iterativa: %d\n", interativa);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

