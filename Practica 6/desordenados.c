#include <stdio.h>
#define MAX 40

void ingresarNumeros(int *arreglo, int *ptrlongitud) {
    int numero;
    int i;
    *ptrlongitud = 0;
    
    printf("NOTA: Ingrese 0 para terminar.\nIngrese numeros enteros (maximo 40):\n");    
    for (i = 0; i < MAX; i++) {
        scanf("%d", &numero);
        if (numero == 0) {
            break;
        }
        *(arreglo + i) = numero;
        (*ptrlongitud)++;
    }

    if (*ptrlongitud > MAX) {
        printf("Error: no puedes ingresar mas de 40 numeros.\n");
    }
}

int* buscarPrimerDesordenado(int *arreglo, int longitud) {
    int *ptr = arreglo;
    for (ptr; ptr < arreglo + longitud - 1; ++ptr) {
        if (*(ptr + 1) < *ptr) {
            return ptr + 1;
        }
    }
    return NULL;
}

void buscarSegundoDesordenado(int *arreglo, int longitud) {
    int *primeroordenado = buscarPrimerDesordenado(arreglo, longitud);  
    int *segundo;
    if (primeroordenado != NULL) {
       segundo = buscarPrimerDesordenado(primeroordenado + 1, longitud - (primeroordenado - arreglo) - 1);  
        if (segundo != NULL) {
            printf("El segundo desordenado es %d y es el elemento numero %ld\n", *segundo, segundo - arreglo + 1);
        } else {
            printf("No hay un segundo elemento desordenado\n");
        }
    }
}

void buscarTercerDesordenado(int *arreglo, int longitud) {
    int *primeroordenado = buscarPrimerDesordenado(arreglo, longitud); 
	int *segundo, *tercero ;
    if (primeroordenado != NULL) {
        segundo = buscarPrimerDesordenado(primeroordenado + 1, longitud - (primeroordenado - arreglo) - 1);  
        if (segundo != NULL) {
            tercero = buscarPrimerDesordenado(segundo + 1, longitud - (segundo - arreglo) - 1);  
            if (tercero != NULL) {
                printf("El tercer desordenado es %d y es el elemento numero %ld\n", *tercero, tercero - arreglo + 1);
            } else {
                printf("No hay un tercer elemento desordenado\n");
            }
        }
    }
}

void mostrarResultado(int *desordenado, int *arreglo) {
    if (desordenado) {
        printf("El primer desordenado es %d y es el elemento numero %ld\n", *desordenado, desordenado - arreglo + 1);
    } else {
        printf("El arreglo esta ordenado\n");
    }
}

void ejecutarPrograma() {
    int arreglo[MAX]; 
    int *ptrArreglo = arreglo;  
    int longitud;       
	int *desordenado;
    ingresarNumeros(ptrArreglo, &longitud);

    if (longitud > MAX) {
        printf("ERROR: No puedes ingresar mas de 40 numeros.\n");
        return;
    }

    desordenado = buscarPrimerDesordenado(ptrArreglo, longitud);  
    mostrarResultado(desordenado, ptrArreglo);

    buscarSegundoDesordenado(ptrArreglo, longitud); 
    buscarTercerDesordenado(ptrArreglo, longitud);  
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}  

