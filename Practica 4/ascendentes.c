#include <stdio.h>

int main(int argc, char *argv[]) {
    
	int numerouno, numerodos, numerotres;

    printf("Ingrese tres numeros enteros:\n ");
    scanf("\n%d \n%d \n%d", &numerouno, &numerodos, &numerotres);

    if (numerouno <= numerodos && numerouno <= numerotres) {
 
        if (numerodos <= numerotres) {
            printf("Orden ascendente: %d %d %d\n", numerouno, numerodos, numerotres);
        } else {
            printf("Orden ascendente: %d %d %d\n", numerouno, numerotres, numerodos);
        }
    } else if (numerodos <= numerouno && numerodos <= numerotres) {
  
        if (numerouno <= numerotres) {
            printf("Orden ascendente: %d %d %d\n", numerodos, numerouno, numerotres);
        } else {
            printf("Orden ascendente: %d %d %d\n", numerodos, numerotres, numerouno);
        }
    } else {

        if (numerouno <= numerodos) {
            printf("Orden ascendente: %d %d %d\n", numerotres, numerouno, numerodos);
        } else {
            printf("Orden ascendente: %d %d %d\n", numerotres, numerodos, numerouno);
        }
    }

    return 0;
}
