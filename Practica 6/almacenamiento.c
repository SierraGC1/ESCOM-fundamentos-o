#include <stdio.h>

void mostrarDirecciones(int arreglo[]){
    int i;
    printf("\nDirecciones del arreglo\n");
    for(i = 0; i < 14; i++)
    {
        printf("Arreglo[%d], su direccion: %d, su valor: %d\n", i, (arreglo + i), *(arreglo + i));
    }
}

void imprimirJustificacion(int arreglo[]) {
    int *ptr = arreglo;  // Asignar la direccion del arreglo al puntero `ptr`

    // Imprimir el valor en la posicion `ptr + 7` del arreglo =85
    printf("\n------------------------------------------------------");
    printf("\nValor en la posicion 7 del arreglo: %d", *(ptr + 7));
    printf("\nDireccion inicial: %d | Direccion p + 7: %d", ptr, ptr + 7);
    printf("\nDireccion final: %d", &arreglo[*(ptr+7)]);  // Dirección final
    printf("\nReferencia del valor (indice 7): %d\n", arreglo[*(ptr + 7)]); 
    
    // Imprimir el primer elemento del arreglo mas 3 = 26
    printf("\n------------------------------------------------------");
    printf("\nYa que *arreglo obtiene el valor en la posicion 0 y su valor es 23 y se suma 3\n");
    printf("\nPrimer valor mas 3: %d y su direccion es: %d", *arreglo + 3, arreglo);  

    // Imprimir el valor de `*ptr` y luego avanzar al siguiente=23
    printf("\n------------------------------------------------------");
    printf("\nValor en la direccion inicial %d (avanzando al siguiente) al puntero para que apunte en arreglo[1]", ptr);
    printf("\nDireccion Inicial: %d", ptr);
    printf("\nValor inicial: %d", *ptr++);
    printf("\nDirreccion final: %d", ptr);

    // Imprimir el segundo elemento del arreglo (indice 1)=5
    printf("\n------------------------------------------------------");
    printf("\n Ya que el arrglo apunta en el arreglo[0]=23");
    printf("\nValor en la posicion 1 del arreglo (siguiente a la inicial): %d", *(arreglo + 1));
    printf("\nDireccion de la posicion 0: %d", arreglo );
    printf("\nDireccion de la posicion 1: %d", (arreglo + 1));

    // Incrementar el valor de `*ptr` y mostrarlo antes(5) y despues(6)
    printf("\n------------------------------------------------------");
    printf("\n*ptr hace referencia a arreglo[1],como modificamos antes el puntero");
    printf("\nValor en indice 1 (antes de incrementar): %d", (*ptr)++);  
    printf("\nValor en indice 1 (despues de incrementar): %d", *ptr); 
    printf("\nDireccion Inicial: %d y Direccion Final: %d\n", ptr, ptr);

    // Imprimir el valor en `ptr + 2` (indice 4)=65
    printf("\n------------------------------------------------------");
    printf("\nDesde la posicion 2, avanzamos 2 posiciones hasta la 4.");
    printf("\nDireccion inicial: %d | Direccion posicion 4: %d", ptr, ptr + 2);
    printf("\nAqui se recorrio dos posiciones de 4 bytes, es igual a 8 bytes");
    printf("\nValor en la posicion 4: %d", *(ptr + 2));

    // Confirmar que `ptr` no se modifico=6
    printf("\n------------------------------------------------------");
    printf("\nYa que hacemos referencia a *ptr");  
    printf("\nValor actual de *ptr (sin cambio): %d", *ptr);
	printf("\nDireccion: %d", ptr);    
	//  Hacer que *(ptr+2)
    printf("\n------------------------------------------------------");
    printf("\nEl puntero p apunta inicialmente a 'arreglo[1]', luego avanza dos posiciones hacia 'arreglo[3]', cuyo valor es: %d",*(ptr+2));
    printf("\nDireccion Inicial: %d y  Direccion Final: %d\n", ptr, ptr + 2);
    printf("\nEsto indica que avanzó %d posiciones de enteros, es decir: %d * 4 bytes = %d bytes", (ptr + 2) - ptr, (ptr + 2) - ptr, ((ptr + 2) - ptr) * 4);
    
    // Confirmar que `ptr` ya se modifico
	printf("\n------------------------------------------------------");
    printf("\nSabemos que este valor ya se modifico, por lo cual imprime: %d ", *ptr);
    printf("\nDireccion: %d\n", ptr);
    
    // Imprimir el valor en la posicion 9 del arreglo=85
    printf("\n------------------------------------------------------");
    printf("\nAccediendo al valor en la posicion 9 del arreglo desde el inicio.");
    printf("\nDireccion inicial: %d | Direccion en indice 9: %d", arreglo, arreglo + 9);
    printf("\nSe recorrieron 9 posiciones de 4 bytes, es igual a 36 bytes");
    printf("\nValor en la posicion 9: %d", *(arreglo + 9));
    printf("\nDireccion final: %d",arreglo+9);
}

void ejecutarPrograma(){
    int arreglo[14] = {23, 5, 98, 65, 3, 55, 73, 9, 21, 85, 10, 33, 55, 49};   // tamaño del arreglo mal inicializado de 10 a 14
    mostrarDirecciones(arreglo);
    imprimirJustificacion(arreglo);
}

int main(int argc, char *argv[]){
    ejecutarPrograma();
    return 0;
}

