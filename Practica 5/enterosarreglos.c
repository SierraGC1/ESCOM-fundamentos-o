#include <stdio.h>
#define MAX 100

void inviarMensaje() {
    printf("\tNOTA: Al momento de ingresar un numero negativo se termina.\n");
}

int imprimirInstrucciones() {
    int numero;
    printf("Introduzca un numero entero: \n");
    scanf("%d", &numero);
    return numero;
}

void iniciarBucle() {
    int numeros[MAX];
    int contadorDeEnteros = 0;
    int numeroMaximo, numeroMinimo;
    int i;
    int numero;

    while (1) {
        numero = imprimirInstrucciones();

        if (numero < 0 && contadorDeEnteros == 0) {
            printf("El primer numero no puede ser negativo. Intente de nuevo.\n");
            continue;
        }

        if (numero < 0) {
            break;
        }

        if (contadorDeEnteros < MAX) {
            numeros[contadorDeEnteros] = numero;
            contadorDeEnteros++;
        } else {
            printf("No se aceptan más numeros. Intente de nuevo.\n");
            break;
        }
    }

    if (contadorDeEnteros > 0) {
        numeroMaximo = numeros[0];
        numeroMinimo = numeros[0];
        for (i = 1; i < contadorDeEnteros; i++) {
            if (numeros[i] > numeroMaximo) {
                numeroMaximo = numeros[i];
            }
            if (numeros[i] < numeroMinimo) {
                numeroMinimo = numeros[i];
            }
        }

        imprimirResultados(numeros, contadorDeEnteros, numeroMaximo, numeroMinimo);
    }
}

void imprimirResultados(int numeros[], int contadorDeEnteros, int numeroMaximo, int numeroMinimo) {
    int i; 
    if (contadorDeEnteros > 0) {
        printf("Entero mas alto ingresado: %d\n", numeroMaximo);
        printf("Entero mas bajo ingresado: %d\n", numeroMinimo);
        printf("Numero de enteros ingresados: %d\n", contadorDeEnteros);

        printf("Numeros ingresados: ");
        for ( i = 0; i < contadorDeEnteros; i++) {
            printf("%d", numeros[i]);
            if (i < contadorDeEnteros - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    inviarMensaje();
    iniciarBucle();
    return 0;
}

