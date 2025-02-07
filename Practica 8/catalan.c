#include <stdio.h>

int calcularCatalanIterativo(int n) {
    int catalan[n + 1];
    int i,j;
    catalan[0] = 1;
    
    for (i = 1; i <= n; i++) {
        catalan[i] = 0;
        
        for (j = 0; j < i; j++) {								//Formula de recurrencia de los numeros de Catalan:
            catalan[i] += catalan[j] * catalan[i - 1 - j];		// C(n) = sumatoria (C(i) * C(n-i-1)) para i = 0 hasta n-1
        }
    }

    printf("Iterativo: numeros de Catalan hasta C(%d):\n", n);
    for (i = 0; i <= n; i++) {
        printf("Catalan(%d) = %d\n", i, catalan[i]);
    }
    return catalan[n];
}

int calcularCatalanRecursivo(int n) {
	int catalan = 0,i;
    if (n == 0) {
        // base: Catalan(0) = 1
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        catalan += calcularCatalanRecursivo(i) * calcularCatalanRecursivo(n - 1 - i);
    }
    return catalan;
}

void catalanRecursivo(int n) {
	int i;
    printf("Recursividad: numeros de Catalan hasta C(%d):\n", n);
    for (i = 0; i <= n; i++) {
        printf("Catalan(%d) = %d\n", i, calcularCatalanRecursivo(i));
    }
}

void ejecutarPrograma(){
	int n;
    printf("Introduce el valor de n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error: El numero debe ser mayor o igual a 0.\n");
        return 1;
    }
    catalanRecursivo(n);
    
    calcularCatalanIterativo(n);

}

int main(int argc, char *argv[]) {
	ejecutarPrograma();
    return 0;
}

