#include <stdio.h>

unsigned long long factorialRecursivo(unsigned long long n) {
    if (n == 0) { // Paso base
        return 1;
    } else { // Paso recursivo
        return n * factorialRecursivo(n - 1);
    }
}

unsigned long long factorialIterativo(unsigned long long n) {
    unsigned long long resultado = 1;
    while (n > 0) { 
        resultado *= n;
        n--;
    }
    return resultado;
}

void calcularDiferencia(unsigned long long factorial, unsigned long long objetivo) {
    if (factorial == objetivo) {
        printf("El factorial calculado coincide exactamente con el objetivo (%llu).\n", objetivo);
    } else if (factorial < objetivo) {
        printf("El factorial calculado es menor al objetivo por %llu.\n", objetivo - factorial);
    } else {
        printf("El factorial calculado supera el objetivo por %llu.\n", factorial - objetivo);
    }
}

void introducirNumero() {
    unsigned long long numero, objetivo, resultadoRecursivo, resultadoIterativo;

    printf("Introduce un numero entero positivo o nulo: ");
    scanf("%llu", &numero);

    printf("Introduce el valor objetivo para comparar: ");
    scanf("%llu", &objetivo);

    // Calcular factorial recursivo
    resultadoRecursivo = factorialRecursivo(numero);
    printf("El factorial recursivo de %llu es %llu.\n", numero, resultadoRecursivo);
    calcularDiferencia(resultadoRecursivo, objetivo);

    // Calcular factorial iterativo
    resultadoIterativo = factorialIterativo(numero);
    printf("El factorial iterativo de %llu es %llu.\n", numero, resultadoIterativo);
    calcularDiferencia(resultadoIterativo, objetivo);
}

void ejecutarPrograma() {
    introducirNumero();
}

int main() {
    ejecutarPrograma(); 
    return 0;
}

