#include <stdio.h>

void introducirNumero() {
    int numero, resultadoRecursivo, resultadoIterativo;

    printf("Introduce un número entero positivo o nulo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("El número debe ser positivo o nulo.\n");
        return;
    }

    resultadoRecursivo = fibonacciRecursivo(numero);
    printf("El número de Fibonacci recursivo en la posición %d es %d.\n", numero, resultadoRecursivo);
    imprimirSucesionFibonacci(numero);

   	resultadoIterativo=fibonacciRecursivo(numero);
    printf("El número de Fibonacci iterativo en la posición %d es %d.\n", numero, resultadoIterativo);
	fibonacciIterativo(numero, &resultadoIterativo);
}

int fibonacciRecursivo(int n) {
    if (n == 0) { // Caso base 1
        return 0;
    } else if (n == 1) { // Caso base 2
        return 1;
    } else { // Paso recursivo
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    }
}

void fibonacciIterativo(int n, int *resultado) {
    int fi = 0, fi1 = 1, fi2 = 0;
    int i = 2; 

    if (n == 0 || n == 1) { // Casos base
        *resultado = n;
        return;
    }

    printf("Fibonacci(0) = 0\n");
    printf("Fibonacci(1) = 1\n");

    for (i; i <= n; i++) { 
        fi = fi1 + fi2; 
        printf("Fibonacci(%d) = Fibonacci(%d) + Fibonacci(%d) = %d + %d = %d\n",i, i - 1, i - 2, fi1, fi2, fi);

        fi2 = fi1;
        fi1 = fi;
    }

    *resultado = fi;
}

void imprimirSucesionFibonacci(int limite) {
    int i = 0; 

    printf("Sucesión de Fibonacci hasta el término %d:\n", limite);

    for (i; i <= limite; i++) { 
        if (i < limite) {
            printf("%d ", fibonacciRecursivo(i));
        } else {
            printf("= %d", fibonacciRecursivo(i));
        }
    }
    printf("\n");
}

void ejecutarPrograma() {
    introducirNumero();
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

