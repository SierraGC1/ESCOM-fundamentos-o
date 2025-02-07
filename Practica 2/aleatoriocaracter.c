#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>     

int main(int argc, char *argv[]) {
    char caracteresuno,caracteresdos,caracterestres;
	int limite=255; 
	
    srand(time(NULL));

 
    caracteresuno = rand()% limite;  
	caracteresdos = rand()% limite; 
	caracterestres = rand()% limite;  
  
    printf("caracter = %c\n", caracteresuno);
    printf("caracter= %c\n", caracteresdos);
    printf("caracter= %c\n", caracterestres);

    return 0;
}

