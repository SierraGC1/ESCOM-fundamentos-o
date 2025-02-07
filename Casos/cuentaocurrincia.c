#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 50

void darAleatoriedad() {
    srand(time(NULL));
}

void iniciarMatriz(int matriz[], int contador[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        matriz[i] = rand() % MAX;
        contador[i] = 0;
    }
}

void contarNumeros(int matriz[], int contador[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        contador[matriz[i]]++;
    }
}

void calcularProbabilidades(int contador[], float probabilidades[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        probabilidades[i] = (float)contador[i] / MAX;
    }
}

void informarSalida(int contador[], float probabilidades[]) {
    int i;
    printf("No.\tcuenta\tp(contador)\n");
    for (i = 0; i < MAX; i++) {
        printf("%d\t%d\t%.3f\n", i, contador[i], probabilidades[i]);
    }
}

void ejecutarPrograma() {
    int matriz[MAX], contador[MAX];
    float probabilidades[MAX];
    darAleatoriedad();
    iniciarMatriz(matriz, contador);
    contarNumeros(matriz, contador);
    calcularProbabilidades(contador, probabilidades);
    informarSalida(contador, probabilidades);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

