#include <stdio.h> 
#define aceleracion 32
int main(int argc, char *argv[]) {
	float tiempo;
	float producto;
	float distancia; 
	printf("Introduce el tiempo en segundos: "); 
	scanf("%f", &tiempo); 
	producto = aceleracion * (tiempo * tiempo); 
	distancia = producto / 2; 
	printf("El objeto caeria una distancia de %.2f pies en %.2f segundos.\n", distancia, 
	tiempo);
    return 0;
}
