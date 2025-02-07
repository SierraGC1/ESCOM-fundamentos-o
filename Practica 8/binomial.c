#include <stdio.h>

int calcularBinomialIterativo(int n, int k) {
    int i;
    int resultado = 1;
    if (k > n) { //condicion de que el coeficiente es 0 entoces NO EXISTE
        return 0;
    }

    if (k > n - k) {
        k = n - k;
    }

    for (i = 1; i <= k; i++) {
        resultado *= n - (k - i);   // Multiplica el resultado por (n-i+1), donde i es el índice de la iteración
        resultado /= i; 			// Divide el resultado por i (esto corresponde a i! en el denominador)
    }

    return resultado;
}


int calcularBinomialRecursivo(int n, int k) {
	
    if (k == 0 || k == n) {	
        return 1;
    } else {
        
        return calcularBinomialRecursivo(n - 1, k - 1) + calcularBinomialRecursivo(n - 1, k); //CB(n, k) = CB(n-1, k-1) + CB(n-1, k)
    }
}

void ejecutarPrograma(){
	int n, k, recursivo, iterativo;
	
    printf("Primer numero que sea mayor igual a 0 (n): ");
    scanf("%d", &n);
    
    printf("Segundo numero que sea mayor igual a 0 o menor que el primer numero (k): ");
    scanf("%d", &k);

    if (n < 0 || k < 0) {
        printf("El valor de los numeros no puede ser negativo\n");
        return 1;
    } else if (k > n) {
        printf("El valor de k no puede ser mayor que n.\n");
        return 1;
    }

	recursivo = calcularBinomialRecursivo(n, k);
    printf("CB(%d, %d) resultado recusivo: %d\n", n, k, recursivo);
	iterativo = calcularBinomialIterativo(n, k);
    printf("CB(%d, %d) resultado iterativo: %d\n", n, k, iterativo);

}

int main(int argc, char *argv[]) {
	ejecutarPrograma();
    return 0;
}

