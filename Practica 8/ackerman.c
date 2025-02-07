#include <stdio.h>
#define MAX_PILA 100000  

int calcularAckermannRecursiva(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return calcularAckermannRecursiva(m - 1, 1);
    } else {
        return calcularAckermannRecursiva(m - 1, calcularAckermannRecursiva(m, n - 1));
    }
}


int calcularAckermannIterativa(int m, int n) {
    int pila[MAX_PILA];
    int top = -1;  // Inicio de la pila
    pila[++top] = m;

    while (top >= 0) {
        m = pila[top--];
        if (m == 0) {
            n = n + 1;  // Caso base
        } else if (n == 0) {
            pila[++top] = m - 1;  // Reducción de m
            n = 1;
        } else {
            pila[++top] = m - 1;  // Reducción de m
            pila[++top] = m;      // Reducción de n
            n = n - 1;
        }
    }
    return n;
}

void ejecutarPrograma(){
  	int m, n, resultadoR, resultadoI;
    printf("Ingrese el valor de m: ");
    scanf("%d", &m);
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    resultadoR = calcularAckermannRecursiva(m, n);
    printf("\n[Recursiva] Ackermann(%d, %d) = %d\n", m, n, resultadoR);

    resultadoI = calcularAckermannIterativa(m, n);
    printf("[Iterativa] Ackermann(%d, %d) = %d\n", m, n, resultadoI);

}

int main(int argc, char *argv[]) {
	ejecutarPrograma();
    return 0;
}

