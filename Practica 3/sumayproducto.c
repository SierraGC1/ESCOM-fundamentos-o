#include <stdio.h> 
int main(int argc, char *argv[]) {
    int uno;
    int dos;
    int suma;
    int producto;
    printf("Dame el primer numero:");
    scanf("%d", &uno); 
    printf("Dame el segundo numero:");
    scanf("%d", &dos); 
    suma=uno+dos;
    producto=uno*dos;
    printf("Este es el resultado de la suma:%d\n",suma);
    printf("Este es el resultado de su producto:%d\n",producto);
	printf( "Este es el final del programa.\n" );
    return 0;
}

