#include <stdio.h>

int main(int argc, char *argv[]) {
    int recibirGenero, recibirTipo, recibircomida, recibirEstilo;

    printf("Eres hombre o mujer?\n");
    printf("1. Hombre\n");
    printf("2. Mujer\n");
    printf("Selecciona una opcion (1 o 2): ");
    scanf("%d", &recibirGenero);

    if (recibirGenero == 1) { 
        printf("Eres un superheroe o un supervillano?\n");
        printf("1. Superheroe\n");
        printf("2. Supervillano\n");
        printf("Selecciona una opcion (1 o 2): ");
        scanf("%d", &recibirTipo);

        if (tirecibirTipopo == 1) {  
            printf("Prefieres bistec o sushi?\n");
            printf("1. Bistec\n");
            printf("2. Sushi\n");
            printf("Selecciona una opcion (1 o 2): ");
            scanf("%d", &recibircomida);

            if (recibircomida == 1) {
                printf("Deberias pedir un corte de parte superior plana.\n");
            } else if (recibircomida == 2) {
                printf("Deberias pedir un corte de copete.\n");
            }
        } else if (recibirTipo == 2) {  
            printf("Deberias pedir un corte Mohicano.\n");
        }
    } else if (recibirGenero == 2) {  
        printf("Eres una superheroe o una supervillano?\n");
        printf("1. Superheroe\n");
        printf("2. Supervillano\n");
        printf("Selecciona una opcion (1 o 2): ");
        scanf("%d", &recibirTipo);

        if (recibirTipo == 1) {  
            printf("Prefieres animado o comedia?\n");
            printf("1. Animado\n");
            printf("2. Comedia\n");
            printf("Selecciona una opcion (1 o 2): ");
            scanf("%d", &recibirEstilo);

            if (estirecibirEstilolo == 1) {
                printf("Deberias pedir un corte de flequillo.\n");
            } else if (recibirEstilo == 2) {
                printf("Deberias pedir un corte de sacudida.\n");
            }
        } else if (recibirTipo == 2) {  
            printf("Deberias pedir un corte Mohicano.\n");
        }
    } else {
        printf("Opcion no valida.\n");
    }

    return 0;
}
