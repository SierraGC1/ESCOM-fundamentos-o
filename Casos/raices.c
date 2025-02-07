#include <stdio.h>
#include <math.h>

int solicitarDiscriminanteA() {
    int a;
    printf("Introduzca valor entero de a: \n");
    scanf("%d", &a);
    return a;
}

int solicitarDiscriminanteB() {
    int b;
    printf("Introduzca valor entero de b: \n");
    scanf("%d", &b);
    return b;
}

int solicitarDiscriminanteC() {
    int c;
    printf("Introduzca valor entero de c: \n");
    scanf("%d", &c);
    return c;
}

double calcularDiscriminante(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

void calcularRaices(int a, int b, int c, double discriminante) {
    double raizUno, raizDos, raizUnoSec, raizDosSec;

    if (discriminante == 0) {
        raizUno = -b / (2.0 * a);
        raizDos = raizUno;
        raizUnoSec = 0;
        raizDosSec = 0;
    } else if (discriminante > 0) {
        raizUno = (-b + sqrt(discriminante)) / (2.0 * a);
        raizDos = (-b - sqrt(discriminante)) / (2.0 * a);
        raizUnoSec = 0;
        raizDosSec = 0;
    } else {
        raizUno = -b / (2.0 * a);
        raizDos = raizUno;
        raizUnoSec = sqrt(-discriminante) / (2.0 * a);
        raizDosSec = raizUnoSec;
    }
    
    printf("El calculo de las raices %dx^2 + %dx + %d = 0 es: \n", a, b, c);

    if (discriminante >= 0) {
        printf("raizUno = %f \n", raizUno);
        printf("raizDos = %f \n", raizDos);
    } else {
        printf("raizUno = %f + %fi \n", raizUno, raizUnoSec);
        printf("raizDos = %f - %fi \n", raizDos, raizDosSec);
    }
}

void resolverEcuacion() {
    int a = solicitarDiscriminanteA();
    int b = solicitarDiscriminanteB();
    int c = solicitarDiscriminanteC();
    double discriminante = calcularDiscriminante(a, b, c);
    calcularRaices(a, b, c, discriminante);
}

int main(int argc, char *argv[]) {
    resolverEcuacion();
    return 0;
}

