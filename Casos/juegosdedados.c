#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUMERO_CARAS 6

int solicitarNumero() {
    int numero;
    printf("Introduzca un numero entre 2 y 12: ");
    scanf("%d", &numero);
    
    while (numero < 2 || numero > 12) {
        printf("Intente de nuevo, elija un numero entre 2 y 12: \n");
        scanf("%d", &numero);
    }
    return numero;
}
void tomarLosDados() {
    srand(time(NULL));
}

void agitarLosDados() {
    printf("Sonido de dados chocando.....\n");
}

void soplarLosDados() {
    printf("Soplando dados.......\n");
}

void decirMiNumero(int numero) {
    printf("Mi numero es %d\n", numero);
}

int lanzarLosDados() {
    int dadoUno = (rand() % NUMERO_CARAS) + 1;
    int dadoDos = (rand() % NUMERO_CARAS) + 1;
    return dadoUno + dadoDos;
}

void jugarAlJuego() {
    int numero = solicitarNumero();
    tomarLosDados();
    agitarLosDados();
    soplarLosDados();
    decirMiNumero(numero);

    int numeroGanador = lanzarLosDados();
    if (numeroGanador == numero) {
        printf("Felicidades, has ganado con %d\n", numeroGanador);
    } else {
        printf("No has ganado porque %d es distinto de %d\n", numeroGanador, numero);
    }
}

int main(int argc, char *argv[]) {
    jugarAlJuego();
    return 0;
}

