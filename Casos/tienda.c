#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 100
#define MAX_CODIGO 5
#define SEMANAS_EN_MES 4

void registrarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], char codigos[MAX_PRODUCTOS][MAX_CODIGO], float costos[MAX_PRODUCTOS], float preciosVenta[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int totProductos) {
    int valido = 0;

    if (totProductos >= MAX_PRODUCTOS) {
        printf("No se pueden añadir mas productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    fgets(nombres[totProductos], MAX_NOMBRE, stdin);
    nombres[totProductos][strcspn(nombres[totProductos], "\n")] = 0;

    while (!valido) {
        printf("Ingrese el codigo del producto (exactamente 5 caracteres): ");
        scanf("%5s", codigos[totProductos]);
        getchar();
        if (strlen(codigos[totProductos]) != 5) {
            printf("El codigo debe tener exactamente 5 caracteres. Intente de nuevo.\n");
        } else {
            valido = 1;
        }
    }

    printf("Registra el costo del producto: ");
    scanf("%f", &costos[totProductos]);
    getchar();

    printf("Especifica el precio de venta del producto: ");
    scanf("%f", &preciosVenta[totProductos]);
    getchar();

    printf("Registra la cantidad disponible del producto: ");
    scanf("%d", &cantidades[totProductos]);
    getchar();

    printf("Producto agregado correctamente.\n");
}

void registrarVenta(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], char codigos[MAX_PRODUCTOS][MAX_CODIGO], float costos[MAX_PRODUCTOS], float preciosVenta[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int totProductos, float ganancias_semanales[SEMANAS_EN_MES]) {
    char codigo[MAX_CODIGO];
    int indiceProducto = -1;
    int j, semana;
    int cantidadVendida;
    float gananciaProducto;

    if (totProductos <= 0) {
        printf("No hay productos registrados para vender.\n");
        return;
    }

    printf("\nEsta registrando la venta semanal.\n");
    printf("Ingrese el codigo del producto vendido: ");
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    for (j = 0; j < totProductos; j++) {
        if (strcmp(codigos[j], codigo) == 0) {
            indiceProducto = j;
            break;
        }
    }

    if (indiceProducto == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (semana = 0; semana < SEMANAS_EN_MES; semana++) {
        printf("Ingrese la cantidad vendida de %s en la semana %d: ", nombres[indiceProducto], semana + 1);
        scanf("%d", &cantidadVendida);
        getchar();

        if (cantidadVendida < 0) {
            printf("La cantidad no puede ser negativa. Intente de nuevo.\n");
        } else if (cantidadVendida > cantidades[indiceProducto]) {
            printf("No hay suficientes productos en inventario para la semana %d.\n", semana + 1);
            printf("Cantidad actual: %d. Intente de nuevo.\n", cantidades[indiceProducto]);
            semana--;
        } else {
            cantidades[indiceProducto] -= cantidadVendida;
            gananciaProducto = (preciosVenta[indiceProducto] - costos[indiceProducto]) * cantidadVendida;
            ganancias_semanales[semana] += gananciaProducto;
        }
    }

    printf("Venta del producto %s registrada correctamente.\n", nombres[indiceProducto]);
}

void calcularGanancias(float ganancias_semanales[SEMANAS_EN_MES]) {
    int semana;
    float gananciasMensuales = 0;
    for (semana = 0; semana < SEMANAS_EN_MES; semana++) {
        gananciasMensuales += ganancias_semanales[semana];
    }

    printf("\nLas ganancias mensuales son: $%.2f\n", gananciasMensuales);
}

void desplegarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], char codigos[MAX_PRODUCTOS][MAX_CODIGO], float costos[MAX_PRODUCTOS], float preciosVenta[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int totProductos) {
    int i;
    printf("\nLista de Productos:\n");
    for (i = 0; i < totProductos; i++) {
        printf("Nombre: %s, Codigo: %s, Costo: $%.2f, Precio de Venta: $%.2f, Cantidad: %d\n", nombres[i], codigos[i], costos[i], preciosVenta[i], cantidades[i]);
    }
}

void desplegarMenu() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE] = {0};
    char codigos[MAX_PRODUCTOS][MAX_CODIGO] = {0};
    float costos[MAX_PRODUCTOS] = {0};
    float preciosVenta[MAX_PRODUCTOS] = {0};
    int cantidades[MAX_PRODUCTOS] = {0};
    int totProductos = 0;
    float ganancias_semanales[SEMANAS_EN_MES] = {0};
    int opcion;

    do {
        printf("********La Tienda de Todos*************\n");
        printf("1.-Agregar Producto\n");
        printf("2.-Registrar Venta\n");
        printf("3.-Calcular Ganancias\n");
        printf("4.-Mostrar Productos\n");
        printf("5.-Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                registrarProducto(nombres, codigos, costos, preciosVenta, cantidades, totProductos);
                totProductos++;
                break;
            case 2:
                registrarVenta(nombres, codigos, costos, preciosVenta, cantidades, totProductos, ganancias_semanales);
                break;
            case 3:
                calcularGanancias(ganancias_semanales);
                break;
            case 4:
                desplegarProductos(nombres, codigos, costos, preciosVenta, cantidades, totProductos);
                break;
            case 5:
                printf("Saliendo.\nHasta luego.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
}

int main(int argc, char *argv[]) {
    desplegarMenu();
    return 0;
}

