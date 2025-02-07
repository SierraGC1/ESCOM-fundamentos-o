#include <stdio.h>

int calcularEuclidesIterativo(int a, int b) {
    int variableTemporalb;
    while (b != 0) {
        printf("a: %d, b: %d\n", a, b); // Mostrar los valores actuales de a y b
        variableTemporalb = b; // Guardar el valor actual de b en bTemporal
        b = a % b; // Calcular el residuo de a dividido por b, y asignarlo a b
        a = variableTemporalb; // Actualizar a para que tome el valor de bTemporal (anterior b)
    }
    printf("a: %d, b: %d \n", a, b); // Último paso donde b es 0
    return a; // Cuando b es 0, a contiene el MCD
}

int calcularEuclidesRecursivo(int a, int b) {
    printf("a: %d, b: %d\n", a, b);
    if (b == 0) {
        return a;
    } else {
        return calcularEuclidesRecursivo(b, a % b); // recursividad
    }
}

int validarNumeros(int a, int b) {
    if (a < 0 || b < 0) {
        printf("El MCD no se puede calcular en negativo.\n");
        return 0; 
    } else if (a == 0 && b == 0) {
        printf("MCD(0, 0) no está definido.\n");
        return 0; 
    } else if (a == 0) {
        printf("MCD de (0, %d) es %d\n", b, b);
        return 0; 
    } else if (b == 0) {
        printf("MCD de (%d, 0) es %d\n", a, a);
        return 0; 
    }
    return 1; 
}

int solicitarNumero(int* a, int* b) {
    printf("Primer numero: ");
    scanf("%d", a);

    printf("Segundo numero: ");
    scanf("%d", b);

    return validarNumeros(*a, *b); 
}

void ejecutarPrograma() {
    int a, b, recursivo, iterativo;
    
    if (!solicitarNumero(&a, &b)) {
        return; 
    }

    printf("Calcular de forma recursiva:\n");
    recursivo = calcularEuclidesRecursivo(a, b);
    printf("MCD (%d, %d) = %d\n", a, b, recursivo);

    printf("Calcular de forma iterativa:\n");
    iterativo = calcularEuclidesIterativo(a, b);
    printf("MCD (%d, %d) = %d\n", a, b, iterativo);
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}


