#include <stdio.h>

int calcularParticionRecursivo(int m, int n) {
    if (m == 0) {
        return 1; // Caso base: hay una partición válida
    }
    if (m < 0 || n == 0) {
        return 0; // Caso base: no hay partición válida
    }
    return calcularParticionRecursivo(m - n, n) + calcularParticionRecursivo(m, n - 1);
}

int calcularParticionIterativa(int m, int n) {
    int tabla[m + 1][n + 1];
	int i,j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) {
                tabla[i][j] = 1; // Hay una partición si m es 0
            } else if (j == 0) {
                tabla[i][j] = 0; // No hay partición si n es 0
            } else if (i < j) {
                tabla[i][j] = tabla[i][i]; // Limitar máximo al valor de i
            } else {
                tabla[i][j] = tabla[i - j][j] + tabla[i][j - 1]; // Sumar casos: usar o no usar j
            }
        }
    }

    return tabla[m][n];
}
void ejecutarPrograma(){
	    int m, n, recursiva, iterativa;

    printf("Primer numero(m): ");
    scanf("%d", &m);
    printf("Segundo numero(n): ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0) {
        printf("No se puede calcular la particion de numeros menores o iguales que 0.\n");
        return 0;
    }

    recursiva = calcularParticionRecursivo(m, n);
    printf("Particion recursiva de %d y %d: %d\n", m, n, recursiva);
    
    iterativa = calcularParticionIterativa(m, n);
    printf("Particion iterativa de %d y %d: %d\n", m, n, iterativa);

}

int main(int argc, char *argv[]) {
	ejecutarPrograma();
    return 0;
}

