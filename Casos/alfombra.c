#include <stdio.h>
#define METRO_ALFOMBRA 2.75
#define DESCUENTO 0.15

void realizarCompra() {
    double calcularMetros, calcularCostoTotal, sacarSubTotal, descuento, total;

    printf("Ingresar la cantidad de metros de alfombra a adquirir: ");
    scanf("%lf", &calcularMetros);

    calcularCostoTotal = calcularMetros * METRO_ALFOMBRA;
    sacarSubTotal = calcularCostoTotal;

    if (calcularMetros > 10) {
        descuento = calcularCostoTotal * DESCUENTO;
        total = calcularCostoTotal - descuento;
    } else {
        descuento = 0;
        total = calcularCostoTotal;
    }
    
    printf("Usted esta adquiriendo %.2lf metros de alfombra\n", calcularMetros);
    printf("Subtotal: %.2lf\n", sacarSubTotal);
    printf("Descuento: %.2lf\n", descuento);
    printf("Total: %.2lf\n", total);
}

int main(int argc, char *argv[]) {
    realizarCompra();
    return 0;
}

