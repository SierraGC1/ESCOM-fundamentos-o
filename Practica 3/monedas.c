#include <stdio.h> 
int main(int argc, char *argv[]) {
 	int cuartos, deci, quintos; 
	int monedas; 
	printf("Introduce el numero de cuartos: "); 
	scanf("%d", &cuartos); 
	printf("Introduce el numero de monedas de diez centavos: "); 
	scanf("%d", &deci); 
	printf("Introduce el numero de monedas de cinco centavos: "); 
	scanf("%d", &quintos); 
	monedas = (25*cuartos) + (10*deci) + (5*quintos); 
	printf("Las monedas valen %d centavos.\n", monedas); 
    return 0;
}
