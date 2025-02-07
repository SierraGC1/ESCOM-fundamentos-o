#include <stdio.h>

#define MAX 15 

void imprimirArregloIterativo(int arreglo[MAX]) {
	int i;
    printf("Imprimir iterativo del arreglo:\n");
    for (i = 0; i < MAX; i++) {
        printf("Numero: %d\n", *(arreglo + i));
    }
}

void imprimirArregloRecursivo(int arreglo[MAX], int longitud) {
    if (longitud >= 0) {
        imprimirArregloRecursivo(arreglo, longitud - 1); // recursividad
        printf("Numero: %d\n", *(arreglo + longitud));
    }
}

void ejecutarPrograma() {
    int arreglo[MAX] = {5,55,666,1,3,777,908,9,20,11,555,15,13,14,10};
    printf("Imprimir recursivo del arreglo:\n");
    imprimirArregloRecursivo(arreglo, MAX - 1);
    imprimirArregloIterativo(arreglo);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma(); 
    return 0;
}

