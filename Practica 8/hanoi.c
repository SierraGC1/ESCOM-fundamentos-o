#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCOS 64

typedef struct {
    int discos[MAX_DISCOS];
    int tope;
} Pila;

void inicializarPila(Pila *pila) {
    pila->tope = -1;
}

int pilaVacia(Pila *pila) {
    return pila->tope == -1;
}

int cima(Pila *pila) {
    return pila->discos[pila->tope];
}

void apilar(Pila *pila, int disco) {
    pila->tope++;
    pila->discos[pila->tope] = disco;
}

int desapilar(Pila *pila) {
    int disco = pila->discos[pila->tope];
    pila->tope--;
    return disco;
}

void moverDisco(char desde, char hasta, Pila *origen, Pila *destino) {
    int discoDesde, discoHasta;

    if (pilaVacia(origen)) {
        discoDesde = 0;
    } else {
        discoDesde = desapilar(origen);
    }

    if (pilaVacia(destino)) {
        discoHasta = 0;
    } else {
        discoHasta = cima(destino);
    }

    if (discoDesde == 0) {
        apilar(origen, desapilar(destino));
        printf("Mover disco %d de %c a %c\n", discoHasta, hasta, desde);
    } else if (discoHasta == 0) {
        apilar(destino, discoDesde);
        printf("Mover disco %d de %c a %c\n", discoDesde, desde, hasta);
    } else if (discoDesde > discoHasta) {
        apilar(origen, desapilar(destino));
        printf("Mover disco %d de %c a %c\n", discoHasta, hasta, desde);
    } else {
        apilar(destino, discoDesde);
        printf("Mover disco %d de %c a %c\n", discoDesde, desde, hasta);
    }
}


void calcularHanoiIterativa(int numDiscos, Pila *origen, Pila *auxiliar, Pila *destino) {
    char nombres[3] = {'A', 'B', 'C'};
    int totalMovimientos = (1 << numDiscos) - 1;
	int i;
    for (i = numDiscos; i >= 1; i--) {
        apilar(origen, i);
    }

    for (i = 1; i <= totalMovimientos; i++) {
        switch (i % 3) {
            case 1:
                moverDisco(nombres[0], nombres[2], origen, destino);
                break;
            case 2:
                moverDisco(nombres[0], nombres[1], origen, auxiliar);
                break;
            case 0:
                moverDisco(nombres[1], nombres[2], auxiliar, destino);
                break;
        }
    }
}

void calcularhanoiRecursiva(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mover disco de %c a %c\n", origen, destino);
        return;
    }

    calcularhanoiRecursiva(n - 1, origen, destino, auxiliar);
    printf("Mover disco de %c a %c\n", origen, destino);
    calcularhanoiRecursiva(n - 1, auxiliar, origen, destino);
}

void ejecutarPrograma() {
    int numDiscos;
    Pila origen, auxiliar, destino;

    inicializarPila(&origen);
    inicializarPila(&auxiliar);
    inicializarPila(&destino);

    printf("Indica el numero de discos: ");
    scanf("%d", &numDiscos);

    if (numDiscos < 1 || numDiscos > MAX_DISCOS) {
        printf("Numero de discos inválido. Debe estar entre 1 y %d.\n", MAX_DISCOS);
        return;
    }

    printf("Resultado de la iterativa:\n");
    calcularHanoiIterativa(numDiscos, &origen, &auxiliar, &destino);

    printf("\nResultado de la recursiva:\n");
    calcularhanoiRecursiva(numDiscos, 'A', 'B', 'C');
}

int main(int argc, char *argv[]) {
    ejecutarPrograma();
    return 0;
}

