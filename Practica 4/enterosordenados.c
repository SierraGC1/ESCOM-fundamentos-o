#include <stdio.h>

int main(int argc, char *argv[]) {
    int numero, mayor, menor;
	int n = 1;
    printf("Ingrese un numero entero (Con un numero negativo termina la lectura): ");
    scanf("%d", &numero);
    
    if (numero >= 0) {
        mayor = menor = numero;
        
        while (numero >= 0) {
            printf("Ingrese un numero entero (Con un numero negativo termina la lectura): ");
            scanf("%d", &numero);

            if (numero <= 0) {
                break;
            }

            if (numero > mayor) {
                mayor = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
            n++;
        }

        printf("\n");
        printf("Numero mayor: %d\n", mayor);
        printf("Numero menor: %d\n", menor);
        printf("Total de numeros ingresados: %d\n", n);
    } 

    return 0;
}

