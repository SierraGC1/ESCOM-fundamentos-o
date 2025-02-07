#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 45
#define MAX_DESCRIPCION 250
#define MAX_ARTICULOS 50
#define MAX_PEDIDOS 35
#define MAX_VENTAS 25

typedef struct Articulo {
    char nombre[MAX_NOMBRE];
    char descripcion[MAX_DESCRIPCION];
    double precio;
} Articulo;

typedef struct Pedido {
    Articulo *articulos;
    int *cantidades;
    int numArticulos;
    int realizado; // 0 = no realizado, 1 = realizado
} Pedido;

typedef struct Venta {
    Pedido *pedidos;
    double subTotal;
    double iva;
    double total;
} Venta;

void quitarEnter(char cadena[]) {
    int longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
}

void leerArticulo(Articulo *articulo) {
    printf("Ingrese el nombre del articulo: ");
    fgets(articulo->nombre, MAX_NOMBRE, stdin);
    quitarEnter(articulo->nombre);

    printf("Ingrese la descripcion del articulo: ");
    fgets(articulo->descripcion, MAX_DESCRIPCION, stdin);
    quitarEnter(articulo->descripcion);

    printf("Ingrese el precio del articulo: ");
    scanf("%lf", &articulo->precio);
    getchar();  
}

int buscarArticulo(Articulo *articulos, int numArticulos, char *nombre) {
	Articulo *articulo= articulos;
    for (articulos; articulo < articulos + numArticulos; articulo++) {
        if (strcmp(articulo->nombre, nombre) == 0) {
            return articulo - articulos;  
        }
    }
    return -1;  
}

void modificarArticulo(Articulo *articulo) {
    printf("Ingrese el nuevo nombre del articulo: ");
    fgets(articulo->nombre, MAX_NOMBRE, stdin);
    quitarEnter(articulo->nombre);

    printf("Ingrese la nueva descripcion del articulo: ");
    fgets(articulo->descripcion, MAX_DESCRIPCION, stdin);
    quitarEnter(articulo->descripcion);

    printf("Ingrese el nuevo precio del articulo: ");
    scanf("%lf", &articulo->precio);
    getchar();  
}

void eliminarArticulo(Articulo *articulos, int *numArticulos, Articulo *articulo) {
    for (; articulo < articulos + *numArticulos - 1; articulo++) {
        *articulo = *(articulo + 1);
    }
    (*numArticulos)--;
}

void tomarPedido(Pedido *pedido, Articulo *articulos, int numArticulos) {
    char nombreArticulo[MAX_NOMBRE];
    pedido->articulos = (Articulo *)malloc(numArticulos * sizeof(Articulo));
    pedido->cantidades = (int *)malloc(numArticulos * sizeof(int));
    pedido->numArticulos = 0;

    do {
        printf("Ingrese el nombre del articulo (o 'fin' para terminar): ");
        fgets(nombreArticulo, MAX_NOMBRE, stdin);
        quitarEnter(nombreArticulo);

        if (strcmp(nombreArticulo, "fin") == 0) {
            break;
        }

        int index = buscarArticulo(articulos, numArticulos, nombreArticulo);
        if (index != -1) {
            Articulo *articulo = pedido->articulos + pedido->numArticulos;
            *articulo = articulos[index];

            printf("Ingrese la cantidad del articulo %s: ", articulo->nombre);
            scanf("%d", &pedido->cantidades[pedido->numArticulos]);
            getchar();

            pedido->numArticulos++;
        } else {
            printf("Articulo no encontrado. Intente de nuevo.\n");
        }

    } while (pedido->numArticulos < MAX_PEDIDOS);
}


void cambiarArticuloPedido(Pedido *pedido) {
    Articulo *ptrArticulo = pedido->articulos;
    int *ptrCantidad = pedido->cantidades;
    int indiceArticulo;
    Articulo *articulo = ptrArticulo;

    printf("Articulos en el pedido:\n");
    for (ptrArticulo; articulo < ptrArticulo + pedido->numArticulos; articulo++) {
        printf("%ld. %s (Cantidad: %d, Precio: %.2f)\n", articulo - ptrArticulo, articulo->nombre, *(ptrCantidad + (articulo - ptrArticulo)), articulo->precio);
    }

    printf("Seleccione el indice del articulo a modificar: ");
    scanf("%d", &indiceArticulo);
    getchar(); 

    if (indiceArticulo >= 0 && indiceArticulo < pedido->numArticulos) {
        printf("Ingrese la nueva cantidad para el articulo %s: ", (ptrArticulo + indiceArticulo)->nombre);
        scanf("%d", (ptrCantidad + indiceArticulo));
        getchar(); 
    } else {
        printf("Indice invalido. Intente nuevamente.\n");
    }
}

void cancelarPedido(Pedido *pedidos, int *numPedidos) {
    int index;
    printf("Lista de pedidos:\n");

    Pedido *p = pedidos;
    for (p; p < pedidos + *numPedidos; p++) {
        printf("%ld. Pedido %ld\n", (p - pedidos) + 1, (p - pedidos) + 1);
    }

    printf("Seleccione el numero del pedido que desea cancelar: ");
    scanf("%d", &index);
    getchar();

    if (index >= 1 && index <= *numPedidos) {
        Pedido *pedidoSeleccionado = pedidos + (index - 1);
        free(pedidoSeleccionado->articulos);
        free(pedidoSeleccionado->cantidades);
		Pedido *p = pedidos + (index - 1);
        for (; p < pedidos + *numPedidos - 1; p++) {
            *p = *(p + 1);
        }

        (*numPedidos)--;
        printf("Pedido cancelado exitosamente.\n");
    } else {
        printf("Número de pedido inválido.\n");
    }
}



void menuArticulos(Articulo *articulos, int *numArticulos) {
    int opcion;
    char nombre[MAX_NOMBRE];

    do {
        printf("\nMenu Articulos:\n");
        printf("1. Introducir un articulo\n");
        printf("2. Buscar un articulo\n");
        printf("3. Modificar un articulo\n");
        printf("4. Eliminar un articulo\n");
        printf("5. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();  

        switch (opcion) {
            case 1:
                if (*numArticulos < MAX_ARTICULOS) {
                    leerArticulo(articulos + *numArticulos);
                    (*numArticulos)++;
                } else {
                    printf("No se pueden agregar mas articulos.\n");
                }
                break;
            case 2:
                printf("Ingrese el nombre del articulo a buscar: ");
                fgets(nombre, MAX_NOMBRE, stdin);
                quitarEnter(nombre);

                int index = buscarArticulo(articulos, *numArticulos, nombre);
                if (index != -1) {
                    printf("Articulo encontrado: %s, Precio: %.2f\n", articulos[index].nombre, articulos[index].precio);
                } else {
                    printf("Articulo no encontrado.\n");
                }
                break;
            case 3:
                printf("Ingrese el nombre del articulo a modificar: ");
                fgets(nombre, MAX_NOMBRE, stdin);
                quitarEnter(nombre);

                index = buscarArticulo(articulos, *numArticulos, nombre);
                if (index != -1) {
                    modificarArticulo(articulos + index);
                } else {
                    printf("Articulo no encontrado.\n");
                }
                break;
            case 4:
                printf("Ingrese el nombre del articulo a eliminar: ");
                fgets(nombre, MAX_NOMBRE, stdin);
                quitarEnter(nombre);

                index = buscarArticulo(articulos, *numArticulos, nombre);
                if (index != -1) {
                    eliminarArticulo(articulos, numArticulos, articulos + index);
                    printf("Articulo eliminado.\n");
                } else {
                    printf("Articulo no encontrado.\n");
                }
                break;
            case 5:
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 5);
}

void menuPedidos(Pedido *pedidos, int *numPedidos, Articulo *articulos, int numArticulos) {
    int opcion;

    do {
        printf("\nMenu Pedidos:\n");
        printf("1. Tomar un nuevo pedido\n");
        printf("2. Cambiar un pedido\n");
        printf("3. Cancelar un pedido\n");
        printf("4. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();  

        switch (opcion) {
            case 1:
                tomarPedido(&pedidos[*numPedidos], articulos, numArticulos);
                (*numPedidos)++;
                break;
            case 2:
                cambiarArticuloPedido(&pedidos[*numPedidos - 1]);
                break;
            case 3:
                cancelarPedido(pedidos, numPedidos);
                break;
            case 4:
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 4);
}

void menuVentas(Pedido *pedidos, int numPedidos) {
    int opcion;
    Venta ventas[MAX_VENTAS];
    int numVentas = 0; 
    int i, pedidoSeleccionado;
    double totalVentas = 0;

    do {
        printf("\nMenu Ventas:\n");
        printf("1. Realizar una venta\n");
        printf("2. Mostrar resumen de los pedidos realizados\n");
        printf("3. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();  

        switch (opcion) {
            case 1: {
                printf("Pedidos disponibles:\n");
                for (i = 0; i < numPedidos; i++) {
                    if (!pedidos[i].realizado) {
                        printf("%d. Pedido %d (Articulos: %d)\n", i + 1, i + 1, pedidos[i].numArticulos);
                    }
                }
                
                printf("Seleccione el numero del pedido que desea realizar: ");
                scanf("%d", &pedidoSeleccionado);
                getchar();

                if (pedidoSeleccionado >= 1 && pedidoSeleccionado <= numPedidos && !pedidos[pedidoSeleccionado - 1].realizado) {
                    Pedido *pedido = &pedidos[pedidoSeleccionado - 1];
                    
                    Venta *venta = &ventas[numVentas];
                    venta->pedidos = pedido;
                    calcularVenta(venta, pedido);
                    pedido->realizado = 1; 

                    printf("\nResumen del pedido realizado:\n");
                    mostrarResumenVenta(venta);
                    numVentas++;
                    totalVentas += venta->total; 
                } else {
                    printf("Seleccion invalida o el pedido ya fue realizado.\n");
                }
                break;
            }
            case 2: {
                
                printf("\nResumen de pedidos realizados:\n");
                for (i = 0; i < numVentas; i++) {
                    printf("\nPedido %d:\n", i + 1);
                    mostrarResumenVenta(&ventas[i]);
                }

                printf("\nTotal de ventas realizadas: %.2f\n", totalVentas);
                break;
            }
            case 3:
                printf("Regresando al menu principal...\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);
}

void calcularVenta(Venta *venta, Pedido *pedido) {
    double subTotal = 0;
    
    int *cantidad = pedido->cantidades;
	Articulo *articulo = pedido->articulos;
    for (; articulo < pedido->articulos + pedido->numArticulos; articulo++) {
        subTotal += articulo->precio * *(cantidad + (articulo - pedido->articulos));
    }

    venta->subTotal = subTotal;
    venta->iva = subTotal * 0.16;
    venta->total = venta->subTotal + venta->iva;
}

void mostrarResumenVenta(Venta *venta) {
    printf("Subtotal: %.2f\n", venta->subTotal);
    printf("IVA: %.2f\n", venta->iva);
    printf("Total: %.2f\n", venta->total);
}


void ejecutarPrograma() {
    Articulo articulos[MAX_ARTICULOS];
    Pedido pedidos[MAX_PEDIDOS];
    Venta ventas[MAX_VENTAS];
    int numArticulos = 0, numPedidos = 0, numVentas = 0;

    int opcion;

    do {
        printf("\n****Menu Principal*****\n");
        printf("1. Gestionar Articulos\n");
        printf("2. Gestionar Pedidos\n");
        printf("3. Gestionar Ventas\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();  

        switch (opcion) {
            case 1:
                menuArticulos(articulos, &numArticulos);
                break;
            case 2:
                menuPedidos(pedidos, &numPedidos, articulos, numArticulos);
                break;
            case 3:
                menuVentas(pedidos, numPedidos);
                break;
            case 4:
                printf("Hasta luego.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

int main() {
    ejecutarPrograma();
    return 0;
}

