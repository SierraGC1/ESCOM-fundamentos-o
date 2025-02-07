#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
    
    int iUno, iDos;

    int limite = 100;

    srand(time(NULL));

    iUno = rand() % limite;
    iDos = rand() % limite;

    printf("numeroUno      = %d\n", iUno);
    printf("numeroDos      = %d\n", iDos);
    return 0;
}
